//
// Created by 23640 on 2024/11/22.
//

#include "transform.h"

// 图像缩放
void scaleImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, float scaleX, float scaleY) {
    int newWidth = static_cast<int>(std::round( width*1.0 * scaleX));
    int newHeight = static_cast<int>(std::round( height*1.0 * scaleY));
    output.resize(newWidth * newHeight);

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int srcX = static_cast<int>(std::round( x*1.0 / scaleX));
            int srcY = static_cast<int>(std::round( y*1.0 / scaleY));
            srcX = std::clamp(srcX, 0, width - 1);
            srcY = std::clamp(srcY, 0, height - 1);
            output[y * newWidth + x] = input[srcY * width + srcX];
        }
    }
}

// 图像平移
void translateImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, int offsetX, int offsetY) {
    output.resize(width * height, 255); // 填充背景为白色

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int newX = x + offsetX;
            int newY = y + offsetY;
            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                output[newY * width + newX] = input[y * width + x];
            }
        }
    }
}

// 图像镜像（水平或垂直）
void mirrorImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, bool horizontal) {
    output.resize(width * height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (horizontal) {
                output[y * width + x] = input[y * width + (width - 1 - x)];
            } else {
                output[y * width + x] = input[(height - 1 - y) * width + x];
            }
        }
    }
}

// 图像旋转
void rotateImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, float angle) {
    int newWidth = width;
    int newHeight = height;
    output.resize(newWidth * newHeight, 255); // 背景白色填充

    float radians = angle * M_PI / 180.0;
    float cosAngle = cos(radians);
    float sinAngle = sin(radians);

    int centerX = width / 2;
    int centerY = height / 2;

    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            int srcX = static_cast<int>((x - centerX) * cosAngle + (y - centerY) * sinAngle + centerX);
            int srcY = static_cast<int>(-(x - centerX) * sinAngle + (y - centerY) * cosAngle + centerY);
            if (srcX >= 0 && srcX < width && srcY >= 0 && srcY < height) {
                output[y * newWidth + x] = input[srcY * width + srcX];
            }
        }
    }
}

void run_transform_lab(){
    std::string  lena = R"(D:\Code\C++Project\digital_image\images\lena.bmp)";

    BMPHeader header_lena;
    BMPInfoHeader infoHeader_lena;
    std::vector<uint8_t> grayData_lena;
    int width,height;

    readGrayBMP(lena,grayData_lena,width,height,header_lena,infoHeader_lena);

    // 图像缩放
    std::vector<uint8_t> scaledImage;
    float scaleX = 1.5,scaleY = 1.5;
    int newWidth = static_cast<int>(std::round( width*1.0 * scaleX));
    int newHeight = static_cast<int>(std::round( height*1.0 * scaleY));
    scaleImage(grayData_lena, scaledImage, width, height, scaleX, scaleY);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\scaled_lena.bmp)",BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),scaledImage,newWidth,newHeight);

    // 图像平移
    std::vector<uint8_t> translatedImage;
    translateImage(grayData_lena, translatedImage, width, height, 50, 50);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\translated_lena.bmp)",BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),translatedImage,width,height);

    // 图像镜像
    std::vector<uint8_t> mirroredImage;
    mirrorImage(grayData_lena, mirroredImage, width, height, true); // 水平镜像
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\mirrored_lena.bmp)",BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),mirroredImage,width,height);

    // 图像旋转
    std::vector<uint8_t> rotatedImage;
    rotateImage(grayData_lena, rotatedImage, width, height, 45); // 旋转 45 度
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\rotated_lena.bmp)",BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),rotatedImage,width,height);

    std::cout << "图像处理完成，结果已保存！" << std::endl;
}
