﻿#include "Utils.h"

FileType Utils::getFileType(const std::string& filename) {
    size_t dotIndex = filename.find_last_of(".");
    if (dotIndex != std::string::npos && dotIndex < filename.length() - 1) {
        std::string extension = filename.substr(dotIndex + 1);
        // 将扩展名转换为大写字母
        for (char& c : extension) {
            c = toupper(c);
        }
        // 判断文件类型
        if (extension == "JPG" || extension == "JPEG") {
            return FileType::JPG_IMG;
        } else if (extension == "PNG") {
            return FileType::PNG_IMG;
        } else if (extension == "HEIF" || extension == "HEIC") {
            return FileType::HEIF_IMG;
        } else if (extension == "RAW" || extension == "DNG" || extension == "NEF" || extension == "ARW"
                   || extension == "CR2" || extension == "CR3" || extension == "NRW" || extension == "RW2"
                   || extension == "RAF" || extension == "ORF" || extension == "RWL" || extension == "SRW") {
            return FileType::RAW_IMG;
        } else {
            return FileType::OTHER_FILE;
        }
    } else {
        return FileType::OTHER_FILE;
    }
}

std::string Utils::byteToText(unsigned long long bytes)
{
    if (bytes >= 1024 * 1024) {
        float mb = (float)bytes / (1024 * 1024);
        return std::to_string(mb) + " MB";
    } else if (bytes >= 1024 && bytes < 1024 * 1024) {
        float kb = (float)bytes / 1024;
        return std::to_string(kb) + " KB";
    } else if (bytes >= 0 && bytes < 1024) {
        return std::to_string(bytes) + " B";
    }
    return "";
}

std::string Utils::typeToText(FileType fileType)
{
    switch (fileType) {
    case FileType::JPG_IMG:
        return "JPEG";
    case FileType::PNG_IMG:
        return "PNG";
    case FileType::HEIF_IMG:
        return "HEIF";
    case FileType::RAW_IMG:
        return "RAW";
    default:
        return "";
    }
    return "";
}

std::pair<std::string, std::string> Utils::splitFilepath(const std::string& filepath)
{
    size_t found = filepath.find_last_of("/\\");
    if (found == std::string::npos) {
        return std::make_pair("", filepath); // 没有找到路径分隔符，整个字符串是文件名
    }
    std::string filePath = filepath.substr(0, found);
    std::string fileName = filepath.substr(found + 1);

    return std::make_pair(filePath, fileName);
}
