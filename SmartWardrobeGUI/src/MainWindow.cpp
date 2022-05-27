#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "QDataHandler.h"
#include "AppConstants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new AppModel();

    m_cameraWidget = new QCameraWidget(nullptr, m_model);
    m_wardrobeWidget = new QWardrobeWidget(nullptr, m_model);
    m_stackWidget = new QStackedWidget();

    m_stackWidget->addWidget(m_cameraWidget);
    m_stackWidget->addWidget(m_wardrobeWidget);

    m_stackWidget->setCurrentWidget(m_wardrobeWidget);

    setCentralWidget(m_stackWidget);

    connect(m_model, &AppModel::slotUpdate, m_wardrobeWidget, &QWardrobeWidget::updateUI);

    connect(m_model, &AppModel::havePerson, this, [this] {
        CONSOLE << "Start Person checking";
        m_stackWidget->setCurrentWidget(m_cameraWidget);
        m_cameraWidget->startWidget();
    });

    // Need check APP_STATE before emit this signal
    connect(m_model, &AppModel::noPerson, this, [this] {
        CONSOLE << "Stop Person checking";
        m_stackWidget->setCurrentWidget(m_wardrobeWidget);
        m_cameraWidget->stopWidget();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
