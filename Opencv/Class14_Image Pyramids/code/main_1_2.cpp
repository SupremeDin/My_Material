#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <math.h>
using namespace cv;

// global parameter
Mat src,dst,tmp;
char* win_name = "dst-image pyramid";
void show_times(int);

int main()
{
    // introduction:
    printf("here is the instruction\n");
    printf("press [u] ---> zoom in\n");
    printf("press [d] ---> zoom out\n");
    printf("press [w] ---> save images\n");
    printf("press [Esc] ---> exit\n");

    src = imread("/home/supremedin/Documents/QT_project/Pic/Sierra.jpg");
    if(!src.data)
    {
        printf("No Data!...\n");
        return -1;
    }
    namedWindow(win_name,CV_WINDOW_AUTOSIZE);
    imshow(win_name,src);

    tmp = src;
    dst = src;

    while(1)
    {
        int input ;
        static int exp = 0; //pow(base,exp);
        input = waitKey(10);
        if((char)input == 27)
        {
            //printf("the dst-img is %lf times!",pow(2,exp));
            //printf("exp=%d  ",exp);
            show_times(exp);
            printf("exit the program!\n");
            break;
        }
        if((char)input == 'u')
        {
            printf("image*2 !\n");
            exp++;
            pyrUp(tmp,dst,Size(tmp.cols*2,tmp.rows*2));
        }
        if((char)input == 'd')
        {
            printf("image/2 !\n");
            exp--;
            pyrDown(tmp,dst,Size(tmp.cols/2,tmp.rows/2));
        }
        else if((char)input == 'w')
        {
            show_times(exp);
            printf("save the current image!\n");
            imwrite("/home/supremedin/Documents/QT_project/Pic/vortex_up_down.jpg",dst);
        }
        imshow(win_name,dst);
        tmp = dst;
    }
    //waitKey(0);
    return 0;
}
void show_times(int _exp)
{
    if(_exp>=0)
        printf("Now you get %d times as the source-image!  ",(int)pow(2,_exp));
    else
        printf("Now you get 1/%d times as the source-image!  ",(int)pow(2,abs(_exp)));
}
