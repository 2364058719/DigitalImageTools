//
// Created by 23640 on 2024/11/15.
//

#ifndef DIGITAL_IMAGE_FILTER_H
#define DIGITAL_IMAGE_FILTER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdint>
#include <cstring>
#include "bmp.h"

void meanFilter(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height,
                int kernelSize);
void medianFilter(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height,
                  int kernelSize);
void run_filter_lab();

#endif //DIGITAL_IMAGE_FILTER_H
