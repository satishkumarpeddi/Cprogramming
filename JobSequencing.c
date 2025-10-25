#include <stdio.h>
#include <stdlib.h>
struct job{
    int index;
    int profit;
    int deadline;
};
typedef struct job *JOB;
int compare(const void *a,const void *b){
    JOB j1 = (JOB)a;
    JOB j2 = (JOB)b;
    return j2->profit-j1->profit;
}
void main(){
    int n;
    scanf("%d",&n);
    JOB jobs[10];
    for(int i=0;i<n;i++){
        printf("%d",&jobs[i]->profit);
        printf("%d",&jobs[i]->deadline);
        jobs[i]->index =i+1;
    }
    qsort(jobs,n,sizeof(struct job),compare);
    int maxDeadline=0;
    for(int i=0;i<n;i++){
        if(jobs[i]->deadline>maxDeadline){
            maxDeadline=jobs[i]->profit;
        }
    }
    int slots[10];
    for(int i=0;i<n;i++)
        slots[i]=-1;
    int slotsAssigned[10];
    for(int i=0;i<n;i++)
        slotsAssigned[i]=-1;
    for(int i=0;i<n;i++){
        for(int j=jobs[i]->deadline;j>0;j--){
            if(slots[j]==-1)
                slots[j]=jobs[i]->index;
                slotsAssigned[jobs[i]->index-1]=j;
                break;
        }
    }
    printf("Index Profit Deadline Slot Alloted\n");
    for(int i=0;i<n;i++){
        printf("%d %d %d",i+1,jobs[i]->profit,jobs[i]->deadline);
        int slot=-1;
        for(int s =1;s<=maxDeadline;s++){
            if(slots[s]==jobs[i]->index)
                slot=s;
            
        }
        if(slot!=-1)
            printf("[%d-%d]\n",slot-1,slot);
        else
            printf("Rejected\n");
    }
}