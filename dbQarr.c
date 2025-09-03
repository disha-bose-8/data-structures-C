//
// Created by disha on 02-09-2025.
//

#include <stdio.h>
#define MAX 5

void insert_front(int *q, int *r, int *f, int ele)
    {
      if((*f == 0 && *r == MAX - 1) || (*f==*r+1)) // full condition
        {
          printf("Queue is full\n");
          return;
        }
      else
          {
        if(*f == -1 && *r == -1) // first element
          {
            *f = 0;
            *r = 0;
            q[*f] = ele;
            //printf("%d inserted at front\n", ele);
            //return;
          }
        else if(*f == 0) // f at first position, need to shift elements to right (for 2nd element)
          {
            *f = MAX - 1; // wrap around front
            q[*f] = ele;
            }
        else // normal case
          {
            (*f)--; // decrement front
        q[*f] = ele; // insert element at front
        }
        //printf("%d inserted at front\n", ele);
      }
    }

void insert_rear(int *q, int *r, int *f, int ele)
    {
      if((*f == 0 && *r == MAX - 1) || (*f==*r+1)) // full condition
        {
          printf("Queue is full\n");
          // return;
        }
      else
          {
        if(*f == -1 && *r == -1) // first element always inserted at one and only position one
          {
            *f = 0;
            *r = 0;
            q[*r] = ele;
            //printf("%d inserted at rear\n", ele);
            //return;
          }
        else if(*r == MAX - 1) // r at last position, need to wrap around
          {
            *r = 0; // wrap around rear
            q[*r] = ele;
            }
        else // normal case
          {
            (*r)++; // increment rear
        q[*r] = ele; // insert element at rear
        }
        //printf("%d inserted at rear\n", ele);
      }
    }

void display(int *q, int f, int r)
    {
      if(f == -1 && r == -1) // empty condition
        {
          printf("Queue is empty\n");
          return;
        }
        else
          {
            printf("Queue elements: ");
            int i = f;
            while(i!=r)
              {
                printf("%d ", q[i]);
                i = (i + 1) % MAX; // circular increment
              }
            printf("%d\n", q[r]); // print last element
          }
    }

int delete_front(int *q, int *f, int *r)
    {
      if(*f == -1 && *r == -1) // empty condition
        {
          printf("Queue is empty\n");
          return 9999;
        }
      else{
          int x;
          if(*f == *r) // only one element
            {
              x = q[*f];
              *f = -1;
              *r = -1;

            }
          else if(*f == MAX - 1) // f at last position, need to wrap around
            {
              x = q[*f];
              *f = 0; // wrap around front

            }
            else
            {
              x = q[*f];
              *f = (*f + 1) % MAX; // circular increment front

            }
          return x;
    }
    }

int delete_front(int *q, int *f, int *r);
{
      if(*f == -1 && *r == -1) // empty condition
        {
          printf("Queue is empty\n");
          return 9999;
        }
      else{
          int x;
          if(*f == *r) // only one element
            {
              x = q[*r];
              *f = -1;
              *r = -1;

            }
          else if(*r == 0) // r at first position, need to wrap around
            {
              x = q[*r];
              *r = MAX - 1; // wrap around rear

            }
            else
            {
              x = q[*r];
              (*r)--; // decrement rear

            }
          return x;
    }
}

int main()
    {
  int q[MAX];
    int f = -1, r = -1, ele, ch, x;
    while(1)
      {
      printf("1.insert at front\n2.insert at rear\n3.delete from front\n4.delete from rear\n5.display\n6.exit\n");
      printf("Enter your choice: ");
      scanf("%d", &ch);
      switch(ch)
      {
        case 1:
          printf("Enter element at front: \n");
          scanf("%d", &ele);
          insert_front(q, &r, &f, ele);
          break;

        case 2:
          printf("Enter element at rear: \n");
          scanf("%d", &ele);
          insert_rear(q, &r, &f, ele);
          break;

        case 3:
          void display(int *q, int f, int r);
          break;

        case 4:
          // delete from rear function call
          delete_rear(q, &r, &f);
          break;

        case 5:
          delete_front(q, &f, &r);
          break;

        case 6:
          exit(0);
          break;

        default:
          printf("Invalid choice\n");
      }
      printf("\n");
    }
    return 0;
}