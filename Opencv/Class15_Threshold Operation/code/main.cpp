#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src,dst;
char output_src[] = "src";
char output_dst[] = "dst-threshold";
void Threshold_Demo(int,void*);
int thresh = 100;
int threshold_type;
char* threshold_value = "threshold_value";
char* thresh_type = "threshold_type";

int main(int argc, char *argv[])
{
    src = imread("/home/supremedin/Documents/QT_project/Pic/Sierra_down.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow(output_src,CV_WINDOW_AUTOSIZE);
    imshow(output_src,src);
    namedWindow(output_dst,CV_WINDOW_AUTOSIZE);
    //imshow(output_dst,dst);

    createTrackbar(threshold_value,output_dst,&thresh,255,Threshold_Demo);
    createTrackbar(thresh_type,output_dst,&threshold_type,4,Threshold_Demo);
    Threshold_Demo(0,0);

    waitKey(0);
    return 0;
}
void Threshold_Demo(int, void *)
{
    threshold(src,dst,thresh,255,threshold_type);
    imshow(output_dst,dst);
}
