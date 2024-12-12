#pragma once

#include <QFileInfo>
#include <string>

enum class FileType {
    OTHER_FILE = 0x0000,
    HEIF_IMG = 0x0001,
    PNG_IMG = 0x0002,
    JPG_IMG = 0x0004,
    RAW_IMG = 0x0008,
    ALL_IMG = 0x000F
};

struct ImageFile {
    std::string fileName;
    std::string filePath;
    QFileInfo fileInfo;
    FileType fileType;
};

class Utils
{
public:
    static FileType getFileType(const std::string& filename);
    static std::string byteToText(unsigned long long bytes);
    static std::string typeToText(FileType fileType);
    static std::pair<std::string, std::string> splitFilepath(const std::string& filepath);
};
