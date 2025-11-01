//
// Created by disha on 28-08-2025.
//
/* Queue is an ADT
Queue follows FIFO - First in First Out
Operations:
1. enqueue 2. dequeue 3. is empty 4. is full 5. peekFront 6. peekRear 7. size 8. clearQueue 9. display 10. min
11. max 12. search 13. sum 14. average 15. countOccurrences 16. reverse 17. sort 18. rotate 19. removeDuplicates
20. removeElement 21. mergeQueues 22. compareQueues 23. palindromeCheck 24. evenOddSeparate
Implementation using array
*/

#include<stdio.h>
#include<stdlib.h>

#define max 5 // Maximum size of queue

// Function to insert element into queue
void enqueue(int *q,int *rear,int ele) // rear → pointer to the rear index *q is the array
{
    if(*rear == max-1) // initially rear = -1, if rear = max-1 → queue is full
    {
        printf("Queue is full\n");
    }
    else
    {
        *rear = *rear + 1; // If rear = -1 initially, after inserting 10, rear = 0, q[0] = 10
        q[*rear] = ele;
        printf("%d inserted\n", ele);
    }
}

// Function to delete element from queue
int dequeue(int *q,int *front,int rear) // front → pointer to the front index
{
    if(*front > rear) // Queue is empty (if even one element is present front will be ≤ rear front = 0 initially, rear = -1 initially)
        return 0;
    else
    {
        int x = q[*front]; // The value of front is initially set to 0 in main
        *front = *front + 1; // Move front to next position (increment front)
        return x;
    }
}

// Display elements of queue
void display(int *q,int rear, int front )
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}

// Check if queue is empty
int isEmpty(int front, int rear) {
    return (front > rear);
}

// Check if queue is full
int isFull(int rear) {
    return (rear == max - 1);
}

