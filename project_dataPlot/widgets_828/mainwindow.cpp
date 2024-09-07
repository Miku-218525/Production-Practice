#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "fft.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _pBuff=new char [BUFF_SIZE];

    _psample=new splab::Vector<std::complex<double>>;
    _psample_part=new splab::Vector<std::complex<double>>;
    _pfft=new splab::Vector<std::complex<double>>;
    _pfftshift=new splab::Vector<std::complex<double>>;

    ui->widget_time->setGraph("时域图像","时间(ms)","幅度");
    ui->widget_fft->setGraph("频域图像","频率(MHz)","幅度");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] _pBuff;
}

int MainWindow::analysisData(QVector<uint>&vec,int size,int ch_index)
{
    //定义指向数据的指针
    uint *p1;
    p1=(uint*)_pBuff;
    p1=p1+1;//跳过第一个四字节（0x00000000）

    //定义数据长度
    int len;
    len=size/4;

    //查找第一个样点的地址
    for(int i=0;i<len;i++)
    {
        if((*(p1+i)) != 0xaaaaaaaa)
        {
            p1=p1+i;//将第一个样点的地址赋值给指针
            break;
        }
    }

    //向动态数组容器中添加通道对应的样点
    for(int i=ch_index;i<len;i=i+6)
    {
        //uint temp=*(p1+i);
        vec.push_back(*(p1+i));
    }
    return vec.count();//返回元素个数
}

int MainWindow::new_analysisData(splab::Vector<std::complex<double>>&vec,int size,int ch_index)
{
    //定义存储的数据
    short R;//实部
    short I;//虚部

    //定义指向数据的指针
    uint *p1;
    p1=(uint*)_pBuff;
    p1=p1+1;//跳过第一个四字节（0x00000000）

    //定义总数据长度（单位：样点、4Byte）
    int len;
    len=size/4;

    //定义通道总样点长度
    int len_sample=0;

    //查找第一个样点的地址
    for(int i=0;i<len;i++)
    {
        if((*(p1+i)) != 0xaaaaaaaa)
        {
            p1=p1+i;//将第一个样点的地址赋值给指针
            len_sample=len-1-i;//更新通道总样点数
            vec.resize(len_sample/6);//设置存储大小为单通道样点数
            break;
        }
    }

    //解析样点数据
    int vec_index=0;
    for(int i=ch_index;i<len_sample;i=i+6)
    {
        R=(*(p1+i))&0x0000ffff;
        I=((*(p1+i))>>16)&0x0000ffff;
        //I=(*(p1+i))&0xffff0000;//不要使用这段代码，因为short类型只有16位，直接与的话会损失高位，使结果一直保持0x0000
        vec[vec_index]=std::complex<double>(R,I);
        vec_index++;
    }

    return vec_index;//返回样点数目
}

short MainWindow::getCenter(const QString &filename)
{
    QStringList list = filename.split("/");
    QString str = list.last();
    list = str.split("_");
    QString center = list.at(1);

    return center.toShort();
}

void MainWindow::cutSample(splab::Vector<std::complex<double> > &vec_psample, splab::Vector<std::complex<double> > &vec_psample_part, int part_num, int part_index)
{
    int sample_num_part = vec_psample.size() / part_num;
    vec_psample_part.resize(sample_num_part);
    for(int i=sample_num_part * part_index, j = 0;i < vec_psample.size() && j < sample_num_part;i++,j++)
    {
        vec_psample_part[j] = vec_psample[i];
    }
}

void MainWindow::on_pb_select_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Select Bin Files"), "./", tr("Bin Files (*.bin)"));
    ui->lineEdit->setText(filename);

    if(!filename.isEmpty())
    {
        short center = getCenter(filename);
        double fStart,fStop;
        fStart = center - 30;
        fStop = center + 30;
        ui->widget_lofar->setRange(fStart,fStop);
    }

}

