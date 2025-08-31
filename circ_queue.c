//
// Created by disha on 28-08-2025.
//
// circular queue

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void enqueue(int *q,int *r, int *f, int ele)
    {
  if(((*f==0) && (*r==MAX-1)) || (*f== *r+1))
    {
    *f=0;
    *r=(*r+1)%MAX;
    q[*r]=ele;
    }
    }
void display(int *q, int f, int r)
        {
  if(f==1)
    {}
    }