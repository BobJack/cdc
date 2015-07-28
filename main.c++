#include <QCoreApplication>
#include "globalsettings.h"


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    if (argc < 2) {
        showHelp();
    } else {
        chooseAction(argv);
    }
    a.exit();
}
