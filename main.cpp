#include "multitask.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MultiTask w;
    w.show();

    return a.exec();
}
