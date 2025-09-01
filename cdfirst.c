//
// Created by disha on 01-09-2025.
//
// CIRCULAR DOUBLY LINKED LIST WHERE HEAD POINTS TO FIRST NODE
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node NODE;

NODE *head = NULL; // first node pointer

// Function prototypes
void insertfront(int ele);
void inserttail(int ele);
void display();
void deletefirst();
void deletelast();
void deletenode(int ele);

int main() {
    int ch, data;

    // Initialize first node manually
    printf("Enter first node data: ");
    scanf("%d", &data);
    head = (NODE*)malloc(sizeof(NODE));
    head->data = data;
    head->rlink = head;
    head->llink = head;

    while(1) {
        printf("\nCurrent List: ");
        display();

        printf("\n\nMenu:");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Tail");
        printf("\n3. Delete First Node");
        printf("\n4. Delete Last Node");
        printf("\n5. Delete Node by Value");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: printf("Enter data: "); scanf("%d",&data); insertfront(data); break;
            case 2: printf("Enter data: "); scanf("%d",&data); inserttail(data); break;
            case 3: deletefirst(); break;
            case 4: deletelast(); break;
            case 5: printf("Enter data to delete: "); scanf("%d",&data); deletenode(data); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

// ================= Functions =================

// Insert at front
void insertfront(int ele) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = ele;

    NODE *last = head->llink;

    temp->rlink = head;
    temp->llink = last;
    last->rlink = temp;
    head->llink = temp;

    head = temp; // update head to new first
}

// Insert at tail
void inserttail(int ele) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = ele;

    NODE *last = head->llink;

    temp->rlink = head;
    temp->llink = last;
    last->rlink = temp;
    head->llink = temp;
}

// Display circular DLL
void display() {
    if (head == NULL) {
        printf("List is empty");
        return;
    }

    NODE *cur = head;
    do {
        printf("%d <-> ", cur->data);
        cur = cur->rlink;
    } while(cur != head);
}

// Delete first node
void deletefirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if (head->rlink == head) {
        free(head);
        head = NULL;
        return;
    }

    NODE *last = head->llink;
    NODE *second = head->rlink;

    last->rlink = second;
    second->llink = last;
    free(head);
    head = second;
}

// Delete last node
void deletelast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if (head->rlink == head) {
        free(head);
        head = NULL;
        return;
    }

    NODE *last = head->llink;
    NODE *prev = last->llink;

    prev->rlink = head;
    head->llink = prev;
    free(last);
}

// Delete node by value
void deletenode(int ele) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE *cur = head;
    NODE *found = NULL;

    // Search
    do {
        if (cur->data == ele) {
            found = cur;
            break;
        }
        cur = cur->rlink;
    } while(cur != head);

    if (found == NULL) {
        printf("Node not found\n");
        return;
    }

    // Only one node
    if (found->rlink == found) {
        free(found);
        head = NULL;
        return;
    }

    NODE *prev = found->llink;
    NODE *next = found->rlink;

    prev->rlink = next;
    next->llink = prev;

    if (found == head)  // if deleting first node
        head = next;

    free(found);
}
