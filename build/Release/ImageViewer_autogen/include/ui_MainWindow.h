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
#include <QtWidgets/QTabWidget>
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
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btn_rotate;
    QPushButton *btn_fullScreen;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_min;
    QPushButton *btn_max;
    QPushButton *btn_close;
    QWidget *mainArea;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QPlainTextEdit *plainTextEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_8;
    CustomOpenGLWidget *openGLWidget_1_1;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_9;
    CustomOpenGLWidget *openGLWidget_2_1;
    CustomOpenGLWidget *openGLWidget_2_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    CustomOpenGLWidget *openGLWidget_3_1;
    CustomOpenGLWidget *openGLWidget_3_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_7;
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
    QLabel *label_3;
    QPushButton *btn_imageList;
    QPushButton *btn_imageInfo;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_dimensions;
    QLabel *label_6;
    QLabel *label_size;

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
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        headBar = new QWidget(centralwidget);
        headBar->setObjectName("headBar");
        headBar->setMaximumSize(QSize(16777215, 30));
        headBar->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 700 12pt \"Microsoft YaHei UI\";\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
""));
        horizontalLayout_2 = new QHBoxLayout(headBar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(headBar);
        widget_6->setObjectName("widget_6");
        widget_6->setMinimumSize(QSize(0, 0));
        horizontalLayout_10 = new QHBoxLayout(widget_6);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        btn_rotate = new QPushButton(widget_6);
        btn_rotate->setObjectName("btn_rotate");
        btn_rotate->setMinimumSize(QSize(30, 30));
        btn_rotate->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_rotate->setIcon(icon);
        btn_rotate->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(btn_rotate);

        btn_fullScreen = new QPushButton(widget_6);
        btn_fullScreen->setObjectName("btn_fullScreen");
        btn_fullScreen->setMinimumSize(QSize(30, 30));
        btn_fullScreen->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/full.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fullScreen->setIcon(icon1);
        btn_fullScreen->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(btn_fullScreen);

        btn_delete = new QPushButton(widget_6);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setMinimumSize(QSize(30, 30));
        btn_delete->setMaximumSize(QSize(30, 30));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_delete->setIcon(icon2);
        btn_delete->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(btn_delete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        horizontalLayout_2->addWidget(widget_6);

        widget_8 = new QWidget(headBar);
        widget_8->setObjectName("widget_8");
        horizontalLayout_12 = new QHBoxLayout(widget_8);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        label_name = new QLabel(widget_8);
        label_name->setObjectName("label_name");

        horizontalLayout->addWidget(label_name);


        horizontalLayout_12->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(widget_8);

        widget_7 = new QWidget(headBar);
        widget_7->setObjectName("widget_7");
        widget_7->setMinimumSize(QSize(0, 0));
        horizontalLayout_11 = new QHBoxLayout(widget_7);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);

        btn_min = new QPushButton(widget_7);
        btn_min->setObjectName("btn_min");
        btn_min->setEnabled(true);
        btn_min->setMinimumSize(QSize(50, 30));
        btn_min->setMaximumSize(QSize(50, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/min.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_min->setIcon(icon3);

        horizontalLayout_11->addWidget(btn_min);

        btn_max = new QPushButton(widget_7);
        btn_max->setObjectName("btn_max");
        btn_max->setMinimumSize(QSize(50, 30));
        btn_max->setMaximumSize(QSize(50, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_max->setIcon(icon4);

        horizontalLayout_11->addWidget(btn_max);

        btn_close = new QPushButton(widget_7);
        btn_close->setObjectName("btn_close");
        btn_close->setMinimumSize(QSize(50, 30));
        btn_close->setMaximumSize(QSize(50, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_close->setIcon(icon5);

        horizontalLayout_11->addWidget(btn_close);


        horizontalLayout_2->addWidget(widget_7);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addWidget(headBar);

        mainArea = new QWidget(centralwidget);
        mainArea->setObjectName("mainArea");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mainArea->sizePolicy().hasHeightForWidth());
        mainArea->setSizePolicy(sizePolicy2);
        horizontalLayout_4 = new QHBoxLayout(mainArea);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(mainArea);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(260, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(widget_2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setMaximumSize(QSize(250, 16777215));
        plainTextEdit->setUndoRedoEnabled(false);
        plainTextEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(plainTextEdit);


        horizontalLayout_4->addWidget(widget_2);

        tabWidget = new QTabWidget(mainArea);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_8 = new QHBoxLayout(tab);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        openGLWidget_1_1 = new CustomOpenGLWidget(tab);
        openGLWidget_1_1->setObjectName("openGLWidget_1_1");
        openGLWidget_1_1->setMinimumSize(QSize(0, 0));

        horizontalLayout_8->addWidget(openGLWidget_1_1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_9 = new QHBoxLayout(tab_2);
        horizontalLayout_9->setSpacing(10);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        openGLWidget_2_1 = new CustomOpenGLWidget(tab_2);
        openGLWidget_2_1->setObjectName("openGLWidget_2_1");

        horizontalLayout_9->addWidget(openGLWidget_2_1);

        openGLWidget_2_2 = new CustomOpenGLWidget(tab_2);
        openGLWidget_2_2->setObjectName("openGLWidget_2_2");

        horizontalLayout_9->addWidget(openGLWidget_2_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        openGLWidget_3_1 = new CustomOpenGLWidget(tab_3);
        openGLWidget_3_1->setObjectName("openGLWidget_3_1");

        verticalLayout_3->addWidget(openGLWidget_3_1);

        openGLWidget_3_2 = new CustomOpenGLWidget(tab_3);
        openGLWidget_3_2->setObjectName("openGLWidget_3_2");

        verticalLayout_3->addWidget(openGLWidget_3_2);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_4->addWidget(tabWidget);

        widget_4 = new QWidget(mainArea);
        widget_4->setObjectName("widget_4");
        widget_4->setMaximumSize(QSize(210, 16777215));
        horizontalLayout_7 = new QHBoxLayout(widget_4);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(widget_4);
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
        cBox_typeJpg->setChecked(true);

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


        horizontalLayout_7->addWidget(widget);


        horizontalLayout_4->addWidget(widget_4);


        verticalLayout->addWidget(mainArea);

        bottomArea = new QWidget(centralwidget);
        bottomArea->setObjectName("bottomArea");
        bottomArea->setStyleSheet(QString::fromUtf8("* {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
"\n"
"#bottomArea {\n"
"	border: 0px solid;\n"
"	background-color: rgba(50, 50, 50, 50);\n"
"}\n"
""));
        horizontalLayout_5 = new QHBoxLayout(bottomArea);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        bottomBar = new QWidget(bottomArea);
        bottomBar->setObjectName("bottomBar");
        bottomBar->setStyleSheet(QString::fromUtf8("* {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(bottomBar);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btn_zoomOut = new QPushButton(bottomBar);
        btn_zoomOut->setObjectName("btn_zoomOut");
        btn_zoomOut->setMinimumSize(QSize(30, 30));
        btn_zoomOut->setMaximumSize(QSize(30, 30));
        btn_zoomOut->setStyleSheet(QString::fromUtf8(""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/smaller.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoomOut->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/bigger.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_zoomIn->setIcon(icon7);
        btn_zoomIn->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_zoomIn);

        btn_prev = new QPushButton(bottomBar);
        btn_prev->setObjectName("btn_prev");
        btn_prev->setMinimumSize(QSize(30, 30));
        btn_prev->setMaximumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_prev->setIcon(icon8);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next->setIcon(icon9);
        btn_next->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(btn_next);

        label_3 = new QLabel(bottomBar);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        btn_imageList = new QPushButton(bottomBar);
        btn_imageList->setObjectName("btn_imageList");
        btn_imageList->setMinimumSize(QSize(30, 30));
        btn_imageList->setMaximumSize(QSize(30, 30));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/list.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_imageList->setIcon(icon10);
        btn_imageList->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_imageList);

        btn_imageInfo = new QPushButton(bottomBar);
        btn_imageInfo->setObjectName("btn_imageInfo");
        btn_imageInfo->setMinimumSize(QSize(30, 30));
        btn_imageInfo->setMaximumSize(QSize(30, 30));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_imageInfo->setIcon(icon11);
        btn_imageInfo->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btn_imageInfo);


        horizontalLayout_5->addWidget(bottomBar);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        label_dimensions = new QLabel(bottomArea);
        label_dimensions->setObjectName("label_dimensions");

        horizontalLayout_5->addWidget(label_dimensions);

        label_6 = new QLabel(bottomArea);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        label_size = new QLabel(bottomArea);
        label_size->setObjectName("label_size");

        horizontalLayout_5->addWidget(label_size);


        verticalLayout->addWidget(bottomArea);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 20);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_rotate->setText(QString());
        btn_fullScreen->setText(QString());
        btn_delete->setText(QString());
        label_name->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_min->setText(QString());
        btn_max->setText(QString());
        btn_close->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
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
        label_3->setText(QCoreApplication::translate("MainWindow", " | ", nullptr));
        btn_imageList->setText(QString());
        btn_imageInfo->setText(QString());
        label_dimensions->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " | ", nullptr));
        label_size->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