void MainWindow::on_pb_start_clicked(bool checked)
{
    if(checked)
    {
        //start

        //定义
        int ch_index;
        int size;
        QString filename;
        //QVector<uint> dataVec;

        ui->comboBox->setEnabled(false);//锁定comboBox

        //读取通道序号和文件地址
        ch_index=ui->comboBox->currentIndex();
        filename=ui->lineEdit->text();

        if(!filename.isEmpty())
        {
            QByteArray ba = filename.toLatin1();
            char* name = ba.data();
            FILE* fp = fopen(name,"rb");
            if(fp)
            {
                size=fread(_pBuff,sizeof(char),BUFF_SIZE,fp);//返回数据总大小（Byte)
                fclose(fp);
                if(size>0)
                {
                    /*
                    analysisData(dataVec,size,ch_index);

                    for(int i=0;i<200;i++)
                    {
                        uint temp=dataVec.at(i);
                        ui->textEdit->append(QString::number(temp,16)+"\n");
                    }
                    */

                    /*
                    new_analysisData(*_psample,size,ch_index);

                    for(int i=0;i<100;i++)
                    {
                        QString str=QString("%1 +i*%2")
                                .arg((*_psample)[i].real())
                                .arg((*_psample)[i].imag());
                        ui->textEdit->append(str);
                    }
                    */

                    //解析文件名，获得下边频
                    short center=getCenter(filename);

                    //解析数据，获得通道样点
                    new_analysisData(*_psample,size,ch_index);

                    //截取通道部分样点
                    int part_index = ui->toolButton->text().toInt();
                    cutSample(*_psample,*_psample_part,10,part_index);

                    /*
                    int sample_num_part = _psample->size() / 10;
                    _psample_part->resize(sample_num_part);
                    for(int i=sample_num_part * part_index, j = 0;i < _psample->size() && j < sample_num_part;i++,j++)
                    {
                        (*_psample_part)[j] = (*_psample)[i];
                    }
                    */

                    //画时域图
                    QVector<double> vec_x,vec_y;
                    for(int i=0;i<_psample_part->size();i++)
                    {
                        double x=i*1.0/6e4;
                        double y=((*_psample_part)[i].real())*((*_psample_part)[i].real())+((*_psample_part)[i].imag())*((*_psample_part)[i].imag());
                        //y = 10.0 * log10(y + 1e-10);

                        vec_x.push_back(x);
                        vec_y.push_back(y);
                    }
                    ui->widget_time->plot(vec_x,vec_y);

                    vec_x.clear();
                    vec_y.clear();

                    //画频域图
                    size=_psample_part->size();

                    _pfft->resize(size);
                    //splab::fft(*_psample,*_pfft);
                    *_pfft=splab::fft(*_psample_part);
                    //频谱搬移
                    _pfftshift->resize(size);
                    for(int i=0;i<size;i++)
                    {
                        if(i<size/2)
                        {
                            (*_pfftshift)[i+size/2]=(*_pfft)[i];
                        }
                        else
                        {
                            (*_pfftshift)[i-size/2]=(*_pfft)[i];
                        }
                    }
                    for(int i=0;i<size;i++)
                    {
                        double x=center-30+60*i*1.0/size;//f=f0-fs/2+fs/N*i；其中，f0为中心频率，fs=60MHz，N为样点数目；
                        double y=((*_pfftshift)[i].real())*((*_pfftshift)[i].real())+((*_pfftshift)[i].imag())*((*_pfftshift)[i].imag());
                        //y = 10.0 * log10(y + 1e-10);

                        vec_x.push_back(x);
                        vec_y.push_back(y);
                    }
                    ui->widget_fft->plot(vec_x,vec_y);

                    vec_x.clear();
                    vec_y.clear();

                    //画瀑布图
                    double fftData[1024]={};
                    _psample_part->resize(1024);
                    for(int i=0,h=0;i+1024<_psample->size();i=i+512,h++)
                    {
                        for(int j=0;j<1024;j++)
                        {
                            (*_psample_part)[j]=(*_psample)[i+j];
                        }
                        _pfft->resize(1024);
                        *_pfft=splab::fft(*_psample_part);
                        _pfftshift->resize(1024);
                        for(int k=0;k<1024;k++)
                        {
                            if(k<1024/2)
                            {
                                (*_pfftshift)[k+1024/2]=(*_pfft)[k];
                            }
                            else
                            {
                                (*_pfftshift)[k-1024/2]=(*_pfft)[k];
                            }
                        }
                        for(int l=0;l<1024;l++)
                        {
                            fftData[l]=((*_pfftshift)[l].real())*((*_pfftshift)[l].real())+((*_pfftshift)[l].imag())*((*_pfftshift)[l].imag());
                            fftData[l]=10*log10(fftData[l]);
                        }
                        ui->widget_lofar->plot(h,fftData);
                    }
                    ui->widget_lofar->flushplot();
                }
            }
        }

    }
    else
    {
        //stop
        ui->comboBox->setEnabled(true);//解锁comboBox
    }
}

void MainWindow::on_toolButton_clicked()
{
    int part_index = ui->toolButton->text().toInt();
    part_index++;
    part_index=part_index%10;
    ui->toolButton->setText(QString::number(part_index));
}
