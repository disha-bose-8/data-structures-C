#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
    int data;
    int flag;  // 1 = occupied, 0 = empty
} NODE;

typedef struct hash {
    int size;
    NODE *hashtable;
} HASH;

int count = 0;

HASH *createHash(int size) {
    HASH *hash = (HASH *)malloc(sizeof(HASH));
    hash->size = size;
    hash->hashtable = (NODE *)malloc(hash->size * sizeof(NODE));
    for (int i = 0; i < hash->size; i++) {
        hash->hashtable[i].flag = 0;
    }
    return hash;
}

void insert(int key, HASH *h);
void rehash(HASH **h);

void insert(int key, HASH *h) {
    int hash = key % h->size;
    int i = 0;

    // Linear probing
    while (h->hashtable[(hash + i) % h->size].flag == 1)
        i++;

    h->hashtable[(hash + i) % h->size].data = key;
    h->hashtable[(hash + i) % h->size].flag = 1;

    count++;

    float loadFactor = (float)count / h->size;
    if (loadFactor > 0.75) {
        printf("\n🔁 Load factor %.2f > 0.75 → Rehashing...\n", loadFactor);
        rehash(&h);
    }
}

void rehash(HASH **h) {
    int newsize = (*h)->size * 2;
    HASH *newhash = createHash(newsize);

    for (int i = 0; i < (*h)->size; i++) {
        if ((*h)->hashtable[i].flag == 1) {
            insert((*h)->hashtable[i].data, newhash);
        }
    }

    free((*h)->hashtable);
    free(*h);

    *h = newhash;
    printf("✅ Rehash complete! New table size = %d\n", newsize);
}

void display(HASH *h) {
    printf("\nHash Table:\n");
    for (int i = 0; i < h->size; i++) {
        if (h->hashtable[i].flag == 1)
            printf("[%d] = %d\n", i, h->hashtable[i].data);
        else
            printf("[%d] = ---\n", i);
    }
}

int main() {
    HASH *hashtable = createHash(MAX);
    int key, ch;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key, hashtable);
                break;

            case 2:
                display(hashtable);
                break;

            case 3:
                exit(0);
        }
    }
}
