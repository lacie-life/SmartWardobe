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

void QFaceInforWidget::loadFaceInfor1()
{
    ui->nameEdit->setText("Vu Minh Trung");
    ui->cvEdit->setText("Doctor");
    QString position = "A_3";
    if(position == "")
    {
        ui->positionEdit->setText("Không có đồ trong tủ");
    }
    else {
        ui->positionEdit->setText(position);
    }
}

void QFaceInforWidget::loadFaceInfor2()
{
    ui->nameEdit->setText("Nguyen Truong Son");
    ui->cvEdit->setText("Staff");
    QString position = "";
    if(position == "")
    {
        ui->positionEdit->setText("Không có đồ trong tủ");
    }
    else {
        ui->positionEdit->setText(position);
    }
}

