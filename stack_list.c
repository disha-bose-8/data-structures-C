#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node *link;
} NODE;

// initially stack is empty
NODE *top = NULL;  // Stack top pointer top always points to the top of stack (most recently pushed element).

// Function to push element onto stack
void push(int ele) {
    NODE *temp = (NODE *)malloc(sizeof(NODE)); // create new node
    if (temp == NULL) {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }
    temp->data = ele;
    temp->link = top; // new node points to previous top (top contains adress of previous node)
    top = temp; // top now points to new node
    printf("%d pushed to stack\n", ele);
}

// Function to pop element from stack
int pop() {
    if (top == NULL) { // nothing to pop
        printf("Stack Underflow\n");
        return 9999; // Indicate stack is empty
    }
    NODE *temp = top; // temp stores node being popped (top contains its address)
    int val = temp->data; // value to return
    top = top->link; // top now points to next node
    free(temp); // free popped node
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
