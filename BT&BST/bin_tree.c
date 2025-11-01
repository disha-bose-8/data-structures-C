// Program to Create a Binary Tree and Perform Tree Traversals

#include <stdio.h>
#include <stdlib.h>

typedef struct root
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

void inorder_traversal(Btree *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->llink);
    printf("%d ", root->data);
    inorder_traversal(root->rlink);
}

void preorder_traversal(Btree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder_traversal(root->llink);
    preorder_traversal(root->rlink);
}

void postorder_traversal(Btree *root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->llink);
    postorder_traversal(root->rlink);
    printf("%d ", root->data);
}

// 👇 Level Order Traversal
void levelorder_traversal(Btree *root)
{
    if (root == NULL)
        return;

    Btree *queue[100]; // array-based queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Btree *current = queue[front++];
        printf("%d ", current->data);

        if (current->llink != NULL)
            queue[rear++] = current->llink;

        if (current->rlink != NULL)
            queue[rear++] = current->rlink;
    }
}

void free_tree(Btree *root)
{
    if (root == NULL)
        return;
    free_tree(root->llink);
    free_tree(root->rlink);
    free(root);
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

    printf("\nLevel Order Traversal: \n");
    levelorder_traversal(root);

    free_tree(root);
}
