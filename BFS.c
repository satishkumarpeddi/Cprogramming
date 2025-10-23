#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
struct graph{
    int vertices;
    struct node **adjList;
    int* visited;
};
typedef struct graph *GRAPH;
struct queue{
    int front;
    int rear;
    int items[MAX];
};
typedef struct queue *Q;
NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
GRAPH createGraph(int vertices){
    GRAPH g = (GRAPH)malloc(sizeof(struct graph));
    g->vertices=vertices;
    g->adjList = (NODE*)malloc(vertices*sizeof(NODE));
    g->visited = (int*)malloc(vertices*sizeof(int));
    for(int i=0;i<vertices;i++){
        g->adjList[i]=NULL;
        g->visited[i]=0;
    }
    return g;
}
Q createQueue(){
   Q q = (Q)malloc(sizeof(struct queue));
   q->front=-1;
   q->rear=-1;
   return q; 
}
void enqueue(Q q,int data){
    if(q->rear==MAX-1){
        printf("Queue is overflow\n");
        return;
    }
    if(q->front==-1)
        q->front=q->rear=0;
    q->items[q->rear++]=data;
}
int dequeue(Q q){
    if(q->front==-1){
        printf("Queue is underflow\n");
        return -1;
    }
    int value = q->items[q->front++];
    if(q->front>q->rear)
        q->front=q->rear=-1;
    return value;
}
bool isEmpty(Q q){
    return q->front==-1||q->front>q->rear;
}
void addEdge(GRAPH g,int src,int dest){
    NODE newNode = createNode(dest);
    newNode->next=g->adjList[src];
    g->adjList[src]=newNode;
    newNode = createNode(src);
    newNode->next=g->adjList[dest];
    g->adjList[dest]=newNode;
}
void bfs(GRAPH g,int startIndex){
    Q q = createQueue();
    g->visited[startIndex]=1;
    enqueue(q,startIndex);
    printf("The BFS Traversal Start's for index %d: ",startIndex);
    while(!isEmpty(q)){
        int currentIndex = dequeue(q);
        printf("%d --> ",currentIndex);
        NODE temp = g->adjList[currentIndex];
        while(temp){
            int adjIndex = temp->data;
            if(g->visited[adjIndex]==0){
                g->visited[adjIndex]=1;
                enqueue(q,adjIndex);
            }
            temp=temp->next;
        }
    }
}
void main(){
    int V = 5;
    GRAPH graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    bfs(graph,0);
}