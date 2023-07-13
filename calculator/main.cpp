#include "calcer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    calcer w;
    w.show();
    return a.exec();
}
