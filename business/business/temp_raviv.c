#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "print_l.h"
#include <string.h>

void main (){
    PrintLogo();
    char* yes_char[1];

    printf("enter char: ");
    scanf("%s", &*yes_char);
if(strcmp(*yes_char, "y") == 0){

      printf ("\n you are OK!");
    }
    printf ("\nyou are not GOOD !\n");
    printf("%s\n", *yes_char);
}