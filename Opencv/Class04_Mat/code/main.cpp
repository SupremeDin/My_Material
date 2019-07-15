#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main(int argc, char *argv[])
{
   Mat src = imread("/home/supremedin/Documents/QT_project/Pic/Leopard.jpg");
   if (src.empty())
   {
       cout<<"could not load this image..."<<endl;
       return -1;
   }

   namedWindow("input",CV_WINDOW_KEEPRATIO);
   imshow("input",src);

  /* Mat dst;
   dst = Mat(src.size(),src.type());
   dst = Scalar(0,0,255);
   namedWindow("dst-show",CV_WINDOW_NORMAL);
   imshow("dst-show",dst); */

   //Mat dst = src.clone(); //completely copy!!!
   //namedWindow("dst-show",CV_WINDOW_NORMAL);
   //imshow("dst-show",dst);

   Mat dst;
   cvtColor(src,dst,CV_BGR2GRAY);
   namedWindow("dst-show",CV_WINDOW_NORMAL);
   imshow("dst-show",dst);
   printf(" the channels of src pic is %d\n",src.channels());
   printf(" the channels of dst pic is %d\n",dst.channels());

   int cols = dst.cols;
   int rows = dst.rows;
   printf("columns:%d\nrows:%d\n",cols,rows);
   /*for(int i=0;i<cols;i++)
   {
       for(int j=0;j<rows;j++)
       {
           dst.ptr<uchar>(i)[j]=0;
       }
   }
   namedWindow("dst-convert",CV_WINDOW_NORMAL);
   imshow("dst-convert",dst); */
   const uchar* firstRow = dst.ptr<uchar>(0);
   printf("the first pixel value is %d\n",*firstRow);

   Mat M(5,5,CV_8UC3,Scalar(0,0,255));//Mat----Matrix
   cout<<"M="<<endl<<M<<endl;
   namedWindow("M-show",CV_WINDOW_NORMAL);
   imshow("M-show",M);

   waitKey(0);
   return 0;
}
