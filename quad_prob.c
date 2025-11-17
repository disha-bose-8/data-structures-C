//
// Created by disha on 06-11-2025.
// Hash Table using Quadratic Probing
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct item {
    int key;
    int value;
} ITEM;

typedef struct hash {
    int flag;      // 0 = empty, 1 = occupied, 2 = deleted
    ITEM *data;
} HASH_TABLE;

HASH_TABLE *array;

void init() {
    for (int i = 0; i < MAX; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hash_fun(int key) {
    return key % MAX;
}

void insert(int key, int value) {
    int i, index, h = 1;
    ITEM *ele = (ITEM *)malloc(sizeof(ITEM));
    ele->key = key;
    ele->value = value;

    i = hash_fun(key);
    index = i;

    while (array[i].flag == 1) {
        if (array[i].data->key == key) {
            printf("Duplicate key found, updating value...\n");
            array[i].data->value = value;
            return;
        }

        i = (index + (h * h)) % MAX;
        h++;
        if (i == index) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    array[i].flag = 1;
    array[i].data = ele;
    printf("%d inserted at index %d\n", key, i);
}

void search(int key) {
    int i, index, h = 1;
    i = hash_fun(key);
    index = i;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            printf("Key %d found at index %d with value %d\n", key, i, array[i].data->value);
            return;
        }
        i = (i + (h * h)) % MAX;
        h++;
        if (i == index) break;
    }

    printf("Key %d not found in hash table\n", key);
}

void remove_item(int key) {
    int i, index, h = 1;
    i = hash_fun(key);
    index = i;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            printf("Deleting key %d from index %d\n", key, i);
            array[i].flag = 2; // mark as deleted
            free(array[i].data);
            array[i].data = NULL;
            return;
        }
        i = (index + (h * h)) % MAX;
        h++;
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
                printf("Enter key and value to insert: ");
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
