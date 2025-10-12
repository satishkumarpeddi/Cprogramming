#include <stdio.h>
void main(){
    int a=5,b=10;
    a=a^b^(b=a);
    printf(" %d --> %d ", a,b);
}