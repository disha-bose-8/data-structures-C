//
// Created by disha on 25-08-2025.
//
//program to implement circular doubly linked List
//List can start empty.

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next,*prev;
};

typedef struct node node_t;
struct dlist
{
    node_t *head;
};

typedef struct dlist dlist_t;

void insert_head(dlist_t*,int);
void insert_tail(dlist_t*,int);
void delete_node(dlist_t*,int);
void display(dlist_t*);
void init_list(dlist_t*);

int main()
{

    int ch,x,pos;

    dlist_t dl;

    init_list(&dl);

    while(1)
    {
        display(&dl);
        printf("\n1..Insert Head\n");
        printf("2..Insert Tail\n");
        printf("3..Delete a Node..\n");
        printf("4..Display\n");
        printf("5..Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number...");
            scanf("%d",&x);
            insert_head(&dl,x);
            break;
            case 2:printf("Enter the number...");
            scanf("%d",&x);
            insert_tail(&dl,x);
            break;
            case 3: printf("Enter the value of the node to be deleted...");
            scanf("%d",&x);
            delete_node(&dl,x);
            break;

            case 4:display(&dl);
            break;
            case 5:exit(0);
        }
    }
}

void init_list(dlist_t* ptr_list)
{
    ptr_list->head=NULL;
}


