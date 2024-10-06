cmake_minimum_required (VERSION 3.30)

# 添加搜索目录
include_directories(../)
link_directories(../3rdpart/ffmpeg/lib)

# 将源代码添加到此项目的可执行文件
add_executable(
    mmplayer
    "MMPlayer.h"
    "MMPlayer.cpp"
)


# 链接
target_link_libraries(mmplayer mmThread)
target_link_libraries(mmplayer mmav)
target_link_libraries(mmplayer avcodec)
target_link_libraries(mmplayer avdevice)
target_link_libraries(mmplayer avfilter)
target_link_libraries(mmplayer avformat)
target_link_libraries(mmplayer avutil)
target_link_libraries(mmplayer swresample)
target_link_libraries(mmplayer swscale)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
