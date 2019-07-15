#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

char output_src[] = "src";
char output_dst[] = "dst";
char * dst_win = "DOG_image+THRESH_BINARY_INV";


int main(int argc, char *argv[])
{
    Mat src;
    src = imread("/home/supremedin/Documents/QT_project/Pic/Sierra_down.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow(output_src,CV_WINDOW_AUTOSIZE);
    imshow(output_src,src);
    //namedWindow(output_dst,CV_WINDOW_AUTOSIZE);
    //imshow(output_dst,dst);
    Mat src_gray,g1,g2,DOG_Img;
    cvtColor(src,src_gray,CV_BGR2GRAY);
    GaussianBlur(src_gray,g1,Size(5,5),0,0);
    GaussianBlur(g1,g2,Size(5,5),0,0);
    subtract(g1,g2,DOG_Img,Mat());
    normalize(DOG_Img,DOG_Img,255,0,NORM_MINMAX);
    adaptiveThreshold(DOG_Img,DOG_Img,255,THRESH_BINARY_INV,THRESH_BINARY,15,2);

    namedWindow(dst_win,CV_WINDOW_AUTOSIZE);
    imshow(dst_win,DOG_Img);

    waitKey(0);
    return 0;
}
