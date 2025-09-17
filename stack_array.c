#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // constant maximum size of the stack
typedef struct stack // structure for stack
    {
  int top; // keeps track of index of top element
  int a[MAX]; // array to hold stack elements
  } STACK;

void push(STACK *ptr, int ele)
      {
  if (ptr->top == MAX - 1) { // stack is full no more elements can be put
    printf("Stack Overflow\n");
    return;
  }
  else
    ptr->a[++ptr->top] = ele; // increment and element keeps getting added at the top (initially top is -1)
  }

void display(STACK *ptr)
      {
  if (ptr->top == -1) //empty
    printf("Stack Underflow\n");
  else
    {
    for (int i = 0; i <=ptr->top; i++)
      printf("%d\t", ptr->a[i]);
    printf("\n");
    }
  }

int pop(STACK *ptr)
{
  int x;
  if (ptr->top == -1)
    return 9999;
  else
    {
    x = ptr->a[ptr->top--];
    return x;
    }
  }

int peek(STACK *ptr) {
  if (ptr->top == -1)
    return 9999; // underflow
  else
    return ptr->a[ptr->top];
}

int isEmpty(STACK *ptr) {
  return (ptr->top == -1);
}

int isFull(STACK *ptr) {
  return (ptr->top == MAX - 1);
}

int size(STACK *ptr) {
  return (ptr->top + 1);
}

    int main() {
    STACK s;
    STACK *ptr;
    ptr = &s;
    ptr->top = -1;

    int choice, ele, res;

    while (1) {  // infinite loop for menu
      printf("\n--- Stack Menu ---\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Peek\n");
      printf("5. isEmpty\n");
      printf("6. isFull\n");
      printf("7. Size\n");
      printf("8. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
        case 1:
          printf("Enter element to push: ");
          scanf("%d", &ele);
          push(ptr, ele);
        break;

        case 2:
          res = pop(ptr);
        if (res == 9999)
          printf("Stack Underflow\n");
        else
          printf("Popped element = %d\n", res);
        break;

        case 3:
          display(ptr);
        break;

        case 4:
          res = peek(ptr);
          if (res == 9999)
            printf("Stack Underflow\n");
          else
            printf("Top element = %d\n", res);
        break;

        case 5:
          if (isEmpty(ptr))
            printf("Stack is EMPTY\n");
          else
            printf("Stack is NOT empty\n");
        break;

        case 6:
          if (isFull(ptr))
            printf("Stack is FULL\n");
          else
            printf("Stack is NOT full\n");
        break;

        case 7:
          printf("Current stack size = %d\n", size(ptr));
        break;

        case 8:
          printf("Exiting...\n");
        exit(0);

        default:
          printf("Invalid choice! Try again.\n");
      }
    }
  }