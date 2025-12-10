//
// Created by disha on 09-09-2025.
//
// implementation  of josephus problem
// deletion in middle every kth node

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} NODE;

void create(NODE **head) {
  NODE *temp, *rear = NULL;
  int a, ch;
  do {
    printf("Enter number: ");
    scanf("%d", &a);
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = a;
    temp->link = NULL;

    if (*head == NULL) {   // first node
      *head = temp;
      rear = temp;
    } else {
      rear->link = temp;
      rear = temp;
    }

    printf("Do you want to continue? (1=yes / 0=no): ");
    scanf("%d", &ch);
  } while (ch != 0);

  rear->link = *head;  // make circular
}

int survivor(NODE **head, int k) {
  NODE *p, *q;
  int i;
  q = p = *head;

  while (p->link != p) {  // more than one left
    for (i = 1; i < k; i++) {
      q = p;
      p = p->link;
    }
    // delete p (the k-th person)
    q->link = p->link;
    printf("%d has been killed\n", p->data);
    free(p);
    p = q->link;  // move forward
  }

  *head = p;
  return p->data;
}

int main() {
  NODE *head = NULL;
  int survive, skip;

  create(&head);

  printf("Enter the no of persons to be skipped (k): ");
  scanf("%d", &skip);

  survive = survivor(&head, skip);

  printf("\nThe survivor is %d\n", survive);
  return 0;
}
   