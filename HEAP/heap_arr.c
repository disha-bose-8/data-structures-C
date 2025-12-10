 //
// Created by disha on 15-10-2025.
//
// bottom up heapify

/*Array: [50, 30, 20, 15, 10, 8, 16]

Tree:
         50
       /    \
     30      20
    /  \    /  \
   15  10  8   16
*/

/*🧠 Purpose of the Program
This program:
Takes an array of elements.
Builds a Max-Heap using the bottom-up heapify method.
Then repeatedly deletes the maximum element (the root) until the heap is empty.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 25 // Maximum size of the heap

void bottom_up(int *h, int n) // *h is pointer to array, n is number of elements
{
    int k, i, j, key;
    for(k=(n-1)/2;k>=0;k--) // start from last non-leaf node (n-1/2) and go to root, heap of n elements, nodes n/2 to n-1 are leaves
    {
        key=h[k]; // key stores current node value
        j=k; // j is current node index
        i=2*j+1; // left child index
        while(i<=n) // while there is at least one child (this loop chooses the larger child since it's a max-heap)
        {
            if((i+1)<=n) // if right child exists, Right child = i + 1
            {
                if(h[i+1]>h[i]) // if right child is greater than left child
                    i++; // choose right child
            }

            if (key < h[i])  // if parent smaller than child
            {
                h[j] = h[i];  // move child up (swap)
                j = i;        // move down to child position
                i = 2*j + 1;  // update left child index
            }
            else
                break; // heap property satisfied
        }
        h[j] = key;  // put key in its correct position
    }
}

/*Keeps pushing down the parent (key) until it’s bigger than both children (heap property satisfied).
Finally, key is placed at the correct level.
✅ Result: The array h becomes a max-heap (every parent ≥ its children)*/

int deleteheap(int *h, int n)
{
    int max;
    max = h[0];         // root (max element)
    h[0] = h[n-1];      // replace root with last element
    bottom_up(h, n-1);  // re-heapify remaining elements
    return max;
}


int main()
    {
    int h[MAX];
    int n,i,x;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    // Build heap (rearrange array)
    printf("before heapify\n");
    for (i=0;i<n;i++)
        printf("%d ",h[i]);
    bottom_up(h,n);
    printf("\nafter heapify\n");
    for (i=0;i<n;i++)
        printf("%d ",h[i]);
    for (i=0;i<n;i++) {
        x = deleteheap(h,n-i);
        printf("\ndeleted max: %d\n",x);
    }
    }