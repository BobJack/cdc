#include <fstream> // библиотека с классами файлов
#include <iostream> // библиотека ввода-вывода
#include <string>

#define getbit(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 )

using namespace std; 

main() {
	for(int i = 0; i < 8; i++) {
		cout<<getbit('w',i)<<endl;
	}
	return 0;
} 

// int main(int argc, char const *argv[]) {
// 	char const *pathToFile = argv[1];
// 	cout<<pathToFile;
// 	return 0;
// }
