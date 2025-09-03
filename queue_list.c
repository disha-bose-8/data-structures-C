//
// Created by disha on 02-09-2025.
//

#include <stdio.h>
#include <stdlib.h>

/*
The first struct (`qnode`) defines a single node in the queue, holding an integer (`data`) and a pointer to the next node (`link`).
The second struct (`queue`) defines the queue itself, with pointers to the front and rear nodes.
Connection: The `queue` struct uses `qnode` pointers to manage the linked list of nodes that make up the queue.
 */

typedef struct qnode // Defines a node structure for the queue
{
    int data;
    struct qnode *link;
} NODE;

typedef struct queue // Defines the queue structure with front and rear pointers
{
    NODE *front, *rear; // Pointers to the front and rear of the queue
} QUEUE;

QUEUE *createqueue()
{
    QUEUE *temp = (QUEUE *)malloc(sizeof(QUEUE)); // Allocate memory (creates) for a new queue
    if (temp != NULL)
    {
        temp->front = temp->rear = NULL; // Initializes it as empty (front = rear = NULL)
    }
    return (temp); // Returns the new queue pointer.
}
void enqueue(QUEUE *ptr, int ele)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE)); // Allocate memory for a new nod
    temp->data = ele;
    temp->link = NULL;
    if (ptr->front == NULL && ptr->rear == NULL) // If queue is empty → both front and rear point to this first node (this is the first node added to queue)
    {
        ptr->front = ptr->rear = temp;
        return;
    }
    ptr->rear->link = temp; // if queue not empty link the new node at the end of the queue and update rear
    ptr->rear = temp;
}
void display(QUEUE *ptr)
{
    if (ptr->front == NULL && ptr->rear == NULL)
    {
        printf("empty");
    }
    else
    {
        NODE *cur = ptr->front;
        while (cur != NULL)
        {
            printf("%d\t", cur->data);
            cur = cur->link;
        }
    }
}
int dequeue(QUEUE *ptr)
{
    if (ptr->front == NULL && ptr->rear == NULL)
    {
        return 0;
    }
    else
    {
        NODE *first = ptr->front;
        if (first->link == NULL) // if only one node is present and that has to be deleted
        {
            ptr->front = first->link;
            int x = first->data;
            free(first);
            ptr->front = ptr->rear = NULL;
            return (x);
        }
        ptr->front = first->link; // Move front to the next node
        int x = first->data;
        free(first);
        return (x);
    }
}

int main()
{
    QUEUE *ptr = createqueue();
    int ch, ele, x;
    while (1)
    {
        printf("\n1.Enqueue\n 2.Dequeue\n 3.display\n4.exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter the elemnet\n");
            scanf("%d", &ele);
            enqueue(ptr, ele);
            break;
            case 2:
                x = dequeue(ptr);
            if (x == 0)
                printf("empty list\n");
            else
                printf("deleted element is:%d\n", x);
            break;
            case 3:
                display(ptr);
            break;
            case 4: exit(0);
        }
    }
}