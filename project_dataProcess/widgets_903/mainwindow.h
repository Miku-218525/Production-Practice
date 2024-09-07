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

    struct struct_updown{
        int up_position;
        int down_position;
    };

    struct struct_signal_detected{
        double f_start;
        double f_stop;

        double f_center;
        double f_amplitude;

        double bw;

        //int frame_index;
    };

    struct struct_signal_matched{
        //double t_start;    //开始时刻
        //double t_stop;

        double f_center;   //频点
        double f_amplitude;//幅度

        double bw;         //带宽
        double pw;         //脉宽

        int frame_start;   //开始帧
        int frame_stop;    //停止帧
    };

    struct struct_signal_sorted{

    };


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fileProcess(QString filename,int mode_flag=0,int part_index=0);

    short getCenter(const QString &filename);
    int analysisData(splab::Vector<std::complex<double>>&vec,int size,int ch_index);
    void cutSample(splab::Vector<std::complex<double>>&vec_psample,splab::Vector<std::complex<double>>&vec_psample_part,int part_index,int sample_num_part);

    void sampleProcess(short center,int part_index);
    int detectSignal(const QVector<double>&vec_x,const QVector<double>&vec_y,const double threshold,QVector<struct_signal_detected>&vec_signal_detected);
    int matchSignal(const QVector<struct_signal_detected>&vec_signal_detected,const int part_index);





private:
    QStringList _filenames;

    char *_pBuff;
    splab::Vector<std::complex<double>> *_psample;//通道样点
    splab::Vector<std::complex<double>> *_psample_part;//通道部分样点（用来加快fft计算速度）
    splab::Vector<std::complex<double>> *_pfft;//fft结果
    splab::Vector<std::complex<double>> *_pfftshift;//fftshift结果

    QVector<struct_signal_matched> _vec_signal_matched;



private slots:
    void on_pb_start_clicked(bool checked);

    void on_pb_select_clicked();

    void on_toolButton_clicked();

    void on_pb_sort_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
