//
// Created by disha on 06-11-2025.
//

//
// Created by Disha on 06-11-2025
// BFS + DFS + Connectivity + Cycle Detection (Directed + Undirected) + Path Printing
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// ---------- STRUCTURE ----------
typedef struct node {
    int data;
    struct node *link;
} NODE;

// ---------- GLOBAL VARIABLES ----------
NODE *adj[MAX];
int visited[MAX];
int parent[MAX];
int n;

// ---------- UTILITY FUNCTIONS ----------
void insertEdge(int src, int dest, int directed) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = dest;
    temp->link = adj[src];
    adj[src] = temp;

    if (!directed) {  // for undirected graph
        NODE *temp2 = malloc(sizeof(NODE));
        temp2->data = src;
        temp2->link = adj[dest];
        adj[dest] = temp2;
    }
}

void createGraph(int directed) {
    int src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (src dest), -1 -1 to stop:\n");
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
            break;
        insertEdge(src, dest, directed);
    }
}

void displayGraph() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        NODE *temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

// ---------- BFS: CONNECTIVITY + PATH PRINT ----------
void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        NODE *temp = adj[u];
        while (temp) {
            int v = temp->data;
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;
                queue[rear++] = v;
            }
            temp = temp->link;
        }
    }
    printf("\n");
}

// Print path from source to destination using parent[]
void printPath(int src, int dest) {
    if (src == dest) {
        printf("%d ", src);
        return;
    }
    if (parent[dest] == -1) {
        printf("No path from %d to %d\n", src, dest);
        return;
    }
    printPath(src, parent[dest]);
    printf("%d ", dest);
}

// Check if all vertices are connected using BFS
int isConnectedBFS(int start) {
    bfs(start);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

// ---------- DFS: UNDIRECTED CYCLE DETECTION ----------
int dfsCycleUndirected(int v, int parentNode) {
    visited[v] = 1;
    NODE *temp = adj[v];

    while (temp) {
        int u = temp->data;
        if (!visited[u]) {
            if (dfsCycleUndirected(u, v))
                return 1;
        } else if (u != parentNode) {
            return 1; // Found a back edge
        }
        temp = temp->link;
    }
    return 0;
}

int isCyclicUndirected() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycleUndirected(i, -1))
                return 1;
        }
    }
    return 0;
}

// ---------- DFS: DIRECTED CYCLE DETECTION ----------
int recStack[MAX];

int dfsCycleDirected(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    NODE *temp = adj[v];
    while (temp) {
        int u = temp->data;
        if (!visited[u] && dfsCycleDirected(u))
            return 1;
        else if (recStack[u])
            return 1; // Back edge -> cycle
        temp = temp->link;
    }

    recStack[v] = 0;
    return 0;
}

int isCyclicDirected() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfsCycleDirected(i))
            return 1;
    }
    return 0;
}

// ---------- MAIN ----------
int main() {
    int choice, src, dest;

    printf("\n1. Undirected Graph\n2. Directed Graph\nEnter choice: ");
    scanf("%d", &choice);

    createGraph(choice == 2);
    displayGraph();

    printf("\nEnter source vertex for BFS: ");
    scanf("%d", &src);

    bfs(src);

    printf("\nCheck connectivity: ");
    if (isConnectedBFS(src))
        printf("Graph is connected\n");
    else
        printf("Graph is NOT connected\n");

    printf("\nCheck for cycle:\n");
    if (choice == 1) {
        if (isCyclicUndirected())
            printf("Graph contains a cycle (Undirected)\n");
        else
            printf("Graph is acyclic (Undirected)\n");
    } else {
        if (isCyclicDirected())
            printf("Graph contains a cycle (Directed)\n");
        else
            printf("Graph is acyclic (Directed)\n");
    }

    printf("\nEnter destination vertex to print path: ");
    scanf("%d", &dest);
    printf("Path from %d to %d: ", src, dest);
    printPath(src, dest);
    printf("\n");

    return 0;
}

