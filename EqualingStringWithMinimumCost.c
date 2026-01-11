#include <stdio.h>
#include <stdlib.h>
void main(){
    char *s1 = "sea"; 
    char *s2 = "eat";
    int m=0,n=0;
    while(s1[m]!='\0') m++;
    while(s2[n]!='\0') n++;
    int** dp;
    dp = (int**)malloc(m*sizeof(int*));
    
}