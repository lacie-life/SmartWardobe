/********************************************************************************
** Form generated from reading UI file 'qcamerawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCAMERAWIDGET_H
#define UI_QCAMERAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCameraWidget
{
public:
    QLabel *imageViewer;
    QPushButton *closeButton;
    QPushButton *startButton;
    QLabel *idFace;

    void setupUi(QWidget *QCameraWidget)
    {
        if (QCameraWidget->objectName().isEmpty())
            QCameraWidget->setObjectName(QStringLiteral("QCameraWidget"));
        QCameraWidget->resize(1000, 600);
        imageViewer = new QLabel(QCameraWidget);
        imageViewer->setObjectName(QStringLiteral("imageViewer"));
        imageViewer->setGeometry(QRect(170, 40, 640, 480));
        closeButton = new QPushButton(QCameraWidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(790, 550, 89, 25));
        startButton = new QPushButton(QCameraWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(640, 550, 89, 25));
        idFace = new QLabel(QCameraWidget);
        idFace->setObjectName(QStringLiteral("idFace"));
        idFace->setGeometry(QRect(50, 520, 471, 51));

        retranslateUi(QCameraWidget);

        QMetaObject::connectSlotsByName(QCameraWidget);
    } // setupUi

    void retranslateUi(QWidget *QCameraWidget)
    {
        QCameraWidget->setWindowTitle(QApplication::translate("QCameraWidget", "Form", Q_NULLPTR));
        imageViewer->setText(QApplication::translate("QCameraWidget", "TextLabel", Q_NULLPTR));
        closeButton->setText(QApplication::translate("QCameraWidget", "Close", Q_NULLPTR));
        startButton->setText(QApplication::translate("QCameraWidget", "Start", Q_NULLPTR));
        idFace->setText(QApplication::translate("QCameraWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QCameraWidget: public Ui_QCameraWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCAMERAWIDGET_H
