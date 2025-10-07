#include <stdio.h>
#include <stdlib.h>
void main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n/2;i++){
        arr[i]^=arr[n-1-i];
        arr[n-1-i]^=arr[i];
        arr[i]^=arr[n-1-i];
    }
    printf("Reversed array elements:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}