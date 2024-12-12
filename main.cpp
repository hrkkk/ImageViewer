#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // if (argc == 1) {
    //     argv[1] = const_cast<char*>("H:\\DataCenter\\Photo\\#2 Photo\\other\\IMG_4802.HEIC");
    //     argc++;
    // }
    // if (argc == 2) {
    //     MainWindow w(argv[1]);
    //     w.show();
    //     return a.exec();
    // } else {
    //     return 0;
    // }
    MainWindow w("H:\\DataCenter\\Photo\\#2 Photo\\picture\\beautiful\\1aa7fff52e4c112.jpg");
    // 设置窗口无边框
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    w.show();
    return a.exec();
}
