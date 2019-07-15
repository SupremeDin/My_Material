//defination
#include "find_circles.h"
#include <iostream>

using namespace cv;
using namespace std;

FindCircles::FindCircles()
{
    cout << "default constructor called" << endl;
    dp = 1;
    minDist = 100;
    param1 = 150;
    param2 = 30;
    minRadius = 0;
    maxRadius = 200;
}
FindCircles::~FindCircles()
{
    cout << "destructor called" << endl;
}

//other methods' defination
void FindCircles::setAccResolution(double _dp, double _minDist, double _param1, double _param2, int _minRadius, int _maxRadius)
{
    dp = _dp;
    minDist = _minDist;
    param1 = _param1;
    param2 = _param2;
    minRadius = _minRadius;
    maxRadius = _maxRadius;
}
void FindCircles::findCircles_Hough(cv::Mat& binary)
{
    circles.clear();
    HoughCircles(binary,circles,CV_HOUGH_GRADIENT,dp,minDist,param1,param2,minRadius,maxRadius);
}
void FindCircles::drawDetectedCircles(Mat &_dst)
{
    cout << "now we draw the circles" << endl;
    cout << "circles.size() = " << circles.size() << endl;
    for(size_t i = 0;i < circles.size(); i++)
    {
        Point centre(round(circles[i][0]),round(circles[i][1]));
        int radius = round(circles[i][2]);
        cout << "circles[0][0] = " << circles[i][0] <<endl;
        circle(_dst,centre,0,Scalar(0,0,255),10,4,0);
        circle(_dst,centre,radius,Scalar(0,0,255),10,4,0);
    }
}
