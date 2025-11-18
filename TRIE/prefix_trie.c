//
// Created by disha on 17-11-2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 26 // number of child pointers per Trie node (for letters a–z)
#define MAX_LEN 100 //max size of a word and also size for some arrays (like stack, word buffer).

struct Trie {
    int isLeaf;
    struct Trie *character[CHAR_SIZE]; // pointers to child nodes for each character, Each index 0–25 corresponds to 'a' to 'z'
};

// Create a new Trie node
struct Trie *getNewTrieNode() {
    struct Trie *node = (struct Trie *)malloc(sizeof(struct Trie));
    node->isLeaf = 0;
    for (int i = 0; i < CHAR_SIZE; i++)
        node->character[i] = NULL;
    return node;
}

// Insert a word
void insert(struct Trie **head, char *str) { // double pointer to modify head if it's NULL, head is a pointer to the root pointer (so we can modify the root if needed)
    if (*head == NULL)
        *head = getNewTrieNode();

    struct Trie *curr = *head; // Start from the root, curr is a working pointer used to walk down the Trie, starting at the root
    while (*str) { // Traverse each character in the string until the null terminator '\0', *str is the current character.
        int idx = *str - 'a'; // Calculate index for the character (0 for 'a', 1 for 'b', ..., 25 for 'z')
        if (curr->character[idx] == NULL)
            curr->character[idx] = getNewTrieNode();
        curr = curr->character[idx];
        str++; // Move to the next character in the string
    }
    curr->isLeaf = 1; // Mark the end of the word
}

// Search a word
int search(struct Trie *head, char *str) { // head is a pointer to the root of the Trie, head is the root pointer (not pointer to pointer now, we’re not modifying it). str is the word to search.
    if (head == NULL)
        return 0;

    struct Trie *curr = head;
    while (*str) {
        int idx = *str - 'a';
        if (curr->character[idx] == NULL) // If at any point, the required child doesn't exist, the word is not in the Trie → return 0.
            return 0;
        curr = curr->character[idx];
        str++;
    }
    return curr->isLeaf;
}

int haveChildren(struct Trie *curr) {
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i] != NULL)
            return 1;
    return 0;
}

// Non-recursive delete
void delete_trie(struct Trie **head, char *str) {
    if (*head == NULL || *str == '\0')
        return;

    struct Trie *curr = *head;
    struct Trie *stack[MAX_LEN];
    int index_stack[MAX_LEN];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        int idx = str[i] - 'a';
        if (curr->character[idx] == NULL) {
            printf("Word not found.\n");
            return;
        }
        stack[++top] = curr;
        index_stack[top] = idx;
        curr = curr->character[idx];
    }

    if (!curr->isLeaf) {
        printf("Word not found.\n");
        return;
    }

    curr->isLeaf = 0;

    for (int i = top; i >= 0; i--) {
        struct Trie *parent = stack[i];
        int idx = index_stack[i];
        if (!haveChildren(curr) && curr->isLeaf == 0) {
            free(curr);
            parent->character[idx] = NULL;
            curr = parent;
        } else
            break;
    }

    int empty = 1;
    for (int i = 0; i < CHAR_SIZE; i++) {
        if ((*head)->character[i] != NULL) {
            empty = 0;
            break;
        }
    }
    if (empty && (*head)->isLeaf == 0) {
        free(*head);
        *head = NULL;
    }
}

// Helper recursive display functions
char word[MAX_LEN];
int length = 0;

void display(struct Trie *curr) {
    if (curr == NULL)
        return;

    if (curr->isLeaf) {
        word[length] = '\0';
        printf("%s\n", word);
    }

    for (int i = 0; i < CHAR_SIZE; i++) {
        if (curr->character[i]) {
            word[length++] = i + 'a';
            display(curr->character[i]);
            length--;
        }
    }
}

void display_length(struct Trie *curr, int count) {
    if (curr == NULL)
        return;

    if (curr->isLeaf && length == count) {
        word[length] = '\0';
        printf("%s\n", word);
    }

    for (int i = 0; i < CHAR_SIZE; i++) {
        if (curr->character[i]) {
            word[length++] = i + 'a';
            display_length(curr->character[i], count);
            length--;
        }
    }
}

void display_prefix(struct Trie *root, char *prefix) {
    struct Trie *curr = root;
    char temp[MAX_LEN];

    strcpy(temp, prefix);
    for (int i = 0; prefix[i] != '\0'; i++) {
        int idx = prefix[i] - 'a';
        if (curr->character[idx] == NULL) {
            printf("No words found with that prefix.\n");
            return;
        }
        curr = curr->character[idx];
    }

    strcpy(word, temp);
    length = strlen(temp);
    display(curr);
}

// Menu-driven program
int main() {
    struct Trie *root = NULL;
    int choice, k, count;
    char key[MAX_LEN], prefix[MAX_LEN];

    while (1) {
        printf("\n--- Trie Menu ---\n");
        printf("1. Insert word\n");
        printf("2. Delete word\n");
        printf("3. Search word\n");
        printf("4. Display all words\n");
        printf("5. Display words of given length\n");
        printf("6. Display words with given prefix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter word: ");
            scanf("%s", key);
            insert(&root, key);
            break;

        case 2:
            printf("Enter the word for deletion: ");
            scanf("%s", key);
            delete_trie(&root, key);
            break;

        case 3:
            printf("Enter the word to search: ");
            scanf("%s", key);
            k = search(root, key);
            if (k)
                printf("Word found.\n");
            else
                printf("Not found.\n");
            break;

        case 4:
            length = 0;
            printf("\nWords in Trie:\n");
            display(root);
            break;

        case 5:
            length = 0;
            printf("Enter the length: ");
            scanf("%d", &count);
            printf("Words of length %d:\n", count);
            display_length(root, count);
            break;

        case 6:
            length = 0;
            printf("Enter the prefix: ");
            scanf("%s", prefix);
            printf("Words with prefix '%s':\n", prefix);
            display_prefix(root, prefix);
            break;

        case 7:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
