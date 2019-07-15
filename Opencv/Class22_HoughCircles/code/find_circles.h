#ifndef FIND_CIRCLES_H
#define FIND_CIRCLES_H

#include <opencv2/opencv.hpp>
#include <iostream>

class FindCircles
{
private:
    std::vector<cv::Vec3f> circles;
    double dp;
    double minDist;
    double param1;
    double param2;
    int minRadius;
    int maxRadius;
public:
    FindCircles(); //default constructor;
    ~FindCircles();//destructor
    //other methods
    void setAccResolution(double _dp,double _minDist,double _param1,double _param2,int _minRadius,int _maxRadius);
    void findCircles_Hough(cv::Mat& binary);
    void drawDetectedCircles(cv::Mat& _dst);

};
#endif // FIND_CIRCLES_H
