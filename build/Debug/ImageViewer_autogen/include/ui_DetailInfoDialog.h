/********************************************************************************
** Form generated from reading UI file 'DetailInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILINFODIALOG_H
#define UI_DETAILINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetailInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QDialog *DetailInfoDialog)
    {
        if (DetailInfoDialog->objectName().isEmpty())
            DetailInfoDialog->setObjectName("DetailInfoDialog");
        DetailInfoDialog->resize(553, 386);
        verticalLayout = new QVBoxLayout(DetailInfoDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_3 = new QPushButton(DetailInfoDialog);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(DetailInfoDialog);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(DetailInfoDialog);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(DetailInfoDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(DetailInfoDialog);

        QMetaObject::connectSlotsByName(DetailInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailInfoDialog)
    {
        DetailInfoDialog->setWindowTitle(QCoreApplication::translate("DetailInfoDialog", "Dialog", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DetailInfoDialog", "File Info", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DetailInfoDialog", "EXIF", nullptr));
        pushButton->setText(QCoreApplication::translate("DetailInfoDialog", "TIFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetailInfoDialog: public Ui_DetailInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILINFODIALOG_H
