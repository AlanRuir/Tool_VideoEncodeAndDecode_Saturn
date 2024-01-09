#include <iostream>
#include <memory>
#include <video/image_encoder_h26x.h>
#include <video/image_decoder_h26x.h>

class VideoEncoderDecoder
{
public:
    VideoEncoderDecoder();
    ~VideoEncoderDecoder();
    bool Setup(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec);
    bool Encode(uint8_t *frame, uint32_t frame_size);
    bool Decode(uint8_t *data, uint32_t size);
    void EncodedDataHandle(uint8_t *data, uint32_t size);
    void DecodedDataHandle(uint8_t **data_array, int *size_array);
private:
    uint32_t cols_;
    uint32_t rows_;
    std::shared_ptr<ImageEncoderH26X> encoder_;
    std::shared_ptr<ImageDecoderH26X> decoder_;
    uint64_t counter_;
    VideoCodec codec_;
};