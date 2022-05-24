#include "QCameraWidget.h"
#include "ui_qcamerawidget.h"

QCameraWidget::QCameraWidget(QWidget *parent, AppModel *model) :
    QWidget(parent),
    ui(new Ui::QCameraWidget)
{
    ui->setupUi(this);
    m_model = model;
}

QCameraWidget::~QCameraWidget()
{
    delete ui;
}
