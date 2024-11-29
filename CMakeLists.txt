cmake_minimum_required(VERSION 3.28)
project(digital_image)

set(CMAKE_CXX_STANDARD 17)

add_executable(digital_image main.cpp
        bmp.cpp
        bmp.h
        histogram.cpp
        histogram.h
        filter.cpp
        filter.h
        transform.cpp
        transform.h
        threshold.cpp
        threshold.h)
