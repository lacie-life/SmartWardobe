#include "QCameraWidget.h"
#include "ui_qcamerawidget.h"

QCameraWidget::QCameraWidget(QWidget *parent, AppModel *model) :
    QWidget(parent),
    ui(new Ui::QCameraWidget)
{
    ui->setupUi(this);
    m_model = model;
    m_camera = new QCameraCapture();

    m_camera->moveToThread(new QThread(this));

    connect(ui->closeButton, &QPushButton::clicked, this, &QCameraWidget::closeCamera);
    connect(ui->startButton, &QPushButton::clicked, this, &QCameraWidget::startWidget);
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

    m_model->setState(AppModel::CHECKING_STATE);

    connect(m_camera->thread(), &QThread::started, m_camera, &QCameraCapture::stream);
    connect(m_camera->thread(), &QThread::finished, m_camera, &QCameraCapture::deleteLater);
    connect(m_camera, &QCameraCapture::frameReady, m_model, &AppModel::processImage);
    connect(m_camera, &QCameraCapture::frameUIReady, ui->imageViewer, &QLabel::setPixmap);
    connect(m_model, &AppModel::idRecognizedNotify, ui->idFace, &QLabel::setText);

    openCamera();
}

void QCameraWidget::stopWidget()
{
    m_model->setState(AppModel::NO_CHEKCING_STATE);

    disconnect(m_camera->thread(), &QThread::started, m_camera, &QCameraCapture::stream);
    disconnect(m_camera->thread(), &QThread::finished, m_camera, &QCameraCapture::deleteLater);
    disconnect(m_camera, &QCameraCapture::frameReady, m_model, &AppModel::processImage);
    disconnect(m_camera, &QCameraCapture::frameUIReady, ui->imageViewer, &QLabel::setPixmap);
    disconnect(m_model, &AppModel::idRecognizedNotify, ui->idFace, &QLabel::setText);

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
