#include "QWardrobeWidget.h"
#include "ui_qwardrobewidget.h"

QWardrobeWidget::QWardrobeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWardrobeWidget)
{
    ui->setupUi(this);

    updateUI();
}

QWardrobeWidget::~QWardrobeWidget()
{
    delete ui;
}

void QWardrobeWidget::updateUI()
{

}
