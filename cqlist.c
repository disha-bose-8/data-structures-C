//
// Created by disha on 04-09-2025.
//

// implementation of circular node  using linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}NODE;

typedef struct queue {
    NODE *front,*rear;
}CQUEUE;

void enqueue(CQUEUE *ptr, int ele)
{
    NODE *temp=malloc(sizeof(NODE));
    if(temp!=NULL)
    {
        temp->data=ele;
    }
    if(ptr->front==NULL)
    {
        ptr->front=ptr->rear=temp;
    }

    /* making it circular
    Suppose the queue initially contains: front → [10] → [20] → [30] → rear (which points back to front for circularity). now, enqueue 40:
    temp->data = 40
    temp->link = ptr->front; [40] → [10] (new node points to front)
    ptr->rear->link = temp; [30] → [40] (old rear points to new node)
    ptr->rear = temp; rear now points to [40]
    Resulting structure: front → [10] → [20] → [30] → [40] → (loops back to [10]) rear → [40] rear->link → [10] */

    temp->link=ptr->front;
    ptr->rear->link=temp;
    ptr->rear=temp;
}
void display(CQUEUE *ptr)
{
    if(ptr->front==NULL)
        printf("list is empty\n");
    else
    {
        NODE *cur=ptr->front;
        while(cur!=ptr->rear)
        {
            printf("%d\t",cur->data);
            cur=cur->link;
        }
        printf("%d\t",ptr->rear->data);
    }
}
int dequeue(CQUEUE *ptr)
{
    int x;
    if(ptr->front==NULL)
        return(9999);
    if(ptr->rear==ptr->front)
    {
        x=ptr->front->data;
        free(ptr->front);
        ptr->front=ptr->rear=NULL;
    }
    else
    {
        NODE *second=ptr->front->link;
        x=ptr->front->data;
        free(ptr->front);
        ptr->front=second;
        ptr->rear->link=ptr->front;
    }
    return(x);
}

int main()
{
    CQUEUE *ptr=malloc(sizeof(CQUEUE));
    ptr->front=ptr->rear=NULL;
    int ele,x,ch;
    while(1)
    {
        printf("1.Enqueue\n 2.Dequeue\n 3.display\n");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the Element\n");
            scanf("%d",&ele);
            enqueue(ptr,ele);
            break;
            case 2:x=dequeue(ptr);
            if(x==9999)
                printf("underflow\n");
            else{
                printf("deleted element is %d\n",x);
            }
            break;
            case 3: display(ptr);
            break;
        }
    }
}