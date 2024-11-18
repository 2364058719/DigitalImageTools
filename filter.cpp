//
// Created by 23640 on 2024/11/15.
//

#include "filter.h"

// 平均滤波（模板卷积）
void meanFilter(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, int kernelSize) {
    int pad = kernelSize / 2;
    output = input;

    for (int y = pad; y < height - pad; ++y) {
        for (int x = pad; x < width - pad; ++x) {
            int sum = 0;
            for (int ky = -pad; ky <= pad; ++ky) {
                for (int kx = -pad; kx <= pad; ++kx) {
                    int pixelValue = input[(y + ky) * width + (x + kx)];
                    sum += pixelValue;
                }
            }
            output[y * width + x] = static_cast<uint8_t>(sum / (kernelSize * kernelSize));
        }
    }
}

// 中值滤波
void medianFilter(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, int kernelSize) {
    int pad = kernelSize / 2;
    output = input;

    for (int y = pad; y < height - pad; ++y) {
        for (int x = pad; x < width - pad; ++x) {
            std::vector<uint8_t> neighborhood;
            for (int ky = -pad; ky <= pad; ++ky) {
                for (int kx = -pad; kx <= pad; ++kx) {
                    neighborhood.push_back(input[(y + ky) * width + (x + kx)]);
                }
            }
            std::sort(neighborhood.begin(), neighborhood.end());
            output[y * width + x] = neighborhood[neighborhood.size() / 2];
        }
    }
}

// 读取 BMP 图像
bool readBMP(const std::string& filename, std::vector<uint8_t>& data, int& width, int& height, uint16_t& bitCount,BMPHeader& header,BMPInfoHeader& infoHeader) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "无法打开文件 " << filename << std::endl;
        return false;
    }

//    BMPHeader header;
//    BMPInfoHeader infoHeader;

    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    width = infoHeader.width;
    height = infoHeader.height;
    bitCount = infoHeader.bit_count;

    file.seekg(header.offset_data, std::ios::beg);
    size_t dataSize = width * height * (bitCount / 8);
    data.resize(dataSize);
    file.read(reinterpret_cast<char*>(data.data()), data.size());

    file.close();
    return true;
}

// 转换彩色图像为灰度图
void convertToGray(const std::vector<uint8_t>& colorData, std::vector<uint8_t>& grayData, int width, int height, uint16_t bitCount) {
    grayData.clear();
    if (bitCount == 24) { // 彩色图像
        for (int i = 0; i < width * height * 3; i += 3) {
            uint8_t blue = colorData[i];
            uint8_t green = colorData[i + 1];
            uint8_t red = colorData[i + 2];
            uint8_t gray = static_cast<uint8_t>(0.3 * red + 0.59 * green + 0.11 * blue); // 灰度公式
            grayData.push_back(gray);
        }
    } else if (bitCount == 8) { // 已经是灰度图
        grayData = colorData;
    } else {
        std::cerr << "不支持的图像格式！" << std::endl;
    }
}

void run_filter_lab(){
    std::string lena = R"(D:\Code\C++Project\digital_image\images\lena.bmp)";
    std::string noise2 = R"(D:\Code\C++Project\digital_image\images\noise2.bmp)";

    BMPHeader header_lena,header_noise2;
    BMPInfoHeader infoHeader_lena,infoHeader_noise2;
    std::vector<uint8_t> grayData_lena,grayData_noise2,colorData_noise2;
    int width,height;
    uint16_t bitCount;

    // 创建存储滤波结果的数组
    std::vector<uint8_t> meanFiltered, medianFiltered;
    int kernelSize = 3;

    readGrayBMP(lena,grayData_lena,width,height,header_lena,infoHeader_lena);
    // 应用平均滤波
    meanFilter(grayData_lena, meanFiltered, width, height, kernelSize);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\mean_filtered.bmp)",header_lena,infoHeader_lena,meanFiltered,width,height);

//    readGrayBMP(noise2,grayData_noise2,width,height,header_noise2,infoHeader_noise2);
    readBMP(noise2,colorData_noise2,width,height,bitCount,header_noise2,infoHeader_noise2);
    convertToGray(colorData_noise2,grayData_noise2,width,height,bitCount);

    // 应用中值滤波
    medianFilter(grayData_noise2, medianFiltered, width, height, kernelSize);
    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\median_filtered.bmp)",header_noise2,infoHeader_noise2,medianFiltered,width,height);


    std::cout << "空间域滤波处理完成，结果已保存为 mean_filtered.bmp 和 median_filtered.bmp。" << std::endl;

}