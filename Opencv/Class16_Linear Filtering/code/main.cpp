#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
Mat src,dst;
char win_name[] = "Robert-x";
char win_name1[] = "Robert-y";
char win_name2[] = "Laplace";
char win_name3[] = "Sobel-x";
char win_name4[] = "Sobel-y";
int main(int argc, char *argv[])
{
    src = imread("/home/supremedin/Documents/QT_project/Pic/shape.png");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }
    namedWindow("src-image",CV_WINDOW_AUTOSIZE);
    imshow("src-image",src);

    namedWindow(win_name,CV_WINDOW_AUTOSIZE);
    namedWindow(win_name1,CV_WINDOW_AUTOSIZE);
    namedWindow(win_name2,CV_WINDOW_AUTOSIZE);
    namedWindow(win_name3,CV_WINDOW_AUTOSIZE);

    //filtering
    //Robert-x
    Mat kernel_rx = (Mat_<int>(2,2)<<1,0,0,-1);
    filter2D(src,dst,-1,kernel_rx,Point(-1,-1),0.0);
    imshow(win_name,dst);
    //Robert-y
    Mat kernel_ry = (Mat_<int>(2,2)<<0,-1,1,0);
    filter2D(src,dst,-1,kernel_ry,Point(-1,-1),0.0);
    imshow(win_name1,dst);
    //Sobel-x
    Mat kernel_sx = (Mat_<int>(3,3)<<-1,0,1,-2,0,2,-1,0,1);
    filter2D(src,dst,-1,kernel_sx,Point(-1,-1),0.0);
    imshow(win_name3,dst);
    //Sober-y
    Mat kernel_sy = (Mat_<int>(3,3)<<-1,-2,-1,0,0,0,1,2,1);
    filter2D(src,dst,-1,kernel_sy,Point(-1,-1),0.0);
    imshow(win_name4,dst);
    //Laplace
    Mat kernel_l = (Mat_<int>(3,3)<<0,-1,0,-1,4,-1,0,-1,0);
    filter2D(src,dst,-1,kernel_l,Point(-1,-1),0.0);
    imshow(win_name2,dst);


    waitKey(0);
    return 0;
}
