#ifndef QCAMERAWIDGET_H
#define QCAMERAWIDGET_H

#include <QWidget>
#include "AppModel.h"

namespace Ui {
class QCameraWidget;
}

class QCameraWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QCameraWidget(QWidget *parent = nullptr, AppModel *model = nullptr);
    ~QCameraWidget();

private:
    Ui::QCameraWidget *ui;
    AppModel* m_model;
};

#endif // QCAMERAWIDGET_H
