 #include "opencv2/opencv.hpp"
 #include <iostream>
 using namespace std;
 using namespace cv;

 int main()
 {
    Mat temp=imread("/home/supremedin/Documents/QT_project/Pic/2_template.png");
    Mat src=imread("/home/supremedin/Documents/QT_project/Pic/2.png");
    Mat src_down;
    resize(src,src_down,Size(round(src.cols/2),round(src.rows/2)),0,0,INTER_LINEAR);
    imwrite("/home/supremedin/Documents/QT_project/Pic/2_down.png",src_down);
     Mat dst=src_down.clone();
     imshow("temp",temp);

     int width=src_down.cols-temp.cols+1;//result宽度
     int height=src_down.rows-temp.rows+1;//result高度

     Mat result(height,width,CV_32FC1);//创建结果映射图像
     //matchTemplate(srcImg, templateImg, resultImg, CV_TM_SQDIFF); //平方差匹配法(最好匹配0)
     //matchTemplate(srcImg, templateImg, resultImg, CV_TM_SQDIFF_NORMED); //归一化平方差匹配法(最好匹配0)
     //matchTemplate(srcImg, templateImg, resultImg, CV_TM_CCORR); //相关匹配法(最坏匹配0)
     //matchTemplate(srcImg, templateImg, resultImg, CV_TM_CCORR_NORMED); //归一化相关匹配法(最坏匹配0)
     //matchTemplate(srcImg, templateImg, resultImg, CV_TM_CCOEFF); //系数匹配法(最好匹配1)
     matchTemplate(src_down,temp,result,CV_TM_CCOEFF_NORMED);//化相关系数匹配,最佳值1
     imshow("result",result);
     normalize(result,result,0,1,NORM_MINMAX,-1);//归一化到0-1范围

     double minValue,maxValue;
     Point minLoc,maxLoc;
     minMaxLoc(result,&minValue,&maxValue,&minLoc,&maxLoc);
     cout<<"minValue="<<minValue<<endl;
     cout<<"maxValue="<<maxValue<<endl;

     rectangle(dst,maxLoc,Point(maxLoc.x+temp.cols,maxLoc.y+temp.rows),Scalar(0,255,0),2,8);
     imshow("dst",dst);

     waitKey(0);
     return 0;
 }
