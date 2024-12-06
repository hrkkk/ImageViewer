#include "CustomOpenGLWidget.h"
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent): QOpenGLWidget(parent) {}

void CustomOpenGLWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton) {
        emit sign_mouseClicked(event->globalPosition().x(), event->globalPosition().y());
    }
}

void CustomOpenGLWidget::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() > 10) {
        if (m_scaleRatio == 0.01) {
            m_scaleRatio = 0.1;     // 凑整，避免从1%变成11%
        } else {
            m_scaleRatio += 0.1;
        }
        if (m_scaleRatio >= 10.0) {     // 最大可放大至1000%
            m_scaleRatio = 10.0;
        }
    } else {
        m_scaleRatio -= 0.1;
        if (m_scaleRatio <= 0.01) {     // 最小可缩小至1%
            m_scaleRatio = 0.01;
        }
    }
    resizeGL(width(), height());
    emit sign_scaleChanged(m_scaleRatio);
}

#define GET_GLSTR(x) #x
const char* vsrc = GET_GLSTR(
    attribute vec4 inPosition;
    attribute vec2 inTexCoord;

    uniform int rotation;

    varying vec2 texCoord;

    void main(void)
    {
        gl_Position = inPosition;

        // 根据旋转角度变换纹理坐标
        vec2 rotatedTexCoords;
        if (rotation == 1) {    // 顺时针旋转90°，将纹理坐标的x和y坐标交换，然后将x坐标取反
            rotatedTexCoords = vec2(1.0 - inTexCoord.y, inTexCoord.x);
        } else if (rotation == 2) {     // 顺时针旋转180°，将纹理坐标的x和y坐标取反
            rotatedTexCoords = vec2(1.0 - inTexCoord.x, 1.0 - inTexCoord.y);
        } else if (rotation == 3) {     // 顺时针旋转270°（即逆时针旋转90°），将纹理坐标的x和y坐标交换，然后将y坐标取反
            rotatedTexCoords = vec2(inTexCoord.y, 1.0 - inTexCoord.x);
        } else {     // 旋转0°，即默认情况，不旋转
            rotatedTexCoords = inTexCoord;
        }

        texCoord = vec2(rotatedTexCoords.x, 1.0 - rotatedTexCoords.y);
    }
);

const char* fsrc = GET_GLSTR(
    varying vec2 texCoord;
    uniform sampler2D tex;

    void main(void)
    {
        gl_FragColor = texture2D(tex, texCoord);
    }
);

void CustomOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);

    static const GLfloat vertices[] {
        // 顶点坐标
        -1.0f, -1.0f,
        -1.0f, +1.0f,
        +1.0f, +1.0f,
        +1.0f, -1.0f,
        // 纹理坐标
        0.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)(8 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);

    // 创建着色器程序
    program = glCreateProgram();
    // 读取顶点着色器代码
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vsrc, nullptr);
    glCompileShader(vertexShader);
    // 读取片段着色器代码
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fsrc, nullptr);
    glCompileShader(fragmentShader);
    // 绑定代码，编译链接
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glValidateProgram(program);
    glUseProgram(program);

    glBindAttribLocation(program, 0, "inPosition");
    glBindAttribLocation(program, 1, "inTexCoord");

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glClearColor(1.0, 1.0, 1.0, 0.0);
}

void CustomOpenGLWidget::resizeGL(int w, int h)
{
    double ratio = devicePixelRatio();
    // 计算窗口的实际尺寸
    int windowWidth = w * ratio;
    int windowHeight = h * ratio;
    // 计算宽度的缩放比例
    double scaleWidth = (double)windowWidth / m_imageWidth;
    // 计算高度的缩放比例
    double scaleHeight = (double)windowHeight / m_imageHeight;
    // 选取较小的缩放比例以保证图片完整的显示在窗口中，同时不改变图片的宽高比
    double scale = std::min(scaleWidth, scaleHeight);
    // 计算缩放后的图像尺寸
    m_viewportWidth = m_imageWidth * scale * m_scaleRatio;
    m_viewportHeight = m_imageHeight * scale * m_scaleRatio;

    // double imageRatio = (double)m_imageWidth / m_imageHeight;
    // if (imageRatio <= 1.0) {
    //     m_viewportHeight = windowHeight;
    //     m_viewportWidth = windowHeight * imageRatio;
    // } else {
    //     m_viewportWidth = windowWidth;
    //     m_viewportHeight = windowWidth / imageRatio;
    // }

    // 计算图像在窗口中的显示位置
    m_horizontalOffset = (windowWidth - m_viewportWidth) / 2;
    m_verticalOffset = (windowHeight - m_viewportHeight) / 2;

    update();
}

void CustomOpenGLWidget::paintGL()
{
    glViewport(m_horizontalOffset, m_verticalOffset, m_viewportWidth, m_viewportHeight);

    glBindTexture(GL_TEXTURE_2D, texture);

    if (m_imageChannels == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_imageWidth, m_imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_imageData);
    } else if (m_imageChannels == 4){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_imageWidth, m_imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_imageData);
    }

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void CustomOpenGLWidget::slot_showImage(uint8_t* data, uint width, uint height, uint channels)
{
    m_imageData = data;
    m_imageWidth = width;
    m_imageHeight = height;
    m_imageChannels = channels;

    slot_resizeViewport();
    update();
}

void CustomOpenGLWidget::slot_resizeViewport()
{
    resizeGL(width(), height());
}

void CustomOpenGLWidget::slot_changeScale(int flag)
{
    if (flag == 1) {    // 放大
        if (m_scaleRatio == 0.01) {
            m_scaleRatio = 0.1;     // 凑整，避免从1%变成11%
        } else {
            m_scaleRatio += 0.1;
        }
        if (m_scaleRatio >= 10.0) {     // 最大可放大至1000%
            m_scaleRatio = 10.0;
        }
    } else {    // 缩小
        m_scaleRatio -= 0.1;
        if (m_scaleRatio <= 0.01) {     // 最小可缩小至1%
            m_scaleRatio = 0.01;
        }
    }
    resizeGL(width(), height());
    emit sign_scaleChanged(m_scaleRatio);
}
