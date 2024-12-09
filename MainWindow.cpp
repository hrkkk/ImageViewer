#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "ImageReader.h"
#include <QFileInfo>
#include <QDir>
#include <QDebug>

MainWindow::MainWindow(QString url, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    url = "C:\\Users\\hrkkk\\Desktop\\DSC00902.JPG";

    m_currFileInfo = QFileInfo(url);
    m_currDir = m_currFileInfo.dir().path();

    // 默认全屏显示
    this->showMaximized();
    // 默认隐藏侧边文件列表
    ui->widget->hide();
    // 默认隐藏图片信息
    ui->plainTextEdit->hide();

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

    connect(this, &MainWindow::sig_showImage, ui->openGLWidget_1_1, &CustomOpenGLWidget::slot_showImage);
    connect(ui->openGLWidget_1_1, &CustomOpenGLWidget::sign_scaleChanged, this, [=](double scale) {
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
        QLabel* label = static_cast<QLabel*>(ui->listWidget->itemWidget(item));
        m_currFileInfo = QFileInfo(m_currDir + "\\" + label->text());
        loadImage(m_currFileInfo.filePath().toStdString());
    });

    // 加载图片
    getAllFile();
    updateFileList();
    loadImage(m_currFileInfo.filePath().toStdString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImage(const std::string& filename)
{
    int orientation = 0;
    std::shared_ptr<ImageData> imageData;
    std::vector<std::pair<std::string, std::string>> exifInfo;

    FileType fileType = Utils::getFileType(filename);
    switch (fileType) {
        case FileType::JPG_IMG:
            ImageReader::readJPG(filename, imageData);
            ImageReader::readImageExif(filename, exifInfo, orientation);
            break;
        case FileType::PNG_IMG:
            ImageReader::readPNG(filename, imageData);
            break;
        case FileType::HEIF_IMG:
            ImageReader::readHEIF(filename, imageData);
            break;
        case FileType::RAW_IMG:
            ImageReader::readRaw(filename, imageData);
            break;
        default:
            break;
    }

    // 显示图像
    emit sig_showImage(imageData, orientation);
    // 显示图像信息
    if (!exifInfo.empty()) {
        for (auto item : exifInfo) {
            QString tmp = QString("%1 : %2").arg(QString::fromStdString(item.first)).arg(QString::fromStdString(item.second));
            ui->plainTextEdit->appendPlainText(tmp);
        }
    }

    // 显示标头
    ui->label_name->setText(m_currFileInfo.fileName());
    ui->label_dimensions->setText(QString("%1x%2x%3").arg(imageData->width).arg(imageData->height).arg(imageData->channels));
    ui->label_size->setText(QString::fromStdString(Utils::byteToText(m_currFileInfo.size())));
    // 显示信息
    // ui->label_imageIndex->setText(QString("%1 / %2").arg(m_currIndex).arg(m_fileList.size()));
}

/*
 * 获取当前目录下的所有图片文件
 */
void MainWindow::getAllFile()
{
    fs::path dirPath = m_currDir.toStdString();

    // 检查路径是否存在且是否是一个目录
    if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
        // 遍历目录并获取文件名
        for (const auto& entry : fs::directory_iterator(dirPath)) {
            if (fs::is_regular_file(entry.status())) {
                // 检查文件是否隐藏
                if (!entry.path().empty() && entry.path().filename().string()[0] != '.') {
                    m_allFiles.push_back({entry.path().filename(), Utils::getFileType(entry.path().string())});
                }
            }
        }
    } else {
        return;
    }
}

void MainWindow::updateFileList()
{
    QDir dir(m_currDir);

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
    for (const auto& entry : m_allFiles) {
        if (static_cast<int>(entry.second) & fileFilter) {
            m_displayFiles.push_back(entry.first);
        }
    }
    // 获取当前文件在文件列表中的索引
    // m_currIndex = m_fileList.indexOf(m_file.fileName());

    // 清空UI界面中的文件项
    ui->listWidget->clear();
    // 逐个向UI界面中添加文件项
    foreach (const auto& file, m_displayFiles) {
        // ImageItem* imageItem = new ImageItem(icon);
        QLabel* label = new QLabel(QString::fromStdString(file.string()));
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        // item->setSizeHint(imageItem->sizeHint());
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, label);
    }
}
