#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ImageReader.h"
#include "ImageItem.h"
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(const std::string& url, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 默认全屏显示
    this->showMaximized();
    // 默认隐藏侧边文件列表
    ui->widget->hide();
    // 默认隐藏图片信息
    ui->plainTextEdit->hide();
    ui->tabWidget->tabBar()->hide();

    connect(ui->btn_min, &QPushButton::clicked, this, [=]() {
        this->showMinimized();
    });
    connect(ui->btn_max, &QPushButton::clicked, this, [=]() {
        if (this->isMaximized()) {
            this->showNormal();
        } else {
            this->showMaximized();
        }
    });
    connect(ui->btn_close, &QPushButton::clicked, this, [=]() {
        this->close();
    });

    connect(ui->btn_imageList, &QPushButton::clicked, this, [=]() {
        ui->widget->setVisible(!ui->widget->isVisible());
    });
    connect(ui->btn_imageInfo, &QPushButton::clicked, this, [=]() {
        ui->plainTextEdit->setVisible(!ui->plainTextEdit->isVisible());
    });
    connect(ui->btn_prev, &QPushButton::clicked, this, [=]() {

    });
    connect(ui->btn_next, &QPushButton::clicked, this, [=]() {

    });
    connect(ui->btn_zoomIn, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget_1_1->slot_changeScale(1);
    });
    connect(ui->btn_zoomOut, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget_1_1->slot_changeScale(2);
    });
    connect(ui->btn_rotate, &QPushButton::clicked, this, [=]() {
        ui->openGLWidget_1_1->slot_rotateImage();
    });
    connect(ui->btn_delete, &QPushButton::clicked, this, [=]() {

    });

    connect(this, &MainWindow::sig_showImage, ui->openGLWidget_1_1, &CustomOpenGLWidget::slot_showImage);
    connect(ui->openGLWidget_1_1, &CustomOpenGLWidget::sig_scaleChanged, this, [=](double scale) {
        ui->label_zoomPercent->setText(QString("%1%").arg((int)(scale * 100)));
    });

    connect(ui->cBox_typeRaw, &QCheckBox::stateChanged, this, [=](int) {
        updateFileList();
    });
    connect(ui->cBox_typeJpg, &QCheckBox::stateChanged, this, [=](int) {
        updateFileList();
    });
    connect(ui->cBox_typePng, &QCheckBox::stateChanged, this, [=](int) {
        updateFileList();
    });
    connect(ui->cBox_typeHeic, &QCheckBox::stateChanged, this, [=](int) {
        updateFileList();
    });

    connect(ui->listWidget, &QListWidget::itemClicked, this, [=](QListWidgetItem *item) {
        // 通知旧的item取消点击状态
        if (m_lastSelectedItem) {
            ImageItem* oldImageItem = static_cast<ImageItem*>(ui->listWidget->itemWidget(m_lastSelectedItem));
            oldImageItem->setChecked(false);
        }

        // 获取被点击item的索引号
        m_currIndex = ui->listWidget->row(item);
        // 显示信息
        ui->label_imageIndex->setText(QString("%1 / %2").arg(m_currIndex + 1).arg(m_displayFiles.size()));

        // 通知新的item设置为点击状态
        m_lastSelectedItem = item;

        ImageItem* imageItem = static_cast<ImageItem*>(ui->listWidget->itemWidget(item));
        imageItem->setChecked(true);

        // 更新视图
        std::string filepath = imageItem->getFilepath();
        m_currImageFile = loadImage(filepath);
        displayImage(m_currImageFile);
    });


    m_currDir = Utils::splitFilepath(url).first;
    m_currImageFile = loadImage(url);
    // 加载文件列表
    getAllFile();
    updateFileList();
    // 显示图片
    displayImage(m_currImageFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

ImageFile MainWindow::loadImage(const std::string& filepath)
{
    ImageFile imageFile;
    imageFile.fileInfo = QFileInfo(QString::fromStdString(filepath));
    imageFile.fileName = Utils::splitFilepath(filepath).second;
    imageFile.filePath = filepath;
    imageFile.fileType = Utils::getFileType(filepath);
    return imageFile;
}

void MainWindow::displayImage(const ImageFile& imageFile)
{
    int orientation = 0;
    std::shared_ptr<ImageData> imageData;
    std::vector<std::pair<std::string, std::string>> exifInfo;

    std::string filepath = imageFile.filePath;
    FileType fileType = imageFile.fileType;
    switch (fileType) {
    case FileType::JPG_IMG:
        ImageReader::readJPG(filepath, imageData);
        ImageReader::readImageExif(filepath, exifInfo, orientation);
        break;
    case FileType::PNG_IMG:
        ImageReader::readPNG(filepath, imageData);
        break;
    case FileType::HEIF_IMG:
        ImageReader::readHEIF(filepath, imageData);
        break;
    case FileType::RAW_IMG:
        ImageReader::readRaw(filepath, imageData);
        break;
    default:
        break;
    }

    // 显示图像
    emit sig_showImage(imageData, orientation);
    // 显示图像信息
    ui->plainTextEdit->clear();
    if (!exifInfo.empty()) {
        for (auto item : exifInfo) {
            QString tmp = QString("%1 : %2").arg(QString::fromStdString(item.first)).arg(QString::fromStdString(item.second));
            ui->plainTextEdit->appendPlainText(tmp);
        }
    }

    // 显示标头
    ui->label_name->setText(QString::fromStdString(imageFile.fileName));
    ui->label_dimensions->setText(QString("%1x%2x%3").arg(imageData->width).arg(imageData->height).arg(imageData->channels));
    ui->label_size->setText(QString::fromStdString(Utils::byteToText(imageFile.fileInfo.size())));
    // 显示信息
    ui->label_imageIndex->setText(QString("%1 / %2").arg(m_currIndex + 1).arg(m_displayFiles.size()));
}

/*
 * 获取当前目录下的所有图片文件
 */
void MainWindow::getAllFile()
{
    fs::path dirPath = m_currDir;

    // 检查路径是否存在且是否是一个目录
    if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
        // 遍历目录并获取文件名
        for (const auto& entry : fs::directory_iterator(dirPath)) {
            if (fs::is_regular_file(entry.status())) {
                // 检查文件是否隐藏
                if (!entry.path().empty() && entry.path().filename().string()[0] != '.') {
                    ImageFile imageFile;
                    imageFile.fileName = entry.path().filename().string();
                    imageFile.filePath = entry.path().string();
                    imageFile.fileInfo = QFileInfo(QString::fromStdString(imageFile.filePath));
                    imageFile.fileType = Utils::getFileType(imageFile.filePath);

                    m_allFiles.push_back(imageFile);
                }
            }
        }
    } else {
        return;
    }
}

