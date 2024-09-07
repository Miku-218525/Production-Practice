#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int num_1;
    int num_2;
    int flag=0;
    int ans;

private slots:
    void on_pb_0_clicked();

    void on_pb_7_clicked();

    void on_pb_1_clicked();

    void on_pb_2_clicked();

    void on_pb_3_clicked();

    void on_pb_4_clicked();

    void on_pb_5_clicked();

    void on_pb_6_clicked();

    void on_pb_8_clicked();

    void on_pb_9_clicked();

    void on_pb_clear_clicked();

    void on_pb_jia_clicked();

    void on_pb_jian_clicked();

    void on_pb_cheng_clicked();

    void on_pb_chu_clicked();

    void on_pb_equal_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
