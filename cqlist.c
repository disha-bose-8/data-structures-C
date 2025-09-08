//
// Created by disha on 04-09-2025.
//

// implementation of circular queue using linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node { // defines a node structure for the queue
    int data;
    struct node* link;
} NODE;

typedef struct queue // defines the queue structure with front and rear pointers
{
    NODE *front, *rear; // pointers to the front and rear of the queue
} QUEUE;

void enqueue(QUEUE *ptr, int ele) //insert at rear (weve to traverse to the end of the list to insert)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE)); // allocate memory for a new node
    temp->data = ele;
    temp->link = NULL;

    NODE *cur = ptr->rear; // start from rear
    if(ptr->front == NULL && ptr->rear == NULL) // if queue is empty → both front and rear point to this first node (this is the first node added to queue)
    {
        ptr->front = ptr->rear = temp;
        return;
    }
    temp->link = ptr->front; // link new node to front to make it circular
    ptr->rear->link=temp; // update rear to new node (make rear as temp)

}

void display(QUEUE *ptr) // display from front to rear (queue is first to last)
{
    if (ptr->front == NULL && ptr->rear == NULL)
    {
        printf("empty\n");
    }
    else
    {
        NODE *cur = ptr->front;
        while (ptr->front != cur->link) // traverse till we reach back to front
        {
            printf("%d\t", cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
}

int dequeue(QUEUE *ptr) // delete from front (we can directly access front)
{
    int x;
    if (ptr->front == NULL && ptr->rear == NULL) // if queue is empty
    {
        printf("Queue underflow\n");
        return 9999;
    }
    NODE *temp = ptr->front; // store front node in temp
    x = temp->data;          // get data to return
    if (ptr->front == ptr->rear) // if only one element is  present
        ptr->front = ptr->rear = NULL; // now queue will be empty
    else
        ptr->front = ptr->front->link; // move front to next node

    free(temp); // free memory of old front node
    return x;   // return dequeued value
}

int main() {
    QUEUE *ptr = (QUEUE *)malloc(sizeof(QUEUE));
    ptr->front = ptr->rear = NULL; // initialize front and rear to NULL
    int choice, ele, x;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                enqueue(&q, ele);
                break;

            case 2:
                x = dequeue(&q);
                if (x != 9999) // if queue was not empty
                    printf("Dequeued element: %d\n", x);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}