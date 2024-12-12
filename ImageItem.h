#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

#include "Utils.h"

class ImageItem : public QLabel
{
    Q_OBJECT
public:
    explicit ImageItem(const ImageFile& imageFile, QWidget *parent = nullptr);

    void setChecked(bool isChecked);
    void setSelected(bool isSelected);

    std::string getFilepath() const {
        return m_filepath;
    }

signals:

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    std::string m_filepath;
    FileType m_fileType;
    QPixmap m_image;
    bool m_isChecked;
    bool m_isSelected;
};

#endif // IMAGEITEM_H
