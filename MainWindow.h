#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QVBoxLayout>
#include "DetailInfoDialog.h"
#include "CustomOpenGLWidget.h"
#include "ImageItem.h"
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

    int m_currIndex;

    QFileInfo m_currFileInfo;   // 当前显示的文件信息
    QString m_currFilename;     // 当前显示的文件名
    QString m_currDir;      // 当前工作目录
    std::list<std::pair<fs::path, FileType>> m_allFiles;      // 当前目录下的所有文件
    std::list<fs::path> m_displayFiles;   // 要显示在UI界面中的文件列表
};
#endif // MAINWINDOW_H
