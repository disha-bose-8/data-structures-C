//
// Created by disha on 30-10-2025.
//

void printpath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;

    printpath(parent, parent[j]);

    printf("%d ", j);
}

void printallpaths(int parent[], int n)
{
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            printf("Path to %d: ", i);
            printpath(parent, i);
            printf("\n");
        }
    }
}

// write a func to print the no of components in the graph
int countcomponents()
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}