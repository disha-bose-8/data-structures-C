//
// Created by disha on 04-09-2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node { // defines a node structure for the queue (for each element in the queue)
    int data;
    struct node* link;
} NODE;

typedef struct queue // defines the queue structure with front and rear pointers
{
    NODE *front, *rear; // pointers to the front and rear of the queue
} QUEUE;

void enqueue(QUEUE *ptr, int ele) //insert at rear (weve to traverse to the end of the list to insert)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE)); // allocate memory for a new node
    temp->data = ele;
    temp->link = NULL;

    //ptr->rear stores the address of the last node in the queue

    NODE *cur = ptr->rear; // start from rear (stores address of last node)
    if(ptr->front == NULL && ptr->rear == NULL) // if queue is empty → both front and rear point to this first node (this is the first node added to queue)
    {
        ptr->front = ptr->rear = temp;
        return;
    }

    cur->link = temp; // if queue not empty link the new node at the end of the queue and update rear
    ptr->rear = temp; // update rear to new node (make rear as temp, ptr->rear now stores address of temp)

}
void display(QUEUE *ptr) // display from front to rear (queue is first to last)
{
    if (ptr->front == NULL && ptr->rear == NULL)
    {
        printf("empty\n");
    }
    else
    {
        NODE *cur = ptr->front;
        while (cur != NULL)
        {
            printf("%d\t", cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
    }

int dequeue(QUEUE *ptr) // delete from front (we can directly access front)
{
    int x;
    if (ptr->front == NULL && ptr->rear == NULL) // if queue is empty
    {
        printf("Queue underflow\n");
        return 9999;
    }
    if(ptr->front == ptr->rear) // if only one element is present
    {
        x = ptr->front->data; // get the data to return later
        free(ptr->front); // free the memory of the only node
        ptr->front = ptr->rear = NULL; // update both front and rear to NULL
    }
    else
    {
      x=ptr->front->data;
      NODE *second=ptr->front->link;
      free(ptr->front);
      ptr->front=second; // second node is made front (ptr->front now stores address of second node)
    }
    return x; // return the dequeued value
}

// Reverse the queue (linked list) ***************************************
void reverseQueue(QUEUE *ptr) {
    NODE *prev = NULL, *cur = ptr->front, *next = NULL;
    ptr->rear = ptr->front;  // after reversal, old front becomes rear
    while(cur != NULL) {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    ptr->front = prev; // update front
    printf("Queue reversed\n");
}

// Find max element in queue
void getMax(QUEUE *ptr) {
    if(ptr->front == NULL) {
        printf("Queue empty\n");
        return;
    }
    int max = ptr->front->data;
    NODE *cur = ptr->front->link;
    while(cur != NULL) {
        if(cur->data > max)
            max = cur->data;
        cur = cur->link;
    }
    printf("Maximum element = %d\n", max);
}


// Rotate queue by k positions *********************************
void rotateQueue(QUEUE *ptr, int k) {
    if(ptr->front == NULL || ptr->front == ptr->rear)
        return;

    // count nodes
    int n = 0;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        n++;
        cur = cur->link;
    }

    k = k % n; // handle large k
    if(k == 0) return;

    // move first k nodes to end
    NODE *oldFront = ptr->front;
    cur = ptr->front;
    for(int i = 1; i < k; i++) {
        cur = cur->link;
    }
    NODE *newFront = cur->link;
    cur->link = NULL;
    ptr->rear->link = oldFront;
    ptr->rear = cur;
    ptr->front = newFront;

    printf("Queue rotated by %d\n", k);
}

// Count elements in queue
void countQueue(QUEUE *ptr) {
    int count = 0;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        count++;
        cur = cur->link;
    }
    printf("Queue has %d elements\n", count);
}

// Peek front element
void peekFront(QUEUE *ptr) {
    if(ptr->front == NULL)
        printf("Queue empty\n");
    else
        printf("Front element = %d\n", ptr->front->data);
}

// Peek rear element
void peekRear(QUEUE *ptr) {
    if(ptr->rear == NULL)
        printf("Queue empty\n");
    else
        printf("Rear element = %d\n", ptr->rear->data);
}

// Find minimum element
void getMin(QUEUE *ptr) {
    if(ptr->front == NULL) {
        printf("Queue empty\n");
        return;
    }
    int minimum = ptr->front->data;
    NODE *cur = ptr->front->link;
    while(cur != NULL) {
        if(cur->data < minimum)
            minimum = cur->data;
        cur = cur->link;
    }
    printf("Minimum element = %d\n", minimum);
}

// Sum of elements
void sumQueue(QUEUE *ptr) {
    int sum = 0;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        sum += cur->data;
        cur = cur->link;
    }
    printf("Sum of elements = %d\n", sum);
}

// Average of elements
void averageQueue(QUEUE *ptr) {
    int sum = 0, count = 0;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        sum += cur->data;
        count++;
        cur = cur->link;
    }
    if(count == 0) printf("Queue empty\n");
    else printf("Average = %.2f\n", (float)sum / count);
}

