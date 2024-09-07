#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QString str
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_0_clicked()
{
    //QString current_number = ui->pb_0->text();
    QString txt = ui->lineEdit->text();
    if(flag==5)
    {
        txt.clear();
        flag=0;
    }
    int num = txt.toInt();
    if(num==0)
    {
        ui->lineEdit->setText(QString::number(0));
    }
    else
    {
        txt.append(QString::number(0));
        ui->lineEdit->setText(txt);
    }
}

void MainWindow::on_pb_1_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(1));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_2_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(2));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_3_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(3));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_4_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(4));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_5_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(5));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_6_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(6));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_7_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(7));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_8_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(8));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_9_clicked()
{
    QString txt = ui->lineEdit->text();

    if(flag==5)
    {
        txt.clear();
        flag=0;
    }

    txt.append(QString::number(9));
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_clear_clicked()
{
    QString txt = ui->lineEdit->text();
    txt.clear();
    ui->lineEdit->setText(txt);
}

void MainWindow::on_pb_jia_clicked()
{
    QString txt = ui->lineEdit->text();
    num_1 = txt.toInt();
    txt.clear();
    ui->lineEdit->setText(txt);

    flag=1;
}

void MainWindow::on_pb_jian_clicked()
{
    QString txt = ui->lineEdit->text();
    num_1 = txt.toInt();
    txt.clear();
    ui->lineEdit->setText(txt);

    flag=2;
}

void MainWindow::on_pb_cheng_clicked()
{
    QString txt = ui->lineEdit->text();
    num_1 = txt.toInt();
    txt.clear();
    ui->lineEdit->setText(txt);

    flag=3;
}

void MainWindow::on_pb_chu_clicked()
{
    QString txt = ui->lineEdit->text();
    num_1 = txt.toInt();
    txt.clear();
    ui->lineEdit->setText(txt);

    flag=4;
}

void MainWindow::on_pb_equal_clicked()
{
    QString txt = ui->lineEdit->text();
    num_2 = txt.toInt();
    txt.clear();

    switch(flag)
    {
        case 1:
            ans=num_1+num_2;break;
        case 2:
            ans=num_1-num_2;break;
        case 3:
            ans=num_1*num_2;break;
        case 4:
            ans=num_1/num_2;break;
    }
    ui->lineEdit->setText(QString::number(ans));
    flag=5;
}
