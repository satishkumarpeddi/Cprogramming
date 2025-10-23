#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
void dfsUtilBackTrackingMethod(int graph[][MAX],int vertices,int current,bool visited[]){
    visited[current]=true;
    printf("%d --> ",current);
    for(int i=0;i<vertices;i++){
        if(graph[current][i]==1&&!visited[i]){
            visited[i]=true;
            dfsUtilBackTrackingMethod(graph,vertices,i,visited);
        }
    }
}
void dfs(int graph[][MAX],int vertices,int startIndex){
    bool visited[MAX]={false};
    dfsUtilBackTrackingMethod(graph,vertices,startIndex,visited);
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
    printf("The DFS Travesal Start's for index 0.\n");
    dfs(graph,vertices,0);
}