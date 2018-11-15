#include "parser.h"

boolean isNumber(char st) {
    return (st >= '0') && (st <='9');
}

void Calculate(char *st, int *idx, float *result, boolean *valid)
{
  /* KAMUS LOKAL */
  float temp;
  char tempChar;

  /* ALGORITMA */
  if (st[*idx]!='\0'){

      KaliBagi(st, idx, result,valid);
      while (st[*idx] == '+' || st[*idx] == '-'){
        if(st[*idx] == '+'){
          (*idx)++;
          KaliBagi(st,idx,&temp,valid);
          *result += temp;
        }else if(st[*idx] == '-'){
          (*idx)++;
          KaliBagi(st,idx,&temp,valid);
          *result -= temp;
        }
      }
      /* st[*idx] != '+' atau '-' */
  }
}

void KaliBagi(char *st,int *idx, float *result,boolean *valid)
{
  /* KAMUS LOKAL*/
  float temp;

  /* ALGORITMA */
  Sign(st,idx,result,valid);

  while (st[*idx] == '*' || st[*idx] == '/'){
    if(st[*idx] == '*'){
      (*idx)++;
      Sign(st,idx,&temp,valid);
      (*result) *= temp;
    }else if(st[*idx] == '/'){
      (*idx)++;
      Sign(st,idx,&temp,valid);
      (*result) /= temp;
    }
  }
}

void Sign(char *st,int *idx, float *result,boolean *valid)
{
  float temp = 0;
  int x = 1;
  if(st[*idx] == '(') {
      (*idx)++;
      Calculate(st,idx,result,valid);
      if (st[*idx] == ')')
          (*idx)++;
      //else print error
  } else {
      if (st[*idx] == '-')
      {
          (*idx)++;
          x = -1;
      }
      if (isNumber(st[*idx]))
      {

          *result = getNumber(st, idx);
          temp = 0;
      }
      else
      {
          *valid = false;
      }
  }
}

float getNumber(char *st, int *idx)
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
    tempChar = st[*idx];
    if(isNumber(tempChar)||tempChar=='.'){

      if(tempChar=='.'){
        floatPart = true;
        floatDiv = 10;
        (*idx)++;
        tempChar = st[*idx];
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
