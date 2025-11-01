//
// Created by disha on 31-08-2025.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void prefixToInfix(char* prefix) {
    char stack[MAX][MAX];
    int top = -1;
    char op1[MAX], op2[MAX], temp[MAX];
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            strcpy(stack[++top], temp);
        } else {
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            sprintf(temp, "(%s%c%s)", op1, ch, op2);
            strcpy(stack[++top], temp);
        }
    }

    printf("Infix expression: %s\n", stack[top]);
}

int main() {
    char prefix[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix);
    return 0;
}
