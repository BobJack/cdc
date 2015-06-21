/*
Автор кодера - Курашин Максим
*/
#include <iostream>
#include <fstream>

using namespace std;

void mirror(int *s, int n);

int main(int argc, char const *argv[]){
	int pos;
	fstream f;
	char const *pathToFile = argv[1];
	const int maxpass = 128;
	if (pathToFile) {
		f.open(pathToFile, ios::in | ios::out);
		char *c = new char;
		string password;
		cout<<"Enter password"<<endl;
		getline(cin, password);
		int passlen = password.length();
		if (passlen > maxpass){
			cerr<<"Your password is too long!"<<endl;
			return -1;
		}
		int binary[8];
		char temp;
		f.seekg(0, ios::beg);
		for (int i = 0; i<passlen; i++){
			temp = password[i];
			for (int j = 0; j < 8; j++){
				*(binary+j) = temp%2;
			    temp = temp / 2;
			}
			mirror(binary, 8);
			for (int j = 0; j < 8; j++){
				f.read(c, 1);
				f.seekg(i*8+j, ios::beg);
				if (*(binary+j))
				    *c = *c | binary[j];
				else
				    *c = *c & 254;			
				f.write(c,1);	
			} 
		}	
		delete(c);
		f.close();
		cout<<"Lenght of message:"<<passlen<<endl;
	} else {
		cout<<"Enter filename as argument!"<<endl;
		return -1;
	}
}

void mirror(int *s, int n){ //change the position of letters arranged symmetrically relative to the central letter
	int t;
	for (int i = 0, j = n - 1 ;i < j; i++,j--){ 
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
