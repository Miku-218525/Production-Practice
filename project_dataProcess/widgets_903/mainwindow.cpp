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

    //ui->toolButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_start_clicked(bool checked)
{
    if(checked)
    {
        //start
        ui->comboBox->setEnabled(false);//锁定comboBox

        //读取单文件
        QString filename;
        for(int i=0;i<_filenames.size();i++)
        {
            filename=_filenames.at(i);
        }

        //单文件处理
        fileProcess(filename,1);

    }
    else
    {
        //stop
        ui->comboBox->setEnabled(true);//解锁comboBox
    }

}

void MainWindow::on_pb_select_clicked()
{
    _filenames = QFileDialog::getOpenFileNames(this,tr("Select Bin Files"), "./", tr("Bin Files (*.bin)"));
    ui->lineEdit->setText(QString("totally selected %1 file").arg(_filenames.size()));
}

void MainWindow::on_toolButton_clicked()
{
    ui->toolButton->setEnabled(false);

    int part_index = ui->toolButton->text().toInt();

    if(part_index*512+1024 > _psample->size())
    {
        part_index = 0;
    }
    else
    {
        part_index++;
    }

    ui->toolButton->setText(QString::number(part_index));

    //调用fileProcess
    fileProcess(_filenames.at(0),0,ui->toolButton->text().toInt());

    ui->toolButton->setEnabled(true);
}

int MainWindow::analysisData(splab::Vector<std::complex<double>>&vec,int size,int ch_index)
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

void MainWindow::cutSample(splab::Vector<std::complex<double> > &vec_psample, splab::Vector<std::complex<double> > &vec_psample_part, int part_index, int sample_num_part)
{
    //int sample_num_part = vec_psample.size() / part_num;
    vec_psample_part.resize(sample_num_part);
    for(int i=sample_num_part * part_index/2, j = 0;i < vec_psample.size() && j < sample_num_part;i++,j++)
    {
        vec_psample_part[j] = vec_psample[i];
    }
}

int MainWindow::detectSignal(const QVector<double> &vec_x, const QVector<double> &vec_y, const double threshold, QVector<struct_signal_detected> &vec_signal_detected)
{
    if(vec_x.size()==vec_y.size())
    {
        //获取所有上升、下降沿
        QVector<int> vec_up,vec_down;
        for(int i=1+100;i<vec_x.size()-1-100;i++)
        {
            if(vec_y[i]>threshold && vec_y[i-1]<=threshold)//条件有待验证。。。。。
            {
                vec_up.push_back(i);
            }
            if(vec_y[i]>threshold && vec_y[i+1]<=threshold)
            {
                vec_down.push_back(i);
            }
        }

        //

        //删除
        QVector<struct_updown> vec_updown_AfterDelete;
        if(vec_up.size()==0 || vec_down.size()==0)
        {
            return 0;
        }
        else
        {
            if(vec_up.at(0)<=vec_down.at(0))
            {
                for(int i=0;i<vec_down.size();i++)
                {
                    int position_distence = vec_down[i]-vec_up[i];
                    if(position_distence>5)
                    {
                        struct_updown temp;
                        temp.up_position=vec_up.at(i);
                        temp.down_position=vec_down.at(i);
                        vec_updown_AfterDelete.push_back(temp);//载入删除后的上升、下降沿的索引
                    }
                }
            }
            else
            {
                for(int i=0;i<vec_down.size()-1;i++)
                {
                    int position_distence = vec_down[i+1]-vec_up[i];
                    if(position_distence>5)
                    {
                        struct_updown temp;
                        temp.up_position=vec_up.at(i);
                        temp.down_position=vec_down.at(i+1);
                        vec_updown_AfterDelete.push_back(temp);//载入删除后的上升、下降沿的索引
                    }
                }

            }
        }

        //合并
        QVector<struct_updown> vec_updown_AfterCombine;
        if(vec_updown_AfterDelete.size()==0)
        {
            return 0;
        }
        else
        {
            struct_updown last_updown;
            last_updown.up_position=vec_updown_AfterDelete[0].up_position;
            last_updown.down_position=vec_updown_AfterDelete[0].down_position;
            for(int i=1;i<vec_updown_AfterDelete.size();i++)
            {
                int position_distence = abs(vec_updown_AfterDelete[i].up_position - last_updown.down_position);
                if(position_distence<20)
                {
                    //需要合并
                    //如果当前脉冲需要合并，则 ：（1）不推入；
                    //                       （2）更新（相对于下一个脉冲的）上一个（或“上一段”）脉冲last_updown的down_position；（相当于给脉冲加尾巴）
                    last_updown.down_position=vec_updown_AfterDelete[i].down_position;
                }
                else
                {
                    //不用合并
                    //如果当前脉冲不用合并，则：（1）推入（相对于当前脉冲的）上一段脉冲last_updown；
                    //                      （2）更新（相对于下一个脉冲的）上一个脉冲last_updown的up_position和down_position；（相当找到的新脉冲的头）
                    vec_updown_AfterCombine.push_back(last_updown);//载入合并后的上升、下降沿的索引
                    last_updown.up_position=vec_updown_AfterDelete[i].up_position;
                    last_updown.down_position=vec_updown_AfterDelete[i].down_position;
                }
            }
            vec_updown_AfterCombine.push_back(last_updown);//无论最后一个脉冲是否需要合并，都需要在循环结束后推入最后一段（合并后的）脉冲
        }

        //QVector<struct_signal> vec_output;
        for(int i=0;i<vec_updown_AfterCombine.size();i++)
        {
            struct_signal_detected temp;
            temp.f_start=vec_x.at(vec_updown_AfterCombine.at(i).up_position);
            temp.f_stop=vec_x.at(vec_updown_AfterCombine.at(i).down_position);
            temp.f_center=temp.f_start+(temp.f_stop-temp.f_start)/2;

            //temp.f_amplitude=vec_y.at(vec_updown_AfterCombine.at(i).up_position);

            temp.f_amplitude=0;
            for(int j=vec_updown_AfterCombine.at(i).up_position;j<=vec_updown_AfterCombine.at(i).down_position;j++)
            {
                temp.f_amplitude = temp.f_amplitude + vec_y.at(j);
            }
            temp.f_amplitude=temp.f_amplitude/(vec_updown_AfterCombine.at(i).down_position-vec_updown_AfterCombine.at(i).up_position+1);


            temp.bw=temp.f_stop-temp.f_start;
            vec_signal_detected.push_back(temp);

            //打印
            /*
            ui->textEdit->append(QString("up:%1, down:%2, f_center:%3, f_bw:%4, A:%5")
                                 .arg(vec_updown_AfterCombine.at(i).up_position)
                                 .arg(vec_updown_AfterCombine.at(i).down_position)
                                 .arg(temp.f_center)
                                 .arg(temp.bw)
                                 .arg(vec_y.at(vec_updown_AfterCombine.at(i).up_position))
                                 );
            */
        }
        return vec_signal_detected.size();
    }
    else
    {
        return 0;
    }
}

