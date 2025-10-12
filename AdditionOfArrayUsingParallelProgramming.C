#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main(){
    int arr[] = {3,2,1,4,5,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++){
            // int tid = omp_get_thread_num(); 
            printf("Thread adding arr[%d] = %d\n",i,arr[i]);
            sum+=arr[i];
        }
    
    printf("Sum of the array element %d\n",sum);
    return 0;
}