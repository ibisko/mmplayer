cmake_minimum_required (VERSION 3.30)
add_library(
    mmThread
    # "MMThread.h"
    "MMThread.cpp"
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