int MainWindow::matchSignal(const QVector<MainWindow::struct_signal_detected> &vec_signal_detected,const int part_index)
{

    for(int i=0;i<vec_signal_detected.size();i++)
    {
        //记录新的数据
        double new_f_center    = vec_signal_detected[i].f_center;
        double new_f_amplitude = vec_signal_detected[i].f_amplitude;
        double new_bw          = vec_signal_detected[i].bw;
        int new_frame_stop     = part_index;

        //排查极端值
        if(new_bw < 3 || new_f_amplitude<70)
        {
            continue;
        }

        //判断旧数据存储空间是否为空
        if(_vec_signal_matched.isEmpty())
        {
            struct_signal_matched temp;//记录新数据的参数
            temp.f_center    = new_f_center;
            temp.f_amplitude = new_f_amplitude;
            temp.bw          = new_bw;
            temp.frame_start = new_frame_stop;
            temp.frame_stop  = new_frame_stop;
            //temp.t_start     = new_frame_stop*512/1000/60*1.0;//ms
            _vec_signal_matched.push_back(temp);//推入第一个数据

            continue;
        }

        //轮流匹配
        bool judge_flag = false;//
        for(int j=0;j<_vec_signal_matched.size();j++)
        {
            //记录旧的数据
            double old_f_center    = _vec_signal_matched[j].f_center;
            double old_f_amplitude = _vec_signal_matched[j].f_amplitude;
            double old_bw          = _vec_signal_matched[j].bw;
            int old_frame_stop     = _vec_signal_matched[j].frame_stop;

            //匹配
            if(abs(new_f_center - old_f_center) < old_bw
                    && abs(new_f_amplitude - old_f_amplitude) < 15
                    && abs(new_bw          - old_bw)          < 2
                    && abs(new_frame_stop  - old_frame_stop)  < 60)//9,1,26
            {
                //匹配成功（相同信号，新数据刷新旧数据的参数）
                if(new_f_amplitude > old_f_amplitude)//新数据幅值更高
                {
                    //刷新旧数据的参数
                    _vec_signal_matched[j].f_center    = old_f_center;
                    _vec_signal_matched[j].f_amplitude = old_f_amplitude;
                    _vec_signal_matched[j].bw          = old_bw;
                }
                _vec_signal_matched[j].frame_stop = new_frame_stop;//刷新旧数据的停止帧
                _vec_signal_matched[j].pw         = (_vec_signal_matched[j].frame_stop - _vec_signal_matched[j].frame_start)*512/1000/60*1.0;//刷新脉宽（ms）

                judge_flag=true;//匹配成功
                break;//找到匹配对象，跳出循环
            }
        }

        //轮流匹配失败
        if(judge_flag==false)
        {
            //匹配失败（不同信号，新数据要作为单独的信号）
            struct_signal_matched temp;//记录新数据的参数
            temp.f_center    = new_f_center;
            temp.f_amplitude = new_f_amplitude;
            temp.bw          = new_bw;
            temp.frame_start = new_frame_stop;
            temp.frame_stop  = new_frame_stop;
            //temp.t_start     = new_frame_stop*512/60*1.0;
            temp.pw          = (temp.frame_stop - temp.frame_start)*512/1000/60*1.0;//(ms)
            _vec_signal_matched.push_back(temp);//推入新数据

            //judge_flag=false;//重置标志位
        }
    }
    return _vec_signal_matched.size();
}

