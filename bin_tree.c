//
// Created by disha on 16-09-2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct root // structure for one particular node
{
    int data;
    struct root *rlink;
    struct root *llink;
} Btree;

Btree* createnode(int data)
{
    Btree *temp = malloc(sizeof(Btree));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

void inorder_traversal(Btree *root) // Inorder → Left → Root → Right
{
if (root == NULL)
        return;
    inorder_traversal(root->llink);
    printf("%d ", root->data);
    inorder_traversal(root->rlink);
}

void preorder_traversal(Btree *root) // Preorder → Root → Left → Right
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder_traversal(root->llink);
    preorder_traversal(root->rlink);
}

void postorder_traversal(Btree *root) // Postorder → Left → Right → Root
{
    if (root == NULL)
        return;
    postorder_traversal(root->llink);
    postorder_traversal(root->rlink);
    printf("%d ", root->data);
    }

int main()
{
    Btree *root = createnode(10);
    root->llink = createnode(20);
    root->rlink = createnode(30);
    root->rlink->llink = createnode(40);
    root->rlink->rlink = createnode(50);
    root->llink->llink = createnode(10);
    root->llink->rlink = createnode(5);
    printf("Inorder Traversal: \n");
    inorder_traversal(root);
    printf("\nPreorder Traversal: \n");
    preorder_traversal(root);
    printf("\nPostorder Traversal: \n");
    postorder_traversal(root);
}