#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QFileDialog>
#include <QVector>
#include <complex>

#include "vectormath.h"

#define BUFF_SIZE (50*1024*1024)


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int analysisData(QVector<uint>&vec,int size,int ch_index);

    int new_analysisData(splab::Vector<std::complex<double>>&vec,int size,int ch_index);

    //
    short getCenter(const QString &filename);

    void cutSample(splab::Vector<std::complex<double>>&vec_psample,splab::Vector<std::complex<double>>&vec_psample_part,int part_num,int part_index);

private:
    char *_pBuff;
    splab::Vector<std::complex<double>> *_psample;//通道样点
    splab::Vector<std::complex<double>> *_psample_part;//通道部分样点（用来加快fft计算速度）
    splab::Vector<std::complex<double>> *_pfft;//fft结果
    splab::Vector<std::complex<double>> *_pfftshift;//fftshift结果

private slots:
    void on_pb_select_clicked();

    void on_pb_start_clicked(bool checked);

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
