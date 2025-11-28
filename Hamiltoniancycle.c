#include <stdio.h>
#include <stdlib.h>
int G[7][7]={
    {0,1,0,0,0,0,1},
    {1,0,1,0,0,0,0},
    {0,1,0,1,0,0,0},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,1,0},
    {0,0,0,0,1,0,1},
    {1,0,0,0,0,1,0}
};
int x[7];
int n=7;
void nextVertex(int k){
    while(1){
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
            return;
        if(G[x[k-1]-1][x[k]-1]!=0){
            int j;
            for(j=0;j<k;j++){
                if(x[j]==x[k])
                    break;
            }
            if(j==k){
                if(k<n||(k==n&&G[x[n]-1][x[0]-1]!=0))
                    return;
            }
        }
    }
}
void Hamiltonian(int k){
    while(1){
        nextVertex(k);
        if(x[k]==0)
            return;
        if(k==n){
            for(int i=0;i<=n;i++){
                printf("%d --> ",x[i]);
            }
            printf("%d\n",x[1]);
        }else{
            Hamiltonian(k+1);
        }
    }
}
void main(){
    for(int i=0;i<=n;i++){
        x[i]=0;
    }
    x[1]=1;
    Hamiltonian(2);
}