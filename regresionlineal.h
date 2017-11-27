#ifndef REGRESIONLINEAL_H
#define REGRESIONLINEAL_H

#include <QMainWindow>

namespace Ui {
class regresionlineal;
}

class regresionlineal : public QMainWindow
{
    Q_OBJECT

public:
    explicit regresionlineal(QWidget *parent = 0);
    ~regresionlineal();
    double m,b,x1,x2,x3,x4,x5,x6,x7,y1,y2,y3,y4,y5,y6,y7,xy1,xy2,xy3,xy4,xy5,xy6,xy7,xx1,xx2,xx3,xx4,xx5,xx6,xx7,y,sr,sx,sy,sxy,sxx,n,py,px;
public slots:
    void REGRE();
    void Llenar_tabla(int i, double r, double t, double y);
private:
    Ui::regresionlineal *ui;
};

#endif // REGRESIONLINEAL_H
