#include <video/video_encoder_decoder.h>

VideoEncoderDecoder::VideoEncoderDecoder()
    : encoder_{nullptr}
    , counter_(0U)
{

}

VideoEncoderDecoder::~VideoEncoderDecoder()
{

}

bool VideoEncoderDecoder::Setup(uint32_t cols, uint32_t rows, uint32_t fps, VideoCodec codec)
{
    cols_ = cols;
    rows_ = rows;
    codec_ = codec;
    encoder_ = std::make_shared<ImageEncoderH26X>(cols, rows, fps, codec);      // 创建编码器
    if (!encoder_)
    {
        std::cerr << "failed to create encoder" << std::endl;
        return false;
    }
    encoder_->InstallCallback(std::bind(&VideoEncoderDecoder::EncodedDataHandle, this, std::placeholders::_1, std::placeholders::_2));

    decoder_ = std::make_shared<ImageDecoderH26X>(cols, rows, fps, codec);      // 创建解码器
    if (!decoder_)
    {
        std::cerr << "failed to create decoder" << std::endl;
        return false;
    }
    decoder_->InstallCallback(std::bind(&VideoEncoderDecoder::DecodedDataHandle, this, std::placeholders::_1, std::placeholders::_2));

    return true;
}

bool VideoEncoderDecoder::Encode(uint8_t *frame, uint32_t frame_size)
{
    if (!encoder_)
    {
        std::cerr << "encoder is null" << std::endl;
        return false;
    }
    return encoder_->Encode(frame, frame_size);
}

bool VideoEncoderDecoder::Decode(uint8_t *data, uint32_t size)
{
    if (!decoder_)
    {
        std::cerr << "decoder is null" << std::endl;
        return false;
    }
    return decoder_->Decode(data, size);
}

void VideoEncoderDecoder::EncodedDataHandle(uint8_t *data, uint32_t size)
{
    if (!encoder_)
    {
        std::cerr << "encoder data is null" << std::endl;
        return;
    }

    ++counter_;     // 计数
    
    /*将编码后的数据写入文件*/
    if (VideoCodec::H264 == codec_)
    {
        FILE* file = fopen("output.264", "ab+");
        fwrite(data, size, 1, file);
        fclose(file);
        FILE* file2 = fopen((std::to_string(counter_) + ".264").c_str(), "wb");
        fwrite(data, size, 1, file2);
        fclose(file2);
    }
    else if(VideoCodec::H265 == codec_)
    {
        FILE* file = fopen("output.265", "ab+");
        fwrite(data, size, 1, file);
        fclose(file);
        FILE* file2 = fopen((std::to_string(counter_) + ".265").c_str(), "wb");
        fwrite(data, size, 1, file2);
        fclose(file2);
    }
    else
    {
        std::cerr << "unsupported codec" << std::endl;
    }
}

void VideoEncoderDecoder::DecodedDataHandle(uint8_t **data_array, int *size_array)
{
    if (!decoder_)
    {
        std::cerr << "decoder data is null" << std::endl;
        return;
    }

    /*将解码后的数据写入文件*/
    FILE* file = fopen("output.yuv", "ab+");    
    fwrite(data_array[0], size_array[0] * rows_, 1, file);
    fwrite(data_array[1], size_array[1] * rows_ / 2, 1, file);
    fwrite(data_array[2], size_array[2] * rows_ / 2, 1, file);
    fclose(file);
}
