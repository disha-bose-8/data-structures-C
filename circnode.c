//
// Created by disha on 25-08-2025.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct node
    {
  int data;
  struct node *link;
  }NODE;

NODE *createNode()
  {
  NODE *temp=(NODE *)malloc(sizeof(NODE));
  return temp;
  }

void insertFront(NODE *ptr,int data){
  NODE *temp=createNode();
  temp->data=data;
  NODE *first=ptr->link; //address of first node stores in first
  ptr->link=temp; //pointer now points to temp
  temp->link=first; //temp points to first
  }

void insertEnd(NODE *ptr, int data) {
  NODE *temp = createNode();
  temp->data = data;

  if (ptr->link == ptr) {
    // Empty list → directly link to head
    ptr->link = temp;
    temp->link = ptr;
  } else {
    NODE *cur = ptr->link;
    while (cur->link != ptr) {
      cur = cur->link;
    }
    cur->link = temp;
    temp->link = ptr;
  }
}


void display(NODE *ptr){
  if(ptr->link==ptr)
    printf("The linked list is empty\n");
  else{
    NODE *cur=ptr->link;
    while(cur!=ptr){
      printf("%d\t",cur->data);
      cur=cur->link;
    }
    printf("\n");
  }
}

void deletefront(NODE *ptr){
  if(ptr->link==ptr)
    return;
  NODE *first=ptr->link;
  NODE *second=first->link;
  ptr->link=second;
  free(first);
}

void deleteEnd(NODE *ptr){
  if(ptr->link==ptr)
    return;
  NODE *cur=ptr->link;
  NODE *prev=NULL;
  while(cur->link!=ptr){
    prev=cur;
    cur=cur->link;
  }
  prev->link=ptr;
  free(cur);
}

void delete_alternative(NODE *ptr) {
  if(ptr->link==ptr) {
    printf("List is empty, nothing to delete.\n");
    return;
  }

  NODE *cur = ptr->link;
  NODE *temp;

  while(cur!=ptr && cur->link!=ptr) {
    temp = cur->link;
    cur->link = temp->link;
    free(temp);
    cur = cur->link;
  }
  printf("Alternate nodes deleted successfully.\n");
}

void count(NODE *ptr) {
  int count=0;
  if(ptr->link==ptr) {
    printf("List is empty, nothing to count.\n");
    return;
  }
  NODE *cur=ptr->link;
  while(cur!=ptr) {
    count++;
    cur=cur->link;
  }
  printf("The number of nodes in the list is %d\n",count);
}

void insertpos(NODE *ptr, int pos, int data) {
  if (pos <= 0) {
    printf("Invalid position!\n");
    return;
  }

  NODE *temp = createNode();
  temp->data = data;

  // Insert at position 1 (front)
  if (pos == 1) {
    NODE *first = ptr->link;
    ptr->link = temp;
    temp->link = first;
    return;
  }

  int i = 1;
  NODE *cur = ptr->link;
  NODE *prev = ptr;  // start prev at dummy head

  // Traverse to the position
  while (cur != ptr && i < pos) {
    prev = cur;
    cur = cur->link;
    i++;
  }

  // Insert at the found position
  prev->link = temp;
  temp->link = cur;
}

void deletepos(NODE *ptr, int pos) {
  if (ptr->link == ptr) {  // empty list
    printf("List is empty, nothing to delete.\n");
    return;
  }
  if (pos <= 0) {
    printf("Invalid position!\n");
    return;
  }

  NODE *cur = ptr->link;
  NODE *prev = ptr;  // start at dummy head
  int i = 1;

  // Traverse to the node at position pos
  while (cur != ptr && i < pos) {
    prev = cur;
    cur = cur->link;
    i++;
  }

  if (cur == ptr) {  // position out of bounds
    printf("Position %d does not exist.\n", pos);
    return;
  }

  // Unlink and delete
  prev->link = cur->link;
  free(cur);
  printf("Node at position %d deleted successfully.\n", pos);
}


int main() {
  int ch, data,pos;
  NODE *head = createNode();  // create dummy head
  head->link = head;          // initially points to itself (empty list)

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert Front\n");
    printf("2. Insert End\n");
    printf("3. Delete Front\n");
    printf("4. Delete End\n");
    printf("5. Display\n");
    printf("6. Delete alternate nodes\n");
    printf("7. Count nodes\n");
    printf("8. Insert at pos\n");
    printf("9. Delete at pos\n");
    printf("10. Exit\n");
    printf("Enter choice: \n");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter data: \n");
      scanf("%d", &data);
      insertFront(head, data);
      break;
      case 2:
        printf("Enter data: \n");
      scanf("%d", &data);
      insertEnd(head, data);
      break;
      case 3:
        deletefront(head);
      break;
      case 4:
        deleteEnd(head);
      break;
      case 5:
        display(head);
      break;
      case 6:
        delete_alternative(head);
      break;
      case 7:
        count(head);
      break;
      case 8:
        printf("Enter position: \n");
        scanf("%d", &pos);
        printf("Enter data: ");
        scanf("%d", &data);
        insertpos(head, pos, data);
      break;
      case 9:
        printf("Enter position: \n");
        scanf("%d", &pos);
        deletepos(head, pos);
      break;
      case 10:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
}
