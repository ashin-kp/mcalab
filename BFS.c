#include <stdio.h>

#define MAX 100

int queue[MAX];
int visited[MAX];
int adj[MAX][MAX];
int front = -1, rear = -1;

//queue functions

void enqueue(int value) {
    if( rear == MAX - 1 ) 
        printf("queue overflow\n");
    if(front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

int isEmpty(){
    if(front == -1 || front > rear) 
        return 1;
    return 0;
}

int dequeue() {
    if(isEmpty()) {
        printf("queue underflow\n");
        return -1;
    }
    return queue[front++];
}

//bfs function

void BFS(int start , int n) {

    int current;
    //mark all vertices unvisited
    for(int i=0;i<n;i++)
        visited[i] = 0;
    
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(!isEmpty()) {
        current = dequeue();
        printf("%d" ,current);

        //check all neighbours
        for(int i=0;i<n;i++) {
            if(adj[current][i] == 1 && visited[i]==0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    
}

//main function

int main() {
    int n,e,v,u,start;
    printf("enter the no of vertices\n");
    scanf("%d",&n);

    //initialize the adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }

    printf("enter the no of edges:");
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        printf("enter the edges: from u to v\n");
        scanf("%d %d",&u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; //delete this code if undirected graph
    }
    printf("enter the starting vertex: ");
    scanf("%d", &start);

    BFS(start ,n);
    return 0;

}