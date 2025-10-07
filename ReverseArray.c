#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxArrSize 100000
int reverseArray(int Arr[],int ArrLen,int *resultArr){
    for(int i=ArrLen-1;i>=0;i--){
        resultArr[ArrLen-1-i]=Arr[i];
    }
    return ArrLen;
}
int readIntArray(char *argsArray,int arr[]){
    int col=0;
    char *token = strtok(argsArray,",");
    while(token!=NULL){
        arr[col]=atoi(token);
        token = strtok(NULL,",");
        col++;
    }
    return col;
}
void printArrayElements(int *resultsArr,int resultsArrLength){
    int index;
    for(index =0;index<resultsArrLength-1;index++){
        printf("%d ",resultsArr[index]);
    }
    printf("%d\n",resultsArr[index]);
}
int main(int argc,char *argv[]){
    int Arr[MaxArrSize];
    int ArrLen = readIntArray(argv[1],Arr);
    int resultsArr[MaxArrSize];
    int resultsArrLength= reverseArray(Arr,ArrLen,resultsArr);
    printArrayElements(resultsArr,resultsArrLength);
    return 0;
}