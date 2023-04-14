#include <iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include <opencv2/core/core.hpp>
#include "FacePreprocess.h"
#include <numeric>
#include <math.h>
#include "realtime_face_detection.hpp"
#include <time.h>
#include "live.h"
#include "mtcnn_new.h"

#define PI 3.14159265
using namespace std;
using namespace cv;

double sum_score, sum_fps,sum_confidence;

/**
 * 修改了
 */
Mat Zscore(const Mat &fc) {
    Mat fc_norm;
    cv::normalize(fc, fc_norm, 0, 1, cv::NORM_MINMAX);
    return fc_norm;
}


/**
 * This module is using to computing the cosine distance between input feature and ground truth feature
 *  */
float CosineDistance(const cv::Mat &v1, const cv::Mat &v2) {
    double dot_product = v1.dot(v2);
    double norm_v1 = cv::norm(v1);
    double norm_v2 = cv::norm(v2);
    return dot_product / (norm_v1 * norm_v2);
}

/**
 * Calculating the turning angle of face
 *  */
inline double count_angle(float landmark[5][2]) {
    double a = landmark[2][1] - (landmark[0][1] + landmark[1][1]) / 2;
    double b = landmark[2][0] - (landmark[0][0] + landmark[1][0]) / 2;
    double angle = atan(abs(b) / a) * 180 / PI;
    return angle;
}


/**
 * Formatting output structure
 */
inline cv::Mat draw_conclucion(String intro, double input, cv::Mat result_cnn, int position) {
    char string[10];
    sprintf(string, "%.2f", input);
    std::string introString(intro);
    introString += string;
    putText(result_cnn, introString, cv::Point(5, position), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 255, 255),2);
    return result_cnn;
}
/**
 * Face Recognition pipeline using camera. 
 * Firstly, it will use MTCNN face detector to detect the faces [x,y,x2,y2] and [eyes, nose, cheeks] landmarks
 * Then, face alignment will be implemented for wraping the face into decided center point
 * Next, the aligned face will be sent into ncnn-mobilefacenet-arcface model and campare with faces in database
 * Finally, some imformation will be shown on the frame
 * 
 */
