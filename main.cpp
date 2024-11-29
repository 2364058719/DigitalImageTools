#include <iostream>
#include "bmp.h"
#include "histogram.h"
#include "filter.h"
#include "transform.h"
#include "threshold.h"

int main() {
    system("chcp 65001");
    std::cout<<"********************************"<<std::endl;
    std::cout<<"**********图像处理系统************"<<std::endl;
    std::cout<<"********1 BMP文件处理************"<<std::endl;
    std::cout<<"********2 直方图处理**************"<<std::endl;
    std::cout<<"********3 空间域滤波**************"<<std::endl;
    std::cout<<"********4 图像变换****************"<<std::endl;
    std::cout<<"********5 阈值分割****************"<<std::endl;
    std::cout<<"********6 基于区域分割*************"<<std::endl;
    std::cout<<"********7 边缘检测****************"<<std::endl;
    std::cout<<"********8 Hough变换**************"<<std::endl;
    std::cout<<"********9 区域标记****************"<<std::endl;
    std::cout<<"********10 轮廓提取***************"<<std::endl;
    std::cout<<"********************************"<<std::endl;
    std::cout<<"***请输入数字1-10运行对应功能，输入0退出******"<<std::endl;

    int ops;
    std::cin>>ops;
    if(ops==0){
        return 0;
    }
    else if (ops==1){
        run_bmp_lab();
    }
    else if (ops==2){
        run_histogram_lab();
    }
    else if (ops==3){
        run_filter_lab();
    }
    else if (ops==4){
        run_transform_lab();
    }
    else if (ops==5){
        run_threshold_lab();
    }
    else if (ops==6){

    }
    else if (ops==7){

    }
    else if (ops==8){

    }
    else if (ops==9){

    }
    else if (ops==10){

    }
    return 0;
}
