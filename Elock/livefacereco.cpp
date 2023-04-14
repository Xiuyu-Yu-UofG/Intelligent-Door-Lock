#include <math.h>
#include "livefacereco.hpp"
#include <time.h>
#include "math.hpp"
#include "parallel_video_capture.hpp"
#include "mtcnn_new.h"
#include "FacePreprocess.h"
//#include "image_dataset_handler.hpp"
#include <algorithm>

#define PI 3.14159265
using namespace std;

double sum_score, sum_fps, sum_confidence;

#define  PROJECT_PATH "/home/pi/LiveFaceReco_RaspberryPi";

std::vector<std::string> split(const std::string& s, char seperator)
{
	std::vector<std::string> output;

	std::string::size_type prev_pos = 0, pos = 0;

	while ((pos = s.find(seperator, pos)) != std::string::npos)
	{
		std::string substring(s.substr(prev_pos, pos - prev_pos));

		output.push_back(substring);

		prev_pos = ++pos;
	}

	output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

	return output;
}

void calculateFaceDescriptorsFromDisk(Arcface& facereco, std::map<std::string, cv::Mat>& face_descriptors_map)
{
	const std::string project_path = PROJECT_PATH;
	std::string pattern_jpg = project_path + "/img/*.jpg";
	std::vector<cv::String> image_names;

	cv::glob(pattern_jpg, image_names);

	int image_number = image_names.size();

	if (image_number == 0) {
		std::cout << "No image files[jpg]" << std::endl;
		std::cout << "At least one image of 112*112 should be put into the img folder. Otherwise, the program will broke down." << std::endl;
		exit(0);
	}
	//cout <<"loading pictures..."<<endl;
	//cout <<"image number in total:"<<image_number<<endl;
	cv::Mat  face_img;
	unsigned int img_idx = 0;

	//convert to vector and store into fc, whcih is benefical to furthur operation
	for (auto const& img_name : image_names)
	{
		//cout <<"image name:"<<img_name<<endl;
		auto splitted_string = split(img_name, '/');
		auto splitted_string_2 = splitted_string[splitted_string.size() - 1];
		std::size_t name_length = splitted_string_2.find_last_of('_');
		auto person_name = splitted_string_2.substr(0, name_length);
		//std::cout<<person_name<<"\n";
		face_img = cv::imread(img_name);

		cv::Mat face_descriptor = facereco.getFeature(face_img);

		face_descriptors_map[person_name] = Statistics::zScore(face_descriptor);
		//cout << "now loading image " << ++img_idx << " out of " << image_number << endl;
		printf("\rloading[%.2lf%%]\n", (++img_idx) * 100.0 / (image_number));
	}

	cout << "loading succeed! " << image_number << " pictures in total" << endl;
}
void calculateFaceDescriptorsFromImgDataset(Arcface& facereco, std::map<std::string, std::list<cv::Mat>>& img_dataset, std::map<std::string, std::list<cv::Mat>>& face_descriptors_map)
{
	int img_idx = 0;
	const int image_number = img_dataset.size() * 5;
	for (const auto& dataset_pair : img_dataset)
	{
		const std::string person_name = dataset_pair.first;

		std::list<cv::Mat> descriptors;
		if (image_number == 0) {
			cout << "No image files[jpg]" << endl;
			return;
		}
		else {
			cout << "loading pictures..." << endl;
			for (const auto& face_img : dataset_pair.second)
			{
				cv::Mat face_descriptor = facereco.getFeature(face_img);
				descriptors.push_back(Statistics::zScore(face_descriptor));
				cout << "now loading image " << ++img_idx << " out of " << image_number << endl;
				//printf("\rloading[%.2lf%%]\n",  (++img_idx)*100.0 / (image_number));
			}
			face_descriptors_map[person_name] = std::move(descriptors);
		}
	}
}
void loadLiveModel(Live& live)
{
	//Live detection configs
	struct ModelConfig config1 = { 2.7f,0.0f,0.0f,80,80,"model_1",false };
	struct ModelConfig config2 = { 4.0f,0.0f,0.0f,80,80,"model_2",false };
	vector<struct ModelConfig> configs;
	configs.emplace_back(config1);
	configs.emplace_back(config2);
	live.LoadModel(configs);
}
cv::Mat createFaceLandmarkGTMatrix()
{
	// groundtruth face landmark
	float v1[5][2] = {
			{30.2946f, 51.6963f},
			{65.5318f, 51.5014f},
			{48.0252f, 71.7366f},
			{33.5493f, 92.3655f},
			{62.7299f, 92.2041f} };

	cv::Mat src(5, 2, CV_32FC1, v1);
	memcpy(src.data, v1, 2 * 5 * sizeof(float));
	return src.clone();
}
cv::Mat createFaceLandmarkMatrixfromBBox(const Bbox& box)
{
	float v2[5][2] =
	{ {box.ppoint[0], box.ppoint[5]},
	{box.ppoint[1], box.ppoint[6]},
	{box.ppoint[2], box.ppoint[7]},
	{box.ppoint[3], box.ppoint[8]},
	{box.ppoint[4], box.ppoint[9]},
	};
	cv::Mat dst(5, 2, CV_32FC1, v2);
	memcpy(dst.data, v2, 2 * 5 * sizeof(float));

	return dst.clone();
}

