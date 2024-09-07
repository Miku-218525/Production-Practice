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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *pb_jian;
    QPushButton *pb_7;
    QPushButton *pb_equal;
    QPushButton *pb_1;
    QPushButton *pb_cheng;
    QPushButton *pb_5;
    QPushButton *pb_2;
    QPushButton *pb_0;
    QPushButton *pb_4;
    QPushButton *pb_9;
    QPushButton *pb_clear;
    QPushButton *pb_jia;
    QPushButton *pb_8;
    QPushButton *pb_chu;
    QPushButton *pb_3;
    QPushButton *pb_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(427, 303);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(28);
        font.setBold(false);
        font.setWeight(50);
        lineEdit->setFont(font);
        lineEdit->setLayoutDirection(Qt::RightToLeft);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setReadOnly(false);

        verticalLayout->addWidget(lineEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pb_jian = new QPushButton(centralwidget);
        pb_jian->setObjectName(QString::fromUtf8("pb_jian"));

        gridLayout->addWidget(pb_jian, 1, 3, 1, 1);

        pb_7 = new QPushButton(centralwidget);
        pb_7->setObjectName(QString::fromUtf8("pb_7"));

        gridLayout->addWidget(pb_7, 0, 0, 1, 1);

        pb_equal = new QPushButton(centralwidget);
        pb_equal->setObjectName(QString::fromUtf8("pb_equal"));

        gridLayout->addWidget(pb_equal, 4, 2, 1, 1);

        pb_1 = new QPushButton(centralwidget);
        pb_1->setObjectName(QString::fromUtf8("pb_1"));

        gridLayout->addWidget(pb_1, 3, 0, 1, 1);

        pb_cheng = new QPushButton(centralwidget);
        pb_cheng->setObjectName(QString::fromUtf8("pb_cheng"));

        gridLayout->addWidget(pb_cheng, 3, 3, 1, 1);

        pb_5 = new QPushButton(centralwidget);
        pb_5->setObjectName(QString::fromUtf8("pb_5"));

        gridLayout->addWidget(pb_5, 1, 1, 1, 1);

        pb_2 = new QPushButton(centralwidget);
        pb_2->setObjectName(QString::fromUtf8("pb_2"));

        gridLayout->addWidget(pb_2, 3, 1, 1, 1);

        pb_0 = new QPushButton(centralwidget);
        pb_0->setObjectName(QString::fromUtf8("pb_0"));

        gridLayout->addWidget(pb_0, 4, 1, 1, 1);

        pb_4 = new QPushButton(centralwidget);
        pb_4->setObjectName(QString::fromUtf8("pb_4"));

        gridLayout->addWidget(pb_4, 1, 0, 1, 1);

        pb_9 = new QPushButton(centralwidget);
        pb_9->setObjectName(QString::fromUtf8("pb_9"));

        gridLayout->addWidget(pb_9, 0, 2, 1, 1);

        pb_clear = new QPushButton(centralwidget);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));

        gridLayout->addWidget(pb_clear, 4, 0, 1, 1);

        pb_jia = new QPushButton(centralwidget);
        pb_jia->setObjectName(QString::fromUtf8("pb_jia"));

        gridLayout->addWidget(pb_jia, 0, 3, 1, 1);

        pb_8 = new QPushButton(centralwidget);
        pb_8->setObjectName(QString::fromUtf8("pb_8"));

        gridLayout->addWidget(pb_8, 0, 1, 1, 1);

        pb_chu = new QPushButton(centralwidget);
        pb_chu->setObjectName(QString::fromUtf8("pb_chu"));

        gridLayout->addWidget(pb_chu, 4, 3, 1, 1);

        pb_3 = new QPushButton(centralwidget);
        pb_3->setObjectName(QString::fromUtf8("pb_3"));

        gridLayout->addWidget(pb_3, 3, 2, 1, 1);

        pb_6 = new QPushButton(centralwidget);
        pb_6->setObjectName(QString::fromUtf8("pb_6"));

        gridLayout->addWidget(pb_6, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 427, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QString());
        pb_jian->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pb_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pb_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pb_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pb_cheng->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pb_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pb_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pb_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pb_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pb_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pb_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pb_jia->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pb_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pb_chu->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pb_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pb_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
