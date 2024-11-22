//
// Created by 23640 on 2024/11/4.
//

#include "bmp.h"

void convertToGray(const std::vector<uint8_t>& colorData, std::vector<uint8_t>& grayData, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        uint8_t blue = colorData[i];
        uint8_t green = colorData[i + 1];
        uint8_t red = colorData[i + 2];
        uint8_t gray = static_cast<uint8_t>(0.3 * red + 0.59 * green + 0.11 * blue);  // 灰度公式
        grayData.push_back(gray);
    }
}

void invertGray(std::vector<uint8_t>& grayData) {
    for (auto& pixel : grayData) {
        pixel = 255 - pixel;  // 反色处理
    }
}

void separateChannels(const std::vector<uint8_t>& colorData, std::vector<uint8_t>& redChannel, std::vector<uint8_t>& greenChannel, std::vector<uint8_t>& blueChannel, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        blueChannel.push_back(colorData[i]);
        greenChannel.push_back(colorData[i + 1]);
        redChannel.push_back(colorData[i + 2]);
    }
}

void saveGrayBMP(const std::string& filename, const BMPHeader& header, const BMPInfoHeader& infoHeader, const std::vector<uint8_t>& grayData, int width, int height) {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile) {
        outFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
        outFile.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));
        outFile.write(reinterpret_cast<const char*>(grayData.data()), grayData.size());
        outFile.close();
    }
}

// 保存带调色板的8位灰度图像
void saveGrayBMPWithPalette(const std::string& filename, BMPHeader header, BMPInfoHeader infoHeader, const std::vector<uint8_t>& grayData, int width, int height) {
    // 计算行对齐：每行需要填充至4字节边界
    int rowStride = (width + 3) & ~3;  // 对4字节对齐
    int paddingSize = rowStride - width;
    std::vector<uint8_t> paddedGrayData;

    // 每行添加填充字节
    for (int y = 0; y < height; ++y) {
        paddedGrayData.insert(paddedGrayData.end(), grayData.begin() + y * width, grayData.begin() + (y + 1) * width);
        paddedGrayData.insert(paddedGrayData.end(), paddingSize, 0);  // 添加填充字节
    }

    // 更新头部信息
    header.file_size = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + 256 * 4 + paddedGrayData.size();
    header.offset_data = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + 256 * 4;
    infoHeader.bit_count = 8;           // 修改为8位
    infoHeader.size_image = paddedGrayData.size();
    infoHeader.width = width;
    infoHeader.height = height;

    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "无法创建文件 " << filename << std::endl;
        return;
    }

    // 写入 BMP 文件头和信息头
    outFile.write(reinterpret_cast<const char*>(&header), sizeof(header));
    outFile.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));

    // 写入灰度调色板
    for (int i = 0; i < 256; ++i) {
        uint8_t color = static_cast<uint8_t>(i);
        outFile.write(reinterpret_cast<const char*>(&color), 1);  // 蓝色分量
        outFile.write(reinterpret_cast<const char*>(&color), 1);  // 绿色分量
        outFile.write(reinterpret_cast<const char*>(&color), 1);  // 红色分量
        outFile.put(0);  // 调色板的保留字节
    }

    // 写入图像数据
    outFile.write(reinterpret_cast<const char*>(paddedGrayData.data()), paddedGrayData.size());
    outFile.close();
}

//读取灰度BMP图像
bool readGrayBMP(const std::string& filename, std::vector<uint8_t>& grayData, int& width, int& height,BMPHeader& header,BMPInfoHeader& infoHeader){
    std::ifstream file(filename, std::ios::binary);

    // 检查文件是否存在
    if (!std::filesystem::exists(filename)) {
        std::cerr << "错误：找不到文件 " << filename << "。请检查路径是否正确。" << std::endl;
        return false;
    }
    if (!file) {
        std::cerr << "无法打开文件 " << filename << std::endl;
        return false;
    }

//    BMPHeader header;
//    BMPInfoHeader infoHeader;

    // 读取文件头和信息头
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    // 检查是否为8位灰度图像
    if (infoHeader.bit_count != 8) {
        std::cerr << "错误：不是8位灰度图像" << std::endl;
        return false;
    }

    // 获取图像宽度和高度
    width = infoHeader.width;
    height = infoHeader.height;

    // 跳过调色板（256*4字节）
    file.seekg(header.offset_data, std::ios::beg);

    // 读取图像数据
    int rowStride = (width + 3) & ~3; // 4字节对齐
    grayData.resize(height * rowStride);
    for (int y = 0; y < height; ++y) {
        file.read(reinterpret_cast<char*>(&grayData[y * rowStride]), rowStride);
    }

    // 去除每行末尾的填充字节
    if (rowStride != width) {
        std::vector<uint8_t> pureGrayData;
        pureGrayData.reserve(width * height);
        for (int y = 0; y < height; ++y) {
            pureGrayData.insert(pureGrayData.end(), grayData.begin() + y * rowStride, grayData.begin() + y * rowStride + width);
        }
        grayData = std::move(pureGrayData);
    }

    file.close();
    return true;
}

