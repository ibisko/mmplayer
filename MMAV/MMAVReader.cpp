#include "MMAV.h"
#include "MMAVReaderPrivate.h"
#include "MMAVPacketPrivate.h"

// 初始化
MMAVReader::MMAVReader()
{
    imp = new MMAVReaderPrivate();
    imp->ctx = avformat_alloc_context();
}

// 生命周期结束时回收资源
MMAVReader::~MMAVReader()
{
    if (imp->ctx != nullptr)
    {
        avformat_free_context(imp->ctx);
        imp->ctx = nullptr; // 此处虽然没什么用，但为了养成良好习惯
    }
}

int MMAVReader::Open(const char *path)
{
    if (imp->ctx == nullptr)
        return -1;

    int ret = avformat_open_input(&imp->ctx, path, nullptr, nullptr);

    // 返回0即是成功
    if (!ret)
    {
        avformat_find_stream_info(imp->ctx, nullptr);
    }

    return ret;
}

int MMAVReader::Close()
{
    if (imp->ctx == nullptr)
        return -1;

    avformat_close_input(&imp->ctx);
    return 0;
}

int MMAVReader::Read(MMAVPacket *packet)
{
    int ret = av_read_frame(imp->ctx, packet->imp->pkt);
    return ret;
}