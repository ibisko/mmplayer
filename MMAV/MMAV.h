#pragma once

// #include <iostream>
#include <thread>

// 为了引用C编写的ffmpeg，需要先告诉编译器使用c的方式来编译
/* extern "C"
{
// #include <libavformat/avformat.h>
#include <libavformat/avformat.h>
} */

class MMAVPacketPrivate;

class MMAVPacket
{
public:
    MMAVPacket();
    ~MMAVPacket();
    MMAVPacketPrivate *imp = nullptr;
};

class MMAVReaderPrivate;

class MMAVReader
{
private:
    MMAVReaderPrivate *imp = nullptr;

public:
    // 构造方法，用于初始化类，可以重载
    MMAVReader();

    // 析构方法，当对象生命周期结束的时候，会被调用，一般用来做释放资源
    // 没有参数，只能有一个
    ~MMAVReader();

    int Open(const char *path);
    int Close();

    int Read(MMAVPacket *packet);
};