#ifndef REMAP_H
#define REMAP_H

#include <opencv2/opencv.hpp>
#include <iostream>
// NO "using ....."

class Remappppp
{
public:
    Remappppp(); //default constructor
    ~Remappppp(); // destructor
    //other method
    void update_map(cv::Mat &_src, cv::Mat &_mapx, cv::Mat &_mapy, int index);
    void remap_show(cv::Mat& _src,cv::Mat& dst_img,cv::Mat& _mapx, cv::Mat& _mapy);
    //void CallBack_Demo(int,void*);
};
#endif // REMAP_H
