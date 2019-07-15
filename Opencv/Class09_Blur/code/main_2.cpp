#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
//try to use Trackbar!!!
Mat src,dst,dst1;
void CallBack_filter(int,void*);
int element_size = 1;
int max_size = 21;
char trackbar[] = "Element size";
char output_title[] = "dst-median";
char output_title1[] = "dst-bilateral";

int main(int argc, char *argv[])
{
    src = imread("/home/supremedin/Documents/QT_project/Pic/gym2.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);

    namedWindow(output_title,CV_WINDOW_AUTOSIZE);
    namedWindow(output_title1,CV_WINDOW_AUTOSIZE);

    createTrackbar(trackbar,output_title,&element_size,max_size,CallBack_filter);
    CallBack_filter(0,0);

    waitKey(0);
    return 0;
}
void CallBack_filter(int, void *)
{
    int s = 2*element_size + 1;//to ensure [s] is a odd!!!
    medianBlur(src,dst,s);
    bilateralFilter(src,dst1,2*s,4*s,s);

    imshow(output_title,dst);
    imshow(output_title1,dst1);

    return;
}
//This is the slowest program by far~~~! it means the median and bilateral cost time too much!
