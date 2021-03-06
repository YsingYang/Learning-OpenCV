
#include<iostream>
#include<stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat src1;
    int msize;
    src1 = imread("/home/ysing/codeblock Projects/OpenCV/CV_filter/82.png",0);
    Mat src2 = Mat::zeros(src1.rows,src1.cols,CV_8U);
     cout<<src1.rows<<"  "<<src2.rows;
     cout<<"  "<<src1.cols<<"  "<<src2.cols<<endl;
    cout<<"Enter the mask Size";
    cin>>msize;//msize<rsize
    for(int i=0;i<src1.rows-msize;++i){
        for(int j=0;j<src1.cols-msize;++j){
            int intensity1 = 0;
            int  intensity2 =0;
            for(int p=0;p<msize;++p){
                for(int q=0;q<msize;++q){
                    if((p==msize/2)&&(q==msize/2))
                        intensity1 += (src1.at<uchar>(i+p,j+q)*(pow(msize,2)-1));//intensity 1用与存储滤波中心点 
                    else
                        intensity2 += src1.at<uchar>(i+p,j+q);//intensity_2用于暂存中心点领域内值的和,具体的参数有滤波器参数决定
                }
            }
            int diff = intensity1-intensity2;
           if(diff>255)
                diff=255;
            if(diff<0)
                diff=0;
            src2.at<uchar>(i+msize/2,j+msize/2) =(uchar)diff;
        }
    }

    imshow("original",src2);
    //imwrite("filter_hist.jpg",histgraph2);
    //imwrite("original_hist.jpg",histgraph1);
    imwrite("CV_filter/Lap3*3.jpg",src2);
    //imwrite("filter_image.jpg",src2);
    waitKey(0);
    return 1;
}

