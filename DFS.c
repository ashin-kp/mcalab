#include<stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void DFS(int v , int n) {
    printf("%d",v);
    visited[v] = 1;
    for(int i=0;i<n;i++) {
        if(adj[v][i] == 1 && visited[i] == 0)
            DFS(i ,n);
    }

}

int main() {
    int n,e,u,v,start;
    printf("enter the no of vertices:\n");
    scanf("%d",&n);

    //initialize the matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }
    printf("enter the no of edges:\n");
    scanf("%d",&e);
    for(int i=0;i<n;i++){
        printf("enter the edges u to v:\n");
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
        adj[v][u] = 1;  //remove for directed graph
    }

    //mark all vertices unvisited
    for(int i=0;i<n;i++)
        visited[i]=0;

    printf("enter starting vertex\n");
    scanf("%d",&start);

    printf("DFS traversal is: ");
    DFS(start,n);

    return 0;
}