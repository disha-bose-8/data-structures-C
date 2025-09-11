//priority queue using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
    struct node *link;
} NODE;

typedef struct pqueue {
    NODE *front;
} PQUEUE;

void enqueue(PQUEUE *ptr, int ele, int pri) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->priority = pri;
    temp->link = NULL;

    if (ptr->front == NULL || pri < ptr->front->priority) {
        // insert at front
        temp->link = ptr->front;
        ptr->front = temp;
    } else {
        // insert according to priority
        NODE *cur = ptr->front;
        while (cur->link != NULL && cur->link->priority <= pri) {
            cur = cur->link;
        }
        temp->link = cur->link;
        cur->link = temp;
    }
}

int dequeue(PQUEUE *ptr) {
    if (ptr->front == NULL) {
        return 9999; // empty
    }
    NODE *temp = ptr->front;
    int x = temp->data;
    ptr->front = ptr->front->link;
    free(temp);
    return x;
}

void display(PQUEUE *ptr) {
    if (ptr->front == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    NODE *cur = ptr->front;
    printf("Data (Priority)\n");
    while (cur != NULL) {
        printf("%d (%d)\t", cur->data, cur->priority);
        cur = cur->link;
    }
    printf("\n");
}
void display(NODE *ptr) {
    if (ptr->link==NULL)
        printf("list is empty\n");
    else {
        NODE *cur=ptr->link;
        while (cur!=NULL) {
            printf("%d\t",cur->data);
            cur=cur->link;
        }
    }
}

int main() {
    PQUEUE *ptr = malloc(sizeof(PQUEUE));
    ptr->front = NULL;
    int ch, ele, pri, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                printf("Enter its priority (smaller = higher priority): ");
                scanf("%d", &pri);
                enqueue(ptr, ele, pri);
                break;

            case 2:
                x = dequeue(ptr);
                if (x == 9999)
                    printf("Priority Queue is empty\n");
                else
                    printf("Dequeued element: %d\n", x);
                break;

            case 3:
                display(ptr);
                break;

            default:
                printf("Invalid choice\n");
        }
    }
}