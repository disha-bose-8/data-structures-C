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

    NODE *cur = ptr->rear; // start from rear
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

int main()
    {
    int ch, ele, x;
    QUEUE *ptr = malloc(sizeof(QUEUE));
    ptr->front = NULL;
    ptr->rear = NULL;
    while(1)
      {
      printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &ch);
      switch(ch)
        {
        case 1:
              printf("Enter element to enqueue: ");
              scanf("%d", &ele);
              enqueue(ptr, ele);
              break;

        case 2:
            x = dequeue(ptr);
            if(x != 9999)
                printf("Dequeued element: %d\n", x);
            break;

        case 3:
         display(ptr);
         break;

  }
  }
}