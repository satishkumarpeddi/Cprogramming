#include <stdio.h>
#include <stdlib.h>
#define DP(mat,i,j) mat[(i)*cols+(j)]
void main(){
    int rows=3;
    int cols=3;
    int* A = (int*)calloc((rows*cols),sizeof(int));
    int* B = (int*)calloc((rows*cols),sizeof(int));
    int* C = (int*)calloc((rows*cols),sizeof(int));
    printf("Enter values for matrix A : ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int data;
            scanf("%d",&data);
            DP(A,i,j) = data;
        }
    }
    printf("Enter values for matrix B : ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int data;
            scanf("%d",&data);
            DP(B,i,j) = data;
        }
    }
    for(int i=0;i<rows;i++){ 
        for(int j=0;j<cols;j++){
            DP(C,i,j)=0;
            for(int k=0;k<cols;k++){
                DP(C,i,j)+=DP(A,i,k)*DP(B,k,j);
            }
        }
    }
    printf("The Result Matrix C :\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%3d ",DP(C,i,j));
        }
        printf("\n");
    }
}