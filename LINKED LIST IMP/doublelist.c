//
// Created by disha on 23-09-2025.
//

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
void delete_after(DLIST *, int);
void delete_before(DLIST *, int);
void display_reverse(DLIST *);
void count(DLIST *);
void search(DLIST *, int);
void delete_alt(DLIST *);
void sum(DLIST *);
void sortAscending(DLIST *);
void sortDescending(DLIST *);
void orderlist(DLIST *, int);
void orderlistdes(DLIST *, int);
void display_alternate(DLIST *);

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
        printf("4..delete first node\n");
        printf("5..Delete Last Node\n");
        printf("6..Delete a node given value\n");
        printf("7..Delete at a position\n");
        printf("8..Insert at a Given Position\n");
        printf("9..Insert after given value\n");
        printf("10..Insert before given value\n");
        printf("11..Delete before given value\n");
        printf("12..Delete after given value\n");
        printf("13..Display in Reverse Order\n");
        printf("14..Count no of nodes\n");
        printf("15..Search for an element\n");
        printf("16..Delete alternate nodes\n");
        printf("17..Sum of all nodes\n");
        printf("18..Sort the list(ascending)\n");
        printf("19..Sort the list(descending)\n");
        printf("20..Insert in sorted list (ascending)\n");
        printf("21..Insert in sorted list (descending)\n");
        printf("22..Display in zig zag order\n");
        printf("23..Exit\n");

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
            printf("\nEnter the value: ");
            scanf("%d", &value);
            delete_before(&l, value);
            break;
        case 12:
            printf("\nEnter the value: ");
            scanf("%d", &value);
            delete_after(&l, value);
            break;
        case 13:
            display_reverse(&l);
            break;

        case 14:
            printf("Count of nodes\n");
            count(&l);
        break;

        case 15:
            printf("\nEnter the element to be searched");
            scanf("%d", &value);
            search(&l, value);
        break;

        case 16:
            delete_alt(&l);
        break;

        case 17:
            printf("Sum of all nodes\n");
        sum(&l);
        break;

        case 18:
            sortAscending(&l);
        break;

        case 19:
            sortDescending(&l);
        break;

        case 20:
            orderlist(&l,data);
        break;

        case 21:
            orderlistdes(&l,data);
        break;

            case 22:
                display_alternate(&l);
            break;

        case 23:
            exit(0);
        }
    }
}

void init_list(DLIST *ptr)
{
    ptr->head = NULL; //pointer which points to first ele of dlist
}


void display_alternate(DLIST *ptr) {
    if (ptr->head == NULL) {
        printf("Empty List\n");
        return;
    }

    NODE *start = ptr->head;
    NODE *end = ptr->head;

    while (end->rlink != NULL)
        end = end->rlink; // traverse to last node

    printf("Alternate printing: \n");

    while (start != NULL && end != NULL && start != end && start->llink != end) {
        printf("%d", start->data);
        if (start != end)
            printf("%d", end->data);
        start = start->rlink;
        end = end->llink;
    }

    if (start == end)
        printf("%d", start->data);

    printf("\n");
}


void orderlist(DLIST *ptr, int ele) { //insert in a sorted array (ascending)
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = NULL;

    // Case 1: Empty list or insert at front
    if (ptr->head == NULL || ele < ptr->head->data) {
        temp->rlink = ptr->head;
         if (ptr->head != NULL)
            ptr->head->llink = temp;
        ptr->head = temp;
        return;
    }

    NODE *cur = ptr->head;
    NODE *prev = NULL;

    // Traverse until we find correct position
    while (cur != NULL && cur->data < ele) {
        prev = cur;
        cur = cur->rlink;
    }

    // Insert between prev and cur
    prev->rlink = temp;
    temp->llink = prev;
    temp->rlink = cur;
    cur->llink = temp;
}

void orderlistdes(DLIST *ptr, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = NULL;

    // Empty or insert at front (if ele > head->data)
    if (ptr->head == NULL || ele > ptr->head->data) {
        temp->rlink = ptr->head;
            if (ptr->head != NULL)
                ptr->head->llink = temp;
        ptr->head = temp;
        return;
    }

    NODE *cur = ptr->head;
    NODE *prev = NULL;

    while (cur != NULL && cur->data > ele) { // Notice '>' instead of '<'
        prev = cur;
        cur = cur->rlink;
    }

    prev->rlink = temp;
    temp->llink = prev;
    temp->rlink = cur;
    cur->llink = temp;

}

