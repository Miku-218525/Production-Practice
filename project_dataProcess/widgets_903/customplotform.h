#ifndef CUSTOMPLOTFORM_H
#define CUSTOMPLOTFORM_H

#include <QWidget>

namespace Ui {
class CustomPlotForm;
}

class CustomPlotForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomPlotForm(QWidget *parent = nullptr);
    ~CustomPlotForm();

    void CustomPlotForm_Init();
    void plot(const QVector<double>&vec_x,const QVector<double>&vec_y,const int graph_index=0);
    void setGraph(const QString title_name,const QString xlabel_name,const QString ylabel_name);

private:
    Ui::CustomPlotForm *ui;
};

#endif // CUSTOMPLOTFORM_H
