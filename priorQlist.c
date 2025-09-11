//
// Created by disha on 01-09-2025.
//
//insertion expensive process

#include <stdio.h>
#include <stdlib.h>

// Node structure for priority queue
struct node {
    int data;       // value of element
    int priority;   // priority of element (lower number = higher priority)
    struct node* link;
};

typedef struct node NODE;

// Function to create a new node
NODE* createNode(int data, int priority) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->priority = priority;
    temp->link = NULL;
    return temp;
}

// Insert node in priority order
void insert(NODE** head, int data, int priority) {
    NODE* temp = createNode(data, priority);

    // Case: empty list or new node has higher priority than head
    if (*head == NULL || (*head)->priority > priority) {
        temp->link = *head;
        *head = temp;
        return;
    }

    // Traverse to find correct position
    NODE* cur = *head;
    while (cur->link != NULL && cur->link->priority <= priority)
        cur = cur->link;

    temp->link = cur->link;
    cur->link = temp;
}

// Delete node with highest priority (front)
int delete(NODE** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    NODE* temp = *head;
    int val = temp->data;
    *head = (*head)->link;
    free(temp);
    return val;
}

// Display the priority queue
void display(NODE* head) {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Data -> Priority\n");
    NODE* cur = head;
    while (cur != NULL) {
        printf("%d -> %d\n", cur->data, cur->priority);
        cur = cur->link;
    }
}

// Check if empty
int isEmpty(NODE* head) {
    return (head == NULL);
}

int main() {
    NODE* pq = NULL;
    int ch, data, prio, val;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
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
                display(pq);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
