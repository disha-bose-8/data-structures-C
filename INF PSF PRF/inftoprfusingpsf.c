//
// Created by disha on 23-09-2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // for isalnum

#define MAX 20 // maximum length of stack

// function prototypes
void convert_postfix(char *infix, char *postfix);
void push(char *stack, int *top, char x);
char pop(char *stack, int *top);
int precedence(char x);
int isEmpty(int top);

// new function prototypes for prefix
void reverse_infix(char *infix, char *reversed);
void reverse_string(char *str);
void infix_to_prefix(char *infix, char *prefix);

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Infix to Postfix
    convert_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    // Infix to Prefix
    infix_to_prefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

void convert_postfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;
    char x, token;

    push(stack, &top, '#');

    while ((token = infix[i++]) != '\0') {
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        else if (token == '(') {
            push(stack, &top, token);
        }
        else if (token == ')') {
            while ((x = pop(stack, &top)) != '(') {
                postfix[j++] = x;
            }
        }
        else {
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

// ---------------- NEW FUNCTIONS -----------------

// Step 1: Reverse infix and swap ( with )
void reverse_infix(char *infix, char *reversed) {
    int len = strlen(infix);
    int i, j = 0;

    for (i = len - 1; i >= 0; i--) {
        if (infix[i] == '(')
            reversed[j++] = ')';
        else if (infix[i] == ')')
            reversed[j++] = '(';
        else
            reversed[j++] = infix[i];
    }
    reversed[j] = '\0';
}

// Helper: Reverse any string
void reverse_string(char *str) {
    int len = strlen(str);
    int i;
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Step 2 & 3: Infix → Postfix → Reverse(Postfix) = Prefix
void infix_to_prefix(char *infix, char *prefix) {
    char reversed[MAX], postfix[MAX];

    // Step 1: Reverse infix
    reverse_infix(infix, reversed);

    // Step 2: Get postfix of reversed
    convert_postfix(reversed, postfix);

    // Step 3: Reverse postfix to get prefix
    strcpy(prefix, postfix);
    reverse_string(prefix);
}
