- libavutil 基础工具，内存分配，内存管理，基本数据结构
  - 没有涉及到音视频的比较高级的东西
- libavcodec 集成很多 `编码器` 和 `解码器`
- libavformat 存储视频的视频格式、网络流，集成每种格式里面的详情细节
  - ffmpeg 里最有用的模块
- libavdevice 摄像头的采集、音频采集、投屏相关的工作
  - ffmpeg 里最没用的模块……基本用不上
- libavfilter 给视频、图像做滤镜，给音频做处理
  - 用得相对也比较少
- libswscale 将 yuv 转为 rgb，pix_fmt 转化的库
- libswresample 重采样，音频采样率

---

初始化，全局只需调用一次即可

```cpp
// 初始化一些解码器
av_register_all();
// 初始化网络，用于读取网络流、直播流
avformat_network_init();
```

处理目标时分配上下文

```cpp
// 分配上下文，用于读视频的时候，启动这个上下文，若要读另外的文件，就另外再起一个
avformat_alloc_context();
// 调用之后会返回 AVFormatContext 结构体的指针
```

后续都是对 `AVFormatContext` 进行的操作

```cpp
// 尝试打开目标文件 或者打开网络流地址
avformat_open_init();

// 找到所有的视频流和音频流，并列举出详细信息
// 不同清晰度的视频流可能会有多路视频
// 多路音频流，为了适应不同场景，可能有双声道的、有的是三声道的
// 若是在读视频流，该函数执行耗时会比较长（甚至是十几二十秒），有办法避免运行耗时过长
avformat_find_stream_info();
// AVStream

// 通常是循环调用的，成功了会继续去读
av_read_frame();
// 读取成功：返回产物 AVPacket，可以经过解码得到 AVFrame
// 读取失败：1. 出错的情况，如读取网络流的时候，网络不好、网络延迟
//         2. 文件已经读取完毕，读到末尾了，需要执行下面的操作来跳出循环

// 成功读取的产物
// 是编码后的数据、压缩后的数据
AVPacket
// 经过解码后得到
AVFrame

// 结束读取
avformat_close_input();
// 释放上下文的内存
avformat_free_context();
```


---

下载

- Static 无依赖dll
- Shared 有dll
- Dev 有头文件