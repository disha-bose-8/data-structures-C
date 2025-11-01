//
// Created by disha on 09-10-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isalpha(), isdigit()
#include <math.h>  // for pow()
#define MAX 100

typedef struct node {
    char data;
    struct node* llink;
    struct node* rlink;
} NODE;

int eval(NODE *root){
    int num;
    switch(root->data){
        case '+':
            return eval(root->llink) + eval(root->rlink);
        case '-':
            return eval(root->llink) - eval(root->rlink);
        case '*':
            return eval(root->llink) * eval(root->rlink);
        case '/':
            return eval(root->llink) / eval(root->rlink);
        case '^':
            return (pow(eval(root->llink), eval(root->rlink)));
        default: if(isalpha(root->data)){
            printf("Enter the value of %c: ",root->data);
            scanf("%d",&num);
            return num;
            }
            else{
                return (root->data - '0'); //converting char to int
            }
    }
    }

int main(){
    NODE *root=NULL;
    NODE *temp;
    int top =-1;
    NODE *stack[MAX]; //pushing a node into the stack
    int ele,i=0;
    char postfix[MAX],symb;
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    while((symb=postfix[i])!='\0'){
      temp=(NODE*)malloc(sizeof(NODE));
      temp->data=symb;
      temp->llink=NULL;
      temp->rlink=NULL;
        if(isalpha(symb)||isdigit(symb)){
            stack[++top]=temp;
        }
        else{
            temp->rlink=stack[top--];
            temp->llink=stack[top--];
            stack[++top]=temp;
      }
        i++;
        }
        root = stack[top]; //searching address of root node
        int result = eval(root);
        printf("Result of expression: %d\n", result);

  }