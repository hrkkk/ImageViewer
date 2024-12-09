#ifndef CUSTOMRESIZABLEWIDGET_H
#define CUSTOMRESIZABLEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>

class CustomResizableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomResizableWidget(QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
};


#endif // CUSTOMRESIZABLEWIDGET_H
