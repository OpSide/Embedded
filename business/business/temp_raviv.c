#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "print_l.h"
#include <string.h>

void RedColor () {
  printf("\033[1;31m");
}
void WhiteColor () {
  printf("\033[0m");
}
void GreenColor () {
  printf("\033[0;32m");
}
void main (){

RedColor();
printf("\nhi\n");
WhiteColor();
printf("\ncheck2\n");
GreenColor();
printf("green");
WhiteColor();
}