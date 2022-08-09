#include "MainWindow.h"
#include "QDataHandler.h"
#include "AppConstants.h"

#include "ui_mainwindow.h"

#include <QDebug>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/images/data/res/nurses.png"));

    m_model = new AppModel();

    m_cameraWidget = new QCameraWidget(nullptr, m_model);
    m_wardrobeWidget = new QWardrobeWidget(nullptr, m_model);
    m_faceInforWidget = new QFaceInforWidget(nullptr, m_model);
    m_stackWidget = new QStackedWidget();

    m_stackWidget->addWidget(m_cameraWidget);
    m_stackWidget->addWidget(m_wardrobeWidget);
    m_stackWidget->addWidget(m_faceInforWidget);

    m_stackWidget->setCurrentWidget(m_wardrobeWidget);

    setCentralWidget(m_stackWidget);

    connect(m_model, &AppModel::slotUpdate, m_wardrobeWidget, &QWardrobeWidget::updateUI);

    connect(m_model, &AppModel::havePerson, this, [this] {
        CONSOLE << "Start Person checking";
        m_stackWidget->setCurrentWidget(m_cameraWidget);
        m_model->setState(AppModel::APP_STATE::CHECKING_STATE);
        if (!m_cameraWidget->getCameraState()){
            m_cameraWidget->startWidget();
        }
    });

    // Need check APP_STATE before emit this signal
    connect(m_model, &AppModel::noPerson, this, [this] {
        CONSOLE << "Stop Person checking";
        m_model->setState(AppModel::APP_STATE::NO_CHECKING_STATE);
        m_stackWidget->setCurrentWidget(m_wardrobeWidget);
        // m_cameraWidget->stopWidget();
    });

    connect(m_model, &AppModel::recognitionDone, this, [this] {
        CONSOLE << "Checking done";
        m_model->setState(AppModel::APP_STATE::CHECKING_DONE_STATE);
        m_faceInforWidget->loadFaceInfor();
        m_stackWidget->setCurrentWidget(m_faceInforWidget);
        // m_cameraWidget->stopWidget();
    });

    connect(m_model, &AppModel::doorClose, this, [this] {
        CONSOLE << "Return no checking state";
        m_model->setState(AppModel::APP_STATE::NO_CHECKING_STATE);
        m_stackWidget->setCurrentWidget(m_wardrobeWidget);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();

    if(event->key() == Qt::Key_W)
    {
        m_stackWidget->setCurrentWidget(m_wardrobeWidget);
    }
    else if(event->key() == Qt::Key_C)
    {
        m_stackWidget->setCurrentWidget(m_cameraWidget);
    }
    else if (event->key() == Qt::Key_F)
    {
        m_stackWidget->setCurrentWidget(m_faceInforWidget);
    }
    else if (event->key() == Qt::Key_1)
    {
        // LED 1 ON
    }
    else if (event->key() == Qt::Key_2)
    {
        // LED 2 ON
    }
    else if (event->key() == Qt::Key_3)
    {
        // LED 3 ON
    }
    else if (event->key() == Qt::Key_4)
    {
        // LED 4 ON
    }
    else if (event->key() == Qt::Key_5)
    {
        // LED 1 OFF
    }
    else if (event->key() == Qt::Key_6)
    {
        // LED 2 OFF
    }

    else if (event->key() == Qt::Key_7)
    {
        // LED 3 OFF
    }
    else if (event->key() == Qt::Key_8)
    {
        // LED 4 OFF
    }
    else if (event->key() == Qt::Key_9)
    {
        // Open door
    }
    else if (event->key() == Qt::Key_D)
    {
        // Update slot 1
        m_model->addSlot("A_1", "");
    }
    else if (event->key() == Qt::Key_E)
    {
        // Update slot 2
        m_model->addSlot("A_2", "");
    }

    else if (event->key() == Qt::Key_G)
    {
        // Update slot 3
        m_model->addSlot("A_3", "");
    }

    else if (event->key() == Qt::Key_H)
    {
        // Update slot 4
        m_model->addSlot("A_4", "");
    }
    else if (event->key() == Qt::Key_I)
    {
        // Remove slot 1
        m_model->removeSlot("A_1");
    }
    else if (event->key() == Qt::Key_K)
    {
        // Remove slot 2
        m_model->removeSlot("A_2");
    }

    else if (event->key() == Qt::Key_L)
    {
        // Remove slot 3
        m_model->removeSlot("A_3");
    }

    else if (event->key() == Qt::Key_M)
    {
        // Remove slot 4
        m_model->removeSlot("A_4");
    }

}















