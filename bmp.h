//
// Created by 23640 on 2024/11/4.
//

#ifndef DIGITAL_IMAGE_BMP_H
#define DIGITAL_IMAGE_BMP_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <filesystem>

#pragma pack(push, 1)  // 保证结构体按1字节对齐
struct BMPHeader {
    uint16_t file_type{0x4D42};     // 文件类型，必须是"BM"
    uint32_t file_size{};             // 文件大小
    uint16_t reserved1{0};          // 保留字段
    uint16_t reserved2{0};          // 保留字段
    uint32_t offset_data{};           // 图像数据的偏移量
};

struct BMPInfoHeader {
    uint32_t size{};                  // 头信息的大小
    int32_t width{};                  // 图像的宽度
    int32_t height{};                 // 图像的高度
    uint16_t planes{1};             // 必须为1
    uint16_t bit_count{};             // 每个像素的位数
    uint32_t compression{0};        // 图像压缩类型
    uint32_t size_image{0};         // 图像大小
    int32_t x_pixels_per_meter{0};  // 水平分辨率
    int32_t y_pixels_per_meter{0};  // 垂直分辨率
    uint32_t colors_used{256};        // 实际使用的颜色数
    uint32_t colors_important{256};   // 重要的颜色数
};
#pragma pack(pop)

void invertGray(std::vector<uint8_t>& grayData);
void separateChannels(const std::vector<uint8_t>& colorData, std::vector<uint8_t>& redChannel,
                      std::vector<uint8_t>& greenChannel, std::vector<uint8_t>& blueChannel, int width, int height);
void convertToGray(const std::vector<uint8_t>& colorData, std::vector<uint8_t>& grayData, int width, int height);
void saveGrayBMP(const std::string& filename, const BMPHeader& header, const BMPInfoHeader& infoHeader,
                 const std::vector<uint8_t>& grayData, int width, int height);
void saveGrayBMPWithPalette(const std::string& filename, BMPHeader header, BMPInfoHeader infoHeader,
                            const std::vector<uint8_t>& grayData, int width, int height);
bool readGrayBMP(const std::string& filename, std::vector<uint8_t>& grayData, int& width, int& height,
                 BMPHeader& header,BMPInfoHeader& infoHeader);
void run_bmp_lab();

#endif //DIGITAL_IMAGE_BMP_H