void MainWindow::updateFileList()
{
    // 获取目录中的所有文件
    int fileFilter = 0x0000;
    if (ui->cBox_typeHeic->isChecked()) {
        fileFilter |= static_cast<int>(FileType::HEIF_IMG);
    }
    if (ui->cBox_typeJpg->isChecked()) {
        fileFilter |= static_cast<int>(FileType::JPG_IMG);
    }
    if (ui->cBox_typePng->isChecked()) {
        fileFilter |= static_cast<int>(FileType::PNG_IMG);
    }
    if (ui->cBox_typeRaw->isChecked()) {
        fileFilter |= static_cast<int>(FileType::RAW_IMG);
    }

    // 清空文件列表
    m_displayFiles.clear();
    // 按照过滤条件获取工作目录下的所有文件
    int i = 0;
    for (const auto& entry : m_allFiles) {
        if (static_cast<int>(entry.fileType) & fileFilter) {
            m_displayFiles.push_back(entry);
            if (m_currImageFile.filePath == entry.filePath) {
                m_currIndex = i;
            }
        }
        i++;
    }

    // 清空UI界面中的文件项
    ui->listWidget->clear();
    // 逐个向UI界面中添加文件项
    foreach (const auto& file, m_displayFiles) {
        ImageItem* imageItem = new ImageItem(file);
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        item->setSizeHint(imageItem->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, imageItem);
    }

    // 显示信息
    ui->label_imageIndex->setText(QString("%1 / %2").arg(m_currIndex).arg(m_displayFiles.size()));
}

