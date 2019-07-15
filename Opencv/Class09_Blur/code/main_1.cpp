#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    Mat src = imread("/home/supremedin/Documents/QT_project/Pic/gym1.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }
    //use char-array as Window's name
    char input_title[] = "input image";
    namedWindow(input_title,CV_WINDOW_AUTOSIZE);
    imshow(input_title,src);

    Mat dst;
    blur(src,dst,Size(21,21),Point(-1,-1)); //size(odd,odd)  odd is a MUST!!!!
    char output_title[] = "blur21*21";
    namedWindow(output_title,CV_WINDOW_AUTOSIZE);
    imshow(output_title,dst);
    Mat dst1;
    blur(src,dst1,Size(25,1),Point(-1,-1));  //look like a flash-move!!!
    namedWindow("row-blur25*1",CV_WINDOW_AUTOSIZE);
    imshow("row-blur25*1",dst1);

    GaussianBlur(src,dst,Size(21,21),11,11);
    namedWindow("Gaussian-blur21*21",CV_WINDOW_AUTOSIZE);
    imshow("Gaussian-blur21*21",dst);

    waitKey(0);
    return 0;
}

