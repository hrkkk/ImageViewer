#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ImageReader.h"
#include <QFileInfo>
#include <QDir>

MainWindow::MainWindow(QString url, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_url(url)
{
    ui->setupUi(this);

    m_url = R"(H:\DataCenter\Photo\#2 Photo\other\IMG_4785.HEIC)";
    m_file = QFileInfo(m_url);

    this->showMaximized();
    ui->scrollArea->hide();

    connect(ui->btn_imageList, &QPushButton::clicked, this, [this]() {
        ui->scrollArea->setVisible(!ui->scrollArea->isVisible());
    });
    connect(ui->btn_imageInfo, &QPushButton::clicked, this, [this]() {

    });
    connect(ui->btn_prev, &QPushButton::clicked, this, [this]() {
        ImageItem* item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        item->setChecked(false);

        if (m_currIndex <= 1) {
            m_currIndex = m_fileList.size();
        } else {
            m_currIndex--;
        }
        m_file = QFileInfo(m_file.absolutePath() + "/" + m_fileList.at(m_currIndex - 1));
        loadImage(m_file.absoluteFilePath().toStdString());

        item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        item->setChecked(true);
    });
    connect(ui->btn_next, &QPushButton::clicked, this, [this]() {
        ImageItem* item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        item->setChecked(false);

        if (m_currIndex == m_fileList.size()) {
            m_currIndex = 1;
        } else {
            m_currIndex++;
        }
        m_file = QFileInfo(m_file.absolutePath() + "/" + m_fileList.at(m_currIndex - 1));
        loadImage(m_file.absoluteFilePath().toStdString());

        item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        item->setChecked(true);
    });

    connect(this, &MainWindow::sig_showImage, ui->openGLWidget, &CustomOpenGLWidget::slot_showImage);

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
    ImageReader imageReader;
    imageReader.readHEIF(filename, m_data, width, height, channels);

    // 显示图像
    emit sig_showImage(m_data, width, height, channels);

    // 显示标头
    ui->label_name->setText(m_file.fileName());
    ui->label_dimensions->setText(QString("%1x%2").arg(width).arg(height));
    ui->label_size->setText(QString("%1B").arg(m_file.size()));
    // 显示信息
    ui->label_imageIndex->setText(QString("%1 / %2").arg(m_currIndex).arg(m_fileList.size()));
}

void MainWindow::getFileList()
{
    QDir dir(m_file.absolutePath());

    // 获取目录中的所有文件
    QStringList nameFilters;
    nameFilters << "*.heic" << "*.heif";    // 只获取HEIC文件

    m_fileList.clear();
    m_fileList = dir.entryList(nameFilters, QDir::Files | QDir::NoDotAndDotDot);
    m_currIndex = m_fileList.indexOf(m_file.fileName());

    if (m_listLayout != nullptr) {
        delete m_listLayout;
        m_listLayout = nullptr;
    }

    if (m_listLayout == nullptr) {
        m_listLayout = new QVBoxLayout;
        foreach (const QString& item, m_fileList) {
            ImageItem* imageItem = new ImageItem(QPixmap(), ui->scrollAreaWidgetContents);
            m_listLayout->addWidget(imageItem);
        }
        ui->widget->setLayout(m_listLayout);
        m_listLayout->setContentsMargins(QMargins(0, 5, 0, 5));

        ImageItem* item = static_cast<ImageItem*>(m_listLayout->itemAt(m_currIndex)->widget());
        item->setChecked(true);
    }
}
