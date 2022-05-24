#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define PLUGINS_SUBFOLDER "/Plugins/"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_cameraWidget = new QCameraWidget();
    m_wardrobeWidget = new QWardrobeWidget();
    m_stackWidget = new QStackedWidget();

    m_stackWidget->addWidget(m_cameraWidget);
    m_stackWidget->addWidget(m_wardrobeWidget);

    m_stackWidget->setCurrentWidget(m_wardrobeWidget);

    setCentralWidget(m_stackWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
