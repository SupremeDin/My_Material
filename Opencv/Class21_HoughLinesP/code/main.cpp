#include <opencv2/opencv.hpp>
#include <iostream> //matched with "using namespace std"
#include <houghlines_p.h>

using namespace cv;
using namespace std;
//win_name
char win_name[] = "src";
char win_name1[] = "src_gray";
char win_name2[] = "contour";
char win_name3[] = "dst";

int main()
{
    Mat src,src_gray,contour,dst;
    src = imread("/home/supremedin/Documents/QT_project/Pic/shape.png");
    if( !src.data )  //.data is not a function!
    {
        cout << "NO DATA!" <<endl;
        return -1;
    }
    namedWindow(win_name);
    imshow(win_name,src);

    cvtColor(src,src_gray,CV_BGR2GRAY);
    namedWindow(win_name1);
    imshow(win_name1,src_gray);
    Canny(src_gray,contour,5,100,3);
    namedWindow(win_name2);
    imshow(win_name2,contour);
    src.copyTo(dst);

    //class
    LineFinder finder;
    finder.setminVote(80);
    finder.setLineLengthAndGap(100,10);
    finder.findLines(contour);
    finder.drawDetectedLines(dst);

    namedWindow(win_name3);
    imshow(win_name3,dst);

    waitKey(0);
    return 0;
}
