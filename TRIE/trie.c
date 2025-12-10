#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int EOW;                    // End of word flag, for each node
    struct node* child[256];    // Supports all ASCII chars, each node has 256 children
} NODE;

NODE* createNode() {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->EOW = 0;
    for (int i=0; i<256; i++)
        newnode->child[i] = NULL; //
    return newnode;
}

void insert(NODE* root, char* key) {
    NODE* cur = root;
    for (int i=0; key[i] != '\0'; i++) {
        int index = key[i];
        if (cur->child[index] == NULL)
            cur->child[index] = createNode(); // Create new node if path doesn't exist
        cur = cur->child[index]; // Move to the child node
    }
    cur->EOW = 1;
}


char str[100];
int length = 0;

/*Assume root stores words: "cat" and "car".

Traversal:

c is added → str = "c"
a is added → str = "ca"
t is added → str = "cat" → printed
Backtrack to "ca"
r is added → str = "car" → printed
Backtrack to "c" and then beyond*/

void display(NODE* root) { // print all the words stored in a Trie
    if (!root) return;

    for (int i=0; i<256; i++) {
        if (root->child[i] != NULL) {

            str[length++] = i;   // choose character, forming current word

            if (root->child[i]->EOW == 1) { // if end of word, print it
                str[length] = '\0';
                printf("%s\n", str);
            }

            display(root->child[i]);  // recursive call for each word

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
    NODE* root = createNode(); // Initialize root of Trie, empty trie

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
