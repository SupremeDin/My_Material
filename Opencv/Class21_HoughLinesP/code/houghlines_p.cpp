//defination!
#include "houghlines_p.h"
#include <iostream>
#define PI 3.1415926

//default constructor
LineFinder::LineFinder()
{
    std::cout << "default constructor called!..." << std::endl;
    deltaRho = 1;
    deltaTheta = PI / 180;
    minVote = 10;
    miniLength = 0.0;
    maxGap = 0.0;
}
LineFinder::~LineFinder()
{
    std::cout << "destructor called!" << std::endl;
}
//other methods
void LineFinder::setAccResolution(double dRho, double dTheta)
{
    deltaRho = dRho;
    deltaTheta = dTheta;
}
void LineFinder::setminVote(int minV)
{
    minVote = minV;
}
void LineFinder::setLineLengthAndGap(double length, double gap)
{
    miniLength = length;
    maxGap = gap;
}
void LineFinder::findLines(cv::Mat &binary)
{
    lines.clear();
    cv::HoughLinesP(binary,lines,deltaRho,deltaTheta,minVote,miniLength,maxGap);
}
void LineFinder::drawDetectedLines(cv::Mat &dst)
{
    std::vector<cv::Vec4i>::const_iterator it = lines.begin();
    while(it != lines.end())
    {
        cv::Point pt1((*it)[0],(*it)[1]);
        cv::Point pt2((*it)[2],(*it)[3]);
        cv::line(dst,pt1,pt2,cv::Scalar(255),2);//画线段
        ++it;
    }
}







