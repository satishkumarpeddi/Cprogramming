#include <stdio.h>
#include <stdlib.h>
#define V 4
#define INF 99999
void printMethod(int graph[V][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF)
                printf("%7s","INF");
            else    
                printf("%7d",graph[i][j]);
        }
        printf("\n");
    }
}
void floyWarshall(int graph[V][V]){
    int dist[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    printMethod(dist);
}
void main(){
    int graph[V][V]={
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };
    floyWarshall(graph);

}