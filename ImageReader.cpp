#include "ImageReader.h"
#include "libheif/heif.h"

#include <QDebug>

ImageReader::ImageReader() {}

int ImageReader::readHEIF(const std::string &filename, uint8_t*& dataPtr, int& width, int& height, int& channels)
{
    heif_context* ctx = heif_context_alloc();
    heif_context_read_from_file(ctx, filename.c_str(), nullptr);

    heif_image_handle* handle;
    heif_context_get_primary_image_handle(ctx, &handle);


    heif_image* img;
    heif_decode_image(handle, &img, heif_colorspace_RGB, heif_chroma_interleaved_RGBA, nullptr);

    int stride;
    uint8_t* data = heif_image_get_plane(img, heif_channel_interleaved, &stride);
    width = heif_image_get_width(img, heif_channel_interleaved);
    height = heif_image_get_height(img, heif_channel_interleaved);
    int bitsPerPixel = heif_image_get_bits_per_pixel(img, heif_channel_interleaved);
    if (bitsPerPixel == 24) {
        channels = 3;
    } else if (bitsPerPixel == 32) {
        channels = 4;
    }
    uint64_t byteSize = channels * width * height;

    // 将数据转移到堆上
    if (dataPtr == nullptr) {
        dataPtr = new uint8_t[byteSize];
        memcpy(dataPtr, data, byteSize);
    }

    // 释放资源
    heif_image_release(img);
    heif_image_handle_release(handle);
    heif_context_free(ctx);

    return 0;
}

int ImageReader::readPNG()
{
    return 0;
}

int ImageReader::readJPG()
{
    return 0;
}

int ImageReader::readRaw()
{
    return 0;
}
