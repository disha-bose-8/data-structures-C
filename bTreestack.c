#include <stdio.h>
#include <stdlib.h>

typedef struct root {
    int data;
    struct root *rlink;
    struct root *llink;
} Btree;

Btree* createnode(int data) {
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

// ---------------- Inorder (Left → Root → Right) ----------------
void inorder(Btree *root) {
    Btree *s[50], *cur = root;
    int top = -1;

    while (cur != NULL || top != -1) {
        while (cur != NULL) {           // go left
            s[++top] = cur;
            cur = cur->llink;
        }
        cur = s[top--];                 // pop
        printf("%d ", cur->data);       // visit root
        cur = cur->rlink;               // go right
    }
}

// ---------------- Preorder (Root → Left → Right) ----------------
void preorder(Btree *root) {
    if (root == NULL) return;

    Btree *s[50];
    int top = -1;
    s[++top] = root;

    while (top != -1) {
        Btree *cur = s[top--];
        printf("%d ", cur->data);       // visit root first

        if (cur->rlink != NULL)         // push right child
            s[++top] = cur->rlink;
        if (cur->llink != NULL)         // push left child
            s[++top] = cur->llink;
    }
}

// ---------------- Postorder (Left → Right → Root) ----------------
void postorder(Btree *root) {
    if (root == NULL) return;

    Btree *s1[50], *s2[50];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 != -1) {
        Btree *cur = s1[top1--];
        s2[++top2] = cur;

        if (cur->llink != NULL)
            s1[++top1] = cur->llink;
        if (cur->rlink != NULL)
            s1[++top1] = cur->rlink;
    }

    while (top2 != -1) {
        printf("%d ", s2[top2--]->data);   // pop in reverse order
    }
}

// ---------------- Main ----------------
int main() {
    Btree *root = createnode(10);
    root->llink = createnode(20);
    root->rlink = createnode(30);
    root->rlink->llink = createnode(40);
    root->rlink->rlink = createnode(50);

    printf("Inorder Traversal:   ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:  ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
