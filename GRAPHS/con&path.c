//
// Created by disha on 30-10-2025.
//

// Connected Components + Path Printing using DFS (Adjacency List)

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Structure for adjacency list node
typedef struct node {
    int data;
    struct node *link;
} NODE;

NODE *a[MAX];          // adjacency list
int visited[MAX];      // visited array
int parent[MAX];       // to track paths
int n;                 // number of vertices

// Function to insert edge into adjacency list
void insertEdge(int src, int dest) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = dest;
    temp->link = NULL;

    if (a[src] == NULL) {
        a[src] = temp;
    } else {
        NODE *cur = a[src];
        while (cur->link != NULL)
            cur = cur->link;
        cur->link = temp;
    }
}

// Function to create graph
void createGraph() {
    int src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        a[i] = NULL;

    printf("Enter edges (src dest). Enter -1 -1 to stop:\n");
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 || dest == -1)
            break;
        insertEdge(src, dest);
        insertEdge(dest, src); // make it UNDIRECTED
    }
}

// Depth-First Search
void dfs(int v) {
    visited[v] = 1;
    NODE *temp = a[v];

    while (temp != NULL) {
        int u = temp->data;
        if (!visited[u]) {
            parent[u] = v; // track path
            dfs(u);
        }
        temp = temp->link;
    }
}

// Print path from source to vertex j
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

// Print all paths from source to others
void printAllPaths(int parent[], int n, int src) {
    printf("\nAll paths from source vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (i != src && parent[i] != -1) {
            printf("Path to %d: %d ", i, src);
            printPath(parent, i);
            printf("\n");
        }
    }
}

// Count number of connected components
int countComponents() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

// Display adjacency list
void displayGraph() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        NODE *temp = a[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main() {
    createGraph();
    displayGraph();

    // Reset arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    int src;
    printf("\nEnter source vertex for DFS path printing: ");
    scanf("%d", &src);

    dfs(src);
    printAllPaths(parent, n, src);

    // Reset visited[] to count components separately
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int components = countComponents();
    printf("\nNumber of connected components in the graph: %d\n", components);

    return 0;
}
