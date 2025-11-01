#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// ---------- Stack for characters ----------
void push(char *stack, int *top, char x) {
    stack[++(*top)] = x;
}
char pop(char *stack, int *top) {
    return stack[(*top)--];
}
char peek(char *stack, int top) {
    return stack[top];
}
int isEmpty(int top) {
    return top == -1;
}

// ---------- Operator precedence ----------
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '^') return 3;
    return 0;
}

// ---------- Reverse a string ----------
void reverse(char *str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        char tmp = str[l];
        str[l++] = str[r];
        str[r--] = tmp;
    }
}

// ---------- Swap parentheses ----------
void swapParentheses(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

// ---------- Infix → Postfix ----------
void convert_postfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) { // operand
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(stack, &top, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(top) && peek(stack, top) != '(')
                postfix[j++] = pop(stack, &top);
            pop(stack, &top); // remove '('
        }
        else { // operator
            while (!isEmpty(top) && precedence(peek(stack, top)) >= precedence(ch))
                postfix[j++] = pop(stack, &top);
            push(stack, &top, ch);
        }
    }

    while (!isEmpty(top)) {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0';
}

// ---------- Infix → Prefix ----------
void infix_to_prefix(char *infix, char *prefix) {
    char postfix[MAX];

    // Step 1: Reverse infix
    reverse(infix);

    // Step 2: Swap ( and )
    swapParentheses(infix);

    // Step 3: Convert to postfix
    convert_postfix(infix, postfix);

    // Step 4: Reverse postfix to get prefix
    strcpy(prefix, postfix);
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_prefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);
    return 0;
}