void sum(DLIST *ptr) {
    int sum = 0;
    if (ptr->head == NULL) {
        printf("Empty List\n");
        return;
    }
    NODE *cur = ptr->head;
    while (cur != NULL) {
        sum = sum + cur->data;
        cur = cur->rlink;
    }
    printf("%d\n", sum);
}

void sortAscending(DLIST *ptr) {
    if (ptr->head == NULL || ptr->head->rlink == NULL) { // no node or only one node
        return; // empty or single node
    }

    NODE *i, *j;
    int temp;
    for (i = ptr->head; i->rlink != NULL; i = i->rlink) {
        for (j = i->rlink; j != NULL; j = j->rlink) {
            if (i->data > j->data) {
                // swap
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void sortDescending(DLIST *ptr) {
    if (ptr->head == NULL || ptr->head->rlink == NULL) {
        return;
    }

    NODE *i, *j;
    int temp;
    for (i = ptr->head; i->rlink != NULL; i = i->rlink) {
        for (j = i->rlink; j != NULL; j = j->rlink) {
            if (i->data < j->data) {
                // swap
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


void delete_alt(DLIST *ptr) { // important
    if (ptr->head == NULL) {
        printf("The list is empty\n");
        return;
    }

    NODE *cur = ptr->head;  // start from head
    while (cur != NULL && cur->rlink != NULL) {
        NODE *temp = cur->rlink;       // node to delete (next one)
        cur->rlink = temp->rlink;      // bypass deleted node
        if (temp->rlink != NULL) {
            temp->rlink->llink = cur;  // fix backward link
        }
        free(temp);                    // free the alternate node
        cur = cur->rlink;              // move to the next surviving node
    }
}

void search(DLIST *ptr,int ele) {
    int i=1;
    int found = 0;

    if (ptr->head == NULL) {
        printf("The list is empty\n");
        return;
    }
    else {
        NODE *cur = ptr->head;
        while (cur != NULL) {
            if (cur->data == ele) {
                printf("The element is in pos %d\n", i);
                found = 1;
            }
            cur = cur->rlink;
            i++;
        }
    }
    if (!found)
        printf("The element is not in the list\n");
}

void count(DLIST *ptr) {
    int count = 1;

    if (ptr->head==NULL) {
        printf("Empty List\n");
        return;
    }
    else {
        NODE *cur = ptr->head;
        while (cur->rlink!=NULL) {
            count++;
            cur = cur->rlink;
        }
        printf("%d\n", count);
    }
}

// Print the list in reverse order
void display_reverse(DLIST *ptr) {
    NODE *cur = ptr->head;

    if (cur == NULL) {
        printf("\nEmpty List..\n");
        return;
    }

    // move to last node
    while (cur->rlink != NULL)
        cur = cur->rlink;

    // traverse backward
    while (cur != NULL) {
        printf("%d<->", cur->data);
        cur = cur->llink;
    }
    printf("\n");
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
    if (cur->rlink != NULL) //********************************************
        cur->rlink->llink = temp;
    temp->llink = cur;
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
        ptr->head = temp; // inserting before first node**************************

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
        temp->rlink = NULL;

    }
}

// Delete the node before a given value
void delete_before(DLIST *ptr, int value) {
    NODE *cur = ptr->head;

    // find the node with the given value
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;

    if (cur == NULL) {
        printf("\nValue %d not found.\n", value);
        return;
    }

    if (cur->llink == NULL) { // no node before
        printf("\nNo node exists before %d\n", value);
        return;
    }

    NODE *del = cur->llink;

    if (del->llink != NULL)
        del->llink->rlink = cur;
    else
        ptr->head = cur; // deleted node was head

    cur->llink = del->llink;
    free(del);
    printf("\nDeleted node before %d\n", value);
}

// Delete the node after a given value
void delete_after(DLIST *ptr, int value) {
    NODE *cur = ptr->head;

    // find the node with the given value
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;

    if (cur == NULL) {
        printf("\nValue %d not found.\n", value);
        return;
    }

    if (cur->rlink == NULL) { // no node after
        printf("\nNo node exists after %d\n", value);
        return;
    }

    NODE *del = cur->rlink;

    cur->rlink = del->rlink;
    if (del->rlink != NULL)
        del->rlink->llink = cur;

    free(del);
    printf("\nDeleted node after %d\n", value);
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

void delete_node(DLIST *ptr, int data) //delete particular node by value *****************************************
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