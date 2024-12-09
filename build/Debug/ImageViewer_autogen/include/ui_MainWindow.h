/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *headBar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLabel *label_5;
    QLabel *label_dimensions;
    QLabel *label_6;
    QLabel *label_size;
    QSpacerItem *horizontalSpacer_2;
    QWidget *mainArea;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *plainTextEdit;
    CustomOpenGLWidget *openGLWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *cBox_typeJpg;
    QCheckBox *cBox_typePng;
    QCheckBox *cBox_typeHeic;
    QCheckBox *cBox_typeRaw;
    QListWidget *listWidget;
    QWidget *bottomArea;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QWidget *bottomBar;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_zoomOut;
    QLabel *label_zoomPercent;
    QPushButton *btn_zoomIn;
    QPushButton *btn_prev;
    QLabel *label_imageIndex;
    QPushButton *btn_next;
    QPushButton *btn_fullScreen;
    QPushButton *btn_rotate;
    QPushButton *btn_delete;
    QLabel *label_3;
    QPushButton *btn_imageList;
    QPushButton *btn_imageInfo;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1034, 807);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        headBar = new QWidget(centralwidget);
        headBar->setObjectName("headBar");
        headBar->setStyleSheet(QString::fromUtf8("#headBar {\n"
"	background-color: rgba(50, 50, 50, 50);\n"
"}\n"
"\n"
"QLabel {\n"
"	font: 700 12pt \"Microsoft YaHei UI\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(headBar);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_name = new QLabel(headBar);
        label_name->setObjectName("label_name");

        horizontalLayout->addWidget(label_name);

        label_5 = new QLabel(headBar);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        label_dimensions = new QLabel(headBar);
        label_dimensions->setObjectName("label_dimensions");

        horizontalLayout->addWidget(label_dimensions);

        label_6 = new QLabel(headBar);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        label_size = new QLabel(headBar);
        label_size->setObjectName("label_size");

        horizontalLayout->addWidget(label_size);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(headBar);

        mainArea = new QWidget(centralwidget);
        mainArea->setObjectName("mainArea");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mainArea->sizePolicy().hasHeightForWidth());
        mainArea->setSizePolicy(sizePolicy2);
        horizontalLayout_4 = new QHBoxLayout(mainArea);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        plainTextEdit = new QPlainTextEdit(mainArea);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setMaximumSize(QSize(250, 16777215));
        plainTextEdit->setUndoRedoEnabled(false);
        plainTextEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(plainTextEdit);

        openGLWidget = new CustomOpenGLWidget(mainArea);
        openGLWidget->setObjectName("openGLWidget");

        horizontalLayout_4->addWidget(openGLWidget);

        widget = new QWidget(mainArea);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(200, 16777215));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        cBox_typeJpg = new QCheckBox(groupBox);
        cBox_typeJpg->setObjectName("cBox_typeJpg");

        gridLayout->addWidget(cBox_typeJpg, 0, 0, 1, 1);

        cBox_typePng = new QCheckBox(groupBox);
        cBox_typePng->setObjectName("cBox_typePng");

        gridLayout->addWidget(cBox_typePng, 0, 1, 1, 1);

        cBox_typeHeic = new QCheckBox(groupBox);
        cBox_typeHeic->setObjectName("cBox_typeHeic");

        gridLayout->addWidget(cBox_typeHeic, 1, 0, 1, 1);

        cBox_typeRaw = new QCheckBox(groupBox);
        cBox_typeRaw->setObjectName("cBox_typeRaw");

        gridLayout->addWidget(cBox_typeRaw, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout_4->addWidget(widget);


        verticalLayout->addWidget(mainArea);

        bottomArea = new QWidget(centralwidget);
        bottomArea->setObjectName("bottomArea");
        horizontalLayout_5 = new QHBoxLayout(bottomArea);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        bottomBar = new QWidget(bottomArea);
        bottomBar->setObjectName("bottomBar");
        bottomBar->setStyleSheet(QString::fromUtf8("* {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"#bottomBar {\n"
"	border: 0px solid;\n"
"	border-radius: 10px;\n"
"	background-color: rgba(50, 50, 50, 50);\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(bottomBar);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btn_zoomOut = new QPushButton(bottomBar);
        btn_zoomOut->setObjectName("btn_zoomOut");
        btn_zoomOut->setMinimumSize(QSize(30, 30));
        btn_zoomOut->setMaximumSize(QSize(30, 30));
        btn_zoomOut->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/smaller.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoomOut->setIcon(icon);
        btn_zoomOut->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_zoomOut);

        label_zoomPercent = new QLabel(bottomBar);
        label_zoomPercent->setObjectName("label_zoomPercent");
        label_zoomPercent->setMinimumSize(QSize(40, 0));

        horizontalLayout_3->addWidget(label_zoomPercent);

        btn_zoomIn = new QPushButton(bottomBar);
        btn_zoomIn->setObjectName("btn_zoomIn");
        btn_zoomIn->setMinimumSize(QSize(30, 30));
        btn_zoomIn->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/bigger.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoomIn->setIcon(icon1);
        btn_zoomIn->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_zoomIn);

        btn_prev = new QPushButton(bottomBar);
        btn_prev->setObjectName("btn_prev");
        btn_prev->setMinimumSize(QSize(30, 30));
        btn_prev->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_prev->setIcon(icon2);
        btn_prev->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btn_prev);

        label_imageIndex = new QLabel(bottomBar);
        label_imageIndex->setObjectName("label_imageIndex");
        label_imageIndex->setMinimumSize(QSize(50, 0));

        horizontalLayout_3->addWidget(label_imageIndex);

        btn_next = new QPushButton(bottomBar);
        btn_next->setObjectName("btn_next");
        btn_next->setMinimumSize(QSize(30, 30));
        btn_next->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon3);
        btn_next->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btn_next);

        btn_fullScreen = new QPushButton(bottomBar);
        btn_fullScreen->setObjectName("btn_fullScreen");
        btn_fullScreen->setMinimumSize(QSize(30, 30));
        btn_fullScreen->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/full.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fullScreen->setIcon(icon4);
        btn_fullScreen->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_fullScreen);

        btn_rotate = new QPushButton(bottomBar);
        btn_rotate->setObjectName("btn_rotate");
        btn_rotate->setMinimumSize(QSize(30, 30));
        btn_rotate->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_rotate->setIcon(icon5);
        btn_rotate->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_rotate);

        btn_delete = new QPushButton(bottomBar);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setMinimumSize(QSize(30, 30));
        btn_delete->setMaximumSize(QSize(30, 30));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_delete->setIcon(icon6);
        btn_delete->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_delete);

        label_3 = new QLabel(bottomBar);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        btn_imageList = new QPushButton(bottomBar);
        btn_imageList->setObjectName("btn_imageList");
        btn_imageList->setMinimumSize(QSize(30, 30));
        btn_imageList->setMaximumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_imageList->setIcon(icon7);
        btn_imageList->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_imageList);

        btn_imageInfo = new QPushButton(bottomBar);
        btn_imageInfo->setObjectName("btn_imageInfo");
        btn_imageInfo->setMinimumSize(QSize(30, 30));
        btn_imageInfo->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_imageInfo->setIcon(icon8);
        btn_imageInfo->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_imageInfo);


        horizontalLayout_5->addWidget(bottomBar);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(bottomArea);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " | ", nullptr));
        label_dimensions->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " | ", nullptr));
        label_size->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\347\261\273\345\236\213", nullptr));
        cBox_typeJpg->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        cBox_typePng->setText(QCoreApplication::translate("MainWindow", "PNG", nullptr));
        cBox_typeHeic->setText(QCoreApplication::translate("MainWindow", "HEIC", nullptr));
        cBox_typeRaw->setText(QCoreApplication::translate("MainWindow", "RAW", nullptr));
        btn_zoomOut->setText(QString());
        label_zoomPercent->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        btn_zoomIn->setText(QString());
        btn_prev->setText(QString());
        label_imageIndex->setText(QCoreApplication::translate("MainWindow", "1/100", nullptr));
        btn_next->setText(QString());
        btn_fullScreen->setText(QString());
        btn_rotate->setText(QString());
        btn_delete->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", " | ", nullptr));
        btn_imageList->setText(QString());
        btn_imageInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
