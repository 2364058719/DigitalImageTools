//
// Created by 23640 on 2024/12/2.
//

#include "edgeDetection.h"

//卷积操作
void applyKernel(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, const std::vector<int>& kernel, int kernelSize) {
    int halfSize = kernelSize / 2;
    output.assign(input.size(), 0);

    for (int y = halfSize; y < height - halfSize; ++y) {
        for (int x = halfSize; x < width - halfSize; ++x) {
            int sum = 0;
            for (int ky = -halfSize; ky <= halfSize; ++ky) {
                for (int kx = -halfSize; kx <= halfSize; ++kx) {
                    int pixel = input[(y + ky) * width + (x + kx)];
                    int weight = kernel[(ky + halfSize) * kernelSize + (kx + halfSize)];
                    sum += pixel * weight;
                }
            }
            output[y * width + x] = std::clamp(std::abs(sum), 0, 255);
        }
    }
}
//void applyKernel(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, const std::vector<int>& kernel, int kernelSize) {
//    int halfSize = kernelSize / 2;
//    output.assign(input.size(), 0);
//
//    for (int y = 0; y < height; ++y) {
//        for (int x = 0; x < width; ++x) {
//            int sum = 0;
//            for (int ky = -halfSize; ky <= halfSize; ++ky) {
//                for (int kx = -halfSize; kx <= halfSize; ++kx) {
//                    int ny = y + ky;
//                    int nx = x + kx;
//                    if (ny >= 0 && ny < height && nx >= 0 && nx < width) { // 确保索引在范围内
//                        int pixel = input[ny * width + nx];
//                        int weight = kernel[(ky + halfSize) * kernelSize + (kx + halfSize)];
//                        sum += pixel * weight;
//                    }
//                }
//            }
//            output[y * width + x] = std::clamp(std::abs(sum), 0, 255);
//        }
//    }
//}


// Prewitt 算子
void prewittEdgeDetection(const std::vector<uint8_t>& image, std::vector<uint8_t>& output, int width, int height) {
    std::vector<int> prewittX = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    std::vector<int> prewittY = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

    std::vector<uint8_t> gradX(image.size()), gradY(image.size());
    applyKernel(image, gradX, width, height, prewittX, 3);
    applyKernel(image, gradY, width, height, prewittY, 3);

    for (size_t i = 0; i < image.size(); ++i) {
        output[i] = std::clamp(static_cast<int>(std::sqrt(gradX[i] * gradX[i] + gradY[i] * gradY[i])), 0, 255);
    }
}

// Sobel 算子
void sobelEdgeDetection(const std::vector<uint8_t>& image, std::vector<uint8_t>& output, int width, int height) {
    std::vector<int> sobelX = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    std::vector<int> sobelY = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    std::vector<uint8_t> gradX(image.size()), gradY(image.size());
    applyKernel(image, gradX, width, height, sobelX, 3);
    applyKernel(image, gradY, width, height, sobelY, 3);

    for (size_t i = 0; i < image.size(); ++i) {
        output[i] = std::clamp(static_cast<int>(std::sqrt(gradX[i] * gradX[i] + gradY[i] * gradY[i])), 0, 255);
    }
}

// LOG 算子（拉普拉斯高斯）
void logEdgeDetection(const std::vector<uint8_t>& image, std::vector<uint8_t>& output, int width, int height) {
    std::vector<int> logKernel = {
            0,1,0,
            1,-4,1,
            0,1,0
    };

    applyKernel(image, output, width, height, logKernel, 3);

}

void run_edgeDetection_lab(){
    std::string lena = R"(D:\Code\C++Project\digital_image\images\lena.bmp)";
    std::string outputFilePrewitt = R"(D:\Code\C++Project\digital_image\images\lena_prewitt.bmp)";
    std::string outputFileSobel = R"(D:\Code\C++Project\digital_image\images\lena_sobel.bmp)";
    std::string outputFileLog = R"(D:\Code\C++Project\digital_image\images\lena_log.bmp)";

    BMPHeader header_lena;
    BMPInfoHeader infoHeader_lena;
    std::vector<uint8_t> grayData_lena;
    int width,height;

    readGrayBMP(lena,grayData_lena,width,height,header_lena,infoHeader_lena);

    std::vector<uint8_t> output_Prewitt(grayData_lena.size());
    std::vector<uint8_t> output_Sobel(grayData_lena.size());
    std::vector<uint8_t> output_LOG(grayData_lena.size());

    // Prewitt 算子
    prewittEdgeDetection(grayData_lena, output_Prewitt, width, height);
    saveGrayBMPWithPalette(outputFilePrewitt,BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),output_Prewitt,width,height);

    // Sobel 算子
    sobelEdgeDetection(grayData_lena, output_Sobel, width, height);
    saveGrayBMPWithPalette(outputFileSobel,BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),output_Sobel,width,height);

    // LOG 算子
    logEdgeDetection(grayData_lena, output_LOG, width, height);
    saveGrayBMPWithPalette(outputFileLog,BMPHeader(header_lena),
                           BMPInfoHeader(infoHeader_lena),output_LOG,width,height);

    std::cout << "边缘检测完成，结果已保存。" << std::endl;

}