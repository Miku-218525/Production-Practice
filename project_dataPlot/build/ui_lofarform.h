/********************************************************************************
** Form generated from reading UI file 'lofarform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOFARFORM_H
#define UI_LOFARFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "customplot/xxwcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_LofarForm
{
public:
    QGridLayout *gridLayout;
    XxwCustomPlot *lofarwidget;

    void setupUi(QWidget *LofarForm)
    {
        if (LofarForm->objectName().isEmpty())
            LofarForm->setObjectName(QString::fromUtf8("LofarForm"));
        LofarForm->resize(738, 535);
        gridLayout = new QGridLayout(LofarForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lofarwidget = new XxwCustomPlot(LofarForm);
        lofarwidget->setObjectName(QString::fromUtf8("lofarwidget"));

        gridLayout->addWidget(lofarwidget, 0, 0, 1, 1);


        retranslateUi(LofarForm);

        QMetaObject::connectSlotsByName(LofarForm);
    } // setupUi

    void retranslateUi(QWidget *LofarForm)
    {
        LofarForm->setWindowTitle(QCoreApplication::translate("LofarForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LofarForm: public Ui_LofarForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOFARFORM_H
