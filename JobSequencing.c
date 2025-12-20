#include <stdio.h>
#include <stdlib.h>
struct job{
    int index;
    int profit;
    int deadline;
};
int compare(const void *a,const void *b){
    struct job* j1=(struct job*)a;
    struct job* j2=(struct job*)b;
    return j2->profit-j1->profit;
}
void main(){
    int n;
    if(scanf("%d",&n)!=1) return;
    struct job jobs[10];
    for(int i=0;i<n;i++){
        scanf("%d",&jobs[i].profit);
        scanf("%d",&jobs[i].deadline);
        jobs[i].index=i+1;
    }
    qsort(jobs,n,sizeof(struct job),compare);
    int maxDeadline=0;
    for(int i=0;i<n;i++){
        if(jobs[i].deadline>maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    int slots[10];
    for(int i=0;i<=maxDeadline;i++){
        slots[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(slots[j]==-1){
                slots[j]=jobs[i].index;
                break;
            }
        }
    }
    printf("Index Profit Deadline Slots:\n");
    for(int i=0;i<n;i++){
        printf("%d %d %d ",jobs[i].index,jobs[i].profit,jobs[i].deadline);
        int slot=-1;
        for(int s=1;s<=maxDeadline;s++){
            if(slots[s]==jobs[i].index){
                slot=s;
            }
        }
        if(slot!=-1){
            printf("%d-%d",slot-1,slot);
        }else{
            printf("Rejected\n");
        }
    }
    
}