//
// Created by disha on 30-10-2025.
//

#include <stdio.h>

#define MAX 50

int visited[MAX];



int iscycle()
    {
  for(int i=0;i<n;i++)
    {
      visited[i]=0;
      path[i]=0;
    }
    for(int i=0;i<n;i++)
    {
      if(!visited[i])
      {
        if(detectcycle(i))
        {
          return 1;
        }
      }
    }
    return 0;
    }

int detectcycle(int v) //dfs based cycle detection
{
  visited[v]=1;
  path[v]=1;
  for(int i=0;i<n;i++)
  {
    if(a[v][i]==1)
    {
      if(!visited[i] && detectcycle(i))
      {
        return 1;
      }
      else if(path[i])
      {
        return 1;
      }
    }
  }
  path[v]=0;
  return 0;
}

int main()
{
    int n, adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (isCyclic(adj, n))
        printf("\nThe graph contains a cycle.\n");
    else
        printf("\nThe graph does not contain any cycle.\n");

    return 0;
}
