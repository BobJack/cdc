#ifndef DECODER_H
#define DECODER_H
#endif // DECODER_H

#include <math.h>

#define getbit(x,pos) ( ((x) & ( 0x1 << (pos) )) !=0 ) // get bit per position

char toDec(const int n, const int *arr);
int decode(char const *pathToFile);
