#include <stdio.h>
int fib(int value){
    int dp[10];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=value;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
}
void main(){
    int value =5;
    printf("%d --> ",fib(value));
}