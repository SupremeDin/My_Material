#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src,dst,dst1;
char output_dilate[] = "dst-dilate";
char outout_erode[] = "dst-erode";
void CallBack_Demo(int,void*); //function prototype!
int element_size = 3;
int max_size = 21;

int main(int argc, char *argv[])
{
    src = imread("/home/supremedin/Documents/QT_project/Pic/Danny.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);

    namedWindow(output_dilate,CV_WINDOW_AUTOSIZE);
    namedWindow("Trackbar",CV_WINDOW_NORMAL);
    createTrackbar("Element size","Trackbar",&element_size,max_size,CallBack_Demo);
    CallBack_Demo(0,0);


    waitKey(0);
    return 0;
}
void CallBack_Demo(int,void*)
{
    int size = element_size*2+1;
    Mat structureElement = getStructuringElement(MORPH_RECT,Size(size,size),Point(-1,-1));
    dilate(src,dst,structureElement,Point(-1,-1));
    erode(src,dst1,structureElement,Point(-1,-1));

    imshow(output_dilate,dst);
    imshow(outout_erode,dst1);

    return;
}
