#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <memory>
#include <vector>
#include <string>

class ImageReader
{
public:
    static int readHEIF(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readPNG(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readJPG(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readRaw(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readImageExif(const std::string& filename, std::vector<std::pair<std::string, std::string>>& exif, int& orientation);

private:
    static std::string translateNumToText(const std::string& type, int num);
};

#endif // IMAGEREADER_H
