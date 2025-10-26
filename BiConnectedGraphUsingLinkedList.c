#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int time_counter =0;
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
struct graph{
    int vertices;
    struct node **adjList;
};
typedef struct graph *G;
NODE createNode(int data){
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
G createGraph(int vertices){
    G g = (G)malloc(sizeof(struct graph));
    g->vertices=vertices;
    g->adjList=(NODE*)malloc(vertices*sizeof(struct node));
    for(int i=0;i<vertices;i++){
        g->adjList[i]=NULL;
    }
    return g;
}
void addEdges(G g,int src,int dest){
    NODE newNode = createNode(dest);
    newNode->next=g->adjList[src];
    g->adjList[src]=newNode;
    newNode=createNode(src);
    newNode->next=g->adjList[dest];
    g->adjList[dest]=newNode;
}
bool DFS(G g,int u,int parent,int visited[],int low[],int disc[]){
    visited[u]=1;
    disc[u]=low[u]=++time_counter;
    int children=0;
    NODE temp=  g->adjList[u];
    while(temp){
        if(g->adjList[u]){
            if(!visited[u]){
                children++;
                if(!DFS(g,temp->data,u,visited,low,disc))
                    return false;
                low[u] = low[u]<low[temp->data]?low[u]:low[temp->data];
                if(parent!=-1&&low[temp->data]>=disc[u])
                    return false;
            }else if(temp->data!=parent){
                low[u]=low[u]<disc[temp->data]?low[u]:disc[temp->data];
            }
        }
        temp=temp->next;
    }
    if(parent==-1&&children>1)
        return false;
    return true;
}
bool isBiconnectedGraph(G g){
    int visited[MAX]={0};
    int disc[MAX],low[MAX];
    if(!DFS(g,0,-1,visited,low,disc))
        return false;
    for(int i=0;i<g->vertices;i++)
        if(!visited[i])
            return false;
    return true;
}
void main(){

    int v;
    printf("Enter number of vertices: ");
    if(scanf("%d",&v)!=-1) return;
    G g=createGraph(v);
    int e;
    printf("Enter number of edges: ");
    if(scanf("%d",&e)!=-1) return;
    printf("Enter %d edges of  (u v) from 0-index to %d:\n",e,v-1);
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdges(g,u,v);
    }
    if(isBiconnectedGraph(g))
        printf("Graph is connected.\n");
    else
        printf("Graph is not connected.\n");
}