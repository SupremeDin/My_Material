#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace cv;

int main(int argc, char *argv[])
{
   Mat src = imread("/home/supremedin/Documents/QT_project/Pic/gym4.jpg",IMREAD_UNCHANGED);
   if (src.empty())
   {
       printf("could not load image...\n ");
       return -1;
   }
   namedWindow("gym",CV_WINDOW_AUTOSIZE);
   imshow("gym",src);

   namedWindow("output window",CV_WINDOW_AUTOSIZE);
   Mat out_image;
   cvtColor(src,out_image,CV_BGR2HLS);
   imshow("output window",out_image);

   //imwrite("/home/supremedin/Documents/QT_project/vortex_hls.tiff",out_image);

   waitKey(0);
   return 0;
}
