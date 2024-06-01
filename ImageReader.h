#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <memory>

class ImageReader
{
public:
    ImageReader();

    int readHEIF(const std::string& filename, uint8_t*& dataPtr, int& width, int& height, int& channels);
    int readPNG();
    int readJPG();
    int readRaw();
};

#endif // IMAGEREADER_H
