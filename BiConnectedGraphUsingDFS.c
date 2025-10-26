#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
int time_counter ;
struct graph{
    int vertices;
    int adjMatrix[MAX][MAX];
};
void initializeTheGraph(struct graph *g,int vertices){
    g->vertices=vertices;
    for(int i=0;i<vertices;i++) 
        for(int j=0;j<vertices;j++)
            g->adjMatrix[i][j]=0;
}
void addEdges(struct graph *g,int u,int v){
    g->adjMatrix[u][v]=1;
    g->adjMatrix[v][u]=1;
}
bool DFS(struct graph *g,int u,int parent,int visited[],int disc[],int low[]){
    visited[u]=1;
    disc[u]=low[u]=1;
    int children=0;
    for(int v=0;v<g->vertices;v++){
        if(g->adjMatrix[u][v]){
            if(!visited[v]){
                children++;
                if(!DFS(g,v,u,visited,disc,low))    
                    return false;
                low[u] = low[u]<low[v]?low[u]:low[v];
                if(parent!=-1&&low[v]>=disc[u])
                    return false;
            }else if(v!=parent){
                low[u]=low[u]<disc[v]?low[u]:low[v];
            }
        }
    }
    if(parent==-1&&children>1)
        return false;
    return true;
}
bool isBiconnected(struct graph *g){
    int visited[MAX]={0};
    int disc[MAX],low[MAX];
    if(!DFS(g,0,-1,visited,disc,low))
        return false;
    for(int i=0;i<g->vertices;i++){
        if(!visited[i])
        return false;
    }
    return true;
}
void main(){
        struct graph g;
        int v,e;
        printf("Enter number of vertices: ");
        scanf("%d",&v);
        initializeTheGraph(&g,v);
        printf("Enter number of edges: ");
        scanf("%d",&e);
        printf("Enter edges (u v) 0-indexed:\n");
        for(int i=0;i<e;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            addEdges(&g,u,v);
        }
        if(isBiconnected(&g))
            printf("Graph is connected\n");
        else
            printf("Graph is NOT BiConnected\n");
}