#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "CustomOpenGLWidget.h"
#include "Utils.h"

#include <list>
#include <filesystem>
namespace fs = std::filesystem;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const std::string& url, QWidget *parent = nullptr);
    ~MainWindow();

private:
    ImageFile loadImage(const std::string& filename);
    void displayImage(const ImageFile& imageFile);
    void getAllFile();
    void updateFileList();

signals:
    void sig_showImage(std::shared_ptr<ImageData>& imageData, int orientation);

private:
    Ui::MainWindow *ui;

    int m_currIndex;
    ImageFile m_currImageFile;
    std::string m_currDir;      // 当前工作目录
    std::list<ImageFile> m_allFiles;      // 当前目录下的所有文件
    std::list<ImageFile> m_displayFiles;   // 要显示在UI界面中的文件列表

    QListWidgetItem* m_lastSelectedItem = nullptr;
};
#endif // MAINWINDOW_H
