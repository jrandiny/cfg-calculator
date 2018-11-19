#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "boolean.h"

/*
S -> T | S+T | S-T calculate
T -> P | T*P | T/P KaliBagi
P -> F | F^P
F -> (S) | A sign
A -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | AA number
*/

int isNumber(char strIn);
void plusMinus(char *strIn, int *idx, float *result, int *status);
void kaliBagi(char *strIn,int *idx, float *result,int *status);
void pangkat(char *strIn,int *idx, float *result,int *status);
void sign(char *strIn,int *idx, float *result,int *status);
float getNumber(char *strIn, int *idx);

#endif
