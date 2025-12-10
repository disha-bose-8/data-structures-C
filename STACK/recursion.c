//
// Created by disha on 23-09-2025.
//
#include <stdio.h>

// Factorial using recursion
int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Fibonacci using recursion
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Addition using recursion
int add(int a, int b) {
    if (b == 0)
        return a;
    return add(a + 1, b - 1);
}

// Subtraction using recursion
int subtract(int a, int b) {
    if (b == 0)
        return a;
    return subtract(a - 1, b - 1);
}

// Multiplication using recursion
int multiply(int a, int b) {
    if (b == 0)
        return 0;
    if (b > 0)
        return a + multiply(a, b - 1);
    // For negative numbers
    return -multiply(a, -b);
}

// Division using recursion (integer division)
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    if (a < b)
        return 0;
    return 1 + divide(a - b, b);
}

// Modulus using recursion
int mod(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero!\n");
        return 0;
    }
    if (a < b)
        return a;  // remainder
    if (a > 0)
        return mod(a - b, b);
    // handle negative numbers
    if (a < 0)
        return mod(a + b, b);
    return 0;
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Step 3: Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n1, n2, n, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    printf("Enter a number for factorial and Fibonacci: ");
    scanf("%d", &n);

    printf("\nResults using recursion:\n");
    printf("Factorial of %d = %d\n", n, factorial(n));
    printf("Fibonacci of %d = %d\n", n, fibonacci(n));
    printf("Addition: %d + %d = %d\n", n1, n2, add(n1, n2));
    printf("Subtraction: %d - %d = %d\n", n1, n2, subtract(n1, n2));
    printf("Multiplication: %d * %d = %d\n", n1, n2, multiply(n1, n2));
    printf("Division: %d / %d = %d\n", n1, n2, divide(n1, n2));
    printf("Modulus: %d %% %d = %d\n", n1, n2, mod(n1, n2));
    printf("\nTower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
