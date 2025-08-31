//
// Created by disha on 28-08-2025.
//
// Circular Queue implementation with utility functions

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Check if queue is empty
int isEmpty(int f) {
    return (f == -1);
}

// Check if queue is full
int isFull(int f, int r) {
    return ((f == 0 && r == MAX - 1) || (f == (r + 1) % MAX));
}

// Enqueue operation
void enqueue(int *q, int *r, int *f, int ele)
{
    if(isFull(*f, *r))
    {
        printf("Queue is full\n");
        return;
    }

    if(*f == -1) // First element
        *f = 0;

    *r = (*r + 1) % MAX;
    q[*r] = ele;
    printf("%d inserted\n", ele);
}

// Dequeue operation
int dequeue(int *q, int *f, int *r)
{
    if(isEmpty(*f))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int x = q[*f];
    if(*f == *r) // Only one element left
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        *f = (*f + 1) % MAX;
    }
    return x;
}

// Display operation
void display(int *q, int f, int r)
{
    if(isEmpty(f))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = f;
    while(1)
    {
        printf("%d ", q[i]);
        if(i == r)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Peek front element
int peekFront(int *q, int f, int r)
{
    if(isEmpty(f))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q[f];
}

// Peek rear element
int peekRear(int *q, int f, int r)
{
    if(isEmpty(f))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q[r];
}

// Return size of queue
int size(int f, int r)
{
    if(f == -1) return 0;
    if(r >= f) return (r - f + 1);
    else return (MAX - f + r + 1);  // wrapped around
}

int main()
{
    int q[MAX];
    int f = -1, r = -1, ele, ch, x;

    while(1)
    {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek Front\n5. Peek Rear\n");
        printf("6. Check Empty\n7. Check Full\n8. Size\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(q, &r, &f, ele);
                break;

            case 2:
                x = dequeue(q, &f, &r);
                if(x != -1)
                    printf("Deleted element: %d\n", x);
                break;

            case 3:
                display(q, f, r);
                break;

            case 4:
                x = peekFront(q, f, r);
                if(x != -1) printf("Front element: %d\n", x);
                break;

            case 5:
                x = peekRear(q, f, r);
                if(x != -1) printf("Rear element: %d\n", x);
                break;

            case 6:
                if(isEmpty(f)) printf("Queue is empty\n");
                else printf("Queue is not empty\n");
                break;

            case 7:
                if(isFull(f, r)) printf("Queue is full\n");
                else printf("Queue is not full\n");
                break;

            case 8:
                printf("Queue size: %d\n", size(f, r));
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
