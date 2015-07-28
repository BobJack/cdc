#ifndef DECODER_H
#define DECODER_H

#endif // DECODER_H

#include <fstream>
#include <iostream>
#include <math.h>

#define getbit(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 ) // get bit per position

using namespace std;

char todec(const int n, const int *arr);
int decode(char *argv[]);
