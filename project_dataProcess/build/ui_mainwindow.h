/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customplotform.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pb_select;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QPushButton *pb_start;
    QPushButton *pb_sort;
    QVBoxLayout *verticalLayout;
    CustomPlotForm *widget_fft;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pb_select = new QPushButton(centralwidget);
        pb_select->setObjectName(QString::fromUtf8("pb_select"));

        horizontalLayout->addWidget(pb_select);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon_source/icon_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setCheckable(false);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(toolButton);

        pb_start = new QPushButton(centralwidget);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon_source/icon_start.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon_source/icon_stop.png"), QSize(), QIcon::Normal, QIcon::On);
        pb_start->setIcon(icon1);
        pb_start->setCheckable(true);

        horizontalLayout->addWidget(pb_start);

        pb_sort = new QPushButton(centralwidget);
        pb_sort->setObjectName(QString::fromUtf8("pb_sort"));

        horizontalLayout->addWidget(pb_sort);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_fft = new CustomPlotForm(centralwidget);
        widget_fft->setObjectName(QString::fromUtf8("widget_fft"));

        verticalLayout->addWidget(widget_fft);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\277\241\345\217\267\345\244\204\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        pb_select->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2231", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2232", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2233", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2234", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2235", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2236", nullptr));

        toolButton->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_start->setText(QString());
        pb_sort->setText(QCoreApplication::translate("MainWindow", "\345\210\206\351\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
