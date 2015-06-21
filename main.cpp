#include "stega.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stega w;
    w.show();

    return a.exec();
}
