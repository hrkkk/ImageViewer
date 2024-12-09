#include "CustomOpenGLWidget.h"
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent): QOpenGLWidget(parent)
{}

float offsetX = 0.0f, offsetY = 0.0f;
float lastX = 0.0f, lastY = 0.0f;
bool isPressed = false;

void CustomOpenGLWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton) {
        emit sign_mouseClicked(event->globalPosition().x(), event->globalPosition().y());
    } else if (event->button() == Qt::LeftButton) {
        isPressed = true;
        lastX = offsetX = event->pos().x();
        lastY = offsetY = event->pos().y();
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

void CustomOpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isPressed) {
        offsetX += event->pos().x() - lastX;
        offsetY += event->pos().y() - lastY;
    }
    lastX = event->pos().x();
    lastY = event->pos().y();
    qDebug() << "move" << offsetX << offsetY;
}

void CustomOpenGLWidget::mouseReleaseEvent(QMouseEvent* event)
{
    isPressed = false;
}

#define GET_GLSTR(x) #x
const char* vsrc = GET_GLSTR(
    attribute vec4 inPosition;
    attribute vec2 inTexCoord;

    uniform int orientation;
    uniform float offsetX;
    uniform float offsetY;

    varying vec2 texCoord;

    void main(void)
    {
        gl_Position = inPosition + vec4(offsetX, offsetY, 0.0f, 0.0f);

        // 根据旋转角度变换纹理坐标
        vec2 rotatedTexCoords;
        switch (orientation) {
        case 1:
            rotatedTexCoords = inTexCoord;   // 不旋转
            break;
        case 2:
            rotatedTexCoords = vec2(1.0 - inTexCoord.x, inTexCoord.y);    // 水平翻转
            break;
        case 3:
            rotatedTexCoords = vec2(1.0 - inTexCoord.x, 1.0 - inTexCoord.y);  // 顺时针旋转180°
            break;
        case 4:
            rotatedTexCoords = vec2(inTexCoord.x, 1.0 - inTexCoord.y);    // 垂直翻转
            break;
        case 5:
            rotatedTexCoords = vec2(1.0 - inTexCoord.y, inTexCoord.x);    // 顺时针旋转90° + 水平翻转
            break;
        case 6:
            rotatedTexCoords = vec2(inTexCoord.y, inTexCoord.x);  // 顺时针旋转90°
            break;
        case 7:
            rotatedTexCoords = vec2(1.0 - inTexCoord.y, 1.0 - inTexCoord.x);  // 顺时针旋转90° + 垂直翻转
            break;
        case 8:
            rotatedTexCoords = vec2(inTexCoord.y, 1.0 - inTexCoord.x);    // 逆时针旋转90°
            break;
        default:
            rotatedTexCoords = inTexCoord;   // 不旋转
            break;
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
    if (m_image == nullptr) {
        return;
    }

    double ratio = devicePixelRatio();
    // 计算窗口的实际尺寸
    int windowWidth = w * ratio;
    int windowHeight = h * ratio;
    // 计算宽度的缩放比例
    double scaleWidth = (double)windowWidth / (m_isRotated ? m_image->height : m_image->width);
    // 计算高度的缩放比例
    double scaleHeight = (double)windowHeight / (m_isRotated ? m_image->width : m_image->height);
    // 选取较小的缩放比例以保证图片完整的显示在窗口中，同时不改变图片的宽高比
    double scale = std::min(scaleWidth, scaleHeight);
    // 计算缩放后的图像尺寸
    m_viewportWidth = (m_isRotated ? m_image->height : m_image->width) * scale * m_scaleRatio;
    m_viewportHeight = (m_isRotated ? m_image->width : m_image->height) * scale * m_scaleRatio;
    // 计算图像在窗口中的显示位置
    m_horizontalOffset = (windowWidth - m_viewportWidth) / 2;
    m_verticalOffset = (windowHeight - m_viewportHeight) / 2;

    update();
}

void CustomOpenGLWidget::paintGL()
{
    if (m_image == nullptr) {
        return;
    }

    glViewport(m_horizontalOffset, m_verticalOffset, m_viewportWidth, m_viewportHeight);

    glBindTexture(GL_TEXTURE_2D, texture);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if (m_image->channels == 3) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_image->width, m_image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_image->pixels);
    } else if (m_image->channels == 4){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_image->width, m_image->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image->pixels);
    }

    glUniform1i(glGetUniformLocation(program, "offsetX"), offsetX);
    glUniform1i(glGetUniformLocation(program, "offsetY"), offsetX);
    glUniform1i(glGetUniformLocation(program, "orientation"), m_orientation);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void CustomOpenGLWidget::slot_showImage(std::shared_ptr<ImageData>& imageData, int orientation)
{
    m_image = imageData;
    m_orientation = orientation;
    if (m_orientation >= 5 && m_orientation <= 8) {
        m_isRotated = true;
    } else {
        m_isRotated = false;
    }

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

void CustomOpenGLWidget::slot_rotateImage()
{
    m_orientation++;
    if (m_orientation > 8) {
        m_orientation = 1;
    }
    if (m_orientation >= 5 && m_orientation <= 8) {
        m_isRotated = true;
    } else {
        m_isRotated = false;
    }

    slot_resizeViewport();
    update();
}
