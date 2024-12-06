#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QVBoxLayout>
#include "DetailInfoDialog.h"
#include "ImageItem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class FileType {
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
    void getFileList();

signals:
    void sig_showImage(uint8_t* data, uint width, uint height, uint channels);

private:
    Ui::MainWindow *ui;
    DetailInfoDialog* m_detailInfoDialog;
    QString m_url;
    uint8_t* m_data = nullptr;
    QFileInfo m_file;
    int m_currIndex;
    QStringList m_fileList;     // 当前目录下的所有图片名

    QString m_currDir;      // 当前工作目录
};
#endif // MAINWINDOW_H
