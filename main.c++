#include <QCoreApplication>
#include "decoder.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    decode(argv);
    return a.exec();
}
