//
// Created by disha on 31-08-2025.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void postfixToInfix(char* postfix) {
    char stack[MAX][MAX]; // stack of strings
    int top = -1;
    char op1[MAX], op2[MAX], temp[MAX];

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) { // operand
            temp[0] = ch;
            temp[1] = '\0';
            strcpy(stack[++top], temp);
        } else { // operator
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            sprintf(temp, "(%s%c%s)", op1, ch, op2);
            strcpy(stack[++top], temp);
        }
    }

    printf("Infix expression: %s\n", stack[top]);
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix);
    return 0;
}
