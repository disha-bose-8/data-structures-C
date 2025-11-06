//
// Created by disha on 29-10-2025.
//

// UNDIRECTED GRAPH BFS TRAVERSAL USING ADJACENCY MATRIX AND ARRAY-BASED QUEUE

#include <stdio.h>
#define MAX 50
int visited[MAX]={0}; // keeps track of visited vertices
int a[MAX][MAX];
int f=0,r=-1;
int queue[MAX];

void create_matrix(int n)
{
    int i,j;
    printf("enter the graph elements:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void display(int n)
{
    int i,j;
    printf("given graph is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

// initially [0 0 0 0 0]
void bfs(int v, int n) {
    visited[v]=1;
    printf("%d is visited \n",v);
    queue[++r]=v;
    while (f<=r) {
        v=queue[f++];
        for(int u=0;u<n;u++)
        {
            if(a[v][u]==1 )
            {
                if(visited[u]==0) {
                    queue[++r]=u;
                    visited[u]=1;
                    printf("%d\t",u);
                }
            }
        }
    }
}

int main()
    {

    int n,v;
    printf("enter no of vertices:");
    scanf("%d",&n);
    create_matrix(n);
    display(n);
    printf("enter the starting vertex:");
    scanf("%d",&v);
    bfs(v,n);
  }