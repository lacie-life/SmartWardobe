#ifndef QWARDROBEWIDGET_H
#define QWARDROBEWIDGET_H

#include <QWidget>

namespace Ui {
class QWardrobeWidget;
}

/* Display the state of wardrobe */

class QWardrobeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QWardrobeWidget(QWidget *parent = nullptr);
    ~QWardrobeWidget();

    void updateUI();

private:
    Ui::QWardrobeWidget *ui;
};

#endif // QWARDROBEWIDGET_H
