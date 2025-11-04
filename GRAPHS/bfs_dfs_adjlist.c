//
// Created by disha on 29-10-2025.
//

// DIRECTED GRAPH: BFS + DFS + Connectivity Check using Adjacency List
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// Global declarations
int visited[MAX] = {0};
int n;  // total vertices

// Adjacency list node
typedef struct node {
    int data;
    struct node* link;
} NODE;

// Graph adjacency list
NODE *a[MAX];

// ---------------- Graph Creation ----------------
void insert(NODE *a[], int so, int des) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = des;
    temp->link = NULL;

    if (a[so] == NULL) {
        a[so] = temp;
    } else {
        NODE *cur = a[so];
        while (cur->link != NULL)
            cur = cur->link;
        cur->link = temp;
    }
}

void creategraph(NODE *a[], int n) {
    int so, des;
    for (int k = 0; k < n; k++)
        a[k] = NULL;

    printf("Enter edges (source destination). Enter a vertex outside [0, %d] to stop.\n", n - 1);
    while (1) {
        printf("Enter the source and destination: ");
        scanf("%d%d", &so, &des);
        if (so < 0 || des < 0 || so >= n || des >= n)
            break;
        insert(a, so, des); // Directed edge
    }
}

// ---------------- Queue for BFS ----------------
NODE* insertrear(int v, NODE *q) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = v;
    temp->link = NULL;

    if (q == NULL)
        return temp;

    NODE *cur = q;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = temp;
    return q;
}

NODE* deletefront(NODE *q) {
    if (q == NULL)
        return NULL;
    NODE *first = q;
    q = first->link;
    free(first);
    return q;
}

// ---------------- BFS Traversal ----------------
void bfs(int v) {
    NODE *q = NULL, *list;
    int u;

    visited[v] = 1;
    q = insertrear(v, q);
    printf("%d is visited\n", v);

    while (q != NULL) {
        u = q->data;
        q = deletefront(q);
        list = a[u];

        while (list != NULL) {
            int w = list->data;
            if (visited[w] == 0) {
                visited[w] = 1;
                q = insertrear(w, q);
                printf("%d is visited\n", w);
            }
            list = list->link;
        }
    }
}

// ---------------- DFS Traversal ----------------
void dfs(int v) {
    NODE *temp;
    visited[v] = 1;
    printf("%d is visited\n", v);

    temp = a[v];
    while (temp != NULL) {
        if (visited[temp->data] == 0)
            dfs(temp->data);
        temp = temp->link;
    }
}

// ---------------- Connectivity Check ----------------
int isconnected() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

// ---------------- MAIN ----------------
int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    creategraph(a, n);

    printf("Enter starting vertex for DFS/BFS: ");
    scanf("%d", &v);

    printf("\nDFS Traversal:\n");
    for (int i = 0; i < n; i++) visited[i] = 0;
    dfs(v);

    printf("\n\nBFS Traversal:\n");
    for (int i = 0; i < n; i++) visited[i] = 0;
    bfs(v);

    int c = isconnected();
    printf("\n\nGraph is %sconnected.\n", c ? "" : "dis");

    return 0;
}
