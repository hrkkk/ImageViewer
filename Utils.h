#pragma once

#include <string>

enum class FileType {
    OTHER_FILE = 0x0000,
    HEIF_IMG = 0x0001,
    PNG_IMG = 0x0002,
    JPG_IMG = 0x0004,
    RAW_IMG = 0x0008,
    ALL_IMG = 0x000F
};

class Utils
{
public:
    static FileType getFileType(const std::string& filename);
    static std::string byteToText(unsigned long long bytes);
};
