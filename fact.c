//
// Created by disha on 28-08-2025.
//
// recursive factorial
#include<stdio.h>

int factorial(int n)
    {
  if(n<=1)
    return 1;
  else
    return n*factorial(n-1);
    }

int main()
        {
  int n;
  printf("Enter the number:\n");
  scanf("%d",&n);
  printf("The factorial of %d is %d",n,factorial(n));
        }