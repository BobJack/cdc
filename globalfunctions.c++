#include "coder.h"
#include "decoder.h"
#include "globalsettings.h"

void showHelp() {
    string helpMessage = "\nSyntax: cdc flag path_to_file\n\n\
Flags: --help (-h)    Prints help\n\
       --code (-c)    Code message\n\
       --decode (-d)  Decode message\n\r";
    cout<<helpMessage;
}

void chooseAction(char *argv[]) {
    string variantOfAction = argv[1];
    char const *pathToFile = argv[2];
    if (variantOfAction == "-h" || variantOfAction == "--help") {
        showHelp();
    } else if (variantOfAction == "-c" || variantOfAction == "--code") {
        code(pathToFile);
    } else if (variantOfAction == "-d" || variantOfAction == "--decode") {
        decode(pathToFile);
    } else {
        cout<<"Unknown flag! To show help type cdc -h"<<endl;
    }
}
