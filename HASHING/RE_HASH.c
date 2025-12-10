//
// Created by disha on 10-12-2025.
//

//
// Rehashing + Linear Probing Hash Table
//

#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int key;
    int value;
} ITEM;

typedef struct hash {
    int flag;          // 0 = empty, 1 = occupied, 2 = deleted
    ITEM *data;        // pointer to item
} HASH_TABLE;

HASH_TABLE *array;  // pointer to hash table
int MAX = 5;        // initial table size
int count = 0;      // number of elements stored

//----------------------------------------------
// Initialize hash table
//----------------------------------------------
void init() {
    for (int i = 0; i < MAX; i++) {
        array[i].flag = 0;   // empty
        array[i].data = NULL;
    }
}

//----------------------------------------------
// Hash function
//----------------------------------------------
int hash_fun(int key) {
    return key % MAX;
}

//----------------------------------------------
// Rehashing: double the size & reinsert elements
//----------------------------------------------
void rehash() {
    printf("\n🔁 Rehashing... Load factor exceeded 0.75\n");

    int oldMAX = MAX;
    MAX = MAX * 2;

    HASH_TABLE *oldArray = array;

    // Allocate new table with bigger size
    array = (HASH_TABLE *)malloc(MAX * sizeof(HASH_TABLE));
    init();
    count = 0;  // will reinsert, so reset count

    // Copy elements
    for (int i = 0; i < oldMAX; i++) {
        if (oldArray[i].flag == 1) {
            int key = oldArray[i].data->key;
            int value = oldArray[i].data->value;

            // Reinsert into bigger table
            int index = hash_fun(key);
            int start = index;

            while (array[index].flag == 1) {
                index = (index + 1) % MAX;
            }

            array[index].flag = 1;
            array[index].data = (ITEM *)malloc(sizeof(ITEM));
            array[index].data->key = key;
            array[index].data->value = value;

            count++;
        }
    }

    free(oldArray);

    printf("✅ Rehash complete! New size = %d\n\n", MAX);
}

//----------------------------------------------
// Insert using linear probing
//----------------------------------------------
void insert(int key, int value) {
    float load = (float)count / MAX;

    // Check if rehashing needed BEFORE insert
    if (load > 0.75) {
        rehash();
    }

    int index = hash_fun(key);
    int start = index;

    ITEM *newItem = (ITEM *)malloc(sizeof(ITEM));
    newItem->key = key;
    newItem->value = value;

    while (array[index].flag == 1) {
        if (array[index].data->key == key) {
            printf("Duplicate key. Updating value...\n");
            array[index].data->value = value;
            return;
        }
        index = (index + 1) % MAX;

        if (index == start) {
            printf("Table full! Cannot insert.\n");
            return;
        }
    }

    array[index].flag = 1;
    array[index].data = newItem;
    count++;

    printf("%d inserted at index %d\n", key, index);
}

//----------------------------------------------
// Search using linear probing
//----------------------------------------------
void search(int key) {
    int index = hash_fun(key);
    int start = index;

    while (array[index].flag != 0) {
        if (array[index].flag == 1 && array[index].data->key == key) {
            printf("Key %d found at index %d with value %d\n",
                   key, index, array[index].data->value);
            return;
        }
        index = (index + 1) % MAX;

        if (index == start) break;
    }

    printf("Key %d not found\n", key);
}

//----------------------------------------------
// Remove item (lazy deletion)
//----------------------------------------------
void remove_item(int key) {
    int index = hash_fun(key);
    int start = index;

    while (array[index].flag != 0) {
        if (array[index].flag == 1 && array[index].data->key == key) {
            printf("Deleting key %d from index %d\n", key, index);
            free(array[index].data);
            array[index].data = NULL;
            array[index].flag = 2;
            count--;
            return;
        }
        index = (index + 1) % MAX;

        if (index == start) break;
    }

    printf("Key %d not found, cannot delete\n", key);
}

//----------------------------------------------
// Display table
//----------------------------------------------
void display() {
    printf("\nHash Table (size = %d):\n", MAX);

    for (int i = 0; i < MAX; i++) {
        printf("[%d] : ", i);
        if (array[i].flag == 1)
            printf("Key = %d, Value = %d\n", array[i].data->key, array[i].data->value);
        else if (array[i].flag == 2)
            printf("<deleted>\n");
        else
            printf("<empty>\n");
    }
    printf("\n");
}

//----------------------------------------------
// Main
//----------------------------------------------
int main() {
    int key, value, choice;

    array = (HASH_TABLE *)malloc(MAX * sizeof(HASH_TABLE));
    init();

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Remove\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                remove_item(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
