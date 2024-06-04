#include "ImageItem.h"

#include <QLabel>

ImageItem::ImageItem(const QPixmap& image, QWidget *parent)
    : QWidget{parent}, m_image(image)
{
    QLabel* imageLabel = new QLabel(this);
    this->setFixedSize(QSize(100, 100));
    imageLabel->setFixedSize(QSize(100, 100));
    imageLabel->setPixmap(m_image);

    this->setStyleSheet("border:1px solid #000; border-radius:5px;");
}

void ImageItem::setChecked(bool isChecked)
{
    if (isChecked) {
        this->setStyleSheet("border:1px solid #0F0; border-radius:5px;");
    } else {
        this->setStyleSheet("border:1px solid #000; border-radius:5px;");
    }
}
