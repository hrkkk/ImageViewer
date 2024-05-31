#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "libheif/heif.h"
#include <QFileInfo>

MainWindow::MainWindow(QString url, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_url(url)
{
    ui->setupUi(this);

    this->showMaximized();
    ui->widget_info->hide();
    ui->scrollArea->hide();

    connect(ui->btn_imageList, &QPushButton::clicked, this, [this]() {
        ui->scrollArea->setVisible(!ui->scrollArea->isVisible());
    });
    connect(ui->btn_imageInfo, &QPushButton::clicked, this, [this]() {
        ui->widget_info->setVisible(!ui->widget_info->isVisible());
    });

    connect(this, &MainWindow::sig_showImage, ui->openGLWidget, &CustomOpenGLWidget::slot_showImage);


    QFileInfo fileInfo(m_url);

    heif_context* ctx = heif_context_alloc();
    heif_context_read_from_file(ctx, m_url.toStdString().c_str(), nullptr);

    heif_image_handle* handle;
    heif_context_get_primary_image_handle(ctx, &handle);

    heif_image* img;
    heif_decode_image(handle, &img, heif_colorspace_RGB, heif_chroma_interleaved_RGB, nullptr);

    int stride;
    const uint8_t* data = heif_image_get_plane_readonly(img, heif_channel_interleaved, &stride);
    int width = heif_image_get_width(img, heif_channel_interleaved);
    int height = heif_image_get_height(img, heif_channel_interleaved);

    emit sig_showImage(const_cast<uint8_t*>(data), width, height);

    ui->label_name->setText(fileInfo.fileName());
    ui->label_dimensions->setText(QString("%1x%2").arg(width).arg(height));
    ui->label_size->setText(QString("%1B").arg(fileInfo.size()));

    // 释放资源
    heif_image_release(img);
    heif_image_handle_release(handle);
    heif_context_free(ctx);
}

MainWindow::~MainWindow()
{
    delete ui;
}
