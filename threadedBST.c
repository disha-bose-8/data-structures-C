#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* rlink;
    struct node* llink;
    int rthread, lthread;
} NODE;

typedef struct tree {
    NODE* root;
} tree;

tree* initialize() {
    tree* temp = malloc(sizeof(tree));
    temp->root = NULL;
    return temp;
}

NODE* inorderSuccessor(NODE* ptr) {
    if (ptr->rthread == 1) {
        return ptr->rlink;
    } else {
        ptr = ptr->rlink;
        while (ptr->lthread == 0) {
            ptr = ptr->llink;
        }
        return ptr;
    }
}

void create(tree* root, int data) {
    NODE* temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = temp->llink = NULL;
    temp->rthread = temp->lthread = 1;

    if (root->root == NULL) {
        root->root = temp;
        return;
    }

    NODE* current = root->root;
    NODE* parent = NULL;

    while (1) {
        parent = current;
        if (data < current->data) {
            if (current->lthread == 0) {
                current = current->llink;
            } else {
                break;
            }
        } else {
            if (current->rthread == 0) {
                current = current->rlink;
            } else {
                break;
            }
        }
    }

    if (data < parent->data) {
        temp->llink = parent->llink;
        temp->rlink = parent;
        parent->lthread = 0;
        parent->llink = temp;
    } else {
        temp->rlink = parent->rlink;
        temp->llink = parent;
        parent->rthread = 0;
        parent->rlink = temp;
    }
}

void inorder(tree* ptr) {
    NODE* current = ptr->root;
    if (current == NULL) {
        printf("Tree is empty\n");
        return;
    }

    // Go to leftmost node
    while (current->lthread == 0) {
        current = current->llink;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = inorderSuccessor(current);
    }
    printf("\n");
}

int main() {
    tree* root = initialize();
    int ch, ele;

    while (1) {
        printf("\n1. Create threaded BST\n2. Inorder traversal\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &ele);
                create(root, ele);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
