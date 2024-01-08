#include <iostream>
#include <memory>
#include <video/image_encoder_h26x.h>

class VideoEncoderDecoder
{
public:
    VideoEncoderDecoder();
    ~VideoEncoderDecoder();
    bool Setup(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec);
    bool Encode(uint8_t *frame, uint32_t frame_size);
    void EncodedDataHandle(uint8_t *data, uint32_t size);
private:
    std::shared_ptr<ImageEncoderH26X> encoder_;
};