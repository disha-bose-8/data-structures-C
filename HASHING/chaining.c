//
// Created by disha on 12-11-2025.
//

// hashing using linked list (chaining)
// Each index holds a linked list of NODEs → this is chaining.

#include <stdio.h>
#include <stdlib.h>
#define MAX 7 // max size of hash table

typedef struct node{
  int data; // stores the key (integer) you insert.
  struct node *link; // pointer to the next node in the linked list
}NODE;

int hash_fun(int key){ // gives index from 0 to 6, decides which bucket (array index) the key belongs to
  return key % MAX;
}

NODE *create_node(int key){
  NODE *temp = (NODE *)malloc(sizeof(NODE)); // allocate heap memory of size equal to one node
  if (!temp) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  temp->data = key;
  temp->link = NULL;
  return temp;
}

NODE *insert(int key, NODE *root){ // root → pointer to the head of the linked list at some hash index.

 NODE *temp = create_node(key); // create a new node with the given key
  if (root == NULL) {
    return temp;               // new node is now the head
  }

  NODE *cur=root;

  while(cur->link!=NULL){
    cur=cur->link;
  }
  cur->link=temp;
  return root; // return the (possibly unchanged) head of the linked list
}

void display(NODE *a[]){ // NODE *a[] → a is an array of NODE*.

  //This is your hash table.

 // Each a[i] is the head of a linked list (chain) at index i.

  NODE *cur;
  for(int i=0;i<MAX;i++){
    printf("%d-------------\t",i); // prints for each index
    cur=a[i];
    while(cur!=NULL){
      printf("%d\t",cur->data);
      cur=cur->link;
    }
    printf("\n");
  }
}

void search(int key, NODE *a[]){
  int index=hash_fun(key); // Find which bucket this key should be in.
  NODE *cur=a[index]; // Start at the head of the linked list at that bucket.
  while(cur!=NULL){ // traverse
    if(cur->data==key){
      printf("Search successful %d\t",cur->data);
      return;

    }
    cur=cur->link;
  }
  printf("Not found \n");
}

void deleteKey(int key, NODE *a[]) {
  int index = hash_fun(key);
  NODE *cur = a[index];
  NODE *prev = NULL;

  while (cur != NULL) {
    if (cur->data == key) {
      if (prev == NULL) {          // first node in chain
        a[index] = cur->link; // cur->link in this case is NULL
      } else {                     // middle/last node
        prev->link = cur->link;
      }
      free(cur);
      printf("Deleted %d from index %d\n", key, index);
      return;
    }
    prev = cur;
    cur = cur->link;
  }
  printf("Key %d not found for deletion\n", key);
}

int main(){
  NODE *a[MAX];
  for (int i = 0; i < MAX; i++) {
    a[i] = NULL;
  }

  int ch, key, index;

  while (1) {
    printf("\n1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\n");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter the element to be inserted\n");
      scanf("%d", &key);
      index = hash_fun(key);
      a[index] = insert(key, a[index]);
      break;

      case 2:
        display(a);
      break;

      case 3:
        printf("Enter the element to be searched\n");
      scanf("%d", &key);
      search(key, a);
      break;

      case 4:
        printf("Enter the element to be deleted\n");
      scanf("%d", &key);
      deleteKey(key, a);
      break;

      case 5:
        printf("Exiting...\n");
      return 0;

      default:
        printf("Invalid choice\n");
    }
  }
}