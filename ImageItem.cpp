#include "ImageItem.h"

#include <QLabel>

ImageItem::ImageItem(const QString& title, QWidget *parent)
    : m_title(title), QWidget{parent}
{
    QLabel* imageLabel = new QLabel(this);
    imageLabel->setText(m_title);
}
