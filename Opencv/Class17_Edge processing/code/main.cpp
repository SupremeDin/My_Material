#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
char* win_name = "make-border";

int main(int argc, char *argv[])
{
    Mat src = imread("/home/supremedin/Documents/QT_project/Pic/gym1.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);

    int top = (int)(0.05*src.rows);//
    int bottom = (int)(0.05*src.rows);
    int left = (int)(0.05*src.cols);
    int right = (int)(0.05*src.cols);
    RNG rng(12345);
    int BorderType = BORDER_DEFAULT;

    int c = 0;
    while(true)
    {
        c = waitKey(1000);
        if((char)c == 27)
        {
            printf("exit!\n");
            break;
        }
        else if((char)c == 'r')
        {
            printf("BORDER_REPLICATE\n");
            BorderType = BORDER_REPLICATE;
        }
         else if((char)c == 'w')
        {
            printf("BORDER_WRAP\n");
            BorderType = BORDER_WRAP;
        }
        else if((char)c == 'c')
        {
            printf("BORDER_CONSTANT\n");
            BorderType = BORDER_CONSTANT;
        }
        Mat dst;
        Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        copyMakeBorder(src,dst,top,bottom,left,right,BorderType,color);
        imshow(win_name,dst);
    }
    //then you can use filter to ....
    //just
    //GaussianBlur() is a common filter to ....
    return 0;
}
