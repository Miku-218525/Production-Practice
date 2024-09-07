/********************************************************************************
** Form generated from reading UI file 'customplotform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPLOTFORM_H
#define UI_CUSTOMPLOTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include "customplot/xxwcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CustomPlotForm
{
public:
    QGridLayout *gridLayout;
    XxwCustomPlot *customplotwidget;

    void setupUi(QWidget *CustomPlotForm)
    {
        if (CustomPlotForm->objectName().isEmpty())
            CustomPlotForm->setObjectName(QString::fromUtf8("CustomPlotForm"));
        CustomPlotForm->resize(522, 253);
        gridLayout = new QGridLayout(CustomPlotForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        customplotwidget = new XxwCustomPlot(CustomPlotForm);
        customplotwidget->setObjectName(QString::fromUtf8("customplotwidget"));

        gridLayout->addWidget(customplotwidget, 0, 0, 1, 1);


        retranslateUi(CustomPlotForm);

        QMetaObject::connectSlotsByName(CustomPlotForm);
    } // setupUi

    void retranslateUi(QWidget *CustomPlotForm)
    {
        CustomPlotForm->setWindowTitle(QCoreApplication::translate("CustomPlotForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomPlotForm: public Ui_CustomPlotForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPLOTFORM_H
