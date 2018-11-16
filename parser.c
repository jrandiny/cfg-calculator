#include "parser.h"

boolean isNumber(char strIn)
{
    return (strIn >= '0') && (strIn <='9');
}

void plusMinus(char *strIn, int *idx, float *result, boolean *valid)
{
  /* KAMUS LOKAL */
  float temp;
  char tempChar;

  /* ALGORITMA */
  if (strIn[*idx]!='\0'){

      kaliBagi(strIn, idx, result,valid);
      while((strIn[*idx] == '+') ||( strIn[*idx] == '-')){
        if(strIn[*idx] == '+'){
          (*idx)++;
          kaliBagi(strIn,idx,&temp,valid);
          *result += temp;
        }else if(strIn[*idx] == '-'){
          (*idx)++;
          kaliBagi(strIn,idx,&temp,valid);
          *result -= temp;
        }
      }
      /* strIn[*idx] != '+' atau '-' */
  }
}

void kaliBagi(char *strIn,int *idx, float *result,boolean *valid)
{
  /* KAMUS LOKAL*/
  float temp;

  /* ALGORITMA */
  sign(strIn,idx,result,valid);

  while((strIn[*idx] == '*') || (strIn[*idx] == '/')){
    if(strIn[*idx] == '*'){
      (*idx)++;
      sign(strIn,idx,&temp,valid);
      (*result) *= temp;
    }else if(strIn[*idx] == '/'){
      (*idx)++;
      sign(strIn,idx,&temp,valid);
      (*result) /= temp;
    }
  }
}

void sign(char *strIn,int *idx, float *result,boolean *valid)
{
  /* KAMUS LOKAL */

  /* ALGORITMA */
  if(strIn[*idx] == '('){
    (*idx)++;
    plusMinus(strIn,idx,result,valid);
    if(strIn[*idx] == ')'){
      (*idx)++;
    }else{
      *valid = false;
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
      *valid = false;
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
