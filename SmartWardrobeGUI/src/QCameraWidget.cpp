#include "QCameraWidget.h"
#include "ui_qcamerawidget.h"

QCameraWidget::QCameraWidget(QWidget *parent, AppModel *model) :
    QWidget(parent),
    ui(new Ui::QCameraWidget)
{
    ui->setupUi(this);
    m_model = model;
    m_camera = new QCameraCapture();

    connect(ui->closeButton, &QPushButton::clicked, this, &QCameraWidget::closeCamera);
}

QCameraWidget::~QCameraWidget()
{
    m_camera->stop();
    m_camera->thread()->quit();
    m_camera->thread()->wait();

    delete ui;
}

void QCameraWidget::startWidget()
{
    m_camera->initCamera();

    m_camera->moveToThread(new QThread(this));

    connect(m_camera->thread(), &QThread::started, m_camera, &QCameraCapture::stream);
    connect(m_camera->thread(), &QThread::finished, m_camera, &QCameraCapture::deleteLater);
    connect(m_camera, &QCameraCapture::frameReady, m_model, &AppModel::processImage);
    connect(m_model, &AppModel::imageReady, ui->imageViewer, &QLabel::setPixmap);

    openCamera();
}

void QCameraWidget::stopWidget()
{
    disconnect(m_camera->thread(), &QThread::started, m_camera, &QCameraCapture::stream);
    disconnect(m_camera->thread(), &QThread::finished, m_camera, &QCameraCapture::deleteLater);
    disconnect(m_camera, &QCameraCapture::frameReady, m_model, &AppModel::processImage);
    disconnect(m_model, &AppModel::imageReady, ui->imageViewer, &QLabel::setPixmap);

    closeCamera();
}

void QCameraWidget::openCamera()
{
    m_camera->thread()->start();
}

void QCameraWidget::closeCamera()
{
    m_camera->stop();
    m_camera->thread()->quit();
    m_camera->thread()->wait();
}
