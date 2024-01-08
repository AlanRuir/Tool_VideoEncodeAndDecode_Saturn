#include <iostream>
#include <video/image_encoder_h26x.h>
#include <memory>

int main(int argc, char *argv[])
{
    std::shared_ptr<ImageEncoderH26X> encoder = std::make_shared<ImageEncoderH26X>(640, 480, 30, VideoCodec::H265);
    for (int i = 0; i < 30; ++i)
    {
        encoder->Encode(nullptr, 0);
    }

    return 0;
}