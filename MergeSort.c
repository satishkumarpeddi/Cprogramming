#include <stdio.h>
#include <stdlib.h>
void merge(int arr[],int low,int mid,int high){
    int n1 = mid-low+1;
    int n2 = high-mid;
    int left[10];
    int right[10];
    for(int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=left[i++];
    }
    while(j<n2){
        arr[k++]=right[j++];
    }
}
void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid = low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void main(){
    int arr[] = {32,12,4,5,6,7,8,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d --> ",arr[i]);
    }
}