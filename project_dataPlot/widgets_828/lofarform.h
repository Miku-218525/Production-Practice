#ifndef LOFARFORM_H
#define LOFARFORM_H

#include <QWidget>

namespace Ui {
class LofarForm;
}

class LofarForm : public QWidget
{
    Q_OBJECT

public:
    explicit LofarForm(QWidget *parent = nullptr);
    ~LofarForm();

    void LofarForm_Init();

    void plot(const int h,const double *fftData);
    void flushplot();
    void setRange(int fStart,int fStop);

private:
    Ui::LofarForm *ui;
};

#endif // LOFARFORM_H
