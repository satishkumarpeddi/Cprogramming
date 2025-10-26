#include <stdio.h>
int val[10],wt[10];
int n,W;
int maxValue=0;
void knapsack(int i,int currentWeight,int currentValue){
    if(i==n){
        if(currentValue>maxValue)
            maxValue=currentValue;
        return;
    }
    if(currentWeight+wt[i]<=W)
        knapsack(i+1,currentWeight+wt[i],currentValue+val[i]);
    knapsack(i+1,currentWeight,currentValue);
}
void main(){
    printf("Enter no of items: ");
    if(scanf("%d",&n)!=-1) return;
    printf("Enter no values for items:\n");
    for(int i=0;i<n;i++)
        if(scanf("%d",&val[i])!=-1) return;
    printf("Enter weights of items: \n");
    for(int i=0;i<n;i++)
        if(scanf("%d",&wt[i])!=-1) return;
    printf("Enter capactiy of the bag:");
    if(scanf("%d",&W)!=-1) return;
    printf("Maximum value in Knapsack = %d\n",maxValue);
}