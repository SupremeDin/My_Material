//declaration!
#ifndef HOUGHLINES_P_H
#define HOUGHLINES_P_H
#include <opencv2/opencv.hpp>
#include <vector>
//using namespace std;
//using namespace cv;//try not to use "using namespace xx" in Header file!
class LineFinder
{
private:
    std::vector<cv::Vec4i> lines;
    double deltaRho;
    double deltaTheta;
    int minVote;
    double miniLength;
    double maxGap;
public:
    LineFinder(); //default constructor
    ~LineFinder(); //destructor
    //other methods' declaration
    void setAccResolution(double dRho,double dTheta);//variable assignment
    void setminVote(int minV);//variable assignment
    void setLineLengthAndGap(double length,double gap);//variable assignment
    void findLines(cv::Mat& binary);// HoughLineP()检测线段
    void drawDetectedLines(cv::Mat& dst);//用point()函数画直线
};
#endif // HOUGHLINES_P_H
