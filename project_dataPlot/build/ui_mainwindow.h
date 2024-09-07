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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customplotform.h"
#include "lofarform.h"

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
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QProgressBar *progressBar;
    QComboBox *comboBox;
    QPushButton *pb_start;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    CustomPlotForm *widget_time;
    CustomPlotForm *widget_fft;
    LofarForm *widget_lofar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1230, 963);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 25));
        label->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(400, 25));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(lineEdit);

        pb_select = new QPushButton(centralwidget);
        pb_select->setObjectName(QString::fromUtf8("pb_select"));
        pb_select->setMinimumSize(QSize(25, 25));
        pb_select->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Algerian"));
        font.setPointSize(8);
        pb_select->setFont(font);

        horizontalLayout->addWidget(pb_select);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 25));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(label_2);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(300, 25));
        progressBar->setMaximumSize(QSize(16777215, 16777215));
        progressBar->setValue(0);

        horizontalLayout_2->addWidget(progressBar);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(100, 25));
        comboBox->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(comboBox);

        pb_start = new QPushButton(centralwidget);
        pb_start->setObjectName(QString::fromUtf8("pb_start"));
        pb_start->setMinimumSize(QSize(40, 40));
        pb_start->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon_source/icon_start.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon_source/icon_stop.png"), QSize(), QIcon::Normal, QIcon::On);
        pb_start->setIcon(icon);
        pb_start->setCheckable(true);
        pb_start->setChecked(false);

        horizontalLayout_2->addWidget(pb_start);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon_source/icon_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_2->addWidget(toolButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_time = new CustomPlotForm(centralwidget);
        widget_time->setObjectName(QString::fromUtf8("widget_time"));
        widget_time->setMinimumSize(QSize(400, 400));
        widget_time->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(widget_time);

        widget_fft = new CustomPlotForm(centralwidget);
        widget_fft->setObjectName(QString::fromUtf8("widget_fft"));
        widget_fft->setMinimumSize(QSize(400, 400));
        widget_fft->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(widget_fft);


        horizontalLayout_3->addLayout(verticalLayout);

        widget_lofar = new LofarForm(centralwidget);
        widget_lofar->setObjectName(QString::fromUtf8("widget_lofar"));
        widget_lofar->setMinimumSize(QSize(800, 800));
        widget_lofar->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(widget_lofar);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1230, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\277\241\345\217\267\347\273\230\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        lineEdit->setText(QString());
        pb_select->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\247\243\346\236\220\350\277\233\345\272\246\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2231", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2232", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2233", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2234", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2235", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\351\200\232\351\201\2236", nullptr));

        pb_start->setText(QString());
        toolButton->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
