#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define PLUGINS_SUBFOLDER "/Plugins/"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
