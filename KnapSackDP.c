#include <stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int knapsack(int n,int wt[],int val[],int W){
    int dp[100][100];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0||w==0)
                dp[i][w]=0;
            else if(wt[i-1]<=w)
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];
    }
void main(){
    int n,W;
    printf("Enter no of items: ");
    scanf("%d",&n);
    int val[10],wt[10];
    printf("Enter values of items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    printf("Enter weights of items: ");
    for(int i=0;i<n;i++)
        scanf("%d",&wt[i]);
    printf("Enter capacity of knapsack: ");
    scanf("%d",&W);
    int maxValue = knapsack(n,wt,val,W);
    printf("Maximum value in Knapsack = %d\n",maxValue);
}