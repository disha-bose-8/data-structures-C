//
// Created by disha on 30-10-2025.
// Detect Cycle in Directed Graph using DFS
//
//
// Created by disha on 30-10-2025.
// Detect Cycle + Connectivity + Path Printing in Directed Graph (DFS)
//

#include <stdio.h>

#define MAX 50

int n;
int a[MAX][MAX];     // adjacency matrix
int visited[MAX];    // visited array
int recStack[MAX];   // recursion stack for cycle detection
int path[MAX];       // for path storage
int k = 0;           // path index

// -------------------- CYCLE DETECTION USING DFS --------------------
int detectCycle(int v) {
    visited[v] = 1;
    recStack[v] = 1; // part of current recursion path

    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1) {
            if (!visited[i] && detectCycle(i))
                return 1;  // found cycle
            else if (recStack[i])
                return 1;  // back edge -> cycle
        }
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

int isCyclic() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            if (detectCycle(i))
                return 1;
    }
    return 0;
}

// -------------------- CONNECTIVITY CHECK USING DFS --------------------
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (a[v][i] == 1 && !visited[i])
            dfs(i);
    }
}

int isConnectedDFS() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0); // start from vertex 0

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0; // not connected
    }
    return 1; // all vertices reachable
}

// -------------------- PRINT ALL PATHS USING DFS --------------------
void printAllPathsUtil(int src, int dest) {
    visited[src] = 1;
    path[k++] = src;

    if (src == dest) {
        for (int i = 0; i < k; i++)
            printf("%d ", path[i]);
        printf("\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (a[src][i] == 1 && !visited[i])
                printAllPathsUtil(i, dest);
        }
    }

    k--;
    visited[src] = 0;
}

void printAllPaths(int src, int dest) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    k = 0;
    printf("\nAll paths from %d to %d:\n", src, dest);
    printAllPathsUtil(src, dest);
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if (isCyclic())
        printf("\nThe graph contains a cycle (Directed).\n");
    else
        printf("\nThe graph does not contain any cycle.\n");

    if (isConnectedDFS())
        printf("The graph is connected (via DFS reachability).\n");
    else
        printf("The graph is NOT connected.\n");

    int src, dest;
    printf("\nEnter source and destination vertices for path printing: ");
    scanf("%d %d", &src, &dest);
    printAllPaths(src, dest);

    return 0;
}


// using dfs write a function to check graph is connected or not
