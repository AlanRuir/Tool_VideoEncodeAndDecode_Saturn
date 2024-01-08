#include <video/video_encoder_decoder.h>

VideoEncoderDecoder::VideoEncoderDecoder()
    : encoder_{nullptr}
{

}

VideoEncoderDecoder::~VideoEncoderDecoder()
{

}

bool VideoEncoderDecoder::Setup(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec)
{
    encoder_ = std::make_shared<ImageEncoderH26X>(cols, rows, fps, codec);      // 创建编码器
    if (!encoder_)
    {
        return false;
    }
    return true;
}

bool VideoEncoderDecoder::Encode(uint8_t *frame, uint32_t frame_size)
{
    return encoder_->Encode(frame, frame_size);
}

void VideoEncoderDecoder::EncodedDataHandle(uint8_t *data, uint32_t size)
{
    if (!encoder_)
    {
        std::cerr << "encoder data is null" << std::endl;
        return;
    }
    
    /*将编码后的数据写入文件*/
    FILE* file = fopen("test.h26x", "ab+");
    fwrite(data, size, 1, file);
    fclose(file);
}
