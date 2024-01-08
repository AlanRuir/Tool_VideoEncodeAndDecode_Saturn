#include <video/image_encoder_h26x.h>
#include <exception>

ImageEncoderH26X::ImageEncoderH26X(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec)
    : cols_{cols}
    , rows_{rows}
    , counter_{0U}
    , pts_counter_{0U}
    , codec_{nullptr}
    , codec_context_{nullptr}
    , av_frame_{nullptr}
    , pkt_{nullptr}
    , out_buf_{nullptr}
    , frame_buf_{nullptr}
{
    av_register_all();              //注册所有组件
    avcodec_register_all();         //注册所有编解码器
    if (codec == VideoCodec::H264)
    {
        codec_ = avcodec_find_encoder(AV_CODEC_ID_H264);        //查找编码器
        if (!codec_)
        {
            throw std::runtime_error("failed to find encoder");
        }
        else
        {
            std::cout << "use codec: " << codec_->name << std::endl;
        }
    }
    else if (codec == VideoCodec::H265)
    {
        codec_ = avcodec_find_encoder(AV_CODEC_ID_H265);        //查找编码器
        if (!codec_)
        {
            throw std::runtime_error("failed to find encoder");
        }
        else
        {
            std::cout << "use codec: " << codec_->name << std::endl;
        }
    }
    codec_context_ = avcodec_alloc_context3(codec_);        //分配编码器上下文
    if (!codec_context_)
    {
        throw std::runtime_error("failed to alloc avcodec context");
    }
    pkt_ = av_packet_alloc();       //分配packet
    if (!pkt_)
    {
        throw std::runtime_error("failed to alloc avcodec packet");
    }

    /* 设置编码器参数 */
    codec_context_->bit_rate = 400000;
    codec_context_->height = rows;
    codec_context_->width  = cols;
    AVRational rate;
    rate.num                     = 1;
    rate.den                     = 30;
    codec_context_->time_base    = rate;
    codec_context_->gop_size     = 1; 
    codec_context_->max_b_frames = 0;
    codec_context_->pix_fmt      = AV_PIX_FMT_YUV420P;

    AVDictionary* dictParam = 0;
    (void)av_dict_set(&dictParam, "preset", "medium", 0);
    (void)av_dict_set(&dictParam, "tune", "zerolatency", 0);
    (void)av_dict_set(&dictParam, "profile", "main", 0);
    (void)av_opt_set(codec_context_->priv_data, "tune", "zerolatency", 0);

    /* 设置多线程编码 */
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

    if (avcodec_open2(codec_context_, codec_, NULL) < 0)        //打开编码器
    {
        throw std::runtime_error("failed to open avcodec context");
    }
    av_frame_ = av_frame_alloc();       //分配视频帧内存
    if (!av_frame_)
    {
        throw std::runtime_error("failed to allocate video frame");
    }

    /* 设置视频帧数据 */
    av_frame_->format      = codec_context_->pix_fmt;
    av_frame_->width       = codec_context_->width;
    av_frame_->height      = codec_context_->height;
    av_frame_->linesize[0] = FFALIGN(cols, 16);
    av_frame_->linesize[1] = FFALIGN(cols, 16) / 2;
    av_frame_->linesize[2] = FFALIGN(cols, 16) / 2;

    if (av_frame_get_buffer(av_frame_, 0) < 0)        //分配视频帧缓冲
    {
        throw std::runtime_error("failed to get frame buffer");
    }
}

ImageEncoderH26X::~ImageEncoderH26X() noexcept
{
    avcodec_free_context(&codec_context_);
    av_frame_free(&av_frame_);
    av_packet_free(&pkt_);
}

bool ImageEncoderH26X::Encode(uint8_t *frame, uint32_t frame_size)
{
    if (av_frame_make_writable(av_frame_) < 0)      //设置视频帧可写
    {
        std::cerr << "the frame data is un writable " << std::endl;
        return false;
    }

    if (!frame)
    {
        std::cerr << "the frame data is null " << std::endl;
        return false;
    }

    if (frame_size != cols_ * rows_ * 3 / 2)
    {
        std::cerr << "the frame size is invalid " << std::endl;
        return false;
    }

    try
    {
        /* 设置视频帧数据 */
        memcpy(av_frame_->data[0], frame, cols_ * rows_);
        memcpy(av_frame_->data[1], frame + cols_ * rows_, cols_ * rows_ / 4);
        memcpy(av_frame_->data[2], frame + cols_ * rows_ * 5 / 4, cols_ * rows_ / 4);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    int32_t result;

    result = avcodec_send_frame(codec_context_, av_frame_);     //发送视频帧
    if (result < 0)
    {
        std::cerr << "failed to send frame " << std::endl;
        return false;
    }

    while (result >= 0)
    {
        result = avcodec_receive_packet(codec_context_, pkt_);      //接收视频包
        if (result == AVERROR(EAGAIN) || result == AVERROR_EOF)
        {
            return true;
        }
        else if (result < 0)
        {
            std::cerr << "failed to receive packet " << std::endl;
            return false;
        }

        callback_(pkt_->data, pkt_->size);      //编码回调

        av_packet_unref(pkt_);      //释放视频包
    }

    return true;
}

bool ImageEncoderH26X::InstallCallback(const ImageEncoderCallbackType &callback)
{
    if (!callback)
    {
        return false;
    }

    callback_ = callback;
}
