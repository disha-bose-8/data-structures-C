#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue(int *q, int *r, int ele)
    {
      if(*r == MAX - 1)
        {
          printf("Queue is full\n");
        }
        else
        {
          int j = *r; // j starts from rear
            while(j >= 0 && q[j] > ele) // wont work for r=-1, if next element smaller than q[j] (prev) we enter loop
            {
              q[j + 1] = q[j]; // shift bigger element to right
              j--; // decrement j to check previous element
            }
          q[j + 1] = ele; // q[0] gets first element, else we continue here for ascending order
          (*r)++; // increment rear
          printf("%d inserted\n", ele);
          }
    }

int dequeue(int *q, int *f, int r)
    {
      if(*f > r)
        {
          // printf("Queue is empty\n");
          return 9999;
        }
      int x = q[*f]; 
      (*f)++; // increment front
      return x;
    }

void display(int *q, int f, int r)
    {
      if(f > r)
        {
          printf("Queue is empty\n");
          return;
        }
      printf("Queue elements: ");
      for(int i = f; i <= r; i++)
        {
          printf("%d ", q[i]);
        }
      printf("\n");
    }

int main()
    {
    int q[MAX];
    int f = 0, r = -1, ele, ch, x;
    while(1)
      {
      // prioty queue menu
        printf("\n---- Priority Queue Menu ----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek Front\n5. Peek Rear\n");
        printf("6. Check Empty\n7. Check Full\n8. Size\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
          case 1:
            printf("Enter element: ");
            scanf("%d", &ele);
            enqueue(q, &r, ele);
            break;

          case 2:
            x=dequeue(q, &f, r);
            if(x==9999)
              {
                printf("Queue is empty\n");
              }
            else
              {
                printf("Deleted element: %d\n", x);
              }
            break;

          case 3 :
            display(q, f, r);
            break;

          case 4:
            if(f > r)
              {
                printf("Queue is empty\n");
              }
            else
              {
                printf("Front element: %d\n", q[f]);
              }
            break;

            case 5:
            if(f > r)
              {
                printf("Queue is empty\n");
              }
            else
              {
                printf("Rear element: %d\n", q[r]);
              }
            break;

            case 6:
            if(f > r)
              {
                printf("Queue is empty\n");
              }
            else
              {
                printf("Queue is not empty\n");
              }
            break;
            case 7:
            if(r == MAX - 1)
                {
                    printf("Queue is full\n");
                    }
                else
                    {
                        printf("Queue is not full\n");
                    }
            break;
            case 8:
            printf("Queue size: %d\n", (r - f + 1));
            break;
            case 9:
            exit(0);
            default:
            printf("Invalid choice\n");
        }
        }
    return 0;
    }

