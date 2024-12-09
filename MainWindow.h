#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QVBoxLayout>
#include "DetailInfoDialog.h"
#include "CustomOpenGLWidget.h"
#include "ImageItem.h"

#include <filesystem>
namespace fs = std::filesystem;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class FileType {
    OTHER_FILE = 0x0000,
    HEIF_IMG = 0x0001,
    PNG_IMG = 0x0002,
    JPG_IMG = 0x0004,
    RAW_IMG = 0x0008,
    ALL_IMG = 0x000F
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString url, QWidget *parent = nullptr);
    ~MainWindow();

private:
    void loadImage(const std::string& filename);
    void getAllFile();
    void updateFileList();

signals:
    void sig_showImage(std::shared_ptr<ImageData>& imageData, int orientation);

private:
    Ui::MainWindow *ui;
    DetailInfoDialog* m_detailInfoDialog;
    QString m_url;
    QFileInfo m_file;
    int m_currIndex;
    QStringList m_fileList;     // 当前目录下的所有图片名

    QString m_currDir;      // 当前工作目录
    std::vector<std::pair<fs::path, FileType>> m_allFiles;
    std::vector<fs::path> m_displayFiles;
};
#endif // MAINWINDOW_H
