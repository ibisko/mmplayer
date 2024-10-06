cmake_minimum_required (VERSION 3.30)

include_directories(../3rdpart/ffmpeg/include)

add_library(
    mmav
    "MMAVReader.cpp"
    "MMAVPacket.cpp"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
