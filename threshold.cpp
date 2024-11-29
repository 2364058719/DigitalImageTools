//
// Created by 23640 on 2024/11/29.
//

#include "threshold.h"

// 计算直方图
std::vector<int> calculateHistogram(const std::vector<uint8_t>& image){
    std::vector<int> histogram(256, 0);
    for (auto pixel : image) {
        histogram[pixel]++;
    }
    return histogram;
}

std::vector<int> calculateHistogram(const std::vector<uint8_t>& image, int threshold) {
    std::vector<int> histogram(256, 0);
    for (auto pixel : image) {
        histogram[pixel]++;
    }
    histogram[threshold]=0;
    return histogram;
}

// 给定阈值法
void applyThreshold(const std::vector<uint8_t>& image, std::vector<uint8_t>& binary, int threshold) {
    binary.resize(image.size());
    for (size_t i = 0; i < image.size(); ++i) {
        binary[i] = (image[i] > threshold) ? 255 : 0;
    }
}

std::vector<int> applyThresholdwithHistogram(const std::vector<uint8_t>& image, std::vector<uint8_t>& binary, int threshold){
    std::vector<int> histogram(256, 0);
    binary.resize(image.size());
    for (size_t i = 0; i < image.size(); ++i) {
        binary[i] = (image[i] > threshold) ? 255 : 0;
        histogram[image[i]] += (image[i] > threshold) ? 1 : 0;
    }
    return histogram;
}

// 迭代阈值法
int iterativeThresholding(const std::vector<uint8_t>& image) {
    int t0 = 127, t1 = 127;
    do {
        t0 = t1;
        int sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
        for (auto pixel : image) {
            if (pixel > t0) {
                sum1 += pixel;
                count1++;
            } else {
                sum2 += pixel;
                count2++;
            }
        }
        t1 = ((count1 ? (sum1 / count1) : 0) + (count2 ? (sum2 / count2) : 0)) / 2;
    } while (std::abs(t1 - t0) > 1);
    return t1;
}

// Otsu 方法
int otsuThreshold(const std::vector<uint8_t>& image) {
    auto histogram = calculateHistogram(image);
    int total = image.size();
    float sum = 0.0, sumB = 0.0;
    int weightB = 0, weightF = 0;
    float varMax = 0.0;
    int threshold = 0;

    for (int i = 0; i < 256; ++i) {
        sum += i * histogram[i];
    }

    for (int t = 0; t < 256; ++t) {
        weightB += histogram[t];
        if (weightB == 0) continue;

        weightF = total - weightB;
        if (weightF == 0) break;

        sumB += t * histogram[t];
        float meanB = sumB / weightB;
        float meanF = (sum - sumB) / weightF;

        float varBetween = weightB * weightF * (meanB - meanF) * (meanB - meanF);
        if (varBetween > varMax) {
            varMax = varBetween;
            threshold = t;
        }
    }

    return threshold;
}

void run_threshold_lab(){
    std::string  lena = R"(D:\Code\C++Project\digital_image\images\lena.bmp)";

    BMPHeader header_lena;
    BMPInfoHeader infoHeader_lena;
    std::vector<uint8_t> grayData_lena;
    int width,height;

    readGrayBMP(lena,grayData_lena,width,height,header_lena,infoHeader_lena);

    // 应用三种方法
    int fixedThreshold = 128; // 给定阈值
    int iterThreshold = iterativeThresholding(grayData_lena);
    int otsuThresholdValue = otsuThreshold(grayData_lena);

    std::cout << "Fixed Threshold: " << fixedThreshold << std::endl;
    std::cout << "Iterative Threshold: " << iterThreshold << std::endl;
    std::cout << "Otsu Threshold: " << otsuThresholdValue << std::endl;

    int ThresholdValue = otsuThresholdValue;

    std::vector<uint8_t> binaryImage;
    applyThreshold(grayData_lena, binaryImage, ThresholdValue);
//    auto histogram = applyThresholdwithHistogram(grayData_lena, binaryImage, ThresholdValue);

    auto histogram = calculateHistogram(grayData_lena,ThresholdValue);
    printHistogram(histogram,R"(D:\Code\C++Project\digital_image\images\threshold_lena_histogram.bmp)");

    saveGrayBMPWithPalette(R"(D:\Code\C++Project\digital_image\images\threshold_lena.bmp)",BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),binaryImage,width,height);

    std::cout << "二值化图像已保存为: threshold_lena.bmp" << std::endl;

}