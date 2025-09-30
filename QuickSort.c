#include <stdio.h>
#include <stdlib.h>
int parition(int arr[],int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }   
    int temp = arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int partion=parition(arr,low,high);
        quickSort(arr,low,partion-1);
        quickSort(arr,partion+1,high);
    }
}
void main(){
    int arr[] = {32,12,4,5,6,7,8,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d --> ",arr[i]);
    }
}