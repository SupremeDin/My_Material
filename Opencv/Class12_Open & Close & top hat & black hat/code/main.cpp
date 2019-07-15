#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void CallBack_morphology(int,void*);
Mat src,dst,dst1,dst2,dst3,dst4;
int s=3;
char output_title[] = "dst-open";
char output_title1[] = "dst-close";
char output_title2[] = "dst-gradient";
char output_title3[] = "dst-top hat";
char output_title4[] = "dst-black hat";

char trackbar[] = "Trackbar";

int main(int argc, char *argv[])
{
    src = imread("/home/supremedin/Documents/QT_project/Pic/apple.jpeg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_NORMAL);
    imshow("input-image",src);
    //**************START****************//
    namedWindow(output_title,CV_WINDOW_NORMAL);
    namedWindow(output_title1,CV_WINDOW_NORMAL);
    namedWindow(output_title2,CV_WINDOW_NORMAL);
    namedWindow(output_title3,CV_WINDOW_NORMAL);
    namedWindow(output_title4,CV_WINDOW_NORMAL);
    //namedWindow(trackbar,CV_WINDOW_AUTOSIZE);

    createTrackbar("Element size",output_title,&s,50,CallBack_morphology);
    CallBack_morphology(0,0);

    waitKey(0);
    return 0;
}
void CallBack_morphology(int,void*)
{
    int element = 2*s+1; //to ensure that [element] is a odd!!!
    Mat kernel = getStructuringElement(MORPH_RECT,Size(element,element),Point(-1,-1));
    morphologyEx(src,dst,CV_MOP_OPEN,kernel,Point(-1,-1));
    morphologyEx(src,dst1,CV_MOP_CLOSE,kernel,Point(-1,-1));
    morphologyEx(src,dst2,CV_MOP_GRADIENT,kernel,Point(-1,-1));
    morphologyEx(src,dst3,CV_MOP_TOPHAT,kernel,Point(-1,-1));
    morphologyEx(src,dst4,CV_MOP_BLACKHAT,kernel,Point(-1,-1));


    imshow(output_title,dst);
    imshow(output_title1,dst1);
    imshow(output_title2,dst2);
    imshow(output_title3,dst3);
    imshow(output_title4,dst4);
    return;
}
