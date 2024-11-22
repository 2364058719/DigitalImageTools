//
// Created by 23640 on 2024/11/22.
//

#ifndef DIGITAL_IMAGE_TRANSFORM_H
#define DIGITAL_IMAGE_TRANSFORM_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "bmp.h"

void scaleImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, float scaleX,
                float scaleY);
void translateImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, int offsetX,
                    int offsetY);
void mirrorImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, bool horizontal);
void rotateImage(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height, float angle);
void run_transform_lab();


#endif //DIGITAL_IMAGE_TRANSFORM_H
