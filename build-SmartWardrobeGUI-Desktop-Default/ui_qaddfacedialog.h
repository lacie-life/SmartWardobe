/********************************************************************************
** Form generated from reading UI file 'qaddfacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QADDFACEDIALOG_H
#define UI_QADDFACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QAddFaceDialog
{
public:

    void setupUi(QWidget *QAddFaceDialog)
    {
        if (QAddFaceDialog->objectName().isEmpty())
            QAddFaceDialog->setObjectName(QStringLiteral("QAddFaceDialog"));
        QAddFaceDialog->resize(400, 300);

        retranslateUi(QAddFaceDialog);

        QMetaObject::connectSlotsByName(QAddFaceDialog);
    } // setupUi

    void retranslateUi(QWidget *QAddFaceDialog)
    {
        QAddFaceDialog->setWindowTitle(QApplication::translate("QAddFaceDialog", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QAddFaceDialog: public Ui_QAddFaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QADDFACEDIALOG_H