Bbox  getLargestBboxFromBboxVec(const std::vector<Bbox>& faces_info)
{
	if (faces_info.size() > 0)
	{
		int lagerest_face = 0, largest_number = 0;
		for (int i = 0; i < faces_info.size(); i++) {
			int y_ = (int)faces_info[i].y2 * ratio_y;
			int h_ = (int)faces_info[i].y1 * ratio_y;
			if (h_ - y_ > lagerest_face) {
				lagerest_face = h_ - y_;
				largest_number = i;
			}
		}

		return faces_info[largest_number];
	}
	return Bbox();
}

LiveFaceBox Bbox2LiveFaceBox(const Bbox& box)
{
	float x_ = box.x1;
	float y_ = box.y1;
	float x2_ = box.x2;
	float y2_ = box.y2;
	int x = (int)x_;
	int y = (int)y_;
	int x2 = (int)x2_;
	int y2 = (int)y2_;
	struct LiveFaceBox  live_box = { x_,y_,x2_,y2_ };
	return live_box;
}

cv::Mat alignFaceImage(const cv::Mat& frame, const Bbox& bbox, const cv::Mat& gt_landmark_matrix)
{
	cv::Mat face_landmark = createFaceLandmarkMatrixfromBBox(bbox);

	cv::Mat transf = FacePreprocess::similarTransform(face_landmark, gt_landmark_matrix);

	cv::Mat aligned = frame.clone();
	cv::warpPerspective(frame, aligned, transf, cv::Size(96, 112), INTER_LINEAR);
	resize(aligned, aligned, Size(112, 112), 0, 0, INTER_LINEAR);

	return aligned.clone();
}

std::string  getClosestFaceDescriptorPersonName(std::map<std::string, cv::Mat>& disk_face_descriptors, cv::Mat face_descriptor)
{
	vector<double> score_(disk_face_descriptors.size());

	std::vector<std::string> labels;

	int i = 0;

	for (const auto& disk_descp : disk_face_descriptors)
	{
		// cout << "comparing with " << disk_descp.first << endl;

		score_[i] = (Statistics::cosineDistance(disk_descp.second, face_descriptor));
		//cout << "score  " << score_[i] << endl;
		labels.push_back(disk_descp.first);
		i++;
	}
	int maxPosition = max_element(score_.begin(), score_.end()) - score_.begin();
	int pos = score_[maxPosition] > face_thre ? maxPosition : -1;
	//cout << "score_[maxPosition] " << score_[maxPosition] << endl;
	std::string person_name = "";
	if (pos >= 0)
	{
		person_name = labels[pos];
	}
	score_.clear();

	return person_name;
}
std::string  getClosestFaceDescriptorPersonName(std::map<std::string, std::list<cv::Mat>>& disk_face_descriptors, cv::Mat face_descriptor)
{
	vector<std::list<double>> score_(disk_face_descriptors.size());

	std::vector<std::string> labels;

	int i = 0;

	for (const auto& disk_descp : disk_face_descriptors)
	{
		for (const auto& descriptor : disk_descp.second)
		{
			score_[i].push_back(Statistics::cosineDistance(descriptor, face_descriptor));
		}

		labels.push_back(disk_descp.first);
		i++;
	}

	int maxPosition = max_element(score_.begin(), score_.end()) - score_.begin();

	auto get_max_from_score_list =
		[&]()
	{
		double max = *score_[maxPosition].begin();
		for (const auto& elem : score_[maxPosition])
		{
			if (max < elem)
			{
				max = elem;
			}
		}
		return max;
	};

	double max = get_max_from_score_list();

	int pos = max > face_thre ? maxPosition : -1;

	std::string person_name = "";
	if (pos >= 0)
	{
		person_name = labels[pos];
	}

	score_.clear();

	return person_name;
}

