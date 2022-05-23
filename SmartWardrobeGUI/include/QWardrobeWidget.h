#ifndef QWARDROBEWIDGET_H
#define QWARDROBEWIDGET_H

#include <QWidget>

namespace Ui {
class QWardrobeWidget;
}

class QWardrobeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QWardrobeWidget(QWidget *parent = nullptr);
    ~QWardrobeWidget();

private:
    Ui::QWardrobeWidget *ui;
};

#endif // QWARDROBEWIDGET_H
