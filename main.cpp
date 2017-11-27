#include "regresionlineal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    regresionlineal w;
    w.show();

    return a.exec();
}
