#include "QFaceInforWidget.h"
#include "ui_qfaceinforwidget.h"

QFaceInforWidget::QFaceInforWidget(QWidget *parent, AppModel* model) :
    QWidget(parent),
    ui(new Ui::QFaceInforWidget)
{
    ui->setupUi(this);

    m_model = model;
}

QFaceInforWidget::~QFaceInforWidget()
{
    delete ui;
}

void QFaceInforWidget::loadFaceInfor()
{
    ui->nameEdit->setText(m_model->m_currentFace.name());
    ui->cvEdit->setText(m_model->m_currentFace.type());
    ui->positionEdit->setText(m_model->m_currentFace.currentPosition());
}

