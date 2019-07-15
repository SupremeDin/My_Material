#include <opencv2/opencv.hpp>
#include <iostream>
#include "hough.h"

using namespace std;//cause i will use 'cout,cin'....
using namespace cv;
using std::vector;


int main(int argc, char *argv[])
{
    Mat src = imread("/home/supremedin/Documents/QT_project/Pic/shape.png");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);
    //start
    Mat src_gray,contour;
    cvtColor(src,src_gray,CV_BGR2GRAY);
    Canny(src_gray,contour,5,100,3);
    namedWindow("contour");
    imshow("contour",contour);
    // 在原图的拷贝上画直线
    Mat result(contour.rows,contour.cols,CV_8U,Scalar(255));
    src.copyTo(result);
    // Hough变换检测
    LineFinder finder;
    finder.setminVote(130);
    finder.findlines(contour);
    finder.drawDetectedLines(result);

    namedWindow("find-line");
    imshow("find-line",result);

    waitKey(0);
    return 0;
}
