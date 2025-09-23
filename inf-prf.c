//
// Created by disha on 31-08-2025.
//

/*Quick summary of the algorithm
Reverse the input infix string and swap ( ↔ ) (so grouping direction is preserved).
Convert that reversed expression from infix → postfix (using a stack).
Reverse the postfix result to get the final prefix expression.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack functions for characters
void push(char *stack, int *top, char x) {
  stack[++(*top)] = x; // increment top and add x
}
char pop(char *stack, int *top) {
  return stack[(*top)--]; // return top element and decrement top
}
char peek(char *stack, int top) {
  return stack[top]; // return top element without popping
}

// Check precedence
int precedence(char x) { // higher value means higher precedence
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '^') return 3;
    return 0;
}

// Reverse a string
void reverse(char *str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        char tmp = str[l]; // swap characters
        str[l++] = str[r]; // store and increment
        str[r--] = tmp; // store and decrement (last character)
    }
}

/*Swapping parentheses in the reversed infix expression is necessary because reversing the expression changes the direction of the
parentheses. An opening parenthesis ( becomes a closing parenthesis ) and vice versa. This ensures the correct grouping of
sub-expressions when converting from infix to prefix notation.*/

// Swap '(' with ')' and vice versa
void swapParentheses(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
          exp[i] = ')';
        else if (exp[i] == ')')
          exp[i] = '(';
    }
}

// Infix to Prefix conversion
void infixToPrefix(char *infix, char *prefix) {
    char stack[MAX];
    int top = -1;
    int j = 0;
    int len = strlen(infix);

    // Step 1: Reverse infix and swap parentheses
    reverse(infix);
    swapParentheses(infix);

    // Step 2: Standard infix to postfix on reversed expression
    for (int i = 0; i < len; i++) {
        char token = infix[i];
        if (isalnum(token)) {
            prefix[j++] = token; // storing in prefix array
        } else if (token == '(') {
            push(stack, &top, token); //
        } else if (token == ')') {
            while (top != -1 && peek(stack, top) != '(') {
                prefix[j++] = pop(stack, &top);
            }
            pop(stack, &top); // remove '('
        } else { // operator
            while (top != -1 && precedence(peek(stack, top)) >= precedence(token)) {
                prefix[j++] = pop(stack, &top);
            }
            push(stack, &top, token);
        }
    }

    while (top != -1) {
        prefix[j++] = pop(stack, &top);
    }

    prefix[j] = '\0';

    // Step 3: Reverse postfix to get prefix
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
