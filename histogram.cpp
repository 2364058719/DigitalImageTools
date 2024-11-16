//
// Created by 23640 on 2024/11/8.
//

#include "histogram.h"

// 直方图统计
void computeHistogram(const std::vector<uint8_t>& grayData, std::vector<int>& histogram) {
    // 初始化直方图数组
    histogram.assign(256, 0);

    // 统计每个灰度级别的像素数量
    for (uint8_t pixel : grayData) {
        histogram[pixel]++;
    }
}

// 直方图均衡化
void histogramEqualization(std::vector<uint8_t>& grayData, int width, int height) {
    // 计算图像的灰度直方图
    std::vector<int> histogram(256, 0);
    computeHistogram(grayData, histogram);

    // 图像总像素数
    int totalPixels = width * height;

    // 累积分布函数 (CDF) 的归一化计算，使用浮点数来提高精度
    std::vector<float> cdf(256, 0.0f);
    cdf[0] = static_cast<float>(histogram[0]) / (totalPixels*1.0f);

    for (int i = 1; i < 256; ++i) {
        cdf[i] = cdf[i - 1] + static_cast<float>(histogram[i]) / totalPixels;
    }

    // 使用累积分布函数 (CDF) 构建均衡化后的查找表 (LUT)
    std::vector<uint8_t> equalizedLUT(256);
    for (int i = 0; i < 256; ++i) {
        equalizedLUT[i] = static_cast<uint8_t>(std::round(cdf[i] * 255));
    }

    // 应用均衡化后的灰度值映射到图像数据
    for (auto& pixel : grayData) {
        pixel = equalizedLUT[pixel];
    }
}

// 调试函数：显示直方图
bool printHistogram(const std::vector<int>& histogram,const std::string& filename) {
//    for (int i = 0; i < 256; ++i) {
//        std::cout << "灰度级 " << i << ": " << histogram[i] << " 个像素" << std::endl;
//    }
    int width = 256;
    int height = 100;
    // 创建空白图像
    std::vector<uint8_t> histogramImage(width*height,255);
    // 找到直方图的最大值
    int maxHistValue = *std::max_element(histogram.begin(), histogram.end());

    // 绘制直方图
    for (int i = 0; i < 256; ++i) {
        int barHeight = static_cast<int>((static_cast<double>(histogram[i]) / maxHistValue) * height);
        for (int y = height-barHeight; y < height; ++y) {
            histogramImage[(height - 1 - y) * width + i] = 0; // 黑色
        }
    }

    // 设置BMP文件头和信息头
    BMPHeader fileHeader;
    BMPInfoHeader infoHeader;

    fileHeader.file_size = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + 1024 + (width * height) + (width * height) % 4;
    fileHeader.offset_data = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + 1024;

    infoHeader.size = sizeof(BMPInfoHeader);
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.bit_count = 8;
    infoHeader.size_image = width * height;

    // 创建调色板
    uint8_t palette[1024]; // 256 colors, 4 bytes per color
    for (int i = 0; i < 256; ++i) {
        palette[i * 4] = i;     // B
        palette[i * 4 + 1] = i; // G
        palette[i * 4 + 2] = i; // R
        palette[i * 4 + 3] = 0; // Reserved
    }

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "无法打开 BMP 文件进行写入: " << filename << std::endl;
        return false;
    }

    // 写入文件头和信息头
    file.write(reinterpret_cast<const char *>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char *>(&infoHeader), sizeof(infoHeader));
    file.write(reinterpret_cast<const char *>(palette), sizeof(palette)); // 写入调色板

    // 写入灰度图像数据
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file.put(histogramImage[y * width + x]);
        }
        // 添加填充字节
        for (int p = 0; p < (4 - (width % 4)) % 4; ++p) {
            file.put(0);
        }
    }

    file.close();
//    saveGrayBMPWithPalette(filename,fileHeader,infoHeader,histogramImage,width,height);
    return true;
}

// 示例调用
void runHistogramProcessing(int width,int height,std::vector<uint8_t>& grayData) {
    // 假设 grayData 是已加载的灰度图像数据，width 和 height 分别是图像的宽和高
//    std::vector<uint8_t> grayData = { /* 灰度图像数据 */ };
    //int width = /* 图像宽度 */;
    //int height = /* 图像高度 */;

    // 任务 1: 直方图统计
    std::vector<int> histogram(256);
    computeHistogram(grayData, histogram);
    std::string inputfile1 = R"(D:\Code\C++Project\digital_image\images\histogram1.bmp)";
    printHistogram(histogram,inputfile1);

    // 任务 2: 直方图均衡化
    histogramEqualization(grayData, width, height);
    computeHistogram(grayData,histogram);
    std::string inputfile2 = R"(D:\Code\C++Project\digital_image\images\histogram2.bmp)";
    printHistogram(histogram,inputfile2);

    // 均衡化后的图像数据保存在 grayData 中
}

void run_histogram_lab(){
    std::string inputfile = R"(D:\Code\C++Project\digital_image\images\dim.bmp)";

//    // 检查文件是否存在
//    if (!std::filesystem::exists(inputfile)) {
//        std::cerr << "错误：找不到文件 " << inputfile << "。请检查路径是否正确。" << std::endl;
//        return ;
//    }
//
//    std::ifstream file(inputfile, std::ios::binary);
//    if (!file) {
//        std::cerr << "无法打开输入图像文件！" << std::endl;
//        return;
//    }
//
//    BMPHeader header;
//    BMPInfoHeader infoHeader;
//
//    file.read(reinterpret_cast<char*>(&header), sizeof(header));
//    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
//
//    int width = infoHeader.width;
//    int height = infoHeader.height;
////    std::vector<uint8_t> colorData(width * height * 3);  // 存储24位RGB图像数据
//    std::vector<uint8_t> grayData(width*height);                        // 用于存储灰度图数据
//
////    file.read(reinterpret_cast<char*>(colorData.data()), colorData.size());
//    file.read(reinterpret_cast<char*>(grayData.data()), grayData.size());
//    file.close();

    BMPHeader header;
    BMPInfoHeader infoHeader;
    std::vector<uint8_t> grayData;
    int width,height;
    readGrayBMP(inputfile,grayData,width,height,header,infoHeader);

    //24位RGB转灰度图
//    convertToGray(colorData, grayData, width, height);

    runHistogramProcessing(width,height,grayData);

    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\dim2.bmp)",header, infoHeader, grayData, width, height);
    //saveGrayBMP(R"(D:\Code\C++Project\digital_image\images\dim2.bmp)",header, infoHeader, grayData, width, height);
}