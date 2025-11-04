//
// Created by disha on 30-10-2025.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX], front = 0, rear = -1;
int visited[MAX];

// insert element in queue
void enqueue(int vertex) {
    queue[++rear] = vertex;
}

// delete element from queue
int dequeue() {
    return queue[front++];
}

// if queue is empty
int isEmpty() {
    return front > rear;
}

// BFS traversal
void bfs(int adj[MAX][MAX], int n, int start) {
    int i;
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int v = dequeue();
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

// Function to check if graph is connected
int isConnected(int adj[MAX][MAX], int n) {
    int i, start = 0;

    // Initially mark all vertices as unvisited
    for (i = 0; i < n; i++)
        visited[i] = 0;

    bfs(adj, n, start);

    // If any vertex remains unvisited, graph is disconnected
    for (i = 0; i < n; i++) {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (isConnected(adj, n))
        printf("\nThe graph is Connected.\n");
    else
        printf("\nThe graph is Not Connected.\n");

    return 0;
}
