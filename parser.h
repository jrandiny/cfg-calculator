#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include "boolean.h"

/*
S -> T | S+T | S-T calculate
T -> F | T*F | T/F KaliBagi
F -> (S) | -A | A | A.A | -A.A sign
A -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | AA number
*/

boolean isNumber(char st);
boolean isOperator(char st);
void Calculate(char *st, int *idx, float *result, boolean *valid);
void KaliBagi(char *st,int *idx, float *result,boolean *valid);
void Sign(char *st,int *idx, float *result,boolean *valid);
float getNumber(char *st, int *idx);

#endif
