#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class ImageItem : public QLabel
{
    Q_OBJECT
public:
    explicit ImageItem(const QPixmap& image, QWidget *parent = nullptr);

    void setChecked(bool isChecked);

signals:

private:
    QPixmap m_image;
};

#endif // IMAGEITEM_H
