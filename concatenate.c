//
// Created by disha on 19-09-2025.
//

#include<stdio.h>
#include<stdlib.h>
/* Structure of a node*/
typedef struct node
{
    int data;
    struct node *link;
}NODE;
/*creating a node */
NODE* create_node(int data)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->link=NULL;
    return temp;
}
/*concatenating two lists*/
NODE* concatenate(NODE* list1, NODE* list2)
{
    if(list1==NULL) /* if list1 is empty*/
        return list2;
    NODE *temp=list1;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=list2;
    return list1;
}
int count_element(NODE* head)
{
    int count=0;
    NODE *current=head;
    while(current!=NULL)
    {
        count++;
        current=current->link;
    }
    return count;
}

void display(NODE *head)
{
    NODE *current=head;
    while(current!=NULL)
    {
        printf("%d -> ", current->data);
        current=current->link;
    }
    printf("NULL\n");
}
int main()
{  /*createing a list1 */
    /*9->8->5->NULL */
    NODE* list1=create_node(9);
    list1->link=create_node(8);
    list1->link->link=create_node(5);
    /*creating a list2*/
    NODE* list2=create_node(6);
    list2->link=create_node(2);
    list2->link->link=create_node(3);
    printf("The content of list1\n");
    display(list1);
    printf("The content of list2\n");
    display(list2);
    NODE* result=concatenate(list1, list2);
    printf("The concatenated list is");
    display(result);
    int count=count_element(result);
    printf("Number of element is %d\n", count);
    return 0;


}