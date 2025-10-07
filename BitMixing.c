#include <stdio.h>
#include <stdint.h>
uint32_t bitMix(uint32_t x){
    x^=x>>16;
    x*=0x7feb352d;
    x^=x>>15;
    x*=0x846ca68b;
    x^=x>>16;
    return x;
}
int main(){
    uint32_t num  = 12345;
    printf("Original : %u\n",num);
    printf("Bit-mixed: %u\n",bitMix(num));
    return 0;
}
//Bit Mixing --> Creating a random number as possible using a standard signature 