#pragma once

// #include <iostream>
#include <thread>

class MMThread
{
public:
    virtual void run() = 0;
    //  virtual 表示没有实现

    // 用于启动线程
    int Start();
};