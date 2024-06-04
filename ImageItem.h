#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QObject>
#include <QWidget>

class ImageItem : public QWidget
{
    Q_OBJECT
public:
    explicit ImageItem(const QString& title, QWidget *parent = nullptr);

signals:

private:
    QString m_title;
};

#endif // IMAGEITEM_H
