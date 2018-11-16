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
  char tempChar;

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
      if(temp == 0) *status = 2; //pembagian dengan nol
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
    if(*result == 0 && temp1 <= 0) {*status = 2;} //0 pangkat 0 atau 0 pangkat negatif
    else if (*result <0 && trunc(temp1) != temp1) {*status = 2;} //negatif pangkat pecahan 
    else {*result = pow(*result,temp1);}
  }
}
void sign(char *strIn,int *idx, float *result,int *status)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(strIn[*idx] == '('){
    (*idx)++;
    plusMinus(strIn,idx,result,status);
    if(strIn[*idx] == ')'){
      (*idx)++;
    }else{
      *status = 1;
    }
  }else{
    /* Cek negatif*/
    if(strIn[*idx] == '-'){
      (*idx)++;
      *result = -1;
    }else{
      *result = 1;
    }

    if(isNumber(strIn[*idx])){
      *result *= getNumber(strIn, idx);
    }else{
      *status = 1;
    }
  }
}

float getNumber(char *strIn, int *idx)
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

  return temp;
}
