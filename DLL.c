// implementation of doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    //self-referential pointers
    struct node *rlink;
    struct node *llink;
};

typedef struct node NODE;

struct dlist
{
    NODE *head;
    int no_of_nodes;
};

typedef struct dlist DLIST;

void init_list(DLIST *);
void insert_head(DLIST *, int);
void display(DLIST *);
void insert_tail(DLIST *, int);
void delete_first(DLIST *);
void delete_last(DLIST *);
void delete_node(DLIST *, int);
void delete_pos(DLIST *, int);
void insert_pos(DLIST *, int, int);
void insert_after(DLIST *, int, int);
void insert_before(DLIST *, int, int);

int main()
{
    int ch, data, pos, value;
    DLIST l;
    init_list(&l);

    while (1)
    {
        display(&l);
        printf("1..insert_head\n");
        printf("2..insert_tail\n");
        printf("3..Display\n");
        printf("4.delete first node\n");
        printf("5. Delete Last Node..\n");
        printf("6 .Delete a node given value\n");
        printf("7.Delete at a position\n");
        printf("8.Insert at a Given Position\n");
        printf("9. Insert after given value..\n");
        printf("10. Insert before given value..\n");
        printf("11.Exit\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data...");
            scanf("%d", &data);
            insert_head(&l, data);
            break;
        case 2:
            printf("\nEnter the data...");
            scanf("%d", &data);
            insert_tail(&l, data);
            break;
        case 3:
            display(&l);
            break;
        case 4:
            delete_first(&l);
            break;
        case 5:
            delete_last(&l);
            break;
        case 6:
            printf("\nEnter the data...");
            scanf("%d", &data);
            delete_node(&l, data);
            break;
        case 7:
            printf("\nEnter the position");
            scanf("%d", &pos);
            delete_pos(&l, pos);
            break;
        case 8:
            printf("\nEnter the data and position");
            scanf("%d %d", &data, &pos);
            insert_pos(&l, data, pos);
            break;
        case 9:printf("\nEnter the value and data");
                     scanf("%d %d" ,&value,&data);
                    insert_after(&l,value,data);
                    break;
        case 10:printf("\nEnter the value and data");
                     scanf("%d %d" ,&value,&data);
                   insert_before(&l,value,data);
                   break;
        case 11:
            exit(0);
        }
    }
}

void init_list(DLIST *ptr)
{
    ptr->head = NULL; //pointer which points to first ele of dlist
}

void insert_head(DLIST *ptr, int data) //insert at front
{

    // create node
    NODE *temp;

    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = temp->llink = NULL;

    // if first node ?
    if (ptr->head == NULL)
      {
        ptr->head = temp;
        ptr->no_of_nodes++;
    }

    else
    {
      /*
        temp->rlink = ptr->head; //head has address of first element
        ptr->head->llink = temp; //first element now connected to temp (becomes next)
        ptr->head = temp; //ptr pointing to list points to temp(first node)
       */
      NODE *first = ptr->head;
      temp->rlink = first;
      first->llink = temp;
      ptr->head = temp;
      ptr->no_of_nodes++;
    }
}

void display(DLIST *ptr)
{
    NODE *cur;
    cur = ptr->head;

    if (cur == NULL)
        printf("\nEmpty List..\n");
    else
    {
        while (cur != NULL)
        {
            printf("%d<->", cur->data);
            cur = cur->rlink;
        }
    }
    printf("\n");
}

void insert_after(DLIST *ptr, int value, int data) {
    NODE *cur = ptr->head;

    // find the node with the given value
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;

    if (cur == NULL) {
        printf("\nValue %d not found.\n", value);
        return;
    }

    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = cur->rlink;
    temp->llink = cur;

    if (cur->rlink != NULL)
        cur->rlink->llink = temp;

    cur->rlink = temp;
}

void insert_before(DLIST *ptr, int value, int data) {
    NODE *cur = ptr->head;

    // find the node with the given value
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;

    if (cur == NULL) {
        printf("\nValue %d not found.\n", value);
        return;
    }

    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = cur;
    temp->llink = cur->llink;

    if (cur->llink != NULL)
        cur->llink->rlink = temp;
    else
        ptr->head = temp; // inserting before first node

    cur->llink = temp;
}

