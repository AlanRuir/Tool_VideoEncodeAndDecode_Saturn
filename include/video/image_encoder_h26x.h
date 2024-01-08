#ifndef __IMAGE_ENCODER_H__
#define __IMAGE_ENCODER_H__

#include <iostream>
#include <functional>

extern "C" 
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>
}

enum class VideoCodec : uint8_t
{
    H264,
    H265,
};

class ImageEncoderH26X
{
using ImageEncoderCallbackType = std::function<void(uint8_t *, uint32_t)>;

public:
    ImageEncoderH26X(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec = VideoCodec::H265);
    ~ImageEncoderH26X() noexcept;
    bool Encode(uint8_t *frame, uint32_t frame_size);
    bool InstallCallback(const ImageEncoderCallbackType &callback);
private:
    uint32_t                 cols_;
    uint32_t                 rows_;
    uint32_t                 counter_;
    uint32_t                 pts_counter_;
    AVCodec*                 codec_;
    AVCodecContext*          codec_context_;
    AVFrame*                 av_frame_;
    AVPacket*                pkt_;
    uint8_t*                 out_buf_;
    uint8_t*                 frame_buf_;
    ImageEncoderCallbackType callback_;
};

#endif  // __IMAGE_ENCODER_H__