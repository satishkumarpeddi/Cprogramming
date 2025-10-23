#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
struct queue{
    int front;
    int rear;
    int items[MAX];
};
typedef struct queue *Q;
Q createQueue(){
    Q q = (Q)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
void enqueue(Q q,int data){
    if(q->rear==MAX-1){
        printf("Queue is overflow.\n");
        return;
    }
    if(q->front==-1){
        q->front=q->rear=0;
    }
    q->items[q->rear++]=data;
}
int dequeue(Q q){
    if(q->front==-1){
        printf("Queue si underflow.\n");
        return -1;
    }
    int item = q->items[q->front++];
    if(q->front>q->rear){
        q->front=q->rear=-1;
    }
    return item;
}
bool isEmpty(Q q){
    return q->front==-1||q->front>q->rear;
}
void bfs(int graph[][MAX],int vertices,int startIndex){
    bool visited[MAX]={false};
    Q q = createQueue();
    visited[startIndex]=true;
    printf("The BFS Travesal Starting from the index %d --> ",startIndex);
    enqueue(q,startIndex);
    while(!isEmpty(q)){
        int current = dequeue(q);
        printf("%d --> ",current);
        for(int i=0;i<vertices;i++){
            if(graph[current][i]==1&&!visited[i]){
                visited[i]=true;
                enqueue(q,i);
            }
        }
    }
}
void main(){
     int vertices =5;
    int graph[MAX][MAX] = {0};
    graph[0][1] = 1; graph[1][0] = 1;
    graph[0][2] = 1; graph[2][0] = 1;
    graph[1][3] = 1; graph[3][1] = 1;
    graph[3][4] = 1; graph[4][3] = 1;
    graph[4][5] = 1; graph[5][4] = 1;
    graph[1][5] = 1; graph[5][1] = 1;
    bfs(graph,vertices,0);
}