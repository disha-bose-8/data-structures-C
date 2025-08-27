#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *next;
} NODE;

NODE *top = NULL;  // Stack top pointer

// Function to push element onto stack
void push(int ele) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }
    newNode->data = ele;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", ele);
}

// Function to pop element from stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    NODE *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Function to peek top element
int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to display stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    NODE *cur = top;
    printf("Stack elements: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int choice, ele;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                ele = pop();
                if (ele != -1)
                    printf("Popped element: %d\n", ele);
                break;
            case 3:
                ele = peek();
                if (ele != -1)
                    printf("Top element: %d\n", ele);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
