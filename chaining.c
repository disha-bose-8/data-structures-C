//
// Created by disha on 12-11-2025.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct node{
  int data;
  struct node *link;
}NODE;

int hash_fun(int key){
  return key % MAX;
}

NODE *create_node(int key){
  NODE *temp = (NODE *)malloc(sizeof(NODE));
  temp->data = key;
  temp->link = NULL;
  return temp;
}

NODE *insert(int key, NODE *root){
  NODE *temp = create_node(key);
  NODE *cur=root;
  if(cur==NULL){
    return temp;
  }
  while(cur->link!=NULL){
    cur=cur->link;
  }
  cur->link=temp;
}

void display(NODE *a[]){
  NODE *cur;
  for(int i=0;i<MAX;i++){
    printf("%d-------------\t",i);
    cur=a[i];
    while(cur!=NULL){
      printf("%d\t",cur->data);
      cur=cur->link;
    }
    printf("\n");
  }
}

void search(int key, NODE *a[]){
  int index=hash_fun(key);
  NODE *cur=a[index];
  while(cur!=NULL){
    if(cur->data==key){
      printf("Search successful %d\t",cur->data);
      break;

    }
    cur=cur->link;
  }
  printf("Not found \n");
}

void delete(int key, NODE *a[]) {
  int index = hash_fun(key);
  NODE *cur = a[index];
  NODE *prev = NULL;

  while (cur != NULL) {
    if (cur->data == key) {
      if (prev == NULL) {           // First node
        a[index] = cur->link;
      } else {                       // Middle / last node
        prev->link = cur->link;
      }
      }
      cur=cur->link;
      }
      return;
      }

int main(){
  NODE *[MAX];
  for(int i=0;i<MAX;i++){
    a[i]=NULL;
  }
  int ele,ch,key;
  int index;
  while(1){
    printf("1. Insert\n2. Display\n3. search\n4. Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        printf("Enter the element to be inserted\n");
        scanf("%d",&key);
        index=hash_fun(key);
        a[index]=insert(key, a[index]);
        break;

        case 2:
          display(a);
          break;

          case 3:
            printf("Enter the element to be searched\n");
            scanf("%d",&key);
            search(key,a);
            break;

            case 4:
              printf("enter element to be deleted\n");
              scanf("%d",&key);
              delete(key,a[index]);
              break;
            }
    }
  }
}