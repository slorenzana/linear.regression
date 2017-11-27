#include "regresionlineal.h"
#include "ui_regresionlineal.h"
#include "math.h"
#include "QTableWidgetItem"
regresionlineal::regresionlineal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::regresionlineal)
{
    ui->setupUi(this);
    m=0.0;
    b=0.0;
    y=0.0;
    sr=0.0;
    connect(ui->calcular,SIGNAL(clicked()),this,SLOT(REGRE()));
}

regresionlineal::~regresionlineal()
{
    delete ui;
}
void regresionlineal::REGRE(){
    x1=ui->xi1->value();
    x2=ui->xi2->value();
    x3=ui->xi3->value();
    x4=ui->xi4->value();
    x5=ui->xi5->value();
    x6=ui->xi6->value();
    x7=ui->xi7->value();
    y1=ui->yi1->value();
    y2=ui->yi2->value();
    y3=ui->yi3->value();
    y4=ui->yi4->value();
    y5=ui->yi5->value();
    y6=ui->yi6->value();
    y7=ui->yi7->value();
    n=7;
    sxy=(x1*y1)+(x2*y2)+(x3*y3)+(x4*y4)+(x5*y5)+(x6*y6)+(x7*y7);
    sx=x1+x2+x3+x4+x5+x6+x7;
    sy=y1+y2+y3+y4+y5+y6+y7;
    sxx=(x1*x1)+(x2*x2)+(x3*x3)+(x4*x4)+(x5*x5)+(x6*x6)+(x7*x7);
    py=sy/7;
    px=sx/7;
    m=((n*sxy)-(sx*sy))/((n*sxx)-(sx*sx));
    b=(py-(m*px));
    y=m+b;
    sr=28*((sy-b-m)*(sy-b-m));
    Llenar_tabla(m,m,b,sr);
}
void regresionlineal::Llenar_tabla(int i, double r, double t, double y)
{
    QString temp;
    ui->tabla->insertRow(ui->tabla->rowCount());
    temp.setNum(i,4);
    ui->tabla->setItem(ui->tabla->rowCount()-1, 0, new QTableWidgetItem(tr(temp.toLatin1()),0));
    temp.setNum(r,'e',4);
    ui->tabla->setItem(ui->tabla->rowCount()-1, 1, new QTableWidgetItem(tr(temp.toLatin1()),0));
    temp.setNum(t,'e',4);
    ui->tabla->setItem(ui->tabla->rowCount()-1, 2, new QTableWidgetItem(tr(temp.toLatin1()),0));
    temp.setNum(y,'e',4);
    ui->tabla->setItem(ui->tabla->rowCount()-1, 3, new QTableWidgetItem(tr(temp.toLatin1()),0));
}
