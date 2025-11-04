//
// Created by disha on 30-10-2025.
// Detect Cycle in Directed Graph using DFS
//

#include <stdio.h>

#define MAX 50

int n;
int visited[MAX];
int path[MAX];   // recursion stack
int a[MAX][MAX]; // adjacency matrix

// Function to detect cycle using DFS
int detectCycle(int v) {
  visited[v] = 1;
  path[v] = 1; // mark current vertex as part of recursion path

  for (int i = 0; i < n; i++) {
    if (a[v][i] == 1) { // if edge exists
      if (!visited[i] && detectCycle(i)) {
        return 1; // found cycle in DFS subtree
      } else if (path[i]) {
        return 1; // found cycle (back-edge)
      }
    }
  }

  path[v] = 0; // remove vertex from recursion path before backtracking
  return 0;
}

// Function to check if graph contains cycle
int isCyclic() {
  for (int i = 0; i < n; i++) {
    visited[i] = 0;
    path[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      if (detectCycle(i)) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  printf("Enter number of vertices: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  if (isCyclic())
    printf("\nThe graph contains a cycle.\n");
  else
    printf("\nThe graph does not contain any cycle.\n");

  return 0;
}
