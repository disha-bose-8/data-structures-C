#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node NODE;

NODE *ptr = NULL; // last node pointer ********************************

// Function prototypes
void insertfront(int ele);
void inserttail(int ele);
void display();
void deletefirst();
void deleteptr();
void deletenode(int ele);

int main() {
    int ch, data;

    while (1) {
        printf("\nCurrent List: ");
        display();

        printf("\n\nMenu:");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Tail");
        printf("\n3. Delete First Node");
        printf("\n4. Delete Last Node (ptr)");
        printf("\n5. Delete Node by Value");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: printf("Enter data: "); scanf("%d", &data); insertfront(data); break;
            case 2: printf("Enter data: "); scanf("%d", &data); inserttail(data); break;
            case 3: deletefirst(); break;
            case 4: deleteptr(); break;
            case 5: printf("Enter data to delete: "); scanf("%d", &data); deletenode(data); break;
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

    if (ptr == NULL) { // empty list
        temp->rlink = temp;
        temp->llink = temp;
        ptr = temp;
        return;
    }

    NODE *first = ptr->rlink; // address of first node (ptr is last node)
    ptr->rlink = temp; // ptr now stores temp node
    temp->llink = ptr;
    temp->rlink = first;
    first->llink = temp;
}

// Insert at tail
void inserttail(int ele) {
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = ele;

    if (ptr == NULL) { // empty list
        temp->rlink = temp;
        temp->llink = temp;
        ptr = temp;
        return;
    }

    NODE *first = ptr->rlink; // address of first node
    ptr->rlink = temp; // ptr now stores temp node
    temp->llink = ptr;
    temp->rlink = first;
    first->llink = temp;
    ptr = temp; // update last pointer
}

// Display circular DLL
void display() {
    if (ptr == NULL) {
        printf("List is empty");
        return;
    }

    NODE *cur = ptr->rlink; // first node
    do {
        printf("%d <-> ", cur->data);
        cur = cur->rlink;
    } while (cur != ptr->rlink);
}

// Delete first node
void deletefirst() {
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE *first = ptr->rlink;

    // only one node
    if (first == ptr) {
        free(first);
        ptr = NULL;
        return;
    }

    NODE *second = first->rlink;
    ptr->rlink = second;
    second->llink = ptr;
    free(first);
}

// Delete last node (ptr)
void deleteptr() {
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    // only one node
    if (ptr->rlink == ptr) {
        free(ptr);
        ptr = NULL;
        return;
    }

    NODE *prev = ptr->llink;
    NODE *first = ptr->rlink;

    prev->rlink = first;
    first->llink = prev;
    free(ptr);
    ptr = prev;
}

// Delete node by value
void deletenode(int ele) {
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE *cur = ptr->rlink; // start from first
    NODE *found = NULL;

    do {
        if (cur->data == ele) {
            found = cur;
            break;
        }
        cur = cur->rlink;
    } while (cur != ptr->rlink);

    if (found == NULL) {
        printf("Node not found\n");
        return;
    }

    // only one node
    if (found == ptr && found->rlink == ptr) {
        free(found);
        ptr = NULL;
        return;
    }

    NODE *prev = found->llink;
    NODE *next = found->rlink;

    prev->rlink = next;
    next->llink = prev;

    if (found == ptr)  // if last node was deleted
        ptr = prev;

    free(found);
}


