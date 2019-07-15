//here is source cpp
//Defination!
#include "hough.h"  //"源代码所在目录搜索",<系统include目录里搜索,eg如/usr/include/里>
#include <iostream>
using namespace std;
using namespace cv;
#define PI 3.1415926

//define the default constructor
LineFinder::LineFinder()
{
    cout << "default constructor called" << endl;
    deltaRho = 1;
    deltaTheta = PI / 180;
    minVote = 80;
}
// destructor
LineFinder::~LineFinder()
{
    cout << "Bye![destructor]" << endl;
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
// Hough变换检测直线;rho=1,theta=PI/180参数坐标系里的步长,threshold=最小投票数
void LineFinder::findlines(Mat& binary)
{
    cout << "now use Hough to find lines" << endl;
    lines.clear();
    HoughLines(binary,lines,deltaRho,deltaTheta,minVote);
}
void LineFinder::drawDetectedLines(Mat& result)
{
    vector<Vec2f>::const_iterator it = lines.begin();
    while(it != lines.end())
    {
        // 以下两个参数用来检测直线属于垂直线还是水平线
        float rho = (*it)[0];
        float theta = (*it)[1];
        if (theta < PI / 4. || theta > 3.*PI / 4.)
        {   // 若检测为垂直线,直线交于图片的上下两边,先找交点
            cv::Point pt1(rho / cos(theta), 0);
            cv::Point pt2((rho - result.rows*sin(theta)) / cos(theta), result.rows);
            cv::line(result, pt1, pt2, cv::Scalar(255), 1); //
        }
        else // 若检测为水平线,直线交于图片的左右两边,先找交点
        {
            cv::Point pt1(0, rho / sin(theta));
            cv::Point pt2(result.cols, (rho - result.cols*cos(theta)) / sin(theta));
            cv::line(result, pt1, pt2, cv::Scalar(255), 1);
        }
        ++it;
    }
}