QImage cvMat2QImage(const cv::Mat& mat)
{
	QImage image;
	switch (mat.type())
	{
	case CV_8UC1:
		// QImage构造：数据，宽度，高度，每行多少字节，存储结构
		image = QImage((const unsigned char*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
		break;
	case CV_8UC3:
		image = QImage((const unsigned char*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		image = image.rgbSwapped(); // BRG转为RGB
		break;
	case CV_8UC4:
		image = QImage((const unsigned char*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		break;
	}
	return image;
}

int MTCNNDetection_qt(QLabel* window, int& ret)
{
	Arcface facereco;
	std::map<std::string, cv::Mat> face_descriptors_dict;
	calculateFaceDescriptorsFromDisk(facereco, face_descriptors_dict);
	Live live;
	loadLiveModel(live);
	float factor = 0.709f;
	float threshold[3] = { 0.7f, 0.6f, 0.6f };
	//ParallelVideoCapture cap("udpsrc port=5000 ! application/x-rtp, payload=96 ! rtpjitterbuffer ! rtph264depay ! avdec_h264 ! videoconvert ! appsink sync=false",cv::CAP_GSTREAMER,30); //using camera capturing
	ParallelVideoCapture cap(0);
	cap.startCapture();

	std::cout << "okay!\n";

	if (!cap.isOpened()) {
		cerr << "cannot get image" << endl;
		return -1;
	}

	float confidence;
	vector<float> fps;

	Mat frame;
	Mat result_cnn;

	double score, angle;

	cv::Mat face_landmark_gt_matrix = createFaceLandmarkGTMatrix();
	int count = -1;
	std::string liveface;
	float ratio_x = 1;
	float ratio_y = 1;
	int flag = 0;
	int record_count = 0;
	int file_save_count = 0;
	int bingo_count = 0;
	while (cap.isOpened())
	{
		frame = cap.getFrame();
		//cv::resize(frame,frame,cv::Size(300,300));
		//cout << "frame size: " << frame.size() << endl;
		if (frame.empty())
		{
			continue;
		}
		++count;
		flag = 0;
		//detect faces
		std::vector<Bbox> faces_info = detect_mtcnn(frame);
		if (faces_info.size() >= 1)
		{
			flag = 1;
			auto large_box = getLargestBboxFromBboxVec(faces_info);
			//cout << "large_box got" << endl;
			LiveFaceBox live_face_box = Bbox2LiveFaceBox(large_box);

			cv::Mat aligned_img = alignFaceImage(frame, large_box, face_landmark_gt_matrix);
			//cout << "aligned_img got" << endl;
			cv::Mat face_descriptor = facereco.getFeature(aligned_img);
			// normalize
			face_descriptor = Statistics::zScore(face_descriptor);
			//cout << "face_descriptor created" << endl;
			std::string person_name = getClosestFaceDescriptorPersonName(face_descriptors_dict, face_descriptor);

			confidence = live.Detect(frame, live_face_box);

			if (confidence <= true_thre)
			{
				//putText(result_cnn, "Fake face!!", cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 0, 255),2);
				liveface = "Fake face!!";
			}
			else
			{
				//putText(result_cnn, person_name, cv::Point(30, 40), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(255, 255, 0),2);
				putText(frame, person_name, cv::Point(15, 80), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(255, 255, 0), 2);
				liveface = "True face";
				cv::rectangle(frame, Point(large_box.x1 * ratio_x, large_box.y1 * ratio_y), Point(large_box.x2 * ratio_x, large_box.y2 * ratio_y), cv::Scalar(0, 0, 255), 2);
			}
			//cout<<liveface<<"\n";
			cv::putText(frame, liveface, cv::Point(15, 40), 1, 2.0, cv::Scalar(255, 0, 0));
			if (liveface == "True face" && !person_name.empty())
			{
				bingo_count++;
			}
		}
		window->setPixmap(QPixmap::fromImage(cvMat2QImage(frame)));
		count++;
		if (count > 50)
			break;
	}
	cap.stopCapture();
	window->setPixmap(QPixmap("lock.png"));
	if (bingo_count > 5)
	{
		ret = UNLOCKED;
	}
	else {
		ret = ALERT;
	}
	return 0;
}

int MTCNNDetection_qt_save(QLabel* window, QString name, int& ret)
{
	Arcface facereco;
	std::map<std::string, cv::Mat> face_descriptors_dict;
	calculateFaceDescriptorsFromDisk(facereco, face_descriptors_dict);
	Live live;
	loadLiveModel(live);
	float factor = 0.709f;
	float threshold[3] = { 0.7f, 0.6f, 0.6f };
	//ParallelVideoCapture cap("udpsrc port=5000 ! application/x-rtp, payload=96 ! rtpjitterbuffer ! rtph264depay ! avdec_h264 ! videoconvert ! appsink sync=false",cv::CAP_GSTREAMER,30); //using camera capturing
	ParallelVideoCapture cap(0);
	cap.startCapture();

	std::cout << "okay!\n";

	if (!cap.isOpened()) {
		cerr << "cannot get image" << endl;
		return -1;
	}

	float confidence;
	vector<float> fps;

	Mat frame;
	Mat result_cnn;

	double score, angle;

	cv::Mat face_landmark_gt_matrix = createFaceLandmarkGTMatrix();
	int count = -1;
	std::string liveface;
	float ratio_x = 1;
	float ratio_y = 1;
	int flag = 0;
	int record_count = 0;
	int file_save_count = 0;

	while (cap.isOpened())
	{
		frame = cap.getFrame();
		//cv::resize(frame,frame,cv::Size(300,300));
		//cout << "frame size: " << frame.size() << endl;
		if (frame.empty())
		{
			continue;
		}
		++count;
		flag = 0;
		//detect faces
		std::vector<Bbox> faces_info = detect_mtcnn(frame);
		if (faces_info.size() >= 1)
		{
			flag = 1;
			auto large_box = getLargestBboxFromBboxVec(faces_info);
			LiveFaceBox live_face_box = Bbox2LiveFaceBox(large_box);
			cv::Mat aligned_img = alignFaceImage(frame, large_box, face_landmark_gt_matrix);
			confidence = live.Detect(frame, live_face_box);
			if (confidence <= true_thre)
			{
				liveface = "Fake face!!";
			}
			else
			{
				liveface = "True face";
				cv::rectangle(frame, Point(large_box.x1 * ratio_x, large_box.y1 * ratio_y), Point(large_box.x2 * ratio_x, large_box.y2 * ratio_y), cv::Scalar(0, 0, 255), 2);
				imwrite(project_path + "/img/" + name.toStdString() + "_0.jpg", aligned_img);
			}
		}
		window->setPixmap(QPixmap::fromImage(cvMat2QImage(frame)));
		if (flag == 0)
		{
			//cout << "no face detected" << endl;
		}
		count++;
		if (count > 50)
			break;
	}
	cap.stopCapture();
	window->setPixmap(QPixmap("lock.png"));
	ret = 1;
	return 0;
}