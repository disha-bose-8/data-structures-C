//
// Created by disha on 05-11-2025.
//
// linear probing

/*A Hash Table is a data structure that allows for very fast data retrieval (like a dictionary). When we want to store data, we calculate
an index (using a hash function) and put the data there. If that spot is already taken (a collision), Linear Probing simply looks at the
next available slot to store the data.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // max size of hash table

typedef struct item { // structure to hold key-value pairs
    int key;
    int value;
} ITEM;

typedef struct hash { // structure for hash table entries
    int flag;          // 0 = empty, 1 = occupied, 2 = deleted
    ITEM *data; // pointer to the item
} HASH_TABLE;

HASH_TABLE *array; // global hash table array

void init() { // initialize hash table to null values
    for (int i = 0; i < MAX; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hash_fun(int key) {
    return key % MAX; // to check index
}

void insert(int key, int value) {
    int i, index;
    i = hash_fun(key);
    index = i;

    ITEM *ele = (ITEM *)malloc(sizeof(ITEM)); // allocate memory for new item
    ele->key = key;
    ele->value = value;

/*while (array[i].flag == 1): This is the Collision Resolution loop. If the current slot i is occupied (flag == 1), we cannot simply
overwrite it unless it's the same key. if (array[i].data->key == key): Checks if the key already exists. If yes, we just update the value
and stop (we don't insert a duplicate key).
i = (i + 1) % MAX: This is the Linear Probing step. Move to the next index. If we reach the end of the array, wrap around to 0
(circular buffer).
if (i == index): If we have looped all the way back to where we started, the table is 100% full.*/

    while (array[i].flag == 1) {
        if (array[i].data->key == key) { // update value if key already exists
            printf("Duplicate key found, updating value...\n");
            array[i].data->value = value;
            return;
        }
        i = (i + 1) % MAX; // linear probing
        if (i == index) { // If we have looped all the way back to where we started, the table is 100% full
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    array[i].flag = 1;
    array[i].data = ele; // store the new item
    printf("%d inserted at index %d\n", key, i);
}

void search(int key) {
    int i, index;
    i = hash_fun(key);
    index = i;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            printf("Key %d found at index %d with value %d\n", key, i, array[i].data->value);
            return;
        }
        i = (i + 1) % MAX;
        if (i == index) break;
    }

    printf("Key %d not found in hash table\n", key);
}

void remove_item(int key) {
    int i, index;
    i = hash_fun(key);
    index = i;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            printf("Deleting key %d from index %d\n", key, i);
            array[i].flag = 2; // marking it for deletion
            free(array[i].data);
            array[i].data = NULL;
            return;
        }
        i = (i + 1) % MAX;
        if (i == index) break;
    }

    printf("Key %d not found, cannot delete\n", key);
}

void display() {
    printf("\nHash Table:\n");
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
