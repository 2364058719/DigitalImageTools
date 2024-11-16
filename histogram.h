//
// Created by 23640 on 2024/11/8.
//

#ifndef DIGITAL_IMAGE_HISTOGRAM_H
#define DIGITAL_IMAGE_HISTOGRAM_H

#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <filesystem>
#include <cmath>
#include "bmp.h"

void computeHistogram(const std::vector<uint8_t>& grayData, std::vector<int>& histogram);
void histogramEqualization(std::vector<uint8_t>& grayData, int width, int height);
bool printHistogram(const std::vector<int>& histogram,const std::string& filename);
void runHistogramProcessing(int width,int height,std::vector<uint8_t>& grayData);
void run_histogram_lab();

#endif //DIGITAL_IMAGE_HISTOGRAM_H
