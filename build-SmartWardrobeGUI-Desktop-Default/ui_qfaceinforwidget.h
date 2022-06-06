/********************************************************************************
** Form generated from reading UI file 'qfaceinforwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFACEINFORWIDGET_H
#define UI_QFACEINFORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFaceInforWidget
{
public:

    void setupUi(QWidget *QFaceInforWidget)
    {
        if (QFaceInforWidget->objectName().isEmpty())
            QFaceInforWidget->setObjectName(QStringLiteral("QFaceInforWidget"));
        QFaceInforWidget->resize(1000, 600);

        retranslateUi(QFaceInforWidget);

        QMetaObject::connectSlotsByName(QFaceInforWidget);
    } // setupUi

    void retranslateUi(QWidget *QFaceInforWidget)
    {
        QFaceInforWidget->setWindowTitle(QApplication::translate("QFaceInforWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QFaceInforWidget: public Ui_QFaceInforWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFACEINFORWIDGET_H