// Count occurrences of a value
void countOccurrences(QUEUE *ptr, int key) {
    int count = 0;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        if(cur->data == key) count++;
        cur = cur->link;
    }
    printf("%d occurs %d times\n", key, count);
}

// Search for an element
void searchQueue(QUEUE *ptr, int key) {
    int pos = 1;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        if(cur->data == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        cur = cur->link;
        pos++;
    }
    printf("%d not found\n", key);
}

// Remove duplicates (first occurrence kept)
void removeDuplicates(QUEUE *ptr) {
    NODE *cur = ptr->front;
    while(cur != NULL) {
        NODE *runner = cur;
        while(runner->link != NULL) {
            if(runner->link->data == cur->data) {
                NODE *dup = runner->link;
                runner->link = runner->link->link;
                if(dup == ptr->rear) ptr->rear = runner;
                free(dup);
            } else {
                runner = runner->link;
            }
        }
        cur = cur->link;
    }
    printf("Duplicates removed\n");
}

// Remove specific element (first occurrence)
void removeElement(QUEUE *ptr, int key) {
    if(ptr->front == NULL) {
        printf("Queue empty\n");
        return;
    }
    if(ptr->front->data == key) {
        NODE *temp = ptr->front;
        ptr->front = ptr->front->link;
        if(temp == ptr->rear) ptr->rear = NULL;
        free(temp);
        printf("%d removed\n", key);
        return;
    }
    NODE *cur = ptr->front;
    while(cur->link != NULL && cur->link->data != key) {
        cur = cur->link;
    }
    if(cur->link == NULL) {
        printf("%d not found\n", key);
        return;
    }
    NODE *temp = cur->link;
    cur->link = temp->link;
    if(temp == ptr->rear) ptr->rear = cur;
    free(temp);
    printf("%d removed\n", key);
}

// Check if queue is palindrome
void palindromeCheck(QUEUE *ptr) {
    // convert queue to array
    int arr[100], n = 0;
    NODE *cur = ptr->front;
    while(cur != NULL) {
        arr[n++] = cur->data;
        cur = cur->link;
    }
    int flag = 1;
    for(int i=0; i<n/2; i++) {
        if(arr[i] != arr[n-1-i]) { flag = 0; break; }
    }
    if(flag) printf("Queue is palindrome\n");
    else printf("Queue is not palindrome\n");
}

// Separate even and odd numbers into two queues
void evenOddSeparate(QUEUE *ptr, QUEUE *evenQ, QUEUE *oddQ) {
    NODE *cur = ptr->front;
    while(cur != NULL) {
        if(cur->data % 2 == 0) enqueue(evenQ, cur->data);
        else enqueue(oddQ, cur->data);
        cur = cur->link;
    }
    printf("Even and Odd queues created\n");
}