void MainWindow::sampleProcess(short center,int part_index)
{
    //截取通道部分样点
    //int part_index = ui->toolButton->text().toInt();
    cutSample(*_psample,*_psample_part,part_index,1024);

    //画频域图
    QVector<double> vec_x,vec_y;
    QVector<double> vec_threshold;

    int size=_psample_part->size();

    _pfft->resize(size);//fft
    *_pfft=splab::fft(*_psample_part);

    _pfftshift->resize(size);//fftshift
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
        y = 10.0 * log10(y + 1e-10);

        vec_x.push_back(x);
        vec_y.push_back(y);

        vec_threshold.push_back(y);
    }

    std::sort(vec_threshold.begin(),vec_threshold.end());//查找门限值
    double threshold=vec_threshold.at(1024*2/3);
    threshold=threshold+9;
    vec_threshold.clear();
    for(int i=0;i<size;i++)
    {
        vec_threshold.push_back(threshold);
    }

    ui->widget_fft->plot(vec_x,vec_y);
    ui->widget_fft->plot(vec_x,vec_threshold,1);

    //检测信号
    QVector<struct_signal_detected> vec_signal_detected;    //定义探测后的信号
    detectSignal(vec_x,vec_y,threshold,vec_signal_detected);//探测

    //QVector<struct_signal_matched> vec_vec_signal_matched;    //定义匹配后的信号
    matchSignal(vec_signal_detected,part_index);                //匹配

    vec_x.clear();
    vec_y.clear();
    vec_threshold.clear();
}

void MainWindow::fileProcess(QString filename,int mode_flag,int part_index)
{
    //_vec_signal_matched.clear();
    //读取文件地址
    //QString filename=ui->lineEdit->text();
    if(!filename.isEmpty())
    {
        QByteArray ba = filename.toLatin1();
        char* name = ba.data();
        FILE* fp = fopen(name,"rb");
        if(fp)
        {
            int size=fread(_pBuff,sizeof(char),BUFF_SIZE,fp);//返回数据总大小（Byte)
            fclose(fp);
            if(size>0)
            {
                //解析文件名，获得下边频
                short center=getCenter(filename);

                //解析数据，获得通道样点
                int ch_index=ui->comboBox->currentIndex();
                analysisData(*_psample,size,ch_index);

                //处理样点
                if(mode_flag==0)
                {
                    sampleProcess(center,part_index);

                    //打印
                    ui->textEdit->append(QString("----------------loop %1-------------------").arg(ui->toolButton->text().toInt()));
                    for(int i=0;i<_vec_signal_matched.size();i++)
                    {
                        ui->textEdit->append(QString("f_center:%1, f_amplitude:%2, bw:%3, frame_start:%4, frame_stop:%5")
                                             .arg(_vec_signal_matched[i].f_center)
                                             .arg(_vec_signal_matched[i].f_amplitude)
                                             .arg(_vec_signal_matched[i].bw)
                                             .arg(_vec_signal_matched[i].frame_start)
                                             .arg(_vec_signal_matched[i].frame_stop)
                                             );
                    }
                    ui->textEdit->append(QString("------------------------------------------\n"));
                }
                else
                {
                    _vec_signal_matched.clear();

                    for(int part_index=0;part_index<_psample->size()/512;part_index++)
                    {
                        sampleProcess(center,part_index);
                    }
                    //打印
                    for(int i=0;i<_vec_signal_matched.size();i++)
                    {
                        ui->textEdit->append(QString("f_center:%1, f_amplitude:%2, bw:%3, frame_start:%4, frame_stop:%5")
                                             .arg(_vec_signal_matched[i].f_center)
                                             .arg(_vec_signal_matched[i].f_amplitude)
                                             .arg(_vec_signal_matched[i].bw)
                                             .arg(_vec_signal_matched[i].frame_start)
                                             .arg(_vec_signal_matched[i].frame_stop)
                                             );
                    }
                    ui->textEdit->append(QString("\n"));
                }

            }
        }
    }
}

void MainWindow::on_pb_sort_clicked()
{
    if(!_vec_signal_matched.isEmpty())
    {
        //记录新读入的数据

        for(int i=0;i<_vec_signal_matched.size();i++)
        {

        }
    }
}
