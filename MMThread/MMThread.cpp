#include "MMThread.h"

int MMThread::Start()
{
    std::thread t(&MMThread::run, this);
    // t.join();
    t.detach();
    return 0;
}