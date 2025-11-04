#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct node { // each node is a vertex in the adjacency list
    int data;
    struct node* link; // pointer to the next node (next vertex in the list)
} NODE;


void insert(NODE *a[], int i, int j) { // j is data to be inserted at index i
    NODE *temp = malloc(sizeof(NODE));
    if (temp == NULL) {
        perror("Memory allocation failed");
        return;
    }
    temp->data = j;
    temp->link = NULL;

    NODE *cur = a[i];

    if (cur == NULL) {
        a[i] = temp;
        return;
    }

    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
}

void display(NODE* a[], int n) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        NODE *cur = a[i];
        printf("Vertex %d:", i);
        // Corrected: loop condition must be 'cur != NULL'
        while (cur != NULL) {
            printf(" -> %d", cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
}


void create_graph(NODE *a[], int n) { 
    int i, j;
    for (int k = 0; k < n; k++) {
        a[k] = NULL;
    }
    
    printf("Enter edges (source destination). Enter a vertex outside [0, %d] to stop.\n", n - 1);
    while(1) {
        printf("Enter the source and destination: ");

        if (scanf("%d %d", &i, &j) != 2) {
             // Handle non-integer input
             while(getchar() != '\n'); // Clear the buffer
             printf("Invalid input format. Stopping.\n");
             break;
        }

        if (i < 0 || j < 0 || i >= n || j >= n) { 
            printf("Input stopped.\n");
            break;
        }
        
        // This program creates a DIRECTED graph because insert is only called once.
        insert(a, i, j); 
        
        // For an UNDIRECTED graph, you would add:
        // insert(a, j, i); 
    }
}

int indegree(NODE* a[],int v,int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        NODE* cur=a[i];
        while (cur != NULL) {
            if (cur->data == v) {
                ++count;
            }
            cur=cur->link;
        }
    }
    return count;
}

int outdegree(NODE *a[], int v, int n) {
    int count = 0;
    NODE *cur = a[v];
    while (cur != NULL) {
        ++count;
        cur = cur->link;
    }
    return count;
}


int main() {
    int n,v;

    NODE *a[MAX]; 
    
    printf("Enter the number of vertices (max %d):\n", MAX);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    create_graph(a, n);
    display(a, n);

    printf("enter vertex to find indegree: ");
    scanf("%d", &v);

    printf("Indegree of %d = %d\n", v, indegree(a, v, n));
    printf("Outdegree of %d = %d\n", v, outdegree(a, v, n));
}