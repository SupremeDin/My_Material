#include <opencv2/opencv.hpp>
#include <iostream>
#include "remap.h"

using namespace std;
using namespace cv;

char* win_name = "src";
char* win_name1 = "dst";
//int index = 0;
int main()
{
    Mat src,dst;
    src = imread("/home/supremedin/Documents/QT_project/Pic/eye.jpg");
    if( !src.data )
    {
        cout << "NO DATA! "<< endl;
        return -1;
    }
    namedWindow(win_name);
    imshow(win_name,src);

    Mat mapx,mapy;
    mapx.create(src.size(), CV_32FC1);
    mapy.create(src.size(), CV_32FC1);

    Remappppp my_remap;
    my_remap.update_map(src,mapx,mapy,0);
    my_remap.remap_show(src,dst,mapx,mapy);

    cv::namedWindow(win_name1);
    cv::imshow(win_name1,dst);

    waitKey(0);
    return 0;
}
