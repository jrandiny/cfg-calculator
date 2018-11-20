#include "parser.h"
#include <math.h>

int isNumber(char strIn)
{
    return (strIn >= '0') && (strIn <='9');
}

void plusMinus(char *strIn, int *idx, float *result, int *status)
{
  /* KAMUS LOKAL */
  float temp;

  /* ALGORITMA */
  kaliBagi(strIn, idx, result,status);
  while((strIn[*idx] == '+') ||( strIn[*idx] == '-')){
    if(strIn[*idx] == '+'){
      (*idx)++;
      kaliBagi(strIn,idx,&temp,status);
      *result += temp;
    }else if(strIn[*idx] == '-'){
      (*idx)++;
      kaliBagi(strIn,idx,&temp,status);
      *result -= temp;
    }
  }
  /* strIn[*idx] != '+' atau '-' */
}

void kaliBagi(char *strIn,int *idx, float *result,int *status)
{
  /* KAMUS LOKAL*/
  float temp;

  /* ALGORITMA */
  pangkat(strIn,idx,result,status);

  while((strIn[*idx] == '*') || (strIn[*idx] == '/')){
    if(strIn[*idx] == '*'){
      (*idx)++;
      pangkat(strIn,idx,&temp,status);
      (*result) *= temp;
    }else if(strIn[*idx] == '/'){
      (*idx)++;
      pangkat(strIn,idx,&temp,status);
      if(temp == 0) *status = 2; /* pembagian dengan nol */
      else (*result) /= temp;
    }
  }
  /* strIn[*idx] != '*' atau '/' */
}

void pangkat(char *strIn,int *idx, float *result,int *status)
{
  /* KAMUS LOKAL*/
  float temp1;

  /* ALGORITMA */
  sign(strIn,idx,result,status);

  if(strIn[*idx] == '^'){
    (*idx)++;
    pangkat(strIn,idx,&temp1,status);
    if(*result == 0 && temp1 <= 0) {*status = 2;} /* 0 pangkat 0 atau 0 pangkat negatif */
    else if (*result <0 && trunc(temp1) != temp1) {*status = 2;}/* negatif pangkat pecahan */
    else {*result = pow(*result,temp1);}
  }
}
void sign(char *strIn,int *idx, float *result,int *status)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(strIn[*idx] == '('){
    (*idx)++;
    if(strIn[*idx]=='-'){
      (*idx)++;
      number(strIn, idx, result, status);
      *result *= -1;
      if(strIn[*idx] == ')'){
        (*idx)++;
      }else{
        *status = 1;
      }
    }else{
      plusMinus(strIn,idx,result,status);
      if(strIn[*idx] == ')'){
        (*idx)++;
      }else{
        *status = 1;
      }
    }
  }else{
    if(strIn[*idx]=='-'){
      (*idx)++;
      if(strIn[*idx] == '('){
        (*idx)++;
        plusMinus(strIn, idx, result, status);
        if(strIn[*idx] == ')'){
          *result *= -1;
          (*idx)++;
        }else{
          *status = 1;
        }
      }
    }else if(isNumber(strIn[*idx])){
      number(strIn, idx, result, status);
    }else{
      *status = 1;
    }
  }
}

void number(char *strIn, int *idx, float *result, int *status)
{
  /* KAMUS LOKAL */
  float temp;
  float tempDigit;
  char tempChar;
  boolean floatPart;
  int floatDiv;

  /* ALGORITMA */
  temp = 0;
  floatPart = false;

  do{
    tempChar = strIn[*idx];
    if(isNumber(tempChar)||tempChar=='.'){

      if(tempChar=='.'){
        floatPart = true;
        floatDiv = 10;
        (*idx)++;
        tempChar = strIn[*idx];
        tempDigit = tempChar - '0';
      }else{
        tempDigit = tempChar - '0';
      }

      if(floatPart){
        tempDigit /= floatDiv;
        floatDiv *= 10;
      }else{
        temp *=10;
      }

      temp += tempDigit;

      (*idx)++;
    }

  }while(isNumber(tempChar));
  /* !isNumber(tempChar) */

  *result = temp;
}
