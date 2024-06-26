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
    QStringList m_fileList;
    QVBoxLayout* m_listLayout = nullptr;
};
#endif // MAINWINDOW_H