// Peek front element
int peekFront(int *q, int front, int rear) {
    if(front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[front];
}

// Peek rear element
int peekRear(int *q, int front, int rear) {
    if(front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[rear];
}

// Return size of queue
int size(int front, int rear) {
    if(front > rear) return 0;
    return (rear - front + 1);
}

// Clear the queue
void clearQueue(int *front, int *rear) {
    *front = 0;
    *rear = -1;
    printf("Queue cleared\n");
}

// Minimum element
int getMin(int *q, int front, int rear) {
    if(front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int min = q[front];
    for(int i = front+1; i <= rear; i++) {
        if(q[i] < min) min = q[i];
    }
    return min;
}

// Maximum element
int getMax(int *q, int front, int rear) {
    if(front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int maximum = q[front];
    for(int i = front+1; i <= rear; i++) {
        if(q[i] > maximum) maximum = q[i];
    }
    return maximum;
}

// Search element
int search(int *q, int front, int rear, int key) {
    for(int i = front; i <= rear; i++) {
        if(q[i] == key) return i; // return index
    }
    return -1; // not found
}

void searchAll(int *q, int front, int rear, int key) {
    int found = 0;
    for(int i = front; i <= rear; i++) {
        if(q[i] == key) {
            printf("%d found at position %d\n", key, i-front+1);
            found = 1;
        }
    }
    if(!found) printf("%d not found\n", key);
}

// Sum of queue elements
int sumQueue(int *q, int front, int rear) {
    int sum = 0;
    for(int i = front; i <= rear; i++) sum += q[i];
    return sum;
}

// Average of queue elements
float averageQueue(int *q, int front, int rear) {
    if(front > rear) return 0;
    return (float)sumQueue(q, front, rear) / (rear - front + 1);
}

// Count occurrences
int countOccurrences(int *q, int front, int rear, int key) {
    int count = 0;
    for(int i = front; i <= rear; i++) {
        if(q[i] == key) count++;
    }
    return count;
}

// Reverse the queue
void reverseQueue(int *q, int front, int rear) {
    while(front < rear) { // swap front and rear elements until they meet in the middle
        int temp = q[front];
        q[front] = q[rear];
        q[rear] = temp;
        front++;
        rear--;
    }
    printf("Queue reversed\n");
}

// Sort the queue (ascending)
void sortQueue(int *q, int front, int rear) {
    for(int i = front; i <= rear; i++) {
        for(int j = front; j < rear - (i-front); j++) {
            if(q[j] > q[j+1]) {
                int temp = q[j];
                q[j] = q[j+1];
                q[j+1] = temp;
            }
        }
    }
    printf("Queue sorted\n");
}

// Rotate queue by k positions
void rotateQueue(int *q, int front, int rear, int k) {
    int n = rear - front + 1; // number of elements in queue
    if(n == 0) return; // empty queue

    k = k % n; // handle large k (rotation beyond size just repeats)
    while(k--) {
        int temp = q[front];  // take front element
        for(int i = front; i < rear; i++) { // shift all elements to left
            q[i] = q[i+1];
        }
        q[rear] = temp; // place front element at rear
    }
    printf("Queue rotated\n");
}

void rotateRight(int *q, int front, int rear, int k) {
    int n = rear - front + 1;
    if (n==0) return; // empty queue

    k=k % n; // handle large k
    while(k--) {
        int temp = q[rear]; // take rear element
        for(int i = rear; i > front; i--) {
            // shift all elements to right
            q[i] = q[i-1];
        }
        q[front] = temp; // place rear element at front
}
    printf("Queue rotated right\n");
}

// Remove duplicates
void removeDuplicates(int *q, int *front, int *rear) {
    for(int i = *front; i <= *rear; i++) {
        for(int j = i+1; j <= *rear; j++) {
            if(q[i] == q[j]) {
                for(int k = j; k < *rear; k++) {
                    q[k] = q[k+1];
                }
                (*rear)--;
                j--;
            }
        }
    }
    printf("Duplicates removed\n");
}

// Remove specific element
void removeElement(int *q, int *front, int *rear, int key) {
    int found = 0;
    for(int i = *front; i <= *rear; i++) {
        if(q[i] == key) {
            for(int j = i; j < *rear; j++) {
                q[j] = q[j+1];
            }
            (*rear)--;
            found = 1;
            break;
        }
    }
    if(found) printf("%d removed\n", key);
    else printf("%d not found\n", key);
}

// Merge two queues
void mergeQueues(int *q1, int front1, int rear1, int *q2, int front2, int rear2, int *q3, int *rear3) {
    *rear3 = -1;
    for(int i = front1; i <= rear1; i++) q3[++(*rear3)] = q1[i];
    for(int i = front2; i <= rear2; i++) q3[++(*rear3)] = q2[i];
    printf("Queues merged\n");
}

// Compare two queues
int compareQueues(int *q1, int front1, int rear1, int *q2, int front2, int rear2) {
    if((rear1-front1) != (rear2-front2)) return 0;
    for(int i = 0; i <= (rear1-front1); i++) {
        if(q1[front1+i] != q2[front2+i]) return 0;
    }
    return 1;
}

// Palindrome check
int palindromeCheck(int *q, int front, int rear) {
    while(front < rear) {
        if(q[front] != q[rear]) return 0;
        front++;
        rear--;
    }
    return 1;
}

// Separate even and odd numbers
void evenOddSeparate(int *q, int front, int rear, int *even, int *re, int *odd, int *ro) {
    *re = -1; *ro = -1;
    for(int i = front; i <= rear; i++) {
        if(q[i] % 2 == 0) even[++(*re)] = q[i];
        else odd[++(*ro)] = q[i];
    }
    printf("Even and Odd separated\n");
}

int main()
{
    int q[max];
    int front = 0, rear = -1, ele, ch, x, k;

    while(1)
    {
        printf("\n---- Queue Menu ----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek Front\n5. Peek Rear\n");
        printf("6. Check Empty\n7. Check Full\n8. Size\n9. Clear Queue\n");
        printf("10. Min\n11. Max\n12. Search\n13. Sum\n14. Average\n15. Count Occurrences\n");
        printf("16. Reverse\n17. Sort\n18. Rotate\n19. Remove Duplicates\n20. Remove Element\n");
        printf("21. Palindrome Check\n22. Search all\n23. Rotate right\n24. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d",&ele);
                enqueue(q,&rear,ele);
                break;

            case 2:
                x = dequeue(q,&front,rear);
                if(x == 0)
                    printf("Queue is empty\n");
                else
                    printf("The element that got deleted: %d\n",x);
                break;

            case 3:
                display(q,rear,front);
                break;

            case 4:
                x = peekFront(q,front,rear);
                if(x != -1) printf("Front element: %d\n",x);
                break;

            case 5:
                x = peekRear(q,front,rear);
                if(x != -1) printf("Rear element: %d\n",x);
                break;

            case 6:
                if(isEmpty(front,rear))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 7:
                if(isFull(rear))
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 8:
                printf("Queue size: %d\n", size(front,rear));
                break;

            case 9:
                clearQueue(&front,&rear);
                break;

            case 10: // Min
                x = getMin(q,front,rear);
                if(x != -1) printf("Minimum element: %d\n",x);
                break;

            case 11: // Max
                x = getMax(q,front,rear);
                if(x != -1) printf("Maximum element: %d\n",x);
                break;

            case 12: // Search
                printf("Enter element to search: ");
                scanf("%d",&ele);
                x = search(q,front,rear,ele);
                if(x == -1) printf("%d not found\n",ele);
                else printf("%d found at position %d\n",ele,x-front+1);
                break;

            case 13: // Sum
                printf("Sum of elements: %d\n", sumQueue(q,front,rear));
                break;

            case 14: // Average
                printf("Average of elements: %.2f\n", averageQueue(q,front,rear));
                break;

            case 15: // Count Occurrences
                printf("Enter element to count: ");
                scanf("%d",&ele);
                printf("%d occurs %d times\n",ele,countOccurrences(q,front,rear,ele));
                break;

            case 16: // Reverse
                reverseQueue(q,front,rear);
                break;

            case 17: // Sort
                sortQueue(q,front,rear);
                break;

            case 18: // Rotate
                printf("Enter k: ");
                scanf("%d",&k);
                rotateQueue(q,front,rear,k);
                break;

            case 19: // Remove Duplicates
                removeDuplicates(q,&front,&rear);
                break;

            case 20: // Remove Element
                printf("Enter element to remove: ");
                scanf("%d",&ele);
                removeElement(q,&front,&rear,ele);
                break;

            case 21: // Palindrome check
                if(palindromeCheck(q,front,rear))
                    printf("Queue is palindrome\n");
                else
                    printf("Queue is not palindrome\n");
                break;

            case 22: // Search all occurrences
                printf("Enter element to search all occurrences: ");
                scanf("%d",&ele);
                searchAll(q,front,rear,ele);
                break;

            case 23: // Rotate right
                printf("Enter k: ");
                scanf("%d",&k);
                rotateRight(q,front,rear,k);
                break;

            case 24:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
