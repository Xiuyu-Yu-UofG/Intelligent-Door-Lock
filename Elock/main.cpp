#include "welcome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MTCNNDetection();
    Welcome w;
    w.show();
    return a.exec();
}
