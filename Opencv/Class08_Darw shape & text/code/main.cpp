#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat src; //golabol for all the sub-function!!!
//Function Declaration
void MyLine();
void MyEllipse();
void MyRectangle();
void MyCircle();
void MyfillPoly();
int main(int argc, char *argv[])
{
     src = imread("/home/supremedin/Documents/QT_project/Pic/gym1.jpg");
    if(src.empty())
    {
        cout<<"can not load this pic..."<<endl;
        return -1;
    }
    //cout << "image's width = " << src.cols << endl;
    //cout << "image's height = " << src.rows << endl;

    MyLine();
    MyEllipse();
    MyRectangle();
    MyCircle();
    MyfillPoly();
    putText(src,"GYM",Point(265,335),CV_FONT_HERSHEY_COMPLEX,2.0,Scalar(0,255,255),5,LINE_8);
    namedWindow("input-image",CV_WINDOW_AUTOSIZE);
    imshow("input-image",src);

    waitKey(0);
    return 0;
}

//Function Defination
void MyLine()
{
   Point pt1 = Point(100,100);
   Point pt2;
   pt2.x = 600;
   pt2.y = 600;
   Scalar colar = Scalar(0,0,255);
   line(src,pt1,pt2,colar,5,LINE_AA,0);
}
void MyEllipse()
{
    Point centre = Point(src.cols/2,src.rows/2);
    Size axes = Size(src.cols/4,src.rows/8);
    Scalar color = Scalar(255,0,0);
    ellipse(src,centre,axes,0,0,280,color,3,LINE_AA,0);
}
void MyRectangle()
{
    Rect rect = Rect(200,200,270,270);
    rectangle(src,rect,Scalar(0,255,0),5,LINE_4,0);
}
void MyCircle()
{
    circle(src,Point(335,335),200,Scalar(1,35,2),9,LINE_MAX,0);
}
void MyfillPoly()
{
    Point pts[1][5];
    pts[0][0] = Point(100,100);
    pts[0][1] = Point(100,200);
    pts[0][2] = Point(200,200);
    pts[0][3] = Point(200,100);
    pts[0][4] = Point(100,100);

    const Point* ppts[] = { pts[0] };
    int npt[] = {5};
    Scalar color = Scalar(255,69,78);
    fillPoly(src,ppts,npt,1,color,8);
}





