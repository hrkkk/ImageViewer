#include "ImageItem.h"

#include <QLabel>
#include <QPainter>

#include "ThumbnailCache.h"

ImageItem::ImageItem(const ImageFile& imageFile, QWidget *parent)
    : QLabel{parent}, m_filepath(imageFile.filePath), m_fileType(imageFile.fileType), m_isChecked(false), m_isSelected(false)
{
    this->setFixedSize(QSize(96, 64));

    std::vector<uint8_t> imageBuffer;
    ThumbnailCache::getInstance().getThumbnail(m_filepath, m_fileType, imageBuffer);

    QImage img(imageBuffer.data(), 64, 64, QImage::Format_RGB888);
    m_image = QPixmap::fromImage(img);
}

void ImageItem::setChecked(bool isChecked)
{
    m_isChecked = isChecked;
    update();
}

void ImageItem::setSelected(bool isSelected)
{
    m_isSelected = isSelected;
    update();
}

void ImageItem::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    int radius = 10; // 设置圆角的半径

    if (m_isChecked) {
        // 绘制高亮边框
        QPen pen(Qt::blue, 3); // 设置颜色和边框宽度
        painter.setPen(pen);
        painter.drawRoundedRect(this->rect().adjusted(1, 1, -1, -1), radius, radius); // 绘制边框，留出1像素的边距
    }

    // 绘制矩形
    painter.setOpacity(0.5); // 设置局部透明度为50%
    painter.setBrush(Qt::gray);
    painter.drawRoundedRect(this->rect(), radius, radius); // 绘制圆角矩形;
    painter.drawPixmap(QPoint(0, 0), m_image); // 在(0,0)位置绘制图像

    // // 绘制按钮
    // QRectF checkboxRect(10, 10, 20, 20); // 单选框的位置和大小
    // QBrush brush(Qt::transparent); // 设置半透明
    // QPen pen(Qt::white, 2); // 设置边框
    // painter.setBrush(brush);
    // painter.setPen(pen);
    // painter.drawRoundedRect(checkboxRect, 3, 3); // 绘制圆角矩形作为单选框

    // // 如果需要，可以添加选中状态的填充
    // if (m_isSelected) {
    //     painter.setBrush(Qt::blue); // 设置填充颜色
    //     painter.drawEllipse(checkboxRect); // 绘制填充的圆形表示选中状态
    // }
}

void ImageItem::mousePressEvent(QMouseEvent* event)
{
    // if (event->button() == Qt::LeftButton) {
    //     float x = event->pos().x();
    //     float y = event->pos().y();
    //     if (x >= 10 && x <= 30 && y >= 10 && y <= 30) {
    //         setSelected(true);
    //     } else {
    //         setChecked(true);
    //     }
    //     update();
    // }
}
