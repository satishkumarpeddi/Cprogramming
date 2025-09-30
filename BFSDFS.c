#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
struct graph{
    int vertices;
    struct node **adjLists;
    int * visited;//Dynamic Programming apporach
};
typedef struct graph *GRAPH;
struct queue{
    int items[MAX];
    int front;
    int rear;
};
typedef struct queue *QUEUE;
NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
GRAPH createGraph(int vertices){
    GRAPH G = (GRAPH)malloc(sizeof(struct graph));
    G->vertices=vertices;
    G->adjLists = (NODE*)malloc(vertices*sizeof(NODE));
    G->visited = (int*)malloc(vertices*sizeof(int));
    for(int i=0;i<vertices;i++){
        G->adjLists[i]=NULL;
        G->visited[i]=0;
    }
    return G;
}
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
    if(q->front==-1)
        q->front=q->rear=0;
    q->items[q->rear++]=data;
}
int dequeue(QUEUE q){
    if(q->front==-1){
        printf("Queue is underflow\n");
        return -1;
    }
    int item = q->items[q->front++];
    if(q->front>q->rear)
        q->front=q->rear=-1;
    return item;
}
bool isEmpty(QUEUE q){
    return (q->front==-1||q->front>q->rear);
}
void addEdge(GRAPH G, int src, int dest){
    NODE newNode = createNode(dest);
    newNode->next= G->adjLists[src];
    G->adjLists[src]=newNode;
    newNode = createNode(src);
    newNode->next=G->adjLists[dest];
    G->adjLists[dest] = newNode;
}
void bfs(GRAPH G,int startIndex){
    QUEUE q = createQueue();
    G->visited[startIndex]=1;
    enqueue(q,startIndex);
    printf("The BFS Traversal Start From Index %d : ",startIndex);
    while(!isEmpty(q)){
        int currentIndex = dequeue(q);
        printf("%d --> ",currentIndex);
        NODE temp = G->adjLists[currentIndex];
        while(temp){
            int adjIndex = temp->data;
            if(G->visited[adjIndex]==0){
                G->visited[adjIndex]=1;
                enqueue(q,adjIndex);
            }
            temp=temp->next;
        }
    }
}
void dfs(GRAPH G, int startIndex){
    G->visited[startIndex]=1;
    printf("%d --> ",startIndex);
    NODE temp = G->adjLists[startIndex];
    while(temp){
        int adjIndex = temp->data;
        if(G->visited[adjIndex]==0){
            dfs(G,adjIndex);
        }
        temp=temp->next;
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
    for(int i = 0; i < V; i++) {
        graph->visited[i] = 0;
    }
    printf("\n");
    dfs(graph,0);
}