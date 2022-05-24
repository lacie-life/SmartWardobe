#include "QWardrobeWidget.h"
#include "ui_qwardrobewidget.h"

QWardrobeWidget::QWardrobeWidget(QWidget *parent, AppModel *model) :
    QWidget(parent),
    ui(new Ui::QWardrobeWidget)
{
    ui->setupUi(this);
    m_model = model;

    updateUI();
}

QWardrobeWidget::~QWardrobeWidget()
{
    delete ui;
}

void QWardrobeWidget::updateUI()
{

}
