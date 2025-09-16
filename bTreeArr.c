//
// Created by disha on 16-09-2025.
//

#include <stdio.h>
#include <stdlib.h>

#define size 20

typedef struct Btree
    {
  int tree[size];
  int lastindex;
    } Tree;

void init (Tree *bt)
    {
  bt->lastindex = -1;
    }

void insert (Tree *bt, int data)
    {
  if (bt->lastindex == size - 1) // if (bt->lastindex+1>=size-1)
    {
      printf ("Tree is full\n");
      return;
    }
  bt->lastindex++;
  bt->tree[bt->lastindex] = data;
    }

void inorder_traversal (Tree *bt, int index)
    {
    if (index <= bt->lastindex)
      {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left <= bt->lastindex)
        {
        inorder_traversal (bt, left); // recursion call next set of code wont be executed until this call is completed goes back to start
        }
      printf ("%d ", bt->tree[index]);
      if(right <= bt->lastindex)
        {
        inorder_traversal (bt, right);
        }

      /*
      Alternative simpler form without extra checks:
      inorder_traversal (bt, left);
      printf ("%d ", bt->tree[index]);
      inorder_traversal (bt, right);
       */

      }
      }

void preorder_traversal (Tree *bt, int index)
    {
  if (index <= bt->lastindex)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      printf ("%d ", bt->tree[index]);
      if(left <= bt->lastindex)
        {
        preorder_traversal (bt, left);
        }
      if(right <= bt->lastindex)
        {
        preorder_traversal (bt, right);
        }
    }
    }

void postorder_traversal (Tree *bt, int index)
    {
  if (index <= bt->lastindex)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left <= bt->lastindex)
        {
        postorder_traversal (bt, left);
        }
      if(right <= bt->lastindex)
        {
        postorder_traversal (bt, right);
        }
      printf ("%d ", bt->tree[index]);
    }
    }

int main()
        {
  Tree bt;
  init (&bt);
  insert (&bt, 1);
  insert (&bt, 2);
  insert (&bt, 3);
  insert (&bt, 4);
  insert (&bt, 5);
  insert (&bt, 6);
  printf("\ninorrder traversal \n");
  inorder_traversal (&bt, 0);
  printf("\npreorder traversal \n");
  preorder_traversal (&bt, 0);
  printf("\npostorder traversal \n");
  postorder_traversal (&bt, 0);
  return 0;
  }