#include <opencv2/opencv.hpp>
#include <iostream>
#include "find_circles.h"

using namespace std;
using namespace cv;

char* win_name = "src";
char* win_name1 = "src_gray";
char* win_name2 = "contour";
char* win_name3 = "dst";

int main()
{
    Mat src,src_gray,contour,dst;
    src = imread("/home/supremedin/Documents/QT_project/Pic/shape.png");
    if( !src.data )
    {
        cout << "NO DATA!" << endl;
        return -1;
    }
    namedWindow(win_name);
    imshow(win_name,src);

    cvtColor(src,src_gray,CV_BGR2GRAY);
    namedWindow(win_name1);
    imshow(win_name1,src_gray);

    Canny(src_gray,contour,100,300,3);
    namedWindow(win_name2);
    imshow(win_name2,contour);

    src.copyTo(dst);

    FindCircles finder;
    finder.findCircles_Hough(contour);
    finder.drawDetectedCircles(dst);
    namedWindow(win_name3);
    imshow(win_name3,dst);

    waitKey(0);
    return 0;
}
