#include "coder.h"
#include "globalsettings.h"

void mirror(int *s, int n){ //change the position of letters arranged symmetrically relative to the central letter
    int t;
    for (int i = 0, j = n - 1 ;i < j; i++,j--){
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int code(char const *pathToFile) {
    fstream fileToCode;
    const int maxMessageLength = 128;
    if (pathToFile) {
        fileToCode.open(pathToFile, ios::in | ios::out);
        char *c = new char;
        string message;
        cout<<"Enter message (max "<<maxMessageLength<<") symbols"<<endl;
        getline(cin, message);
        int messageLength = message.length();
        if (messageLength > maxMessageLength){
            cerr<<"Your password is too long!"<<endl;
            return -1;
        }
        int binary[8];
        char temp;
        fileToCode.seekg(0, ios::beg);
        for (int i = 0; i<passlen; i++){
            temp = message[i];
            for (int j = 0; j < 8; j++){
                *(binary+j) = temp%2;
                temp = temp / 2;
            }
            mirror(binary, 8);
            for (int j = 0; j < 8; j++){
                fileToCode.read(c, 1);
                fileToCode.seekg(i*8+j, ios::beg);
                if (*(binary+j))
                    *c = *c | binary[j];
                else
                    *c = *c & 254;
                fileToCode.write(c,1);
            }
        }
        delete(c);
        fileToCode.close();
        cout<<"Lenght of message:"<<messageLength<<endl;
        return 0;
    } else {
        cout<<"Enter filename as argument!"<<endl;
        return -1;
    }
}
