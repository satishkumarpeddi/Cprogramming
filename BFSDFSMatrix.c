#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
struct queue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct queue *QUEUE;
QUEUE createQueue(){
    QUEUE q = (QUEUE)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
void enqueue(QUEUE q,int data){
    if(q->rear==MAX-1){
        printf("Queue is overflow\n");
        return;
    }
    if(q->front==-1){
        q->front=q->rear=0;
    }
    q->items[q->rear++]=data;
}
int dequeue(QUEUE q){
    if(q->front==-1){
        printf("Queue is underflow\n");
        return -1;
    }
    int item = q->items[q->front++];
    if(q->front>q->rear){
        q->front=q->rear=-1;
    }
    return item;
}
bool isEmpty(QUEUE q){
    return (q->front==-1||q->front>q->rear);
}
void bfs(int graph[][MAX],int vertices,int start){
    bool visited[MAX]={false};
    visited[start]=true;
    QUEUE q = createQueue();
    enqueue(q,start);
    printf("The BFS Traversal start from index %d: ",start);
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
void dfsUtilMethod(int graph[][MAX],int vertices,int current,bool visited[MAX]){
    visited[current]=true;
    printf("%d --> ",current);
    for(int i=0;i<vertices;i++){
        if(graph[current][i]==1&&!visited[i]){
            visited[i]=true;
            dfsUtilMethod(graph,vertices,i,visited);
        }    
    }
}
void dfs(int graph[][MAX],int vertices,int start){
    bool visited[MAX]={false};
    dfsUtilMethod(graph,vertices,start,visited);
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
    dfs(graph,vertices,0);
}