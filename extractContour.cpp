//
// Created by 23640 on 2024/12/16.
//

#include "extractContour.h"



// 轮廓提取函数
void extractContour(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height) {
    output.assign(width * height, 0);

    // 定义邻居方向（8 连通）
    const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    auto isValid = [&](int x, int y) {
        return x >= 0 && x < width && y >= 0 && y < height;
    };

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (input[y * width + x] == 255) { // 前景像素
                bool isBoundary = false;
                for (int i = 0; i < 8; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (isValid(nx, ny) && input[ny * width + nx] == 0) { // 存在背景像素
                        isBoundary = true;
                        break;
                    }
                }
                if (isBoundary) {
                    output[y * width + x] = 255; // 标记为轮廓点
                }
            }
        }
    }
}

void run_extractContour_lab(){
    std::string inputFile = R"(D:\Code\C++Project\digital_image\images\threshold_lena_histogram.bmp)";
    std::string outputFile = R"(D:\Code\C++Project\digital_image\images\contour.bmp)";

    BMPHeader header_lena;
    BMPInfoHeader infoHeader_lena;
    std::vector<uint8_t> inputImage,outputImage;
    int width,height;

    readGrayBMP(inputFile,inputImage,width,height,header_lena,infoHeader_lena);

    extractContour(inputImage,outputImage,width,height);

    saveGrayBMPWithPalette(outputFile,BMPHeader(header_lena),BMPInfoHeader(infoHeader_lena),
                           outputImage,width,height);

    std::cout << "轮廓提取完成，结果保存在 " << outputFile << std::endl;
}