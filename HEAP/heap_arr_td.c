//
// Created by disha on 15-10-2025.
//
// Top-down (Up-heapify) heap implementation

// Add new element at end, then move it upward until it’s not greater than its parent

#include <stdio.h>
#include <stdlib.h>
#define MAX 25

// Function to insert a new value into the heap (top down heapify)
void top_down(int *h, int *size, int value)
{
    if(*size >= MAX) {
        printf("Heap overflow\n");
        return;
    }

    int i = *size;    // index of the newly added element
    int parent;       // index of parent

    h[i] = value;     // insert new element at the end
    (*size)++;        // increase heap size

    // Move the new element up until heap property is satisfied

    while(i > 0) { // If i = 0, we're at root (no parent)
        parent = (i - 1) / 2;   // find parent index
        if(h[parent] < h[i]) {
            // swap parent and child
            int temp = h[parent];
            h[parent] = h[i];
            h[i] = temp;
            i = parent;         // move upward
        } else {
            break; // heap property satisfied
        }
    }
}

// Function to display heap elements
void display(int *h, int size)
{
    if(size == 0) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
}

// Function to restore heap after deletion
void heapify(int *h, int n)
{
    int i = 0, j, key;
    key = h[i];
    j = 2*i + 1; // left child index

    while(j <= n - 1) // while there is at least one child
    {
        if((j + 1) <= n - 1) // if right child exists
        {
            if(h[j + 1] > h[j]) // choose right child if greater
                j++;
        }

        if(key < h[j]) {
            h[i] = h[j];
            i = j;
            j = 2*i + 1;
        } else {
            break;
        }
    }
    h[i] = key;
}

// Function to delete max element (root)
int deleteheap(int *h, int *size)
{
    if(*size <= 0) {
        printf("Heap underflow\n");
        return -1;
    }

    int max = h[0];
    h[0] = h[*size - 1];  // move last element to root
    (*size)--;            // reduce heap size
    heapify(h, *size);    // restore heap
    return max;
}

// Main program
int main()
{
    int h[MAX];
    int size = 0;
    int choice, value, deleted;

    while(1)
    {
        printf("\n1. Insert\n2. Delete Max\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                top_down(h, &size, value);
                break;

            case 2:
                deleted = deleteheap(h, &size);
                if(deleted != -1)
                    printf("Deleted max: %d\n", deleted);
                break;

            case 3:
                display(h, size);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

// this program creates max heap simultaneously as we insert elements using top-down method
