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
    MainWindow w("");
    w.show();
    return a.exec();
}
