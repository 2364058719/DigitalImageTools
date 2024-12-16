//
// Created by 23640 on 2024/12/16.
//

#ifndef DIGITAL_IMAGE_EXTRACTCONTOUR_H
#define DIGITAL_IMAGE_EXTRACTCONTOUR_H

#include <iostream>
#include <vector>
#include <fstream>
#include "bmp.h"

void extractContour(const std::vector<uint8_t>& input, std::vector<uint8_t>& output, int width, int height);
void run_extractContour_lab();


#endif //DIGITAL_IMAGE_EXTRACTCONTOUR_H
