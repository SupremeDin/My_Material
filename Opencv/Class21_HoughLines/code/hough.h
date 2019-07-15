//Declaration!
//DO NOT USE  "using namespace XX"
#ifndef HOUGH_H
#define HOUGH_H
#include<opencv2/opencv.hpp>
#include <vector>
class LineFinder
{
private:
    std::vector<cv::Vec2f> lines;
    double deltaRho;
    double deltaTheta;
    int minVote;
public:
    LineFinder();//first,there is a default constructor
                    //there is NO constructor;
    ~LineFinder();//destructor!(isnt a MUST,cause the compiler will do it if u didnt do it)
    //other methods~
    void setAccResolution(double dRho,double dTheta);//CAN olny use methods to change private;
    void setminVote(int minV);//to change private varible
    void findlines(cv::Mat& binary);
    void drawDetectedLines(cv::Mat& result);
};
#endif // HOUGH_H
