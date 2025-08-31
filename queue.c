//
// Created by disha on 28-08-2025.
//
/* Queue is an ADT
Queue follows FIFO - First in First Out
Operations:
1. enqueueueue
2. dequeueueue
3. isempty
4. display the elements at the front and rear pointers
front - used for dequeue(deletion)
rear - used to enqueue(insertion)
initially rear and front will be -1.
*/
//implementing the Queue data structure using arrays
#include<stdio.h>
#include<stdlib.h>
#define max 5
void enqueue(int *q,int *rear,int ele)
{
    if(*rear == max-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        *rear = *rear + 1;
        q[*rear] = ele;
    }
}
void display(int *q,int rear, int front)
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }
}
int dequeue(int *q,int *front,int rear)
{
    if(*front>rear)
        return 0;
    else
    {
        int x = q[*front];
        *front = *front + 1;
        return x;
    }
}


int main()
{
    int q[max];
    int front = 0,rear = -1,ele,ch,x;
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.Display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element:\n");
            scanf("%d",&ele);
            enqueue(q,&rear,ele);
            break;
            case 2: x = dequeue(q,&front,rear);
            if(x == 0)
            {
                printf("Q is empty\n");
            }
            else
            {
                printf("The element that got deleted:%d\n",x);
            }
            case 3: display(q,rear,front);break;
            case 4: exit(0);

        }
    }

}