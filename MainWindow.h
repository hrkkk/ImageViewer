#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

signals:
    void sig_showImage(uint8_t* data, uint width, uint height);

private:
    Ui::MainWindow *ui;
    QString m_url;
};
#endif // MAINWINDOW_H
