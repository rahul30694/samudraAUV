#include "globals.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "cv.h"

int highh = 59, lowh = 10, highs = 255	, lows = 146, highv = 255, lowv = 167,rho=50,theta=200,threshold=3; //Values for orange colour (temporary)
cv::VideoCapture cap;
cv::Mat cur_frame;
cv::Mat thresh;
bool opened = false;
