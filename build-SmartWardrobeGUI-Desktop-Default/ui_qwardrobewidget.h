/********************************************************************************
** Form generated from reading UI file 'qwardrobewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWARDROBEWIDGET_H
#define UI_QWARDROBEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWardrobeWidget
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *A_3;
    QLabel *A_1;
    QLabel *A_2;
    QLabel *A_4;
    QLabel *title;

    void setupUi(QWidget *QWardrobeWidget)
    {
        if (QWardrobeWidget->objectName().isEmpty())
            QWardrobeWidget->setObjectName(QStringLiteral("QWardrobeWidget"));
        QWardrobeWidget->setEnabled(true);
        QWardrobeWidget->resize(1000, 600);
        gridLayoutWidget = new QWidget(QWardrobeWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 220, 961, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        A_3 = new QLabel(gridLayoutWidget);
        A_3->setObjectName(QStringLiteral("A_3"));

        gridLayout->addWidget(A_3, 0, 2, 1, 1);

        A_1 = new QLabel(gridLayoutWidget);
        A_1->setObjectName(QStringLiteral("A_1"));

        gridLayout->addWidget(A_1, 0, 0, 1, 1);

        A_2 = new QLabel(gridLayoutWidget);
        A_2->setObjectName(QStringLiteral("A_2"));

        gridLayout->addWidget(A_2, 0, 1, 1, 1);

        A_4 = new QLabel(gridLayoutWidget);
        A_4->setObjectName(QStringLiteral("A_4"));

        gridLayout->addWidget(A_4, 0, 3, 1, 1);

        title = new QLabel(QWardrobeWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(330, 100, 351, 41));
        QFont font;
        font.setPointSize(22);
        title->setFont(font);
        title->setTextFormat(Qt::AutoText);
        title->setAlignment(Qt::AlignCenter);

        retranslateUi(QWardrobeWidget);

        QMetaObject::connectSlotsByName(QWardrobeWidget);
    } // setupUi

    void retranslateUi(QWidget *QWardrobeWidget)
    {
        QWardrobeWidget->setWindowTitle(QApplication::translate("QWardrobeWidget", "Form", Q_NULLPTR));
        A_3->setText(QApplication::translate("QWardrobeWidget", "TextLabel", Q_NULLPTR));
        A_1->setText(QApplication::translate("QWardrobeWidget", "TextLabel", Q_NULLPTR));
        A_2->setText(QApplication::translate("QWardrobeWidget", "TextLabel", Q_NULLPTR));
        A_4->setText(QApplication::translate("QWardrobeWidget", "TextLabel", Q_NULLPTR));
        title->setText(QApplication::translate("QWardrobeWidget", "Smart Wardrobe", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QWardrobeWidget: public Ui_QWardrobeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWARDROBEWIDGET_H
