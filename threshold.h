//
// Created by 23640 on 2024/11/29.
//

#ifndef DIGITAL_IMAGE_THRESHOLD_H
#define DIGITAL_IMAGE_THRESHOLD_H


#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include "bmp.h"
#include "histogram.h"

void run_threshold_lab();
void applyThreshold(const std::vector<uint8_t>& image, std::vector<uint8_t>& binary, int threshold);
int iterativeThresholding(const std::vector<uint8_t>& image);
int otsuThreshold(const std::vector<uint8_t>& image);
std::vector<int> calculateHistogram(const std::vector<uint8_t>& image, int threshold);
std::vector<int> calculateHistogram(const std::vector<uint8_t>& image);
std::vector<int> applyThresholdwithHistogram(const std::vector<uint8_t>& image, std::vector<uint8_t>& binary,
                                             int threshold);


#endif //DIGITAL_IMAGE_THRESHOLD_H
