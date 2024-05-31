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

public slots:
    void slot_showImage(uint8_t* data, uint width, uint height);
    void slot_resizeViewport();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    unsigned int program;
    unsigned int vao;
    unsigned int vbo;
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int texture;

    uint videoWidth, videoHeight;
    int viewportWidth, viewportHeight;
    int startX, startY;

    uint8_t* data;
};

#endif // CUSTOMOPENGLWIDGET_H
