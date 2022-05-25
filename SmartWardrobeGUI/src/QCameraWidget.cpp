#include "QCameraWidget.h"
#include "ui_qcamerawidget.h"

QCameraWidget::QCameraWidget(QWidget *parent, AppModel *model) :
    QWidget(parent),
    ui(new Ui::QCameraWidget)
{
    ui->setupUi(this);
    m_model = model;
    m_camera = new QCameraCapture();
    m_camera->initCamera();

    m_camera->moveToThread(new QThread(this));

    connect(m_camera->thread(), &QThread::started, m_camera, &QCameraCapture::stream);
    connect(m_camera->thread(), &QThread::finished, m_camera, &QCameraCapture::deleteLater);
    connect(m_camera, &QCameraCapture::frameReady, ui->imageViewer, &QLabel::setPixmap);
    connect(ui->closeButton, &QPushButton::clicked, this, &QCameraWidget::closeCamera);

    openCamera();
}

QCameraWidget::~QCameraWidget()
{
    m_camera->stop();
    m_camera->thread()->quit();
    m_camera->thread()->wait();

    delete ui;
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
