#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <string>
#include <memory>
#include <vector>
#include <string>

#include "Utils.h"
#include "CustomOpenGLWidget.h"

class ImageReader
{
public:
    static int readHEIF(const std::string& filename, std::shared_ptr<ImageData>& imageData);
    static int readPNG(const std::string& filename, std::shared_ptr<ImageData>& imageData);
    static int readJPG(const std::string& filename, std::shared_ptr<ImageData>& imageData);
    static int readRaw(const std::string& filename, std::shared_ptr<ImageData>& imageData);
    static int readImageExif(const std::string& filename, std::vector<std::pair<std::string, std::string>>& exif, int& orientation);
    static int createThumbnail(const std::string& filename, FileType fileType, std::vector<uint8_t>& imageData);

private:
    static std::string translateNumToText(const std::string& type, int num);
};

#endif // IMAGEREADER_H
