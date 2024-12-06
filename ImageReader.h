#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <memory>

class ImageReader
{
public:
    static int readHEIF(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readPNG(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readJPG(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    static int readRaw(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
};

#endif // IMAGEREADER_H
