#include "iniciarsesion.h"
#include "singup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iniciarsesion w;
    w.show();
    return a.exec();
}
