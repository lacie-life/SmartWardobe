#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "CvPluginInterface.h"
#include "QCameraWidget.h"
#include "QWardrobeWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QCameraWidget* m_cameraWidget;
    QWardrobeWidget* m_wardrobeWidget;
    QStackedWidget* m_stackWidget;

};
#endif // MAINWINDOW_H
