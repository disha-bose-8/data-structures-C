//
// Created by disha on 27-08-2025.
//
// Evaluation of Postfix Expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 20

// User-defined function to read a line of input
void get(char str[])
{
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0'; // null-terminate the string
}

int main() {
    char postfix[MAX];
    int stack[MAX];
    int top = -1;
    int op1, op2, res;
    char symb;

    printf("Enter the Postfix Expression (single-digit numbers only):\n");
    get(postfix);  // read input

    for (int i = 0; i < strlen(postfix); i++) {
        symb = postfix[i];

        if (isdigit(symb)) {
            stack[++top] = symb - '0';  // convert char to int
        }
        else if (symb == ' ' || symb == '\t') {
            continue; // skip spaces/tabs
        }
        else { // operator
            op2 = stack[top--];  // pop second operand
            op1 = stack[top--];  // pop first operand

            switch (symb) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '%': res = op1 % op2; break;
                case '^': res = pow(op1, op2); break;
                default:
                    printf("Invalid operator: %c\n", symb);
                return 1;
            }

            stack[++top] = res; // push result back onto stack which again goes into switch with next digit
        }
    }

    printf("Result of Postfix Evaluation = %d\n", stack[top]);
    return 0;
}
