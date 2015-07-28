#include "decoder.h"
#include "globalsettings.h"

char toDec(const int n, const int *arr) { // bin to dec (array of 1,0)
    int dec = 0, j = 0, p = 0;
    for (j = n, p = 0; j > n-8; j--, p++) {
        if (arr[j] == 1) {
            dec += pow(2,p);
        }
    }
    return dec;
}

int decode(char const *pathToFile) {
    int amountOfSymbols = 0, i;
    if (pathToFile) {
        ifstream fileToDecode(pathToFile, ios::in);
        cout<<"Amount of symbols:"<<endl;
        cin>>amountOfSymbols;

        int *bits = new int[n*8];
        fileToDecode.seekg(0,ios::beg);

        for (i = 0; i < (amountOfSymbols*8); i++) {
            bits[i] = getbit(fileToDecode.get(),0);
        }

        for (i = 7; i < (amountOfSymbols*8); i += 8) {
            cout<<toDec(i,bits);
        }

        delete []bits;
        fileToDecode.close();
        cout<<endl;
        return 0;
    } else {
        cout<<"Enter filename as argument!"<<endl;
        return -1;
    }
}
