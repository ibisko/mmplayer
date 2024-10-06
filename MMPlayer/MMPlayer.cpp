#include "MMPlayer.h"
#include "MMThread/MMThread.h"

// #include "thread"

// void thread_function(int x)
// {
//     printf("Thread Function: %d\n", x);
//     std::this_thread::sleep_for(std::chrono::seconds(3));
// }

// class MyMMThread : public MMThread
// {
// private:
//     int a = 1;

// public:
//     MyMMThread(int _a = 123)
//     {
//         a = _a;
//     }

//     virtual void run()
//     {
//         printf("MyMMThread: %d\n", a);
//     }
// };

// int main()
// {
//     // thread_function();
//     std::thread t(thread_function, 1234567);
//     // t.join(); // 阻塞创建它的线程，直到该线程执行完毕
//     // t.detach(); // 将该线程与创建它的线程完全分离

//     // std::this_thread::sleep_for(std::chrono::seconds(2));

//     if (t.joinable())
//     {
//         printf("joinable is ok!\n");
//     }
//     else
//     {
//         printf("joinable is null~\n");
//     }

//     t.detach(); // 将该线程与创建它的线程完全分离
//     // t.join(); // 阻塞创建它的线程，直到该线程执行完毕

//     std::this_thread::sleep_for(std::chrono::seconds(1));

//     MyMMThread t2(98765);
//     t2.Start();

//     std::this_thread::sleep_for(std::chrono::seconds(1));

//     std::cout << "hello world" << std::endl;
//     return 0;
// }

#include "MMAV/MMAV.h"

int main()
{
    MMAVReader reader;
    int ret = reader.Open("/Users/nnhu/Movies/3debf531162aab331805b0899b5babcb.mp4");
    printf("ret: %d\n", ret);
    while (1)
    {
        MMAVPacket packet;
        ret = reader.Read(&packet);
        if (ret)
        {
            printf("结束\n");
            break;
        }

        printf("Read Packet Success\n");
    }

    reader.Close();
    return 0;
}