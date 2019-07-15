#include "remap.h"
#include <iostream>

Remappppp::Remappppp()
{
    std::cout << "default contructor called!" << std::endl;
}
Remappppp::~Remappppp()
{
    std::cout << "destructor called" << std::endl;
}
void Remappppp::update_map(cv::Mat& _src, cv::Mat& _mapx, cv::Mat& _mapy, int index)
{
    std::cout << "now update the map!" << std::endl;
    std::cout << "we know that:" << std::endl;
    std::cout << "src img.rows()="<< _src.rows<<"    ";
    std::cout << "src img.cols()=" << _src.cols << std::endl;
    for(int row = 0;row < _src.rows;row++)
    {
        for(int col = 0;col < _src.cols;col++)
        {
            switch(index)
            {
            //index = 0 ，图像的行跟列为为原来的1/2。
            //index = 1，为左右翻转（列变换，行不变）
            //index = 2，为上下翻转（行变换，列不变）
            //index = 3，为中心旋转
            case 0:
                if((col>_src.cols*0.25)&&(col<_src.cols*0.75)&&(row>_src.rows*0.25)&&(row<_src.rows*0.75))
                {
                    _mapx.at<float>(row,col) = 2*(col - _src.cols*0.25);
                    _mapy.at<float>(row,col) = 2*(row - _src.rows*0.25);
                }
                else
                {
                    _mapx.at<float>(row,col) = 0;
                    _mapy.at<float>(row,col) = 0;
                }
                break ;
            case 1:
                _mapx.at<float>(row,col) = _src.cols - col;
                _mapy.at<float>(row,col) = row;
                break;
            case 2:
                _mapx.at<float>(row,col) = col;
                _mapy.at<float>(row,col) = _src.rows - row;
                break;
            case 3:
                _mapx.at<float>(row,col) = _src.cols - col;
                _mapy.at<float>(row,col) = _src.rows - row;
                break;
            default:
                break;
            }
        }
    }
}
void Remappppp::remap_show(cv::Mat& _src,cv::Mat& dst_img,cv::Mat& _mapx, cv::Mat& _mapy)
{
    cv::remap(_src,dst_img,_mapx,_mapy,CV_INTER_LINEAR);

}

