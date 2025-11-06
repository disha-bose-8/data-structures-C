//
// Connected Components + Path Printing using DFS
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct node {
    int data;
    struct node *link;
} NODE;

NODE *a[MAX];
int visited[MAX];
int parent[MAX];
int n;

void insertEdge(int src, int dest) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = dest;
    temp->link = NULL;

    if (a[src] == NULL)
        a[src] = temp;
    else {
        NODE *cur = a[src];
        while (cur->link)
            cur = cur->link;
        cur->link = temp;
    }
}

void createGraph() {
    int src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        a[i] = NULL;

    printf("Enter edges (src dest), -1 -1 to stop:\n");
    while (1) {
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1) break;
        insertEdge(src, dest);
        insertEdge(dest, src);
    }
}

void dfs(int v) {
    visited[v] = 1;
    NODE *temp = a[v];

    while (temp) {
        int u = temp->data;
        if (!visited[u]) {
            parent[u] = v;
            dfs(u);
        }
        temp = temp->link;
    }
}

void printPath(int j) {
    if (parent[j] == -1) return;
    printPath(parent[j]);
    printf("%d ", j);
}

void printAllPaths(int src) {
    printf("\nPaths from %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (i != src && parent[i] != -1) {
            printf("Path to %d: %d ", i, src);
            printPath(i);
            printf("\n");
        }
    }
}

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

void displayGraph() {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        NODE *temp = a[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main() {
    createGraph();
    displayGraph();

    for (int i = 0; i < n; i++)
        visited[i] = parent[i] = -1;

    int src;
    printf("\nEnter source for DFS paths: ");
    scanf("%d", &src);

    visited[src] = 1;
    dfs(src);

    printAllPaths(src);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int components = countComponents();
    printf("\nConnected Components = %d\n", components);

    return 0;
}
