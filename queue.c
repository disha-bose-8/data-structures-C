//
// Created by disha on 28-08-2025.
//
/* Queue is an ADT
Queue follows FIFO - First in First Out
Operations:
1. enqueue
2. dequeue
3. is empty
4. is full
5. peekFront
6. peekRear
7. size
8. clearQueue
9. display
*/

#include<stdio.h>
#include<stdlib.h>
#define max 5 // Maximum size of queue

// Function to insert element into queue
void enqueue(int *q,int *rear,int ele) // rear → pointer to the rear index
{
    if(*rear == max-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        *rear = *rear + 1; // If rear = -1 initially, after inserting 10, rear = 0, q[0] = 10
        q[*rear] = ele;
        printf("%d inserted\n", ele);
    }
}

// Function to delete element from queue
int dequeue(int *q,int *front,int rear) // front → pointer to the front index
{
    if(*front > rear) // Queue is empty
        return 0;
    else
    {
        int x = q[*front]; // The value of front is initially set to 0 in main
        *front = *front + 1;
        return x;
    }
}

// Display elements of queue
void display(int *q,int rear, int front)
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}

// Check if queue is empty
int isEmpty(int front, int rear) {
    return (front > rear);
}

// Check if queue is full
int isFull(int rear) {
    return (rear == max - 1);
}

// Peek front element
int peekFront(int *q, int front, int rear) {
    if(front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[front];
}

// Peek rear element
int peekRear(int *q, int front, int rear) {
    if(front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[rear];
}

// Return size of queue
int size(int front, int rear) {
    if(front > rear) return 0;
    return (rear - front + 1);
}

// Clear the queue
void clearQueue(int *front, int *rear) {
    *front = 0;
    *rear = -1;
    printf("Queue cleared\n");
}

int main()
{
    int q[max];
    int front = 0, rear = -1, ele, ch, x;

    while(1)
    {
        printf("\n---- Queue Menu ----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek Front\n5. Peek Rear\n");
        printf("6. Check Empty\n7. Check Full\n8. Size\n9. Clear Queue\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d",&ele);
                enqueue(q,&rear,ele);
                break;

            case 2:
                x = dequeue(q,&front,rear);
                if(x == 0)
                    printf("Queue is empty\n");
                else
                    printf("The element that got deleted: %d\n",x);
                break;

            case 3:
                display(q,rear,front);
                break;

            case 4:
                x = peekFront(q,front,rear);
                if(x != -1) printf("Front element: %d\n",x);
                break;

            case 5:
                x = peekRear(q,front,rear);
                if(x != -1) printf("Rear element: %d\n",x);
                break;

            case 6:
                if(isEmpty(front,rear))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 7:
                if(isFull(rear))
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 8:
                printf("Queue size: %d\n", size(front,rear));
                break;

            case 9:
                clearQueue(&front,&rear);
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
