//
// Created by disha on 23-10-2025.
//

// represent a graph using an adjacency matrix

#include <stdio.h>
#include <stdlib.h>

#define Max_vertices 100

/*graph is a 2D array (adjacency matrix).
If there’s an edge between vertex start and end, we mark both directions as 1 because this program represents an undirected graph.
For a directed graph, you would only set graph[start][end] = 1; and not the reverse.*/

void addEdge(int graph[Max_vertices][Max_vertices], int start, int end)
    {
  graph[start][end] = 1; // this much for directed graph only
  graph[end][start] = 1; // for undirected graph
    }

void display(int graph[Max_vertices][Max_vertices],int vertices)
    {
  for(int i=0;i<vertices;i++)
    {
      for(int j=0;j<vertices;j++)
        {
          printf("%d ", graph[i][j]);
        }
      printf("\n");
    }
    }

int in_degree(int graph[Max_vertices][Max_vertices], int v, int vertices)
    {
  int count = 0;
  for(int i=0;i<vertices;i++)
    {
      if(graph[i][v] == 1)
        count++;
    }
  return count;
    }

int out_degree(int graph[Max_vertices][Max_vertices], int v, int vertices)
    {
      int count = 0;
      for(int i=0;i<vertices;i++)
        {
          if(graph[v][i] == 1)
            count++;
        }
      return count;
    }

int main()
    {
  int vertices, edges;
  printf("Enter number of vertices: ");
  scanf("%d", &vertices);
  if(vertices<=0 || vertices>Max_vertices)
    {
      printf("Invalid number of vertices\n");
      return 1;
    }

  printf("Enter number of edges: ");
  scanf("%d", &edges);
    int graph[Max_vertices][Max_vertices]={0}; // initialize adjacency matrix to 0
    for(int i=0; i<edges;i++)
      {
      int start, end;
      printf("Enter edge %d (start end): ", i+1);
      scanf("%d %d", &start, &end);
      if(start<0 || start>=vertices || end<0 || end>=vertices)
        {
          printf("Invalid vertices. try again \n");
          i--; // decrement i to repeat this iteration
          continue;
        }
        addEdge(graph, start, end);
        }
        display(graph, vertices);
        return 0;
        }