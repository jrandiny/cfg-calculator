#include <stdio.h>
#include <string.h>
#include "parser.h"

#ifdef __linux__
#include <readline/readline.h>
#include <readline/history.h>
#endif

int main()
{
    /* KAMUS */
    int status;
    int idx;
    float res;
    char *strIn;


    /* ALGORITMA */
    printf("\n");
    printf("                  888                   888          888                     \n");
    printf("                  888                   888          888                     \n");
    printf("                  888                   888          888                     \n");
    printf(" .d8888b  8888b.  888  .d8888b 888  888 888  8888b.  888888  .d88b.  888d888 \n");
    printf("d88P'        '88b 888 d88P'    888  888 888     '88b 888    d88''88b 888P'   \n");
    printf("888      .d888888 888 888      888  888 888 .d888888 888    888  888 888     \n");
    printf("Y88b.    888  888 888 Y88b.    Y88b 888 888 888  888 Y88b.  Y88..88P 888     \n");
    printf(" 'Y8888P 'Y888888 888  'Y8888P  'Y88888 888 'Y888888  'Y888  'Y88P'  888     \n\n");

    printf("Silahkan masukkan input: (ketik 'exit' untuk mengakhiri program)\n");

    #ifdef __linux__
    strIn = readline(">> ");
    #else
    printf(">> ");
    scanf("%s", strIn);
    #endif

    while(strcmp(strIn,"exit") != 0){

        status = 0;
        //status = 0 ekspresi valid
        //status = 1 syntax errror
        //status = 2 math error
        idx = 0;
        res = 0;
        plusMinus(strIn, &idx, &res, &status);
        printf(">> ");
        if (status==0 && strIn[idx]=='\0'){
            printf("%.2f\n",res);
        }else{
            if (status == 2 && strIn[idx] =='\0'){
                printf("Math Error\n");
            }
            else{
                printf("Syntax Error\n");
            }
        }

        printf("\nSilahkan masukkan input: (ketik 'exit' untuk mengakhiri program)\n");
        
        #ifdef __linux__
        strIn = readline(">> ");
        #else
        printf(">> ");
        scanf("%s", strIn);
        #endif
    }

    return 0;

}
