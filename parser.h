#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "boolean.h"

/*
S -> T | S+T | S-T plusMinus
T -> F | T*F | T/F kaliBagi
F -> (S) | A sign
*/

boolean isNumber(char strIn);
void plusMinus(char *strIn, int *idx, float *result, boolean *valid);
void kaliBagi(char *strIn,int *idx, float *result,boolean *valid);
void sign(char *strIn,int *idx, float *result,boolean *valid);
float getNumber(char *strIn, int *idx);

#endif