int MTCNNDetection() {
    //OpenCV Version
    cout << "OpenCV Version: " << CV_MAJOR_VERSION << "."
    << CV_MINOR_VERSION << "."
    << CV_SUBMINOR_VERSION << endl;

    //Live detection configs
    struct ModelConfig config1 ={2.7f,0.0f,0.0f,80,80,"model_1",false};
    struct ModelConfig config2 ={4.0f,0.0f,0.0f,80,80,"model_2",false};
    vector<struct ModelConfig> configs;
    configs.emplace_back(config1);
    configs.emplace_back(config2);
    class Live live;
    live.LoadModel(configs);

    class Arcface reco;



    // loading faces   

    // Define a matrix variable faces of type Mat and a container fc1 of type vector
    Mat  faces;
    vector<cv::Mat> fc1;
    // Define wildcards for image file names
    std::string pattern_jpg = project_path+ "/img/*.jpg";

    // Define a vector type container image_names and use the glob function to find image file names in the specified directory that match the wildcard rule
	std::vector<cv::String> image_names;
    
	cv::glob(pattern_jpg, image_names);

    // Get the number of image files found
    int image_number=image_names.size();
	if (image_number == 0) {
		std::cout << "No image files[jpg]" << std::endl;
		return 0;
	}
    // Output a message indicating that the image is being loaded
    cout <<"loading pictures..."<<endl;

   //convert to vector and store into fc, whcih is benefical to furthur operation
	for (unsigned int image_ = 0; image_ < image_number; ++ image_){
		faces = cv::imread(image_names[ image_]);
		//imshow("data set", faces);
		//waitKey(50);
        fc1.push_back(reco.getFeature(faces));
        fc1[image_] = Zscore(fc1[image_]);
        printf("\rloading[%.2lf%%]",  image_*100.0 / (image_number - 1));
     }
      cout <<""<<endl;  
      float factor = 0.709f;
      float threshold[3] = {0.7f, 0.6f, 0.6f};
       cout <<"loading succeed! "<<image_number<<" pictures in total"<<endl;

    int count = 0;
    VideoCapture cap(0); //using camera capturing
    cap.set(CAP_PROP_FRAME_WIDTH, input_width);
    cap.set(CAP_PROP_FRAME_HEIGHT, input_height);
    cap.set(CAP_PROP_FPS, 90);
    if (!cap.isOpened()) {
        cerr << "cannot get image" << endl;
        return -1;
    }

    float confidence;
    vector<float> fps;
    static double current;
    static char string[10];
    static char string1[10];
    char buff[10];
    Mat frame;
    Mat result_cnn;

    // gt face landmark
    float v1[5][2] = {
            {30.2946f, 51.6963f},
            {65.5318f, 51.5014f},
            {48.0252f, 71.7366f},
            {33.5493f, 92.3655f},
            {62.7299f, 92.2041f}};

    cv::Mat src(5, 2, CV_32FC1, v1); 
    memcpy(src.data, v1, 2 * 5 * sizeof(float));

    double score, angle;


    while (1) {
         count++;
         double t = (double) cv::getTickCount();
         cap >> frame;        
         cv::flip (frame,frame,1);
         resize(frame, result_cnn, frame_size,INTER_LINEAR);
         vector<Bbox> faceInfo = detect_mtcnn(frame);        
         //find the laggest face
         int lagerest_face=0,largest_number=0;
         for (int i = 0; i < faceInfo.size(); i++){
                int y_ = (int) faceInfo[i].y2 * ratio_y;
                int h_ = (int) faceInfo[i].y1 * ratio_y;
                if (h_-y_> lagerest_face){
                    lagerest_face=h_-y_;
                    largest_number=i;                   
                }
         }

         int start_la,end_la;
         if (faceInfo.size()==0) {  
            start_la= 0;
            end_la= 0;
         }
         else if(largest_face_only){
            start_la= largest_number;
            end_la= largest_number+1;
         }
         else {
            start_la=0;
            end_la=faceInfo.size();
        }

            //the faces to operate Iterate through the detected faces
            for (int i =  start_la; i <end_la; i++) {
                float x_   =  faceInfo[i].x1;
                float y_   =  faceInfo[i].y1;
                float x2_ =  faceInfo[i].x2;
                float y2_ =  faceInfo[i].y2;
                int x = (int) x_ ;
                int y = (int) y_;
                int x2 = (int) x2_;
                int y2 = (int) y2_;
                struct LiveFaceBox  live_box={x_,y_,x2_,y2_} ;
                // 在图像上画出人脸框
                cv::rectangle(result_cnn, Point(x*ratio_x, y*ratio_y), Point(x2*ratio_x,y2*ratio_y), cv::Scalar(0, 0, 255), 2);
                // Perspective Transformation
                float v2[5][2] =
                        {{faceInfo[i].ppoint[0], faceInfo[i].ppoint[5]},
                        {faceInfo[i].ppoint[1], faceInfo[i].ppoint[6]},
                        {faceInfo[i].ppoint[2], faceInfo[i].ppoint[7]},
                        {faceInfo[i].ppoint[3], faceInfo[i].ppoint[8]},
                        {faceInfo[i].ppoint[4], faceInfo[i].ppoint[9]},
                        };


                // compute the turning angle
                angle = count_angle(v2);

                static std::string hi_name;
                static std::string liveface;
                static int stranger,close_enough;
 

/****************************jump*****************************************************/                
                if (count%jump==0){
                cv::Mat dst(5, 2, CV_32FC1, v2);
                memcpy(dst.data, v2, 2 * 5 * sizeof(float));

                cv::Mat m = FacePreprocess::similarTransform(dst, src);
                cv::Mat aligned = frame.clone();
                cv::warpPerspective(frame, aligned, m, cv::Size(96, 112), INTER_LINEAR);
                resize(aligned, aligned, Size(112, 112), 0, 0, INTER_LINEAR);
                

                //set to 1 if you want to record your image
                if (record_face) {
                    imshow("aligned face", aligned);
                    waitKey(2000);
                    imwrite(project_path+ format("/img/%d.jpg", count), aligned);
                }
                //features of camera image
                cv::Mat fc2 = reco.getFeature(aligned);

                // normalize
                fc2 = Zscore(fc2);

                //the similarity score
                vector<double> score_;
                for (unsigned int compare_ = 0; compare_ < image_number; ++ compare_){
                    score_.push_back(CosineDistance(fc1[compare_], fc2));// Calculate similarity score
                }
                int maxPosition = max_element(score_.begin(),score_.end()) - score_.begin(); 
                current=score_[maxPosition];
                score_.clear();
                sprintf(string, "%.4f", current);

                 if (current >= face_thre && y2-y>= distance_threshold){
                            //put name  如果当前相似度分数大于阈值，且人脸框高度大于阈值
                            // 标出人名
                            int slant_position=image_names[maxPosition].rfind ('/');
                            cv::String name = image_names[maxPosition].erase(0,slant_position+1);
                            name=name.erase( name.length()-4, name.length()-1);
                            hi_name="Hello,"+name;
                            putText(result_cnn, hi_name, cv::Point(5, 60), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 255, 255),2);
                            cout<<name<<endl;
                            //determin whethe it is a fake face
                            confidence=live.Detect(frame,live_box);
                            
                            sprintf(string1, "%.4f", confidence);
                            cv::putText(result_cnn,string1, Point(x*ratio_x, y2*ratio_y+20), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0,255,255),2);
                            if (confidence<=true_thre)
                                    {putText(result_cnn, "Fake face!!", cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 0, 255),2);
                                    liveface="Fake face!!";
                                    }
                                else
                                    {putText(result_cnn, "True face", cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(255, 255, 0),2);     
                                    liveface="True face";
                                    }
                                cout<<liveface<<endl;
                                stranger=0;
                                close_enough=1;
                                } 
                            
                else if(current >= face_thre && y2-y < distance_threshold){
                                //put name
                                int slant_position=image_names[maxPosition].rfind ('/');
                                cv::String name = image_names[maxPosition].erase(0,slant_position+1);
                                name=name.erase( name.length()-4, name.length()-1);
                                hi_name="Hi,"+name;
                                putText(result_cnn, hi_name, cv::Point(5, 60), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 255, 255),2);
                                //Ask be closer to avoid mis-reco
                                putText(result_cnn, "Closer please", cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 255, 255),2);   
                                cout<<"Closer please"<<endl;
                                stranger=0;
                                close_enough=0;
                    }    
                else {
                            putText(result_cnn, "Stranger", cv::Point(5, 60), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 0, 255),2);   
                            cout<<"Stranger"<<endl;
                            stranger=1;
                }    
                 
                 
                 //修改了highlight the significant landmarks on face

                // Define landmark colors
                vector<Scalar> colors = {Scalar(0, 255, 0), Scalar(0, 0, 255), Scalar(255, 0, 0), Scalar(0, 0, 255), Scalar(0, 255, 0)};

                // Loop through landmarks and draw circles
                for (int j = 0; j < 5; j++) {
                    int color_index = (j == 1 or j == 4) ? 0 : (j == 2) ? 2 : 1;
                    cv::circle(result_cnn, Point(faceInfo[i].ppoint[j]*ratio_x, faceInfo[i].ppoint[j + 5]*ratio_y), 3, colors[color_index], FILLED, LINE_AA);
                }
                // Show similarity score
                cv::putText(result_cnn,string, Point(x*ratio_x, y2*ratio_y), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(255, 255, 0),2);
            
                }
                else{
                    if(stranger)
                    {
                         putText(result_cnn, "Stranger", cv::Point(5, 60), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 0, 255),2);
                    }
                    else if(close_enough)
                    {
                         putText(result_cnn, hi_name, cv::Point(5, 60), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 255, 255),2);
                         putText(result_cnn,string1,Point(x*ratio_x, y2*ratio_y+20), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0,255,255),2);
                         if (liveface.length()==9)
                            putText(result_cnn, liveface, cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(255, 255, 0),2);
                         else
                            putText(result_cnn, liveface, cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 0, 255),2);
                    }
                    else
                    {
                       putText(result_cnn, hi_name, cv::Point(5, 60), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 255, 255),2);
                       putText(result_cnn, "Closer please", cv::Point(5, 80), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(0, 255, 255),2);
                    }
                    
                if (count==10*jump-1) count=0;
                 //highlight the significant landmarks on face
                for (int j = 0; j < 5; j += 1) {
                    if (j == 0 or j == 3) {
                        cv::circle(result_cnn, Point(faceInfo[i].ppoint[j]*ratio_x, faceInfo[i].ppoint[j + 5]*ratio_y), 3,
                                Scalar(0, 255, 0),
                                FILLED, LINE_AA);
                    } else if (j==2){
                        cv::circle(result_cnn, Point(faceInfo[i].ppoint[j]*ratio_x, faceInfo[i].ppoint[j + 5]*ratio_y), 3,
                                Scalar(255, 0, 0),
                                FILLED, LINE_AA);
                    }
                        else {
                        cv::circle(result_cnn, Point(faceInfo[i].ppoint[j]*ratio_x, faceInfo[i].ppoint[j + 5]*ratio_y), 3,
                                Scalar(0, 0, 255),
                                FILLED, LINE_AA);
                        }
            }
                cv::putText(result_cnn,string, Point(x*ratio_x, y2*ratio_y), cv::FONT_HERSHEY_SIMPLEX,0.75, cv::Scalar(255, 255, 0),2);
               
            
                }

            }

            t = ((double) cv::getTickCount() - t) / (cv::getTickFrequency());
            fps.push_back(1.0/t);
            int fpsnum_= fps.size();
            float fps_mean;                
            //compute average fps value
            if(fpsnum_<=30){
                sum_fps = std::accumulate(std::begin(fps), std::end(fps), 0.0);
                fps_mean = sum_fps /  fpsnum_; 
                
            }
            else{
                sum_fps = std::accumulate(std::end(fps)-30, std::end(fps), 0.0);
                fps_mean = sum_fps /  30; 
                if(fpsnum_>=300) fps.clear();

            }
            result_cnn = draw_conclucion("FPS: ", fps_mean, result_cnn, 20);//20
            result_cnn = draw_conclucion("Angle: ", angle, result_cnn, 40);//65
           
             
            cv::imshow("image", result_cnn);
            cv::waitKey(1);

        }
}