//读取灰度BMP图像
bool readGrayBMP(const std::string& filename, std::vector<uint8_t>& grayData, int& width, int& height){
    std::ifstream file(filename, std::ios::binary);

    // 检查文件是否存在
    if (!std::filesystem::exists(filename)) {
        std::cerr << "错误：找不到文件 " << filename << "。请检查路径是否正确。" << std::endl;
        return false;
    }
    if (!file) {
        std::cerr << "无法打开文件 " << filename << std::endl;
        return false;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;

    // 读取文件头和信息头
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    // 检查是否为8位灰度图像
    if (infoHeader.bit_count != 8) {
        std::cerr << "错误：不是8位灰度图像" << std::endl;
        return false;
    }

    // 获取图像宽度和高度
    width = infoHeader.width;
    height = infoHeader.height;

    // 跳过调色板（256*4字节）
    file.seekg(header.offset_data, std::ios::beg);

    // 读取图像数据
    int rowStride = (width + 3) & ~3; // 4字节对齐
    grayData.resize(height * rowStride);
    for (int y = 0; y < height; ++y) {
        file.read(reinterpret_cast<char*>(&grayData[y * rowStride]), rowStride);
    }

    // 去除每行末尾的填充字节
    if (rowStride != width) {
        std::vector<uint8_t> pureGrayData;
        pureGrayData.reserve(width * height);
        for (int y = 0; y < height; ++y) {
            pureGrayData.insert(pureGrayData.end(), grayData.begin() + y * rowStride, grayData.begin() + y * rowStride + width);
        }
        grayData = std::move(pureGrayData);
    }

    file.close();
    return true;
}

void run_bmp_lab() {

    std::string inputfile = R"(D:\Code\C++Project\digital_image\images\rgb.bmp)";

    // 检查文件是否存在
    if (!std::filesystem::exists(inputfile)) {
        std::cerr << "错误：找不到文件 " << inputfile << "。请检查路径是否正确。" << std::endl;
        return ;
    }

    std::ifstream file(inputfile, std::ios::binary);
    if (!file) {
        std::cerr << "无法打开输入图像文件！" << std::endl;
        return;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;

    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    int width = infoHeader.width;
    int height = infoHeader.height;
    std::vector<uint8_t> colorData(width * height * 3);  // 存储24位RGB图像数据
    std::vector<uint8_t> grayData;                        // 用于存储灰度图数据
    std::vector<uint8_t> redChannel, greenChannel, blueChannel;  // 存储分离的通道数据

    file.read(reinterpret_cast<char*>(colorData.data()), colorData.size());
    file.close();

    // 任务1：将彩色图像转换为灰度图
    convertToGray(colorData, grayData, width, height);
    //saveGrayBMP(R"(D:\Code\C++Project\digital_image\images\gray.bmp)", header, infoHeader, grayData, width, height);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\gray.bmp)", header, infoHeader, grayData, width, height);

    // 任务2：对灰度图进行反色
    invertGray(grayData);
    //saveGrayBMP(R"(D:\Code\C++Project\digital_image\images\inverted_gray.bmp)", header, infoHeader, grayData, width, height);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\inverted_gray.bmp)", header, infoHeader, grayData, width, height);

    // 任务3：分离R、G、B通道
    separateChannels(colorData, redChannel, greenChannel, blueChannel, width, height);
    //saveGrayBMP(R"(D:\Code\C++Project\digital_image\images\red_channel.bmp)", header, infoHeader, redChannel, width, height);
    //saveGrayBMP(R"(D:\Code\C++Project\digital_image\images\green_channel.bmp)", header, infoHeader, greenChannel, width, height);
    //saveGrayBMP(R"(D:\Code\C++Project\digital_image\images\blue_channel.bmp)", header, infoHeader, blueChannel, width, height);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\red_channel.bmp)", header, infoHeader, redChannel, width, height);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\green_channel.bmp)", header, infoHeader, greenChannel, width, height);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\blue_channel.bmp)", header, infoHeader, blueChannel, width, height);

    std::cout << "处理完成！生成的图像文件已保存到 ./images/ 目录下："
              << "gray.bmp, inverted_gray.bmp, red_channel.bmp, green_channel.bmp, blue_channel.bmp" << std::endl;

}
