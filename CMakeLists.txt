cmake_minimum_required(VERSION 3.10)
project(VideoEncoderDecoder)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 设置CMake安装目录
set(CMAKE_PREFIX_PATH "/usr")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)  # 将cmake目录添加到CMAKE_MODULE_PATH
find_package(FFmpeg REQUIRED COMPONENTS AVCODEC AVFORMAT AVUTIL SWSCALE)

# 添加可执行文件
file(GLOB SOURCE_FILES "src/video/*.cpp" "src/main.cpp")
add_executable(VideoEncoderDecoder ${SOURCE_FILES})

# 添加头文件和链接库
include_directories(${CMAKE_SOURCE_DIR}/include ${FFMPEG_INCLUDE_DIRS_AVCODEC} ${FFMPEG_INCLUDE_DIRS_AVFORMAT} ${FFMPEG_INCLUDE_DIRS_AVUTIL} ${FFMPEG_INCLUDE_DIRS_SWSCALE})
target_link_libraries(VideoEncoderDecoder PRIVATE ${FFmpeg_LIBRARIES})

# 设置可执行文件的输出路径
set_target_properties(VideoEncoderDecoder PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)