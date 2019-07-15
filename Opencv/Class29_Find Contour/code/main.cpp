#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

Mat src_img, dst_img;
const string output_win = "找到的轮廓";
int threshold_value = 100;
int threshold_max = 255;
RNG rng;
void Demo_Contours(int, void*);
int main()
{
    src_img = imread("/home/supremedin/Documents/QT_project/Pic/shape.png");
    if (src_img.empty())
    {
        printf("could not load the  image...\n");
        return -1;
    }
    namedWindow("原图", CV_WINDOW_AUTOSIZE);
    namedWindow(output_win, CV_WINDOW_AUTOSIZE);
    imshow("原图", src_img);
    cvtColor(src_img, src_img, CV_BGR2GRAY);

    createTrackbar("Threshold Value:", output_win, &threshold_value, threshold_max, Demo_Contours);
    Demo_Contours(0, 0);

    waitKey(0);
    return 0;
}

void Demo_Contours(int, void*)
{
    Mat canny_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierachy;
    Canny(src_img, canny_output, threshold_value, threshold_value * 2, 3, false);
    findContours(canny_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    dst_img = Mat::zeros(src_img.size(), CV_8UC3);
    RNG rng(12345);
    for (auto i = 0; i < contours.size(); ++i)
    {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));   //随机颜色
        drawContours(dst_img, contours, i, color, 2, 8, hierachy, 0, Point(0, 0));
    }
    imshow(output_win, dst_img);
}
