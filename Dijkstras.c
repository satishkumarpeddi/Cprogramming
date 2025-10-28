#include <stdio.h>
#include <stdbool.h>
#define INF 99999
#define MAX 100
int minDistance(int dist[],bool visited[],int n){
    int min=INF,min_index=-1;
    for(int v=0;v<n;v++){
        if(!visited[v]&&dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}
void dijkstras(int graph[MAX][MAX],int n,int src){
    bool visited[MAX]={false};
    int dist[MAX];
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[src]=0;
    for(int count=0;count<n-1;count++){
        int  u = minDistance(dist,visited,n);
        visited[u]=true;
        for(int v=0;v<n;v++){
            if(!visited[v]&&graph[u][v]&&dist[u]!=INF&&dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }
    printf("\nVertex\tDistance from Source (%d)\n",src);
    for(int i=0;i<n;i++)    
        printf("%d\t\t%d\n",i,dist[i]);
}
void main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int graph[MAX][MAX];
    printf("Enter adjacency matrix (0 if no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    int src;
    printf("Enter source vertex (0 to %d): ",n-1);
    scanf("%d",&src);
    dijkstras(graph,n,src);
    return;
}