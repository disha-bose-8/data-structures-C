//
// Created by disha on 24-08-2025.
//
/* WAP to insert_front, insert_end, delete_front, delete_end and display the content of list*/
#include<stdio.h>
#include<stdlib.h> /* Dynamic memorh allocation like, malloc, calloc, realloc, and free*/
/* node definition*/
typedef struct node
{
 int data; /* holds value*/
 struct node *link; /*holds the address of next node*/
} NODE;

NODE *create_node(int value)
{
    /* create a temp node and allocate memory*/
 struct node *temp=(NODE*)malloc(sizeof(NODE));
 temp->data=value;
 temp->link=NULL;
 return temp;

}

void insert_front(int value, NODE **start) /* callled func*/
{
  struct node *temp=create_node(value);
  if(*start==NULL) /*list is empty*/
  *start=temp;
  else
  {
  temp->link=*start;
  *start=temp;
  }
}
/*Insert a node at the end/ appending a node*/
void insert_end(int value, NODE **start)
{
  NODE *temp=create_node(value);
  if(*start==NULL)
  {
    *start=temp;
  }
  else
  {
    NODE *current=*start;
    while(current->link!=NULL)
    {
      current=current->link;
    }
    current->link=temp;
  }
}

void delete_end(NODE **start)
{
  if(*start==NULL)
  {
    printf("The list is empty");

  }
  else if((*start)->link==NULL) /* one ele in a list*/
  {
   printf("The deleted ele is %d\n", (*start)->data);
   free(*start);
   *start=NULL;
  }
  else
  {
    NODE *current=*start;
    while(current->link->link!=NULL)
    {
      current=current->link;
    }
    printf("The del ele is %d\n", current->link->data);
    free(current->link);
    current->link=NULL;
  }
}
void delete_front(NODE **start)
{
struct node *temp;
int value;
if(*start==NULL)
printf("The list is empty\n");
else
{
    temp=*start;
    *start=(*start)->link;
    printf("The deleted element is %d", temp->data);
    free(temp);
    return;
}
}
void display(NODE *start)
{
  if(start==NULL)
  printf("The list is empty");
  else
  {
    printf("The elements in the list are\n");
    while(start!=NULL)
    {
      printf("\t%d", start->data);
      start=start->link;
    }
  }
}

int  search(int value, NODE *start)
{
  int position=1;
  while(start!=NULL)
  {
    if(start->data==value)
    return position;
    start=start->link; /* go to the next node*/
    position++;   /* increment the ptr*/
  }
 return -1; /* if the ele is not found*/
}
int main()
{
 int choice, value;
 NODE *start=NULL; /* NODE* start=NULL*/
 printf("Enter the choice\n1) Insert_front \n2) Delete_front \n3) Insert_end \n4) Delete_end  \n5) Display \n6) Search");
 while(1)
 {
 printf("\nEnter the choice\n");
 scanf("%d", &choice);
 switch(choice)
 {
  case 1: printf("Enter the value\n");
          scanf("%d", &value);
          insert_front(value, &start); /*calling function*/
          break;
  case 2: delete_front(&start);
          break;
  case 3: printf("Enter the value\n");
          scanf("%d", &value);
          insert_end(value, &start); /*calling function*/
          break;
  case 4: delete_end(&start);
          break;
  case 5: display(start);
          break;
  case 6: printf("Enter the value");
          scanf("%d", &value);
          int pos=search(value, start); /*calling function*/
          if(pos!=-1)
          printf("The element %d is found at %d\n", value, pos);
          else
          printf("The element %d not is found the list", value);
          break;

  default: printf("Invalid choice\n");
           exit(1);
 }
 }
 return 0;
}