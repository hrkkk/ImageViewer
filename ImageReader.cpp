#include "ImageReader.h"
#include "libheif/heif.h"
#include "opencv2/opencv.hpp"
#include <QDebug>
#include <QImage>

int ImageReader::readHEIF(const std::string &filename, uint8_t*& dataPtr, int& width, int& height, int& channels)
{
    heif_context* ctx = heif_context_alloc();
    heif_context_read_from_file(ctx, filename.c_str(), nullptr);

    heif_image_handle* handle;
    heif_context_get_primary_image_handle(ctx, &handle);

    heif_image* img;
    heif_decode_image(handle, &img, heif_colorspace_RGB, heif_chroma_interleaved_RGBA, nullptr);

    // 获取图像数据
    int stride;
    uint8_t* data = heif_image_get_plane(img, heif_channel_interleaved, &stride);
    // 获取图像宽度
    width = heif_image_get_width(img, heif_channel_interleaved);
    // 获取图像高度
    height = heif_image_get_height(img, heif_channel_interleaved);
    // 获取图像像素位深
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

int ImageReader::readPNG(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels)
{
    QImage img(QString::fromStdString(filename));
    if (img.isNull()) {
        return -1;
    }

    width = img.width();
    height = img.height();
    int bitDepth = img.depth();
    if (bitDepth == 24) {
        channels = 3;
    } else if (bitDepth == 32) {
        channels = 4;
    }

    uint64_t byteSize = img.sizeInBytes();
    // 将图像数据复制到堆上
    if (dataPtr == nullptr) {
        dataPtr = new uint8_t[byteSize];
        memcpy(dataPtr, img.bits(), byteSize);
    }

    return 0;
}

int ImageReader::readJPG(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels)
{
    cv::Mat img = cv::imread(filename, cv::IMREAD_UNCHANGED);
    if (img.empty()) {
        return -1;
    }


    width = img.cols;
    height = img.rows;
    channels = img.channels();
    if (channels == 3) {
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    } else if (channels == 4) {
        cv::cvtColor(img, img, cv::COLOR_BGRA2RGBA);
    }

    uint64_t byteSize = width * height * channels;
    // 将图像数据复制到堆上
    if (dataPtr == nullptr) {
        dataPtr = new uint8_t[byteSize];
        memcpy(dataPtr, img.data, byteSize);
    }

    return 0;
}

int ImageReader::readRaw(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels)
{
    return 0;
}
