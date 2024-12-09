#ifndef CUSTOMOPENGLWIDGET_H
#define CUSTOMOPENGLWIDGET_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QtOpenGLWidgets/QOpenGLWidget>

class CustomOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions
{
    Q_OBJECT
public:
    CustomOpenGLWidget(QWidget* parent = nullptr);

signals:
    void sign_mouseClicked(int x, int y);
    void sign_scaleChanged(double scale);

public slots:
    void slot_showImage(uint8_t* data, uint width, uint height, uint channels, int orientation);
    void slot_resizeViewport();
    void slot_changeScale(int flag);
    void slot_rotateImage();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    unsigned int program;
    unsigned int vao;
    unsigned int vbo;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int texture;

    // 显示窗口
    int m_viewportWidth, m_viewportHeight;
    int m_horizontalOffset, m_verticalOffset;
    double m_scaleRatio = 1.0;
    int m_orientation = 1;
    bool m_isRotated = false;

    // 图像数据
    uint8_t* m_imageData;
    uint m_imageWidth;
    uint m_imageHeight;
    uint m_imageChannels;
};

#endif // CUSTOMOPENGLWIDGET_H
