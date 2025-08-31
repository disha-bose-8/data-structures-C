//
// Created by disha on 31-08-2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack functions for characters
void push(char *stack, int *top, char x) { stack[++(*top)] = x; }
char pop(char *stack, int *top) { return stack[(*top)--]; }
char peek(char *stack, int top) { return stack[top]; }

// Check precedence
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '^') return 3;
    return 0;
}

// Reverse a string
void reverse(char *str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        char tmp = str[l];
        str[l++] = str[r];
        str[r--] = tmp;
    }
}

// Swap '(' with ')' and vice versa
void swapParentheses(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
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
            prefix[j++] = token;
        } else if (token == '(') {
            push(stack, &top, token);
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
