//
// Created by disha on 26-08-2025.
//
/* stack implementation using list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
int choice, x;
void push()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is not being allocated hence we can't insert an ele");
    }
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d", &x); /* x is element to be inserted*/
        newnode->data=x;
        newnode->next=top;
        top=newnode;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        struct node *temp=top;
        printf("The element to be deleted is %d\n", temp->data);
        top=top->next;
        free(temp);
    }
}
void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The top ele is %d\n", top->data);
    }

}
void display()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp=top;
        printf("\nThe ele in the stack are\n");
        while(temp!=NULL)
        {
            printf("\t%d\n", temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    printf("Enter the stack operations \n1) Push() \n2) Pop() \n3) Peek() \n4) Display() \n");
    do
    {
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default:printf("Invalid choice");
            exit(1);
        }
    } while(choice!=5);
    return 0;

}