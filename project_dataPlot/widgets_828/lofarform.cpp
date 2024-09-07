#include "lofarform.h"
#include "ui_lofarform.h"

static QCPColorMap *pColormap;

LofarForm::LofarForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LofarForm)
{
    ui->setupUi(this);

    LofarForm_Init();

    ui->lofarwidget->showTracer(true);

}

LofarForm::~LofarForm()
{
    delete ui;
}

void LofarForm::LofarForm_Init()
{
    ui->lofarwidget->setBackground(Qt::white);

    qreal fStart, fStop, height;
    fStart = -30;
    fStop  = 30;
    height = 5000;

    //坐标轴
    ui->lofarwidget->xAxis->ticker()->setTickCount(11);
    ui->lofarwidget->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability); //可读性优于设置

    pColormap = new QCPColorMap(ui->lofarwidget->xAxis, ui->lofarwidget->yAxis);
    pColormap->data()->setSize(1024, height);   //设置整个图点的个数 x*y
    pColormap->data()->setRange(QCPRange(fStart, fStop), QCPRange(0, height*512/(60*1000))); //设置X轴和Y轴范围

    //坐标刻度文本颜色
    ui->lofarwidget->xAxis->setLabel("频率(MHz)");//轴标签
    ui->lofarwidget->yAxis->setLabel("时间(ms)");//轴标签

    ui->lofarwidget->axisRect()->setupFullAxesBox();//四边安装轴并显示

    ui->lofarwidget->xAxis->setLabelColor(Qt::black);//文字颜色
    ui->lofarwidget->yAxis->setLabelColor(Qt::black);
    ui->lofarwidget->xAxis->setTickLabelColor(Qt::black);//坐标轴数字颜色
    ui->lofarwidget->yAxis->setTickLabelColor(Qt::black);
    ui->lofarwidget->xAxis->setBasePen(QPen(Qt::black, 1));//坐标轴颜色及宽度
    ui->lofarwidget->yAxis->setBasePen(QPen(Qt::black, 1));
    ui->lofarwidget->xAxis->setTickPen(QPen(Qt::black, 1));//主刻度
    ui->lofarwidget->yAxis->setTickPen(QPen(Qt::black, 1));
    ui->lofarwidget->xAxis->setSubTickPen(QPen(Qt::black, 1));//副刻度
    ui->lofarwidget ->yAxis->setSubTickPen(QPen(Qt::black, 1));

    ui->lofarwidget->xAxis2->setLabelColor(Qt::black);//文字颜色
    ui->lofarwidget->yAxis2->setLabelColor(Qt::black);
    ui->lofarwidget->xAxis2->setTickLabelColor(Qt::black);//坐标轴数字颜色
    ui->lofarwidget->yAxis2->setTickLabelColor(Qt::black);
    ui->lofarwidget->xAxis2->setBasePen(QPen(Qt::black, 1));//坐标轴颜色及宽度
    ui->lofarwidget->yAxis2->setBasePen(QPen(Qt::black, 1));
    ui->lofarwidget->xAxis2->setTickPen(QPen(Qt::black, 1));//主刻度
    ui->lofarwidget->yAxis2->setTickPen(QPen(Qt::black, 1));
    ui->lofarwidget->xAxis2->setSubTickPen(QPen(Qt::black, 1));//副刻度
    ui->lofarwidget->yAxis2->setSubTickPen(QPen(Qt::black, 1));

    ui->lofarwidget->xAxis->grid()->setPen(QPen(QColor(180, 180, 180), 1, Qt::PenStyle::DashLine));//网格白色虚线
    ui->lofarwidget->yAxis->grid()->setPen(QPen(QColor(180, 180, 180), 1, Qt::PenStyle::DashLine));//网格白色虚线
    ui->lofarwidget->xAxis->grid()->setSubGridPen(QPen(QColor(50, 50, 50), 1, Qt::DotLine));//网格浅色点线
    ui->lofarwidget->yAxis->grid()->setSubGridPen(QPen(QColor(50, 50, 50), 1, Qt::DotLine));//网格浅色点线

    //色条设置
    QCPColorScale *colorScale = new QCPColorScale(ui->lofarwidget);  // 构造一个色条
    colorScale->setType(QCPAxis::atRight  );   // 水平显示atLeft,atRight,atTop,atBottom
    ui->lofarwidget->plotLayout()->addElement(0, 1, colorScale); // 在颜色图右边显示
    colorScale->setDataRange(QCPRange(0,100));  //设置色条的数值最大最小
    colorScale->axis()->setLabelColor(Qt::white);
    colorScale->axis()->setTickLabelColor(Qt::white);
    pColormap->setColorScale(colorScale);

    pColormap->setGradient(QCPColorGradient::gpHues);//设置默认渐进色变化（可在QCPColorGradient中查看）
    pColormap->rescaleDataRange(true);

    //初始数据
    double *data = pColormap->data()->coreData();
    for (unsigned int row = 0; row < height; row++)
    {
        for (unsigned int col = 0; col < 1024; col++)
        {
            data[row*1024+col] = qrand() % 80;
        }
    }

    //立即刷新图像
    ui->lofarwidget->rescaleAxes();  //自适应大小
    ui->lofarwidget->replot();
}

void LofarForm::plot(const int h,const double *fftData)
{
    double *data = pColormap->data()->coreData();
    for(unsigned int i=0;i<1024;i++)
    {
        data[h*1024+i] = fftData[i];
    }
}

void LofarForm::flushplot()
{
    ui->lofarwidget->rescaleAxes();  //自适应大小
    ui->lofarwidget->replot();
}

void LofarForm::setRange(int fStart,int fStop)
{
    pColormap->data()->setRange(QCPRange(fStart, fStop),QCPRange(0, 5000*512/(60*1000))); //设置X轴和Y轴范围
    ui->lofarwidget->rescaleAxes();  //自适应大小
    ui->lofarwidget->replot();
}
