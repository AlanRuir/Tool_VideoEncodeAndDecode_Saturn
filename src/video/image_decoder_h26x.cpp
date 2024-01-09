#include <video/image_decoder_h26x.h>
#include <exception>

ImageDecoderH26X::ImageDecoderH26X(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec)
    : cols_(cols)
    , rows_(rows)
    , counter_(0U)
    , codec_(nullptr)
    , frame_(nullptr)
    , codec_context_(nullptr)
    , pkt_(nullptr)
    , callback_(nullptr)
{
    av_register_all();          //注册所有组件
    avcodec_register_all();     //注册所有解码器
    pkt_ = av_packet_alloc();   //分配packet
    if (!pkt_)
    {
        throw std::runtime_error("failed to alloc avcodec packet");
    }

    if (codec == VideoCodec::H264)
    {
        codec_ = avcodec_find_decoder(AV_CODEC_ID_H264);        //查找解码器
        if (!codec_)
        {
            throw std::runtime_error("failed to find decoder");
        }
        else
        {
            std::cout << "use codec: " << codec_->name << std::endl;
        }
    }
    else if (codec == VideoCodec::H265)
    {
        codec_ = avcodec_find_decoder(AV_CODEC_ID_H265);        //查找解码器
        if (!codec_)
        {
            throw std::runtime_error("failed to find decoder");
        }
        else
        {
            std::cout << "use codec: " << codec_->name << std::endl;
        }
    }
    codec_context_ = avcodec_alloc_context3(codec_);        //分配解码器上下文
    if (!codec_context_)
    {
        throw std::runtime_error("failed to init code context");
    }

    /* 设置多线程解码 */
    codec_context_->thread_count = 4U;
    if (codec_->capabilities | AV_CODEC_CAP_FRAME_THREADS)
    {
        codec_context_->thread_type = FF_THREAD_FRAME;
    }
    else if (codec_->capabilities | AV_CODEC_CAP_SLICE_THREADS)
    {
        codec_context_->thread_type = FF_THREAD_SLICE;
    }
    else
    {
        codec_context_->thread_count = 1;
    }

    if (avcodec_open2(codec_context_, codec_, NULL) < 0)        //打开解码器
    {
        throw std::runtime_error("failed to open avcodec");
    }

    frame_ = av_frame_alloc();          //分配frame
    if (!frame_)
    {
        throw std::runtime_error("failed to init av frame");
    }
}

ImageDecoderH26X::~ImageDecoderH26X()
{
    if (codec_context_)
    {
        (void)avcodec_send_packet(codec_context_, NULL);
        avcodec_free_context(&codec_context_);
    }
    if (frame_)
    {
        av_frame_free(&frame_);
    }
    if (pkt_)
    {
        av_packet_free(&pkt_);
    }
}

bool ImageDecoderH26X::Decode(uint8_t *data, uint32_t size)
{
    pkt_->size = size;
    pkt_->data = data;

    int32_t result = avcodec_send_packet(codec_context_, pkt_);
    if (result < 0)
    {
        std::cerr << "error sending a packet for decoding" << std::endl;
        pkt_->size = 0;
        pkt_->data = nullptr;
        return false;
    }

    while (result >= 0)
    {
        result = avcodec_receive_frame(codec_context_, frame_);
        if (result == AVERROR(EAGAIN) || result == AVERROR_EOF)
        {
            return true;
        }
        else if (result < 0)
        {
            std::cerr << "error during decoding: " << stderr << std::endl;
            pkt_->size = 0;
            pkt_->data = nullptr;
            return false;
        }

        if (callback_)
        {
            callback_(frame_->data, frame_->linesize);
        }
    }

    return true;
}

bool ImageDecoderH26X::InstallCallback(const ImageDecoderCallbackType &callback)
{
    if (!callback)
    {
        return false;
    }

    callback_ = callback;
}
