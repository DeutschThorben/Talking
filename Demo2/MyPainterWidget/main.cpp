#include "mypainterwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyPainterWidget w;
    w.show();

    return a.exec();
}
