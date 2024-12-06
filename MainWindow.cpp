#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ImageReader.h"
#include <QFileInfo>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QString url, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_url(url)
{
    ui->setupUi(this);

    m_url = "F:\\DCIM\\100MSDCF\\DSC00985.JPG";
    m_currDir = "F:\\DCIM";
    m_file = QFileInfo(m_url);

    // 默认全屏显示
    this->showMaximized();
    // 默认隐藏侧边文件列表
    ui->widget->hide();

    connect(ui->btn_imageList, &QPushButton::clicked, this, [=]() {
        ui->widget->setVisible(!ui->widget->isVisible());
    });
    connect(ui->btn_imageInfo, &QPushButton::clicked, this, [=]() {

    });
    connect(ui->btn_prev, &QPushButton::clicked, this, [=]() {
        // ImageItem* item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        // item->setChecked(false);

        // if (m_currIndex <= 1) {
        //     m_currIndex = m_fileList.size();
        // } else {
        //     m_currIndex--;
        // }
        // m_file = QFileInfo(m_file.absolutePath() + "/" + m_fileList.at(m_currIndex - 1));
        // loadImage(m_file.absoluteFilePath().toStdString());

        // item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        // item->setChecked(true);
    });
    connect(ui->btn_next, &QPushButton::clicked, this, [=]() {
        // ImageItem* item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        // item->setChecked(false);

        // if (m_currIndex == m_fileList.size()) {
        //     m_currIndex = 1;
        // } else {
        //     m_currIndex++;
        // }
        // m_file = QFileInfo(m_file.absolutePath() + "/" + m_fileList.at(m_currIndex - 1));
        // loadImage(m_file.absoluteFilePath().toStdString());

        // item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        // item->setChecked(true);
    });
    connect(ui->btn_zoomIn, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->slot_changeScale(1);
    });
    connect(ui->btn_zoomOut, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget->slot_changeScale(2);
    });

    connect(this, &MainWindow::sig_showImage, ui->openGLWidget, &CustomOpenGLWidget::slot_showImage);
    connect(ui->openGLWidget, &CustomOpenGLWidget::sign_scaleChanged, this, [=](double scale) {
        ui->label_zoomPercent->setText(QString("%1%").arg((int)(scale * 100)));
    });

    connect(ui->cBox_typeRaw, &QCheckBox::stateChanged, this, [=](int) {
        getFileList();
    });
    connect(ui->cBox_typeJpg, &QCheckBox::stateChanged, this, [=](int) {
        getFileList();
    });
    connect(ui->cBox_typePng, &QCheckBox::stateChanged, this, [=](int) {
        getFileList();
    });
    connect(ui->cBox_typeHeic, &QCheckBox::stateChanged, this, [=](int) {
        getFileList();
    });

    // 加载图片
    getFileList();
    loadImage(m_url.toStdString());
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_data != nullptr) {
        delete[] m_data;
        m_data = nullptr;
    }
}

void MainWindow::loadImage(const std::string& filename)
{
    if (m_data != nullptr) {
        delete[] m_data;
        m_data = nullptr;
    }
    int width, height, channels;
    ImageReader::readJPG(filename, m_data, width, height, channels);

    // 显示图像
    emit sig_showImage(m_data, width, height, channels);

    // 显示标头
    ui->label_name->setText(m_file.fileName());
    ui->label_dimensions->setText(QString("%1x%2x%3").arg(width).arg(height).arg(channels));
    ui->label_size->setText(QString("%1B").arg(m_file.size()));
    // 显示信息
    ui->label_imageIndex->setText(QString("%1 / %2").arg(m_currIndex).arg(m_fileList.size()));
}

/*
 * 获取当前目录下的所有图片文件
 */
void MainWindow::getFileList()
{
    QDir dir(m_currDir);

    // 获取目录中的所有文件
    QStringList nameFilters;
    if (ui->cBox_typeHeic->isChecked()) {
        nameFilters << "*.heic" << "*.heif";
    }
    if (ui->cBox_typeJpg->isChecked()) {
        nameFilters << "*.jpg" << ".jpeg";
    }
    if (ui->cBox_typePng->isChecked()) {
        nameFilters << "*.png";
    }
    if (ui->cBox_typeRaw->isChecked()) {
        nameFilters << ".arw";
    }

    // 清空文件列表
    m_fileList.clear();
    // 按照过滤条件获取工作目录下的所有文件
    m_fileList = dir.entryList(nameFilters, QDir::Files | QDir::NoDotAndDotDot);
    // 获取当前文件在文件列表中的索引
    m_currIndex = m_fileList.indexOf(m_file.fileName());

    // 清空UI界面中的文件项
    ui->listWidget->clear();
    // 逐个向UI界面中添加文件项
    foreach (const QString& file, m_fileList) {
        QPixmap icon;
        if (file.endsWith(".jpg") || file.endsWith(".jpeg")) {
            icon = QPixmap(":/resources/jpg.png");
        } else if (file.endsWith(".png")) {
            icon = QPixmap(":/resources/png.png");
        } else if (file.endsWith(".heic") || file.endsWith(".heif")) {
            icon = QPixmap(":/resources/heic.png");
        } else if (file.endsWith(".arw")) {
            icon = QPixmap(":/resources/raw.png");
        }
        ImageItem* imageItem = new ImageItem(icon);
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(imageItem->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, imageItem);
    }
}
