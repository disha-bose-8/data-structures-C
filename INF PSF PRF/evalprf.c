//
// Created by disha on 31-08-2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

int evaluatePrefix(char *prefix) {
    int stack[MAX]; // stack for integers
    int top = -1; // stack top initally empty

    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) { // traverse from right to left
        char token = prefix[i];
        if (isdigit(token)) {
            stack[++top] = token - '0';
        } else { // operator
            int op1 = stack[top--];
            int op2 = stack[top--];
            int res;
            switch (token) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '%': res = op1 % op2; break;
                case '^': res = pow(op1, op2); break;
                default: printf("Invalid operator: %c\n", token); return 0;
            }
            stack[++top] = res;
        }
    }

    return stack[top];
}

int main() {
    char prefix[MAX];
    printf("Enter prefix expression (single-digit numbers): ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result = %d\n", result);

    return 0;
}
