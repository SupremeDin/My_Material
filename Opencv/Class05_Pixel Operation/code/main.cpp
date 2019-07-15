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

    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);

    //***********1-channel-image:gray**********//
    /*
    Mat gray_src;
    cvtColor(src,gray_src,CV_BGR2GRAY);
    namedWindow("input-gray",CV_WINDOW_AUTOSIZE);
    imshow("input-gray",gray_src);
    //1-channel-image:change pixel by .at<uchar>(_,_)
    int rows = gray_src.rows;
    int cols = gray_src.cols;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int pixel_value = gray_src.at<uchar>(i,j);  //only in 1 channel
            gray_src.at<uchar>(i,j)=255-pixel_value;
        }
    }
    namedWindow("converse-gray",CV_WINDOW_AUTOSIZE);
    imshow("converse-gray",gray_src);
                                                     */

    //3-channels-image:change pixel by .at<Vec3b>(_,_)[]
    Mat dst;
    dst.create(src.size(),src.type());
    int height = src.rows;
    int width = src.cols;
    int nc = src.channels();

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(nc == 1)
            {
                int pixel_value = dst.at<uchar>(i,j);  //only in 1 channel
                dst.at<uchar>(i,j)=255-pixel_value;
            }
            else if(nc == 3)
            {
                int b = src.at<Vec3b>(i,j)[0];
                int g = src.at<Vec3b>(i,j)[1];
                int r = src.at<Vec3b>(i,j)[2];
                dst.at<Vec3b>(i,j)[0]=255-b;
                dst.at<Vec3b>(i,j)[1]=0;
                dst.at<Vec3b>(i,j)[2]=255-r;
            }
        }
     }
    namedWindow("dst-3channel-converse",CV_WINDOW_AUTOSIZE);
    imshow("dst-3channel-converse",dst);

    // bitwise_not(src,dst) :the same function as 3-channels-converse
    Mat dst1=src;
    bitwise_not(src,dst1);
    namedWindow("dst-bitwise_not",CV_WINDOW_AUTOSIZE);
    imshow("dst-bitwise_not",dst1);

    waitKey(0);
    return 0;
}
