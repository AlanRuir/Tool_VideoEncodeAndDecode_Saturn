#ifndef __IMAGE_DECODER_H__
#define __IMAGE_DECODER_H__

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

#include <common/common_type.h>

class ImageDecoderH26X
{
using ImageDecoderCallbackType = std::function<void(uint8_t **, int*)>;

public:
    ImageDecoderH26X(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec);
    ~ImageDecoderH26X();
    bool Decode(uint8_t *data, uint32_t size);
    bool InstallCallback(const ImageDecoderCallbackType &callback);
private:
    uint32_t                 cols_;
    uint32_t                 rows_;
    uint32_t                 counter_;
    AVCodec*                 codec_;
    AVFrame*                 frame_;
    AVCodecContext*          codec_context_;
    AVPacket*                pkt_;
    ImageDecoderCallbackType callback_;
};

#endif  // __IMAGE_DECODER_H__