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
        // YUV 转 RGB
        vec3 rgb;
        rgb = texture2D(tex, texCoord.st);

        // 把颜色值赋值给像素
        gl_FragColor = vec4(rgb, 1.0f);
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

    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void CustomOpenGLWidget::resizeGL(int w, int h)
{
    // double ratio = devicePixelRatio();

    // if (ratioStatus == RENDER_RATIO::RATIO_1_1) {
    //     viewportHeight = h * ratio;
    //     viewportWidth = viewportHeight * renderRatio;
    //     startX = (w * ratio - viewportWidth) / 2;
    //     startY = 0;
    // } else {
    //     viewportWidth = w * ratio;
    //     viewportHeight = viewportWidth / renderRatio;
    //     startX = 0;
    //     startY = (h * ratio - viewportHeight) / 2;
    // }
}

void CustomOpenGLWidget::paintGL()
{
    // glViewport(startX, startY, viewportWidth, viewportHeight);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, videoWidth, videoHeight, 0, GL_RED, GL_UNSIGNED_BYTE, data);

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void CustomOpenGLWidget::slot_showImage(uint8_t* data, uint width, uint height)
{
    this->data = data;
    videoWidth = width;
    videoHeight = height;
    update();
}

void CustomOpenGLWidget::slot_resizeViewport()
{
    resizeGL(width(), height());
}
