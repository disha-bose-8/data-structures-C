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

int main()
{
    char infix[MAX], postfix[MAX]; // store input and output both arrays of length 20
    printf("Enter infix expression: ");
    scanf("%s", infix);

    convert_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}

void convert_postfix(char *infix, char *postfix) {
    char stack[MAX]; // stack to hold operators and parentheses +-*/()
    int top = -1; // initially stack empty
    int i = 0, j = 0; // i → index for infix; j → index for postfix.

    /*
    x holds characters popped from the stack, so it can be any operator (+, -, *, /, %, ^), parentheses ((, )), or the sentinel (#). It never holds digits or operands.  token reads each character from the infix expression. It can be operands (digits or letters), operators, or parentheses.  Functioning:
    token is assigned each character from the infix input, one by one.
    If token is an operand, it is directly added to the postfix output.
    If token is an operator or parenthesis, it is processed using the stack.
    x is used to temporarily hold and process characters popped from the stack, typically operators or parentheses, before adding them to the postfix output.
     */

    char x, token; // x is for popping from stack, token is for reading from infix

    // push a sentinel so we know when stack is empty (all elements removed) during popping
    push(stack, &top, '#');

    while ((token = infix[i++]) != '\0') { //Reads each character from infix until '\0' (end of string)
        if (isalnum(token)) {
            postfix[j++] = token;//each character added in same order add to postfix string (abcd)
        }
        else if (token == '(') {
            push(stack, &top, token);
        }
        else if (token == ')') {
            while ((x = pop(stack, &top)) != '(') {
                postfix[j++] = x; //pop and add to postfix until '(' is found whatever operators bw ()
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
