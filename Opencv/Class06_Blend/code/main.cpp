#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    Mat src1,src2,dst;
    src1= imread("/home/supremedin/Documents/QT_project/Pic/gym1.jpg");
    src2= imread("/home/supremedin/Documents/QT_project/Pic/gymlogo.jpg");
    if(src1.empty())
    {
        cout<<"can not load this pic1..."<<endl;
        return -1;
    }
    if(src2.empty())
    {
        cout<<"can not load this pic1..."<<endl;
        return -1;
    }

    namedWindow("input1",CV_WINDOW_AUTOSIZE);
    imshow("input1",src1);

    namedWindow("input2",CV_WINDOW_AUTOSIZE);
    imshow("input2",src2);

    /*EXTRA*/ //make src2 have the src1's background!
    for(int i=0;i<src2.rows;i++)
    {
        for(int j=0;j<src2.cols;j++)
        {
            if(src2.at<Vec3b>(i,j)[0]<128)
            {
                src2.at<Vec3b>(i,j)[0]=0;
                src2.at<Vec3b>(i,j)[1]=0;
                src2.at<Vec3b>(i,j)[2]=0;
            }
            else
            {
                src2.at<Vec3b>(i,j)[0]=src1.at<Vec3b>(i,j)[0];
                src2.at<Vec3b>(i,j)[1]=src1.at<Vec3b>(i,j)[1];
                src2.at<Vec3b>(i,j)[2]=src1.at<Vec3b>(i,j)[2];

            }
        }

    }
    namedWindow("src2-background",CV_WINDOW_AUTOSIZE);
    imshow("src2-background",src2);

    /*EXTRA*/ //NOW we change src1's pixel!
    for(int i=0;i<src2.rows;i++)
    {
        for(int j=0;j<src2.cols;j++)
        {
            if(src2.at<Vec3b>(i,j)[0]<30)
            {
                src1.at<Vec3b>(i,j)[0]=0;
                src1.at<Vec3b>(i,j)[1]=0;
                src1.at<Vec3b>(i,j)[2]=0;
            }
        }

    }
    namedWindow("src1-change-pixel",CV_WINDOW_AUTOSIZE);
    imshow("src1-change-pixel",src1);




    /*

    //set the ROI!(cause this 2 images do not match in size!)
    int height2 = src2.rows;
    int width2 = src2.cols;
    printf("height2= %d\n width2= %d\n",height2,width2);
    Mat ROI_src1=src1(Range(0,0+src2.rows),Range(0,0+src2.cols));
    //namedWindow("ROI_src1",CV_WINDOW_AUTOSIZE);
    //imshow("ROI_src1",ROI_src1); //THIS ROI_IMAGE is not independent!!! it is still on src1
    addWeighted(ROI_src1,0.5,src2,0.2,0,ROI_src1);
    namedWindow("addWeighted-image",CV_WINDOW_AUTOSIZE);
    imshow("addWeighted-image",src1);   */





    waitKey(0);
    return 0;
}