// Clear the queue
void clearQueue(QUEUE *ptr) {
    NODE *cur = ptr->front;
    while(cur != NULL) {
        NODE *temp = cur;
        cur = cur->link;
        free(temp);
    }
    ptr->front = ptr->rear = NULL;
    printf("Queue cleared\n");
}

// Sort queue in ascending order using simple bubble sort on linked list
void sortQueue(QUEUE *ptr) {
    if(ptr->front == NULL || ptr->front->link == NULL) return;

    int swapped;
    NODE *p;
    NODE *lptr = NULL;

    do {
        swapped = 0;
        p = ptr->front;
        while(p->link != lptr) {
            if(p->data > p->link->data) {
                int temp = p->data;
                p->data = p->link->data;
                p->link->data = temp;
                swapped = 1;
            }
            p = p->link;
        }
        lptr = p;
    } while(swapped);

    printf("Queue sorted in ascending order\n");
}

// Sort queue in descending order using bubble sort
void sortQueueDescending(QUEUE *ptr) {
    if(ptr->front == NULL || ptr->front->link == NULL) return;

    int swapped;
    NODE *p;
    NODE *lptr = NULL;

    do {
        swapped = 0;
        p = ptr->front;
        while(p->link != lptr) {
            if(p->data < p->link->data) {  // Reverse comparison
                int temp = p->data;
                p->data = p->link->data;
                p->link->data = temp;
                swapped = 1;
            }
            p = p->link;
        }
        lptr = p;
    } while(swapped);

    printf("Queue sorted in descending order\n");
}


int main() {
    int ch, ele, x, k, key;
    QUEUE *ptr = malloc(sizeof(QUEUE)); ptr->front=NULL; ptr->rear=NULL;
    QUEUE *evenQ = malloc(sizeof(QUEUE)); evenQ->front=evenQ->rear=NULL;
    QUEUE *oddQ = malloc(sizeof(QUEUE)); oddQ->front=oddQ->rear=NULL;

    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Reverse 5.Rotate 6.Max 7.Min 8.Sum 9.Average 10.Count 11.PeekFront\n");
        printf("12.PeekRear 13.CountOccurrences 14.Search 15.RemoveDuplicates 16.RemoveElement 17.Palindrome 18.EvenOdd 19.Exit\n");
        printf("Enter choice: "); scanf("%d",&ch);

        switch(ch) {
            case 1: printf("Enter element: "); scanf("%d",&ele); enqueue(ptr,ele); break;
            case 2: x=dequeue(ptr); if(x!=9999) printf("Dequeued: %d\n",x); break;
            case 3: display(ptr); break;
            case 4: reverseQueue(ptr); break;
            case 5: printf("Enter k: "); scanf("%d",&k); rotateQueue(ptr,k); break;
            case 6: getMax(ptr); break;
            case 7: getMin(ptr); break;
            case 8: sumQueue(ptr); break;
            case 9: averageQueue(ptr); break;
            case 10: countQueue(ptr); break;
            case 11: peekFront(ptr); break;
            case 12: peekRear(ptr); break;
            case 13: printf("Enter element to count: "); scanf("%d",&key); countOccurrences(ptr,key); break;
            case 14: printf("Enter element to search: "); scanf("%d",&key); searchQueue(ptr,key); break;
            case 15: removeDuplicates(ptr); break;
            case 16: printf("Enter element to remove: "); scanf("%d",&key); removeElement(ptr,key); break;
            case 17: palindromeCheck(ptr); break;
            case 18: evenOddSeparate(ptr,evenQ,oddQ); printf("Even Queue: "); display(evenQ); printf("Odd Queue: "); display(oddQ); break;
            case 19: clearQueue(ptr); clearQueue(evenQ); clearQueue(oddQ); break;
            case 20: sortQueue(ptr); break;
            case 21: sortQueueDescending(ptr); break;
            case 22: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}