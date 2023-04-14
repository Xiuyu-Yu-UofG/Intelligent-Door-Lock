#include <iostream>
#include <stdio.h>
#include "stdlib.h"
#include <iostream>
#include <array>
#include <vector>
#include <opencv2/opencv.hpp>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "arcface.h"
#include "live.h"

using namespace std;
using namespace cv;

// Adjustable Parameters
const bool largest_face_only=true;
const bool record_face=false;
const int distance_threshold = 90;
const float face_thre=0.40;
const float true_thre=0.89;
const int jump=10;
const int input_width = 640;
const int input_height = 480;
const int output_width = 640;
const int output_height = 480;
const string project_path="/home/pi/LiveFaceReco_RaspberryPi";
//end

const cv::Size frame_size = Size(output_width,output_height);
const float ratio_x = (float)output_width/ input_width;
const float ratio_y = (float)output_height/ input_height;

void loadLiveModel(Live & live );
int MTCNNDetection();


