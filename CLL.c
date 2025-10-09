//
// Created by disha on 24-08-2025.
//
// Program to implement circular singly linked list
// Pointer points to the last node

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;

// last : pointer to last node
struct list
{
    NODE *last; // points to the last node in the circular linked list
};

typedef struct list clist_t;

// Function prototypes
void init_list(clist_t *);
void insert_front(clist_t *, int);
void insert_end(clist_t *, int);
void delete_node(clist_t *, int);
void display(clist_t *);

int main()
{
    int ch, data;
    clist_t l;
    init_list(&l);

    while (1)
    {
        printf("\n==============================");
        printf("\n1. Insert at head");
        printf("\n2. Insert at tail");
        printf("\n3. Display");
        printf("\n4. Delete a node");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_front(&l, data);
            break;

        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_end(&l, data);
            break;

        case 3:
            display(&l);
            break;

        case 4:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            delete_node(&l, data);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Initialize list
void init_list(clist_t *ptr)
{
    ptr->last = NULL; // empty list initially
}

// Insert at head
void insert_front(clist_t *ptr, int data)
{
    NODE *temp, *last;

    temp = (NODE *)malloc(sizeof(NODE));
    if (!temp)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    temp->data = data;

    last = ptr->last; // last node

    if (last == NULL) // first node
    {
        temp->link = temp;
        ptr->last = temp;
    }
    else
    {
        temp->link = last->link; // last->link points to previously first node
        last->link = temp;
    }
}

// Insert at end
void insert_end(clist_t *ptr, int data)
{
    NODE *temp, *last;

    temp = (NODE *)malloc(sizeof(NODE));
    if (!temp)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    temp->data = data;

    last = ptr->last;

    if (last == NULL) // if empty list
    {
        temp->link = temp;
        ptr->last = temp;
    }
    else
    {
        temp->link = last->link; // last->link points to first node
        last->link = temp;
        ptr->last = temp; // update last
    }
}

// Display list
void display(clist_t *ptr)
{
    NODE *pres, *last;

    if (ptr->last == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    last = ptr->last;
    pres = last->link; // first node

    printf("\nList: ");
    do
    {
        printf("%d -> ", pres->data);
        pres = pres->link;
    } while (pres != last->link); // until we come back to first node ******************

    printf("(back to head)\n");
}

// Delete node by value (using while instead of do-while)
void delete_node(clist_t *ptr, int data)
{
    if (ptr->last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    NODE *last = ptr->last;       // last node
    NODE *pres = last->link;      // first node
    NODE *prev = last;         // previous node (initially last)

    // Search until we loop back to first node
    while (pres != last)
    {
        if (pres->data == data)
            break;
        prev = pres;
        pres = pres->link;
    }

    // Special check for last node
    if (pres == last && pres->data != data)
    {
        printf("Data not found.\n");
        return;
    }

    // Case 1: Only one node
    if (pres->link == pres)
    {
        ptr->last = NULL;
    }
    else
    {
        prev->link = pres->link;

        if (pres == last) // if deleting last node
            ptr->last = prev;
    }

    free(pres);
    printf("Node with data %d deleted.\n", data);
}
