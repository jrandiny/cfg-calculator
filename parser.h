#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "boolean.h"

/*
S -> T | S+T | S-T calculate
T -> F | T*F | T/F KaliBagi
F -> (S) | A sign
A -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | AA number
*/

boolean isNumber(char strIn);
void plusMinus(char *strIn, int *idx, float *result, boolean *valid);
void kaliBagi(char *strIn,int *idx, float *result,boolean *valid);
void sign(char *strIn,int *idx, float *result,boolean *valid);
float getNumber(char *strIn, int *idx);

#endif
