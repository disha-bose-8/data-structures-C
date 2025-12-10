//
// Created by disha on 06-11-2025.
// Double Hashing Implementation
//

/*In Linear Probing, if your seat (index) is taken, you just move to the next seat (+1).In Double Hashing, if your seat is taken,
you calculate a new step size and jump by that amount.Hash 1 ($h_1$): Determines the Start Index.Hash 2 ($h_2$):
Determines the Step Size (how far to jump if there is a collision).*/

//Index = (h_1(key) + i * h_2(key)) \% SIZE
//$h_2(key)$: Often PRIME - (key % PRIME). Important: This result must never be 0!
//$h_1(k) = k \% 10$$h_2(k) = 7 - (k \% 7)$

/*
Example WalkthroughImagine SIZE = 10.$h_1(k) = k \% 10$$h_2(k) = 7 - (k \% 7)$1. Insert 5:$h_1(5) = 5$. Spot 5 is empty. Insert at 5.2. Insert 15:$h_1(15) = 5$. Collision!Calculate Step Size ($h_2$): $7 - (15 \% 7) \rightarrow 7 - 1 = \mathbf{6}$.New Index: $(5 + 6) \% 10 = 11 \% 10 = \mathbf{1}$.Spot 1 is empty. Insert at 1.(Note: Linear probing would have put 15 at index 6. Double hashing scattered it to index 1).*/

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
    item *ele = malloc(sizeof(item)); // Creates the new data packet (Key and Value) in memory.
    ele->key = key;
    ele->value = value;

    i = hash_fun1(key);
    index = i; // Remembers the starting seat (so we can calculate offsets later).
    int h = 1; // probe count, This is our "collision counter" (1st jump, 2nd jump, etc.).

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
