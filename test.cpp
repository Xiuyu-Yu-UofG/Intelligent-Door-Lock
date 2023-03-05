#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(256, 256), 256, Scalar(0, 0, 255), FILLED);
	Rect roi(128, 128, 256, 256);
	rectangle(img, roi, Scalar(255, 255, 255), FILLED);
	line(img, Point(256, 128), Point(256, 256), Scalar(255, 255, 0), 3);
	putText(img, "I'am CV", Point(256, 128), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
	imshow("img", img);
	waitKey(0);
    return 0;
}