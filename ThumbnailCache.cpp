#include "ThumbnailCache.h"

#include "ImageReader.h"

#include <QDebug>

ThumbnailCache::ThumbnailCache()
{
    // 打开数据库文件，如文件不存在则创建
    sqlite3_open("./thumbnailCache.db", &m_database);

    // 查询指定的表是否存在，如果不存在，则创建一个新的表
    createTable();
}

ThumbnailCache::~ThumbnailCache()
{
    sqlite3_close(m_database);
}

void ThumbnailCache::getThumbnail(const std::string &filename, FileType fileType, std::vector<uint8_t>& imageData)
{
    // 在数据库中查询
    if (queryImageData(filename, fileType, imageData)) {
        return;
    }

    // 如果没查到，则生成缩略图
    ImageReader::createThumbnail(filename, fileType, imageData);

    // 然后向数据库中添加该缩略图
    insertImageData(filename, fileType, imageData);

    return;
}

void ThumbnailCache::shrinkDatabase()
{
    // 遍历数据库
    // 将文件已不存在的记录项标记为待删除

    // 统一删除所有被标记的记录项

}

bool ThumbnailCache::queryImageData(const std::string &filename, FileType fileType, std::vector<uint8_t> &imageBuffer)
{
    sqlite3_stmt* stmt;
    const char* tail;
    char sql[256];

    // 准备SQL查询语句
    sprintf(sql, "SELECT image_data FROM images WHERE image_name = ?;");

    if (sqlite3_prepare_v2(m_database, sql, -1, &stmt, &tail) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, filename.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            // 获取BLOB数据
            const void* blob = sqlite3_column_blob(stmt, 0);
            int blobSize = sqlite3_column_bytes(stmt, 0);

            // 将BLOB数据复制到buffer中
            imageBuffer.assign(static_cast<const char*>(blob), static_cast<const char*>(blob) + blobSize);
        } else {
            // std::cerr << "No image found with id: " << imageId << std::endl;
            sqlite3_finalize(stmt);
            return false;
        }
        sqlite3_finalize(stmt);
    } else {
        // std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}

bool ThumbnailCache::insertImageData(const std::string &filename, FileType fileType, const std::vector<uint8_t> &imageBuffer)
{
    std::string sql = "INSERT INTO images (image_name, image_data, image_type) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(m_database, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, filename.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_blob(stmt, 2, imageBuffer.data(), imageBuffer.size(), SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, Utils::typeToText(fileType).c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            sqlite3_finalize(stmt);
        }
        sqlite3_finalize(stmt);
    }

    return true;
}

bool ThumbnailCache::createTable()
{
    char* errMsg = nullptr;
    const char* sql = "CREATE TABLE IF NOT EXISTS images (id INTEGER PRIMARY KEY, image_name TEXT, image_data BLOB, image_type TEXT);";
    if (sqlite3_exec(m_database, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        // std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
