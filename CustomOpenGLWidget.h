#ifndef CUSTOMOPENGLWIDGET_H
#define CUSTOMOPENGLWIDGET_H

#include <QObject>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QtOpenGLWidgets/QOpenGLWidget>

#include <QDebug>

struct ImageData {
    uint8_t* pixels;
    uint width;
    uint height;
    uint channels;

    ImageData(int w, int h, int ch) : width(w), height(h), channels(ch) {
        pixels = new uint8_t[w * h * ch];
        // qDebug() << "create" << width << "x" << height << "x" << channels;
    }

    ~ImageData() {
        delete[] pixels;
        // qDebug() << "release" << width << "x" << height << "x" << channels;
    }
};


class CustomOpenGLWidget : public QOpenGLWidget, QOpenGLFunctions
{
    Q_OBJECT
public:
    CustomOpenGLWidget(QWidget* parent = nullptr);

signals:
    void sign_mouseClicked(int x, int y);
    void sign_scaleChanged(double scale);

public slots:
    void slot_showImage(std::shared_ptr<ImageData>& data, int orientation);
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
    std::shared_ptr<ImageData> m_image;
};

#endif // CUSTOMOPENGLWIDGET_H
