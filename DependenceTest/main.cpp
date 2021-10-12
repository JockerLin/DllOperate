#include "DependenceTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DependenceTest w;
    w.show();
    return a.exec();
}
