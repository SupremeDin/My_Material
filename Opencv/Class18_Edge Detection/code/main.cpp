#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
Mat src,src_gray,edge;
int threshold_max = 60;
void Trackbar_Demo(int,void*);
char output_name[] = "Canny";
char trackbar[] = "threshold 2";

int main(int argc, char *argv[])
{
    src = imread("/home/supremedin/Documents/QT_project/Pic/shape.png");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);

    namedWindow(output_name,CV_WINDOW_AUTOSIZE);//its a must,otherwise the trackbar will not appear!
    createTrackbar(trackbar,output_name,&threshold_max,255,Trackbar_Demo);
    //imshow(output_name,edge);
    Trackbar_Demo(0,0);

    waitKey(0);
    return 0;
}
void Trackbar_Demo(int, void *)
{
    cvtColor(src,src_gray,CV_BGR2GRAY);
    blur(src_gray,edge,Size(3,3));
    Canny(edge,edge,0,threshold_max,3);
    imshow(output_name,edge);
    return;
}
