//
// Created by disha on 17-09-2025.
//

// WAP to implement expression tree using linked list data structure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> //isalnum, isEmpty
//node definition
struct node
{
 char data;
 struct node *left, *right;
};
// create a node
struct node* create_node(char data)
{
struct node* newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=data;
newnode->left=newnode->right=NULL;
return newnode;
}
// create a stack
struct stack
{
int top,capacity;
struct node** array; //global and dynamic update
};
// create stack
struct stack* create_stack(int capacity)
{
struct stack* s1=(struct stack*)malloc(sizeof(struct stack));
s1->capacity=capacity;
s1->top=-1;
s1->array=(struct node**)malloc(s1->capacity*sizeof(struct node));
return s1;
}
int isEmpty(struct stack* stack)
{
    return stack->top==-1;
}
void push(struct stack* stack, struct node* node)
{
 stack->array[++stack->top]=node;
}
struct node* pop(struct stack* stack)
{
     return stack->array[stack->top--];
}

struct node* create_tree(char postfix[])
{
    struct stack* stack=create_stack(strlen(postfix));
    struct node *t, *t1, *t2;
    for(int i=0;postfix[i]!='\0';i++)
    {
        t=create_node(postfix[i]);
        if(isalnum(postfix[i]))
        {
            push(stack,t);
        }
       else
       {
        t=create_node(postfix[i]);
        t1=pop(stack); // right child
        t2=pop(stack); // left child
        t->right=t1;
        t->left=t2;
        push(stack, t);
       }
    }
  t=pop(stack);
  return t;

}
void inorder(struct node* t)
{
  if(t)
  {
    inorder(t->left);
    printf("%c ", t->data);
    inorder(t->right);
  }
}
int evaluate(struct node* root)
{
if(!root) return 0;  // NULL
if(!root->left && !root->right) //leaf node
return root->data-'0'; //to convert into integer value
int left_eval=evaluate(root->left);
int right_eval=evaluate(root->right);
if(root->data=='+')
return left_eval + right_eval;
if(root->data=='-')
return left_eval - right_eval;
if(root->data=='*')
return left_eval * right_eval;
if(root->data=='/')
return left_eval / right_eval;
return 0;
}
int main()
{
    char postfix[]="53+61-*";
    struct node* root=create_tree(postfix);
    printf("Inorder traversal is \n");
    inorder(root);
    printf("Evaluated expression is %d\n", evaluate(root));
    return 0;

}