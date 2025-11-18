//
// Created by disha on 18-11-2025.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // // Defines a macro SIZE with value 10 (hash table will have 10 buckets)

typedef struct node { // defines a linked list node
    int data;           // 'data' will store the key value in this node
    struct node *next;  // Pointer to the next node (for forming a linked list)
} NODE;                 // 'NODE' is now an alias for 'struct node'


typedef struct hashtable { // This defines a single bucket of the hash table.
    int count;          // Number of elements stored in this particular bucket
    struct node *head;  // Pointer to the first node (head) of the linked list at this bucket
} HASHTABLE;            // 'HASHTABLE' is now an alias for 'struct hashtable'


// Function to create a new node
NODE* createNode(int key) {
    NODE *nn = (NODE*)malloc(sizeof(NODE));  // Allocate memory for one NODE
    if (!nn) {                               // If malloc returned NULL (allocation failed)
        printf("Memory allocation error\n"); // Print error message
        exit(1);                             // Exit the program with status 1 (error)
    }
    nn->data = key;                          // Store the key in the node's data field
    nn->next = NULL;                         // Initially, next is NULL (not linked yet)
    return nn;                               // Return pointer to the newly created node
}


// Insert key into the hash table
void insert(int key, HASHTABLE *HashTable) {
    int hash = key % SIZE;                   // Compute hash index using modulo (0 to SIZE-1)
    NODE *nn = createNode(key);             // Create a new node with the given key
    nn->next = HashTable[hash].head;        // New node points to current head of the list at that index
    HashTable[hash].head = nn;              // Update head to be this new node (insert at beginning)
    HashTable[hash].count++;                // Increase count of elements in this bucket
}


/*First finds the correct bucket using hash = key % SIZE.
Then walks through the linked list at that bucket.
pos tells you at which node in the chain the key was found (1st, 2nd, 3rd, …).*/

// Search for a key in the hash table
void search(int key, HASHTABLE *HashTable) {
    int hash = key % SIZE, pos = 1;         // Compute hash index and initialize position counter (1-based)
    NODE *t = HashTable[hash].head;         // Start from the head of the linked list at this index

    while (t) {                             // Traverse the linked list while t is not NULL
        if (t->data == key) {               // If current node's data matches key
            printf("\nElement found at index [%d], position [%d]\n", hash, pos);
            // Print the index (bucket) and position in the chain
            return;                         // Exit the function after finding the key
        }
        t = t->next;                        // Move to next node
        pos++;                              // Increment position counter
    }

    printf("\nData not found\n");           // If loop ends, key was not found
}


// Delete a key from the hash table
void deleteData(int key, HASHTABLE *HashTable) {
    int hash = key % SIZE;                  // Compute hash index
    NODE *t = HashTable[hash].head, *prev = NULL;
    // 't' is current node, 'prev' is previous node (starts as NULL)
    while (t) {                             // Traverse the linked list
        if (t->data == key) {               // If key is found in the current node
            if (prev) {                     // If this is NOT the first node (there is a previous)
                prev->next = t->next;       // Link previous node to the next node (skip current)
            } else {                        // If this IS the first node in the list
                HashTable[hash].head = t->next;
                // Move head to next node
            }
            free(t);                        // Free memory of the deleted node
            HashTable[hash].count--;        // Decrease count of elements in this bucket
            printf("\nData deleted successfully\n");
            return;                         // Exit function after deletion
        }
        prev = t;                           // Move prev to current node
        t = t->next;                        // Move t to next node
    }
    printf("\nData not found\n");           // If loop ended, key wasn't found
}


// Display the hash table contents
void display(HASHTABLE *HashTable) {
    for (int i = 0; i < SIZE; i++) {
        if (HashTable[i].count != 0) {
            printf("\nindex [%d]: ", i);
            NODE *t = HashTable[i].head;
            while (t) {
                printf("%d -> ", t->data);
                t = t->next;
            }
            printf("NULL");
        }
    }
    printf("\n");
}

// Main function to initialize the hash table and test the operations
int main() {
    HASHTABLE HashTable[SIZE] = {0}; // Initialize the hash table with zero counts and NULL heads
    insert(10, HashTable);
    insert(20, HashTable);
    insert(15, HashTable);
    insert(30, HashTable);
    display(HashTable);
    search(15, HashTable);
    deleteData(10, HashTable);
    display(HashTable);
    return 0;
}