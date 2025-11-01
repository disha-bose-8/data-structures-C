//
// Created by disha on 23-10-2025.
//

// Implementation of Min-Max heap (use array data structure) using priority queue

#include<stdio.h>
int size=0;

void swap( int *a, int *b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}

void heapify(int a[], int i)
{
    if(size==1)
    {
        printf("There is only one element");
    }
    else
    {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<size && a[l]>a[largest])
            largest=l;
        if(r<size && a[r]>a[largest])
            largest=r;

        if(largest!=i) // child is greater than the parent so swap
        {
            swap(&a[i], &a[largest]);
            heapify(a, largest);
        }

    }
}

void insert(int a[], int num)
{
    a[size]=num; // heap tree is exist
    size+=1;
    for(int i=(size/2)-1;i>=0;i--)
    {
        heapify(a,i); // keeps heapifying as we insert elements
    }

}

void display(int a[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t", a[i]);
    }
}

int main()
{
    int a[20];
    insert(a, 31);
    insert(a, 81);
    insert(a, 22);
    insert(a, 5);
    insert(a, 15);
    printf("The max heap is: ");
    display(a, size);

}