//
// Created by disha on 29-10-2025.
//

// DIRECTED GRAPH DFS TRAVERSAL USING ADJACENCY LIST
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int visited[MAX]={0};
int f=0,r=-1;
int queue[MAX];

typedef struct node {
    int data;
    struct node* link;
} NODE;

void insert(NODE *a[], int so, int des) {

    NODE *temp = malloc(sizeof(NODE));
    if (temp == NULL) {
        perror("Memory allocation failed");
        return;
    }
    temp->data = des;
    temp->link = NULL;

    NODE *cur = a[so];

    if (cur == NULL) {
        a[so] = temp;
        return;
    }

    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
}

void creategraph(NODE *a[], int n) {
    int so, des;
    for (int k = 0; k < n; k++) {
        a[k] = NULL;
    }
    
    printf("Enter edges (source destination). Enter a vertex outside [0, %d] to stop.\n", n - 1);
    while(1) {
        printf("Enter the source and destination: ");
        scanf("%d %d", &so, &des);
        if (so < 0 || des < 0 || so >= n || des >= n) {
            break;
        }
        
        // This program creates a DIRECTED graph because insert is only called once.
        insert(a, so, des);
        
        // For an UNDIRECTED graph, you would add:
        // insert(a, des, so);
    }
}

void bfs(int v)
    {
  NODE *q = NULL, *list;
  int u;
  visited[v]=1;
  q = insertrear(v,q);
  printf("%d is visited \n",v);
  while(q!=NULL)
  {
    u=q->data;
    q=deletefront(q);
    list=a[u];
    while(list!=NULL)
    {
      u=list->data;
      if(visited[u]==0)
        {
            visited[u]=1;
            q=insertrear(u,q);
            printf("%d is visited \n",u);
            }
            list=list->link;
    }
    }

NODE * deletefront(NODE *q)
{
    if (q == NULL)
        return NULL;

    NODE *first=q;
    NODE *second=first->link;
    free(first);
    return (q);
}

NODE* insertrear(int v, NODE *q)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = v;
    temp->link = NULL;

    if (q == NULL)
        return temp;

    NODE *cur = q;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return temp;
}

void dfs(int v)
{
  visited[v]=1;
    printf("%d is visited \n",v);
    for(int i=0;i<n;i++)
    {
        if(a[v][i]==1)
        {
            if(visited[i]==0)
            {
                dfs(i);
            }
        }
    }

void dfs(int v)
{
  NODE *temp;
  visisted[v]=1;
    printf("%d is visited \n",v);
    temp=a[v];
    while(temp!=NULL)
    {
      if(visited[temp->data]==0)
      {
            dfs(temp->data);
          }
          temp=temp->link;
        }


int isconnected()
{
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0)
  }
  dfs(0);
  for(int i=0;i<n;i++)
    {
      if(!visited[i])
      {
        return 0;
      }
    }
    return 1;
}


int main()
    {
    NODE *a[MAX];
    int n;
    int v;
    printf("enter the no of vertices \n");
    scanf("%d",&n);
    creategraph(a,n);
    printf("enter the starting vertex:\n");
    scanf("%d",&v);

    int i = isconnected();
    if(i==0)
      printf("disconnected graph\n");
    else
      printf("connected graph\n");
  }