void insert_tail(DLIST *ptr, int data)
{
    // create node
    NODE *temp, *cur;

    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = temp->llink = NULL;

    // if first node
    if (ptr->head == NULL)
        ptr->head = temp;
    else
    {
        cur = ptr->head;
        // go to last node
        while (cur->rlink != NULL)
            cur = cur->rlink;

        cur->rlink = temp;
        temp->llink = cur;
    }
}

void delete_first(DLIST *ptr)
{

    NODE *cur;
    cur = ptr->head;
    if (cur->rlink == NULL) // only one node
        ptr->head = NULL;
    else
    {
        ptr->head = cur->rlink;
        cur->rlink->llink = NULL;
    }
    free(cur);
}

void delete_last(DLIST *ptr)
{
    NODE *cur;
    cur = ptr->head;
    if (cur->rlink == NULL) // only one node
        ptr->head = NULL;
    else
    {
        // go to last node
        while (cur->rlink != NULL)
            cur = cur->rlink;

        cur->llink->rlink = NULL;
    }
    free(cur);
}

void delete_node(DLIST *ptr, int data) //delete particular node by value
{

    NODE *cur;
    cur = ptr->head;
    // find the node
    while ((cur != NULL) && (cur->data != data))
        cur = cur->rlink; //till node is found
    if (cur != NULL) // node found
    {
        // where ?
        // if only one node
        if ((cur->rlink == NULL) && (cur->llink == NULL))
            ptr->head = NULL;
        else if (cur->llink == NULL) // first node
        {
            cur->rlink->llink = NULL;
            ptr->head = cur->rlink;
        }
        else if (cur->rlink == NULL) // last node
            cur->llink->rlink = NULL;
        else // somewhere in the middle
        {
            cur->llink->rlink = cur->rlink; //cur's left link connected to cur's right link
            cur->rlink->llink = cur->llink; //vice versa
        }
        free(cur);
    }
    else // cur==NULL
        printf("\nNode not found..\n");
}

void delete_pos(DLIST *ptr, int pos)
{
    NODE *cur;
    int i;
    cur = ptr->head;
    // find the node at given position
    i = 1;
    while ((cur != NULL) && (i < pos))
    {
        i++;
        cur = cur->rlink;
    }
    if (cur != NULL) // postion found
    {
        // where ?
        // if only one node
        if ((cur->rlink == NULL) && (cur->llink == NULL))
            ptr->head = NULL;
        else if (cur->llink == NULL) // first node
        {
            cur->rlink->llink = NULL;
            ptr->head = cur->rlink;
        }
        else if (cur->rlink == NULL) // last node
            cur->llink->rlink = NULL;
        else // somewhere in the middle
        {
            cur->llink->rlink = cur->rlink;
            cur->rlink->llink = cur->llink;
        }
        free(cur);
    }
    else // cur==NULL
        printf("\nNode not found..Invalid position\n");
}

void insert_pos(DLIST *ptr, int data, int pos)
{
    // create node
    NODE *temp, *cur;
    int i;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = temp->llink = NULL;
    // find the position
    i = 1;
    cur = ptr->head;
    // move forward till you go to last node or position is found
    while ((cur->rlink != NULL) && (i < pos))
    {
        i++;
        cur = cur->rlink;
    }
    if (cur->rlink != NULL) // postion is found
    {
        // where ?
        if (cur->llink == NULL) // first position
        {
            temp->rlink = cur;
            cur->llink = temp;
            ptr->head = temp;
        }
        else // somewhere in middle
        {
            temp->llink = cur->llink;
            cur->llink->rlink = temp;
            temp->rlink = cur;
            cur->llink = temp;
        }
    }
    else // cur->rlink==NULL
    {
        if (i == pos - 1) // insert at end , last position
        {
            cur->rlink = temp;
            temp->llink = cur;
        }
        else
            printf("\n\nInvalid position");
    }
}