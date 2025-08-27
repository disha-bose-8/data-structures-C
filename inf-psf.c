#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isalnum

#define MAX 20 //maximum length of stack

// function prototypes
void convert_postfix(char *infix, char *postfix);
void push(char *stack, int *top, char x);
char pop(char *stack, int *top);
int precedence(char x);
int isEmpty(int top);

int main() {
    char infix[MAX], postfix[MAX]; // store input and output
    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}

void convert_postfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1; //initially stack empty
    int i = 0, j = 0; //i → index for infix; j → index for postfix.
    char x, token;

    // push a sentinel so we know when stack is empty during popping
    push(stack, &top, '#');

    while ((token = infix[i++]) != '\0') { //Reads each character from infix until '\0' (end of string)
        if (isalnum(token)) {
            postfix[j++] = token;//each character added in same order
        }
        else if (token == '(') {
            push(stack, &top, token);
        }
        else if (token == ')') {
            while ((x = pop(stack, &top)) != '(') {
                postfix[j++] = x;
            }
        }
        else { // operator
            while (precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, token);
        }
    }

    while ((x = pop(stack, &top)) != '#') {
        postfix[j++] = x;
    }

    postfix[j] = '\0';
}

void push(char *stack, int *top, char x) {
    stack[++(*top)] = x;
}

char pop(char *stack, int *top) {
    return stack[(*top)--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '^') return 3;
    return 0;
}

int isEmpty(int top) {
    return (top == -1);
}
