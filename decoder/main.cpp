#include <fstream> 
#include <iostream> 
#include <math.h>

#define getbit(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 ) // get bit per position

using namespace std; 

char todec(const int n, const int *arr) { // bin to dec (array of 1,0)
	int dec = 0, j = 0, p = 0;
	for (j = n, p = 0; j > n-8; j--, p++) {
		if (arr[j] == 1) {
			dec += pow(2,p);
		}
	}
	return dec;
}

int main(int argc, char const *argv[]){
	int n = 0, i;
	char const *pathToFile = argv[1];
	if (pathToFile) {
		ifstream fin(pathToFile, ios::in);
		cout<<"Количество символов:"<<endl;
		cin>>n;

		int *bits = new int[n*8]; 
		fin.seekg(0,ios::beg);

		for (i = 0; i < (n*8); i++) {
			bits[i] = getbit(fin.get(),0);
		}

		for (i = 7; i < (n*8); i += 8) {
			cout<<todec(i,bits);
		}

		delete []bits;
		fin.close();
		cout<<endl;
		return 0;
	} else {
		cout<<"Enter filename as argument!"<<endl;
		return -1;
	}
}