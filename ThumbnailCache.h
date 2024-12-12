#ifndef THUMBNAILCACHE_H
#define THUMBNAILCACHE_H

#include <string>
#include <vector>

#include "sqlite3.h"
#include "Utils.h"

class ThumbnailCache
{
public:
    static ThumbnailCache& getInstance() {
        static ThumbnailCache instance;
        return instance;
    }

    void getThumbnail(const std::string& filename, FileType fileType, std::vector<uint8_t>& imageData);
    void shrinkDatabase();

private:
    bool queryImageData(const std::string& filename, FileType fileType, std::vector<uint8_t>& imageData);
    bool insertImageData(const std::string& filename, FileType fileType, const std::vector<uint8_t>& imageData);
    bool createTable();

    ThumbnailCache();
    ~ThumbnailCache();
    ThumbnailCache(const ThumbnailCache&) = delete;
    ThumbnailCache& operator=(const ThumbnailCache&) = delete;

private:
    sqlite3* m_database;
};

#endif // THUMBNAILCACHE_H
