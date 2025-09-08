#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *link;
} NODE;

NODE *top = NULL;  // Stack top pointer

// Function to push element onto stack
void push(int ele) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }
    temp->data = ele;
    temp->link = top;
    top = temp;
    printf("%d pushed to stack\n", ele);
}

// Function to pop element from stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 9999; // Indicate stack is empty
    }
    NODE *temp = top;
    int val = temp->data;
    top = top->link;
    free(temp);
    return val;
}

// Function to display stack
void display() {
    if (top == NULL) {
        printf("Stack/list is empty\n");
        return;
    }
    NODE *cur = top;
    printf("Stack elements: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->link;
    }
    printf("\n");
}

int main() {
    int choice, ele, x;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
            scanf("%d", &ele);
            push(ele);
            break;
            case 2:
                x = pop();
            if (x != 9999)
                printf("Popped element: %d\n", x);
            break;
            case 3:
                display();
            break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
