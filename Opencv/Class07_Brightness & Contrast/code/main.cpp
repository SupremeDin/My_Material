#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat src,dst;
    src = imread("/home/supremedin/Documents/QT_project/Pic/gym1.jpg");
    if(src.empty())
    {
        cout<<"could not load image..."<<endl;
        return -1;
    }
    namedWindow("src-show",CV_WINDOW_AUTOSIZE);
    imshow("src-show",src);

    double alpha = 2.1; // contrast parameter
    int beta = 25; // brightness parameter
    cout << "******input contrast parameter in [1.0,3.0]*********"<<endl;
    cin >> alpha;
    cout << "******input brightness parameter in [0,100]**********"<<endl;
    cin >> beta;

    dst = Mat::zeros(src.size(),src.type());
    for(int i = 0;i < src.rows ; i++)
    {
        for(int j = 0;j < src.cols ; j++)
        {
            for(int k = 0;k < 3; k++)
                dst.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(alpha*src.at<Vec3b>(i,j)[k] + beta);

        }
    }
    namedWindow("dst-show",CV_WINDOW_AUTOSIZE);;
    imshow("dst-show",dst);

    //use .convertTo() to change brightness & contrast
    Mat dst1;
    src.convertTo(dst1,src.type(),2.0,20);
    namedWindow("dst1-show",CV_WINDOW_AUTOSIZE);
    imshow("dst1-show",dst1);

    waitKey(0);
    return 0;
}
