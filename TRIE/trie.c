#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int EOW;                    // End of word flag
    struct node* child[256];    // Supports all ASCII chars
} NODE;

NODE* createNode() {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->EOW = 0;
    for (int i=0; i<256; i++)
        newnode->child[i] = NULL;
    return newnode;
}

void insert(NODE* root, char* key) {
    NODE* cur = root;
    for (int i=0; key[i] != '\0'; i++) {
        int index = key[i];
        if (cur->child[index] == NULL)
            cur->child[index] = createNode();
        cur = cur->child[index];
    }
    cur->EOW = 1;
}


char str[100];
int length = 0;

void display(NODE* root) {
    if (!root) return;

    for (int i=0; i<256; i++) {
        if (root->child[i] != NULL) {

            str[length++] = i;   // choose character

            if (root->child[i]->EOW == 1) {
                str[length] = '\0';
                printf("%s\n", str);
            }

            display(root->child[i]);  // recursive call

            length--;    // backtrack
        }
    }
}


void display_prefix(NODE* root, char* key) {
    NODE* cur = root;
    int i;

    // Move to last node of prefix
    for (i = 0; key[i] != '\0'; i++) {
        int index = key[i];
        if (cur->child[index] == NULL) {
            printf("No words with this prefix\n");
            return;
        }
        cur = cur->child[index];
        str[i] = key[i];
    }

    length = i; // prefix length
    str[length] = '\0';

    if (cur->EOW == 1)
        printf("%s\n", str);

    display(cur);  // display remaining subtree
}

int search(NODE* root, char* key) {
    NODE* cur = root;

    for (int i=0; key[i]!='\0'; i++) {
        int index = key[i];
        if (cur->child[index] == NULL)
            return 0;
        cur = cur->child[index];
    }

    return (cur != NULL && cur->EOW == 1);
}


int main() {
    NODE* root = createNode();

    insert(root, "cat");
    insert(root, "car");
    insert(root, "dog");
    insert(root, "doll");
    insert(root, "dove");
    insert(root, "cart");

    printf("All words:\n");
    display(root);

    printf("\nSearch 'car': %s\n", search(root, "car") ? "Found" : "Not Found");
    printf("Search 'cap': %s\n", search(root, "cap") ? "Found" : "Not Found");

    printf("\nWords with prefix 'do':\n");
    display_prefix(root, "do");

    printf("\nWords with prefix 'ca':\n");
    display_prefix(root, "ca");

    return 0;
}
