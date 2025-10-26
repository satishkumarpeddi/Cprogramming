#include <stdio.h>
#include <stdbool.h>
#define N 4
void printMethod(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%s ",board[i][j]?"Q":".");
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N],int row,int col){
    for(int i=0;i<row;i++)
        if(board[i][col])
            return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j])
            return false;
    for(int i=row,j=col;i>=0&&j<N;i--,j++)
        if(board[i][j])
            return false;
    return true;
}
bool solveNQUtil(int board[N][N],int row){
    if(row==N){
        printMethod(board);
        return true;
    }
    bool res=false;
    for(int col=0;col<N;col++){
        if(isSafe(board,row,col)){
            board[row][col]=1;
            res = solveNQUtil(board,row+1)||res;
            board[row][col]=0;
        }
    }
    return res;
}
void solveNQ(){
    int board[N][N]={0};
    if(!solveNQUtil(board,0))
        printf("Solution does not exist\n");
}
void main(){
    solveNQ(); 
}