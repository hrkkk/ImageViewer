#include "ImageItem.h"

#include <QLabel>

ImageItem::ImageItem(const QPixmap& image, QWidget *parent)
    : QLabel{parent}, m_image(image)
{
    this->setFixedSize(QSize(100, 100));
    this->setPixmap(m_image);
    this->setScaledContents(true);
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
