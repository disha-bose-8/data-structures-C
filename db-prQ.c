//
// Created by disha on 01-09-2025.
//

#include <stdio.h>
#include <stdlib.h>

// Node structure for DLL
struct node {
    int data;
    int priority;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;

// Priority Queue structure
struct pqueue {
    NODE *front;  // highest priority node
    NODE *rear;   // lowest priority node
};

typedef struct pqueue PQ;

// Initialize priority queue
void init(PQ *pq) {
    pq->front = pq->rear = NULL;
}

// Create new node
NODE* createNode(int data, int priority) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->priority = priority;
    temp->next = temp->prev = NULL;
    return temp;
}

// Insert in priority order
void insert(PQ *pq, int data, int priority) {
    NODE *temp = createNode(data, priority);

    // Empty queue
    if (pq->front == NULL) {
        pq->front = pq->rear = temp;
        return;
    }

    // Insert at front if higher priority
    if (priority < pq->front->priority) {
        temp->next = pq->front;
        pq->front->prev = temp;
        pq->front = temp;
        return;
    }

    NODE *cur = pq->front;
    while (cur->next && cur->next->priority <= priority)
        cur = cur->next;

    // Insert at end
    if (cur->next == NULL) {
        cur->next = temp;
        temp->prev = cur;
        pq->rear = temp;
    } else {
        // Insert in middle
        temp->next = cur->next;
        temp->prev = cur;
        cur->next->prev = temp;
        cur->next = temp;
    }
}

// Delete node with highest priority (front)
int delete(PQ *pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    NODE *temp = pq->front;
    int val = temp->data;

    // Only one node
    if (pq->front == pq->rear)
        pq->front = pq->rear = NULL;
    else {
        pq->front = temp->next;
        pq->front->prev = NULL;
    }

    free(temp);
    return val;
}

// Display queue from front to rear
void display(PQ *pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }

    NODE *cur = pq->front;
    printf("Data -> Priority\n");
    while (cur != NULL) {
        printf("%d -> %d\n", cur->data, cur->priority);
        cur = cur->next;
    }
}

int main() {
    PQ pq;
    init(&pq);

    int ch, data, prio, val;

    while (1) {
        printf("\n--- Priority Queue (DLL) Menu ---\n");
        printf("1. Insert\n2. Delete Highest Priority\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (lower = higher): ");
                scanf("%d", &prio);
                insert(&pq, data, prio);
                break;

            case 2:
                val = delete(&pq);
                if (val != -1)
                    printf("Deleted element: %d\n", val);
                break;

            case 3:
                display(&pq);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
