#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <cstdint>

#include <video/video_encoder_decoder.h>

uint64_t GetFileSize(const std::string& filePath) 
{
    std::ifstream file(filePath, std::ifstream::ate | std::ifstream::binary);
    if (!file) 
    {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return 0;
    }

    return static_cast<uint64_t>(file.tellg());
}

void DisplayProgress(int current, int total) 
{
    const int barWidth = 70;
    float progress = static_cast<float>(current) / total;
    int barLength = static_cast<int>(progress * barWidth);

    std::string progressBar = "[";
    for (int i = 0; i < barLength; ++i) 
    {
        progressBar += "=";
    }
    for (int i = barLength; i < barWidth; ++i) 
    {
        progressBar += " ";
    }
    progressBar += "]";

    std::string progressLog = "Progress: " + std::to_string(current) + "/" + std::to_string(total);

    std::cout << "\r" << progressBar << " " << progressLog << std::flush;
}

int main(int argc, char *argv[])
{
    uint32_t frame_size = 1920 * 1080 * 3 / 2;
    std::shared_ptr<uint8_t> frame_buffer(new uint8_t[frame_size](), std::default_delete<uint8_t[]>());
    std::shared_ptr<VideoEncoderDecoder> encoder = std::make_shared<VideoEncoderDecoder>();
    std::shared_ptr<VideoEncoderDecoder> decoder = std::make_shared<VideoEncoderDecoder>();
    FILE* file = nullptr;
    FILE* file2 = nullptr;
    encoder->Setup(1920, 1080, 30, VideoCodec::H265);

    std::cout << "开始编码" << std::endl;
    for (int i = 1; i <= 513; ++i)
    {
        std::string file_path = std::string("../shell/output/") + std::to_string(i) + ".yuv";
        file = fopen(file_path.c_str(), "rb");
        fread(frame_buffer.get(), 1, frame_size, file);
        encoder->Encode(frame_buffer.get(), frame_size);
        fclose(file);
        DisplayProgress(i, 513);
    }
    std::cout << std::endl;

    std::cout << "开始解码" << std::endl;
    for (int i = 1; i <= 500; ++i)
    {
        std::string file_path = std::to_string(i) + ".265";
        file2 = fopen(file_path.c_str(), "rb");
        uint64_t file_size = GetFileSize(file_path);
        fread(frame_buffer.get(), 1, file_size, file2);
        encoder->Decode(frame_buffer.get(), file_size);
        fclose(file2);
        DisplayProgress(i, 500);
    }
    std::cout << std::endl;
    
    return 0;
}