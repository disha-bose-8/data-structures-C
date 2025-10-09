
// Created by disha on 24-08-2025.
// Program to implement circular singly linked list (pointer to first node)
// pointer points to first node

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};
typedef struct node NODE;

// list with pointer to first node
struct list {
    NODE *first;
};
typedef struct list clist_t;

// Function prototypes
void init_list(clist_t *);
void insert_front(clist_t *, int);
void insert_end(clist_t *, int);
void delete_node(clist_t *, int);
void display(clist_t *);

int main() {
    int ch, data;
    clist_t l;
    init_list(&l);

    while (1) {
        display(&l);
        printf("\n1..Insert at Front");
        printf("\n2..Insert at End");
        printf("\n3..Display");
        printf("\n4..Delete a Node");
        printf("\n5..Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insert_front(&l, data);
                break;
            case 2:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insert_end(&l, data);
                break;
            case 3:
                display(&l);
                break;
            case 4:
                printf("\nEnter the data to delete: ");
                scanf("%d", &data);
                delete_node(&l, data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Initialize list
void init_list(clist_t *ptr) {
    ptr->first = NULL;
}

// Insert at front
void insert_front(clist_t *ptr, int data) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;

    if (ptr->first == NULL) {
        temp->link = temp; // first node points to itself
        ptr->first = temp;
    } else {
        NODE *last = ptr->first;
        while (last->link != ptr->first) // find last *******************
            last = last->link;

        temp->link = ptr->first;
        last->link = temp;
        ptr->first = temp; // update first
    }
}

// Insert at end
void insert_end(clist_t *ptr, int data) {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;

    if (ptr->first == NULL) {
        temp->link = temp;
        ptr->first = temp;
    } else {
        NODE *last = ptr->first;
        while (last->link != ptr->first) // find last
            last = last->link;

        last->link = temp;
        temp->link = ptr->first;
    }
}

// Display list
void display(clist_t *ptr) {
    if (ptr->first == NULL) {
        printf("\nEmpty List\n");
        return;
    }

    NODE *cur = ptr->first;
    printf("\nList: ");
    do {
        printf("%d -> ", cur->data);
        cur = cur->link;
    } while (cur != ptr->first);
    printf("(back to first)\n");
}

// Delete a node by value
void delete_node(clist_t *ptr, int data) {
    if (ptr->first == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE *cur = ptr->first;
    NODE *prev = NULL;

    // search node
    do {
        if (cur->data == data)
            break;
        prev = cur;
        cur = cur->link;
    } while (cur != ptr->first);

    if (cur->data != data) {
        printf("Data not found\n");
        return;
    }

    // Only one node
    if (cur->link == cur) {
        free(cur);
        ptr->first = NULL;
        return;
    }

    if (cur == ptr->first) {
        // delete first node
        NODE *last = ptr->first;
        while (last->link != ptr->first)
            last = last->link;

        last->link = cur->link;
        ptr->first = cur->link;
        free(cur);
    } else {
        prev->link = cur->link;
        free(cur);
    }
}
