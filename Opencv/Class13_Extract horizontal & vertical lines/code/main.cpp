#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

char output_src[] = "src";
char output_dst1[] = "dst-h";
char output_dst2[] = "dst-v";
char output_grayimg[] = "gray-img";
char output_binimg[] = "bin-img";

int main(int argc, char *argv[])
{
    Mat src,gray_img,bin_img,dst1,dst2;
    //①输入彩色图像
    src = imread("/home/supremedin/Documents/QT_project/Pic/gym3.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);
    //②转换为灰度图像--cvtcolor
    cvtColor(src,gray_img,CV_BGR2GRAY);
    namedWindow(output_grayimg,CV_WINDOW_AUTOSIZE);
    imshow(output_grayimg,gray_img);
    //③转换为二值图像--adaptiveThreshold（Threshold）
    adaptiveThreshold(gray_img,bin_img,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,2);
    namedWindow(output_binimg,CV_WINDOW_AUTOSIZE);
    imshow(output_binimg,bin_img);
    //④定义结构元素  *(重点)
    Mat h_kernel = getStructuringElement(MORPH_RECT,Size(src.cols/16,1));
    Mat v_kernel = getStructuringElement(MORPH_RECT,Size(1,src.rows/16));
    //⑤开操作（腐蚀+膨胀）提取，水平和垂直线
    morphologyEx(bin_img,dst1,CV_MOP_OPEN,h_kernel,Point(-1,-1));
    namedWindow(output_dst1,CV_WINDOW_AUTOSIZE);
    imshow(output_dst1,dst1);
    morphologyEx(bin_img,dst2,CV_MOP_OPEN,v_kernel,Point(-1,-1));
    namedWindow(output_dst2,CV_WINDOW_AUTOSIZE);
    imshow(output_dst2,dst2);

    waitKey(0);
    return 0;
}
