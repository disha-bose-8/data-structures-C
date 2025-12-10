//
// Created by disha on 28-08-2025.
//
#include <stdio.h>

// C program to check for balanced parentheses in an expression

int main()
    {
  int s[100];
  int top = -1;
  char exp[100];
  int i;
  printf("Enter exp:\n");
  scanf("%s",exp);
  for(i=0;exp[i]!='\0';i++) {
    if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
      s[++top]=exp[i];
    else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
    {
      if(exp[i]==')' && s[top]=='(')
        s[top--];
      else if(exp[i]=='}' && s[top]=='{')
        s[top--];
      else if(exp[i]==']' && s[top]=='[')
        s[top--];
      else
      {
        printf("unbalanced Expression\n");
        return 0;
      }

    }

  }
  if (top==-1)
    printf("balanced Expression\n");
  else
    printf("unbalanced Expression\n");
}