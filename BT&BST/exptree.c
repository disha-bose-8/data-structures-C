#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isalpha(), isdigit()

/*expression tree is a binary tree where:

leaf nodes = operands

internal nodes = operators*/

typedef struct node { // can be operand (A, B, 1, 2…) or operator (+, -, *, /)
    char data;
    struct node* left;
    struct node* right;
} NODE;

typedef struct stack { // stack is needed to build the tree using postfix expression.
    NODE** arr; // array of pointers to NODEs
    int top; // index of top element
    int size; // maximum size of stack
} STACK;

// Function to create a new node
NODE* createNode(char data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Initialize the stack
STACK* createStack(int size) {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->arr = (NODE**)malloc(size * sizeof(NODE*));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Stack operations
void push(STACK* stack, NODE* node) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = node;
}

NODE* pop(STACK* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        return NULL;
    }
    return stack->arr[stack->top--];
}

// Build Expression Tree from Postfix Expression
NODE* buildExpressionTree(char postfix[]) {
    STACK* stack = createStack(100);
    NODE* t1, *t2, *temp;
    int i = 0;
    char symbol;

    while ((symbol = postfix[i++]) != '\0') {
        if (isalpha(symbol) || isdigit(symbol)) {
            temp = createNode(symbol);
            push(stack, temp);
        } else {
            t1 = pop(stack);
            t2 = pop(stack);
            temp = createNode(symbol);
            temp->right = t1;
            temp->left = t2;
            push(stack, temp);
        }
    }
    return pop(stack); // root
}

// Traversal functions
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(NODE* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Evaluate numeric expression tree
int evaluate(NODE* root) {
    if (root == NULL)
        return 0;

    // If leaf node (operand)
    if (isdigit(root->data))
        return root->data - '0'; // convert char '3' to int 3

    // Evaluate left and right subtrees
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // Apply operator
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return rightVal != 0 ? leftVal / rightVal : 0;
        default: return 0;
    }
}

// Main
int main() {
    NODE* root = NULL;
    char postfix[100];
    int choice;

    while (1) {
        printf("\n1. Build Expression Tree\n2. Inorder\n3. Preorder\n4. Postorder\n5. Evaluate Expression\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                root = buildExpressionTree(postfix);
                printf("Expression tree built successfully!\n");
                break;
            case 2:
                printf("Inorder (Infix): ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder (Prefix): ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder (Postfix): ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                if (root == NULL) {
                    printf("Build the tree first!\n");
                } else {
                    int result = evaluate(root);
                    printf("Result = %d\n", result);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
