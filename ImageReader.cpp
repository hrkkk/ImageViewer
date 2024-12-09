#include "ImageReader.h"
#include "libheif/heif.h"
#include <QDebug>
#include <QImage>

extern "C" {
#include "jpeglib.h"
}

#include "TinyEXIF.h"

#include <iostream>
#include <fstream>
#include <iomanip>  // std::set_precision


std::string processString(const std::string& input) {
    // 如果字符串中没有小数点，直接返回原字符串
    size_t decimalPointPos = input.find('.');
    if (decimalPointPos == std::string::npos) {
        return input;
    }

    std::string result = input; // 复制原字符串用于修改
    size_t length = result.size();

    // 从字符串末尾开始遍历，找到最后一个非零数字的位置
    size_t pos = length - 1;
    bool hasNonZero = false;
    for (; pos > decimalPointPos; --pos) {
        if (result[pos] != '0') {
            hasNonZero = true;
            break;
        }
    }

    // 如果小数点后没有非零数字，删除小数点及其后面的所有字符
    if (!hasNonZero) {
        result.erase(decimalPointPos, length - decimalPointPos);
    } else {
        // 如果小数点后有非零数字，删除非零数字后的所有零
        result.erase(pos + 1, length - pos);
    }

    return result;
}

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
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);


    FILE* infile = fopen(filename.c_str(), "rb");
    if (infile == NULL) {
        return -1;
    }
    // 初始化
    jpeg_create_decompress(&cinfo);
    // 指定输入文件
    jpeg_stdio_src(&cinfo, infile);
    // 读取JPEG文件头
    jpeg_read_header(&cinfo, TRUE);
    // 开始解压缩JPEG文件
    jpeg_start_decompress(&cinfo);
    // 获取JPEG图像的宽、高、通道数
    width = cinfo.output_width;
    height = cinfo.output_height;
    channels = cinfo.output_components;

    int rowStride = cinfo.output_width * cinfo.output_components;
    unsigned char* imageData = (unsigned char*)malloc(cinfo.output_height * rowStride);
    JSAMPROW rowPointer[1];
    // 逐行读取图像数据
    while (cinfo.output_scanline < cinfo.output_height) {
        rowPointer[0] = &imageData[cinfo.output_scanline * rowStride];
        jpeg_read_scanlines(&cinfo, rowPointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    uint64_t byteSize = width * height * channels;
    // 将图像数据复制到堆上
    if (dataPtr == nullptr) {
        dataPtr = new uint8_t[byteSize];
        memcpy(dataPtr, imageData, byteSize);
    }

    free(imageData);

    return 0;
}

int ImageReader::readRaw(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels)
{
    return 0;
}

int ImageReader::readImageExif(const std::string& filename, std::vector<std::pair<std::string, std::string>>& exif, int& orientation)
{
    std::ifstream stream(filename.c_str(), std::ios::binary);
    TinyEXIF::EXIFInfo imageEXIF(stream);

    // print extracted metadata
    if (imageEXIF.ImageWidth) {
        exif.push_back({u8"宽度", processString(std::to_string(imageEXIF.ImageWidth))});
    }
    if (imageEXIF.ImageHeight) {
        exif.push_back({u8"高度", processString(std::to_string(imageEXIF.ImageHeight))});
    }
    if (imageEXIF.RelatedImageWidth) {
        exif.push_back({"Related Image Width", processString(std::to_string(imageEXIF.RelatedImageWidth))});
    }
    if (imageEXIF.RelatedImageHeight) {
        exif.push_back({"Related Image Height", processString(std::to_string(imageEXIF.RelatedImageHeight))});
    }
    if (!imageEXIF.ImageDescription.empty()) {
        exif.push_back({"Description", imageEXIF.ImageDescription});
    }
    if (!imageEXIF.Make.empty()) {
        exif.push_back({u8"相机厂商", imageEXIF.Make});
    }
    if (!imageEXIF.Model.empty()) {
        exif.push_back({u8"相机型号", imageEXIF.Model});
    }
    if (!imageEXIF.SerialNumber.empty()) {
        exif.push_back({u8"序列号", imageEXIF.SerialNumber});
    }
    if (imageEXIF.Orientation) {
        orientation = imageEXIF.Orientation;
        exif.push_back({u8"方向", processString(std::to_string(imageEXIF.Orientation))});
    }
    if (imageEXIF.XResolution || imageEXIF.YResolution || imageEXIF.ResolutionUnit) {
        exif.push_back({u8"分辨率", processString(std::to_string(imageEXIF.XResolution)) + "x" + processString(std::to_string(imageEXIF.YResolution))});
        exif.push_back({u8"分辨率单位", translateNumToText("ResolutionUnit", imageEXIF.ResolutionUnit)});
    }
    if (imageEXIF.BitsPerSample) {
        exif.push_back({u8"采样深度", processString(std::to_string(imageEXIF.BitsPerSample))});
    }
    if (!imageEXIF.Software.empty()) {
        exif.push_back({u8"固件", imageEXIF.Software});
    }
    if (!imageEXIF.DateTime.empty()) {
        exif.push_back({u8"日期", imageEXIF.DateTime});
    }
    if (!imageEXIF.DateTimeOriginal.empty()) {
        exif.push_back({"DateTime Original", imageEXIF.DateTimeOriginal});
    }
    if (!imageEXIF.DateTimeDigitized.empty()) {
        exif.push_back({"DateTime Digitized", imageEXIF.DateTimeDigitized});
    }
    if (!imageEXIF.SubSecTimeOriginal.empty()) {
        exif.push_back({"SubSecTime Original", imageEXIF.SubSecTimeOriginal});
    }
    if (!imageEXIF.Copyright.empty()) {
        exif.push_back({u8"版权信息", imageEXIF.Copyright});
    }
    exif.push_back({u8"曝光时间(s)", processString(std::to_string(imageEXIF.ExposureTime))});
    exif.push_back({u8"光圈值(F)", processString(std::to_string(imageEXIF.FNumber))});
    exif.push_back({u8"曝光模式", translateNumToText("ExposureProgram", imageEXIF.ExposureProgram)});
    exif.push_back({u8"ISO速度", processString(std::to_string(imageEXIF.ISOSpeedRatings))});
    exif.push_back({u8"快门速度", processString(std::to_string(imageEXIF.ShutterSpeedValue))});
    exif.push_back({u8"光圈孔径", processString(std::to_string(imageEXIF.ApertureValue))});
    exif.push_back({u8"亮度", processString(std::to_string(imageEXIF.BrightnessValue))});
    exif.push_back({u8"曝光补偿(EV)", processString(std::to_string(imageEXIF.ExposureBiasValue))});
    exif.push_back({u8"物距", processString(std::to_string(imageEXIF.SubjectDistance))});
    exif.push_back({u8"焦距(mm)", processString(std::to_string(imageEXIF.FocalLength))});
    exif.push_back({u8"闪光灯模式", processString(std::to_string(imageEXIF.Flash))});
    // if (!imageEXIF.SubjectArea.empty()) {
    //     std::cout << "SubjectArea";
    //     for (uint16_t val: imageEXIF.SubjectArea)
    //         std::cout << " " << val;
    //     std::cout << "\n";
    // }
    exif.push_back({u8"测光模式", translateNumToText("MeteringMode", imageEXIF.MeteringMode)});
    exif.push_back({u8"光源", processString(std::to_string(imageEXIF.LightSource))});
    exif.push_back({u8"投影类型", processString(std::to_string(imageEXIF.ProjectionType))});
    if (imageEXIF.Calibration.FocalLength != 0) {
        exif.push_back({"Calibration.FocalLength", processString(std::to_string(imageEXIF.Calibration.FocalLength))});
    }
    if (imageEXIF.Calibration.OpticalCenterX != 0) {
        exif.push_back({"Calibration.OpticalCenterX", processString(std::to_string(imageEXIF.Calibration.OpticalCenterX))});
    }
    if (imageEXIF.Calibration.OpticalCenterY != 0) {
        exif.push_back({"Calibration.OpticalCenterY", processString(std::to_string(imageEXIF.Calibration.OpticalCenterY))});
    }
    exif.push_back({u8"镜头光圈范围(F)", processString(std::to_string(imageEXIF.LensInfo.FStopMin)) + "-" + processString(std::to_string(imageEXIF.LensInfo.FStopMax))});
    exif.push_back({u8"镜头焦距范围(mm)", processString(std::to_string(imageEXIF.LensInfo.FocalLengthMin)) + "-" + processString(std::to_string(imageEXIF.LensInfo.FocalLengthMax))});
    exif.push_back({u8"镜头数字缩放", processString(std::to_string(imageEXIF.LensInfo.DigitalZoomRatio))});
    exif.push_back({u8"镜头焦距(等效35mm)", processString(std::to_string(imageEXIF.LensInfo.FocalLengthIn35mm))});
    exif.push_back({"Lens FocalPlaneXResolution", processString(std::to_string(imageEXIF.LensInfo.FocalPlaneXResolution))});
    exif.push_back({"Lens FocalPlaneYResolution", processString(std::to_string(imageEXIF.LensInfo.FocalPlaneYResolution))});
    exif.push_back({"Lens FocalPlaneResolutionUnit", processString(std::to_string(imageEXIF.LensInfo.FocalPlaneResolutionUnit))});
    if (!imageEXIF.LensInfo.Make.empty()) {
        exif.push_back({u8"镜头厂商", imageEXIF.LensInfo.Make});
    }
    if (imageEXIF.LensInfo.Model.empty()) {
        exif.push_back({u8"镜头型号", imageEXIF.LensInfo.Model});
    }
    // if (imageEXIF.GeoLocation.hasLatLon()) {
    //     std::cout << "GeoLocation.Latitude " << std::setprecision(10) << imageEXIF.GeoLocation.Latitude << "\n";
    //     std::cout << "GeoLocation.Longitude " << std::setprecision(10) << imageEXIF.GeoLocation.Longitude << "\n";
    // }
    // if (imageEXIF.GeoLocation.hasAltitude()) {
    //     std::cout << "GeoLocation.Altitude " << imageEXIF.GeoLocation.Altitude << " m" << "\n";
    //     std::cout << "GeoLocation.AltitudeRef " << (int)imageEXIF.GeoLocation.AltitudeRef << "\n";
    // }
    // if (imageEXIF.GeoLocation.hasRelativeAltitude())
    //     std::cout << "GeoLocation.RelativeAltitude " << imageEXIF.GeoLocation.RelativeAltitude << " m" << "\n";
    // if (imageEXIF.GeoLocation.hasOrientation()) {
    //     std::cout << "GeoLocation.RollDegree " << imageEXIF.GeoLocation.RollDegree << "\n";
    //     std::cout << "GeoLocation.PitchDegree " << imageEXIF.GeoLocation.PitchDegree << "\n";
    //     std::cout << "GeoLocation.YawDegree " << imageEXIF.GeoLocation.YawDegree << "\n";
    // }
    // if (imageEXIF.GeoLocation.hasSpeed()) {
    //     std::cout << "GeoLocation.SpeedX " << imageEXIF.GeoLocation.SpeedX << " m/s" << "\n";
    //     std::cout << "GeoLocation.SpeedY " << imageEXIF.GeoLocation.SpeedY << " m/s" << "\n";
    //     std::cout << "GeoLocation.SpeedZ " << imageEXIF.GeoLocation.SpeedZ << " m/s" << "\n";
    // }
    // if (imageEXIF.GeoLocation.AccuracyXY > 0 || imageEXIF.GeoLocation.AccuracyZ > 0)
    //     std::cout << "GeoLocation.GPSAccuracy XY " << imageEXIF.GeoLocation.AccuracyXY << " m" << " Z " << imageEXIF.GeoLocation.AccuracyZ << " m" << "\n";
    // std::cout << "GeoLocation.GPSDOP " << imageEXIF.GeoLocation.GPSDOP << "\n";
    // std::cout << "GeoLocation.GPSDifferential " << imageEXIF.GeoLocation.GPSDifferential << "\n";
    // if (!imageEXIF.GeoLocation.GPSMapDatum.empty())
    //     std::cout << "GeoLocation.GPSMapDatum " << imageEXIF.GeoLocation.GPSMapDatum << "\n";
    // if (!imageEXIF.GeoLocation.GPSTimeStamp.empty())
    //     std::cout << "GeoLocation.GPSTimeStamp " << imageEXIF.GeoLocation.GPSTimeStamp << "\n";
    // if (!imageEXIF.GeoLocation.GPSDateStamp.empty())
    //     std::cout << "GeoLocation.GPSDateStamp " << imageEXIF.GeoLocation.GPSDateStamp << "\n";
    // if (imageEXIF.GPano.hasPosePitchDegrees())
    //     std::cout << "GPano.PosePitchDegrees " << imageEXIF.GPano.PosePitchDegrees << "\n";
    // if (imageEXIF.GPano.hasPoseRollDegrees())
    //     std::cout << "GPano.PoseRollDegrees " << imageEXIF.GPano.PoseRollDegrees << "\n";
}

std::string ImageReader::translateNumToText(const std::string& type, int num)
{
    if (type == "Orientation") {
        switch (num) {
            case 0:
                return u8"未知";
            case 1:
                return u8"不旋转";
            case 2:
                return u8"水平翻转";
            case 3:
                return u8"顺时针旋转180°";
            case 4:
                return u8"垂直翻转";
            case 5:
                return u8"顺时针旋转90° + 水平翻转";
            case 6:
                return u8"顺时针旋转90°";
            case 7:
                return u8"顺时针旋转90° + 垂直翻转";
            case 8:
                return u8"逆时针旋转90°";
        }
    } else if (type == "ExposureProgram") {
        switch (num) {
            case 0:
                return u8"未知";
            case 1:
                return u8"手动控制";
            case 2:
                return u8"程序正常";
            case 3:
                return u8"光圈优先";
            case 4:
                return u8"快门优先";
            case 5:
                return u8"创意程序";
            case 6:
                return u8"动作程序";
            case 7:
                return u8"肖像模式";
            case 8:
                return u8"风景模式";
        }
    } else if (type == "MeteringMode") {
        switch (num) {
            case 0:
                return u8"未知";
            case 1:
                return u8"平均测光";
            case 2:
                return u8"中心权重测光";
            case 3:
                return u8"点测光";
            case 4:
                return u8"多点测光";
            case 5:
                return u8"模式测光";
            case 6:
                return u8"部分测光";
        }
    } else if (type == "ResolutionUnit") {
        switch (num) {
            case 1:
                return u8"无单位";
            case 2:
                return u8"英寸";
            case 3:
                return u8"厘米";
        }
    }
}
