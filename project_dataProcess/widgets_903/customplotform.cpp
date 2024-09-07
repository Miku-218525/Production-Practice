#include "customplotform.h"
#include "ui_customplotform.h"

CustomPlotForm::CustomPlotForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomPlotForm)
{
    ui->setupUi(this);

    CustomPlotForm_Init();

}

CustomPlotForm::~CustomPlotForm()
{
    delete ui;
}

void CustomPlotForm::CustomPlotForm_Init()
{
    ui->customplotwidget->setOpenGl(true);//开启GPU计算？

    ui->customplotwidget->axisRect()->setupFullAxesBox();//四边安装轴并显示

    ui->customplotwidget->xAxis->ticker()->setTickCount(11);
    ui->customplotwidget->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability); //可读性优于设置

    //设置坐标轴
    ui->customplotwidget->xAxis ->setTickLabelColor(Qt::black);//坐标轴数字颜色
    ui->customplotwidget->yAxis->setTickLabelColor(Qt::black);
    ui->customplotwidget->xAxis->setBasePen(QPen(Qt::black, 1));//坐标轴颜色及宽度
    ui->customplotwidget->yAxis->setBasePen(QPen(Qt::black, 1));
    ui->customplotwidget->xAxis->setTickPen(QPen(Qt::black, 1));//主刻度
    ui->customplotwidget->yAxis->setTickPen(QPen(Qt::black, 1));
    ui->customplotwidget->xAxis->setSubTickPen(QPen(Qt::black, 1));//副刻度
    ui->customplotwidget->yAxis->setSubTickPen(QPen(Qt::black, 1));

    ui->customplotwidget->xAxis2->setTickLabelColor(Qt::white);//坐标轴数字颜色
    ui->customplotwidget->yAxis2->setTickLabelColor(Qt::white);
    ui->customplotwidget->xAxis2->setBasePen(QPen(Qt::white, 1));//坐标轴颜色及宽度
    ui->customplotwidget->yAxis2->setBasePen(QPen(Qt::white, 1));
    ui->customplotwidget->xAxis2->setTickPen(QPen(Qt::white, 1));//主刻度
    ui->customplotwidget->yAxis2->setTickPen(QPen(Qt::white, 1));
    ui->customplotwidget->xAxis2->setSubTickPen(QPen(Qt::white, 1));//副刻度
    ui->customplotwidget->yAxis2->setSubTickPen(QPen(Qt::white, 1));
    //ui->customplotwidget->xAxis2->setRange(0, 100);//坐标范围
    //ui->customplotwidget->yAxis2->setRange(0, 100);

    //设置网格
    ui->customplotwidget->xAxis->grid()->setPen(QPen(QColor(180, 180, 180), 1, Qt::PenStyle::DashLine));//网格白色虚线
    ui->customplotwidget->yAxis->grid()->setPen(QPen(QColor(180, 180, 180), 1, Qt::PenStyle::DashLine));//网格白色虚线
    ui->customplotwidget->xAxis->grid()->setSubGridPen(QPen(QColor(50, 50, 50), 1, Qt::DotLine));//网格浅色点线
    ui->customplotwidget->yAxis->grid()->setSubGridPen(QPen(QColor(50, 50, 50), 1, Qt::DotLine));//网格浅色点线

    //设置图例
    //ui->customplotwidget->legend->setVisible(true);

    //添加曲线
    //_p_iq_Graph1 = ui->customplotwidget->addGraph();
    //ui->customplotwidget->graph(0)->setPen(QPen(Qt::red));
    //_p_iq_Graph2 = ui->customplotwidget->addGraph();
    //ui->customplotwidget->graph(1)->setPen(QPen(Qt::green));

    //添加曲线名称
    //_p_iq_Graph1->setName("实部");
    //_p_iq_Graph2->setName("虚部");

    //立即刷新图像
    ui->customplotwidget->rescaleAxes();//自适应大小
    ui->customplotwidget->replot(QCustomPlot::rpQueuedReplot);
}

void CustomPlotForm::plot(const QVector<double> &vec_x, const QVector<double> &vec_y,const int graph_index)
{
    ui->customplotwidget->addGraph();//添加曲线
    ui->customplotwidget->graph(graph_index)->setData(vec_x,vec_y);//给曲线添加数据
    ui->customplotwidget->rescaleAxes();//自适应大小
    ui->customplotwidget->replot(QCustomPlot::rpQueuedReplot);

    switch(graph_index)
    {
        case 0:ui->customplotwidget->graph(0)->setPen(QPen(Qt::blue));break;
        case 1:ui->customplotwidget->graph(1)->setPen(QPen(Qt::red));break;
    }

    ui->customplotwidget->yAxis->setRange(40, 120);
}


void CustomPlotForm::setGraph(const QString title_name, const QString xlabel_name, const QString ylabel_name)
{
    //设置标题（title）
    QCPTextElement *titleElement = new QCPTextElement((ui->customplotwidget), title_name, QFont("sans", 9, QFont::Normal));
    titleElement->setTextColor(Qt::black);
    ui->customplotwidget->plotLayout()->insertRow(0);
    ui->customplotwidget->plotLayout()->addElement(0, 0, titleElement);

    //设置坐标轴
    ui->customplotwidget->xAxis->setLabel(xlabel_name);//添加标签label
    ui->customplotwidget->xAxis->setLabelColor(Qt::black);
    ui->customplotwidget->yAxis->setLabel(ylabel_name);
    ui->customplotwidget->yAxis->setLabelColor(Qt::black);

}



