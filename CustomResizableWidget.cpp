#include "CustomResizableWidget.h"

#include <QDebug>

CustomResizableWidget::CustomResizableWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setStyleSheet("background-color:#000;");
}

void CustomResizableWidget::enterEvent(QEnterEvent* event)
{
    QWidget::enterEvent(event); // 调用基类的事件处理函数
    setCursor(Qt::SizeHorCursor);
}

void CustomResizableWidget::leaveEvent(QEvent* event)
{
    setCursor(Qt::ArrowCursor); // 设置鼠标样式为默认箭头
    QWidget::leaveEvent(event);
}

void CustomResizableWidget::mousePressEvent(QMouseEvent *event)
{

}

void CustomResizableWidget::mouseMoveEvent(QMouseEvent *event)
{

}

void CustomResizableWidget::mouseReleaseEvent(QMouseEvent *event)
{

}
