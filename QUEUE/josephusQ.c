//
// Created by disha on 23-09-2025.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue definition
typedef struct {
    int arr[MAX];
    int front, rear, size;
} Queue;

// Initialize queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Check if queue is full
int isFull(Queue *q) {
    return q->size == MAX;
}

// Enqueue operation
void enqueue(Queue *q, int x) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = x;
    q->size++;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}

// Josephus function
int josephus(int n, int k) {
    Queue q;
    init(&q);

    // Insert persons 1..n into queue
    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }

    // Repeat until one survives
    while (q.size > 1) {
        // Skip k-1 persons (dequeue and enqueue them back)
        for (int i = 1; i < k; i++) { // Each iteration removes the front person and immediately adds them to the rear
            int temp = dequeue(&q);
            enqueue(&q, temp);
        }

        // Kill the k-th person
        int killed = dequeue(&q);
        /*The k-th person is now at the front of the queue.
        dequeue() removes them permanently (not reinserted).
        Prints who got killed.*/
        printf("%d has been killed\n", killed);
    }

    // Last remaining person
    return dequeue(&q);
}

int main() {
    int n, k;
    printf("Enter number of persons: ");
    scanf("%d", &n);
    printf("Enter k (skip count): ");
    scanf("%d", &k);

    int survivor = josephus(n, k);
    printf("\nThe survivor is %d\n", survivor);

    return 0;
}
