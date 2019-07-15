#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace cv;
int main(int argc, char *argv[])
{
   Mat src,dst;
   src = imread("/home/supremedin/Documents/QT_project/Pic/Lazar.jpg",IMREAD_COLOR);
   if (!src.data){
       printf("could not load image...\n");
       return -1;
   }
   namedWindow("Lazar",CV_WINDOW_AUTOSIZE);
   imshow("Lazar",src);

   //use ptr to traverse all pixel
   int columns = (src.cols-1)*src.channels();
   int rows = src.rows;
   int offsets = src.channels();
   //printf("chanels:%d\n",offsets); //channels:3
   dst =Mat::zeros(src.size(),src.type()); //initialize the size & type of dst ;zeros;eyes;ones-----just like matlab' format

   //start MASK by ptr
   for (int row = 1;row < (rows - 1);row++)
   {
       const uchar* previous = src.ptr<uchar>(row-1);
       const uchar* current = src.ptr<uchar>(row);
       const uchar* next = src.ptr<uchar>(row+1);

       uchar* output = dst.ptr<uchar>(row);

       for(int col = offsets;col<columns;col++)
       {
           output[col]= saturate_cast<uchar>(5*current[col] - (current[col-offsets]+current[col+offsets]+previous[col]+next[col]));
       }

   }

//   /* MASK by filter2D */
//   Mat kernel = (Mat_<char>(3,3) << 0,-1,0,-1,5,-1,0,-1,0);//char !!! not uchar cause there is -1 in matrix
//   filter2D(src,dst,src.depth(),kernel);




   namedWindow("contrast image",CV_WINDOW_AUTOSIZE);
   imshow("contrast image",dst);//window's name always in a ""

   waitKey(0);//to hold the window in case we miss it!
    return 0;
}
