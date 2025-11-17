//
// Created by disha on 06-11-2025.
// Double Hashing Implementation
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define PRIME 7   // smaller prime number < MAX

typedef struct item {
    int key;
    int value;
} item;

typedef struct hash {
    int flag;      // 0 = empty, 1 = occupied, 2 = deleted
    item *data;
} hash_table;

hash_table *array;

// ------------------ Hash Functions ------------------
int hash_fun1(int key) {
    return key % MAX;
}

int hash_fun2(int key) {
    return (PRIME - (key % PRIME));
}

// ------------------ Initialize ------------------
void init() {
    for (int i = 0; i < MAX; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

// ------------------ Insert ------------------
void insert(int key, int value) {
    int i, index;
    item *ele = malloc(sizeof(item));
    ele->key = key;
    ele->value = value;

    i = hash_fun1(key);
    index = i;
    int h = 1;

    while (array[i].flag == 1) {
        if (array[i].data->key == key) {
            printf("Duplicate key found, updating value...\n");
            array[i].data->value = value;
            return;
        }
        i = (index + h * hash_fun2(key)) % MAX;
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

// ------------------ Search ------------------
void search(int key) {
    int i = hash_fun1(key);
    int index = i;
    int h = 1;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            printf("Key %d found at index %d with value %d\n",
                   key, i, array[i].data->value);
            return;
        }
        i = (index + h * hash_fun2(key)) % MAX;
        h++;
        if (i == index) break;
    }
    printf("Key %d not found in hash table\n", key);
}

// ------------------ Remove ------------------
void remove_item(int key) {
    int i = hash_fun1(key);
    int index = i;
    int h = 1;

    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            printf("Deleting key %d from index %d\n", key, i);
            array[i].flag = 2; // mark as deleted
            free(array[i].data);
            array[i].data = NULL;
            return;
        }
        i = (index + h * hash_fun2(key)) % MAX;
        h++;
        if (i == index) break;
    }
    printf("Key %d not found, cannot delete\n", key);
}

// ------------------ Display ------------------
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

// ------------------ Main ------------------
int main() {
    int key, value, choice;
    array = malloc(MAX * sizeof(hash_table));
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
