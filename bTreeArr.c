//
// Created by disha on 16-09-2025.
//

#include <stdio.h>
#include <stdlib.h>

#define size 20 // Maximum number of nodes this tree can hold (since it’s array-based).

typedef struct Btree // Array representation of Binary Tree
    {
  int tree[size]; // array to hold tree elements
  int lastindex; // index of the last element in the tree
    } Tree;

void init (Tree *bt) // Initialize the binary tree
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
  bt->lastindex++; // increment lastindex
  bt->tree[bt->lastindex] = data; // insert data at lastindex
    }

void inorder_traversal (Tree *bt, int index) // Inorder → Left → Root → Right
    {
    if (index <= bt->lastindex) // index: the current node’s position in the array representation of the tree.
      {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left <= bt->lastindex) // check if left child exists (visit left subtree)
        {
        // left becomes the current index for the next recursive call
        inorder_traversal (bt, left); // recursion call next set of code won't be executed until this call is completed goes back to start
        }
      printf ("%d ", bt->tree[index]);
      if(right <= bt->lastindex)
        {
        inorder_traversal (bt, right); // visit right subtree
        }

      /*
      Alternative simpler form without extra checks:
      inorder_traversal (bt, left);
      printf ("%d ", bt->tree[index]);
      inorder_traversal (bt, right);
       */

      }
      }

void preorder_traversal (Tree *bt, int index) // Preorder → Root → Left → Right
    {
  if (index <= bt->lastindex)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      printf ("%d ", bt->tree[index]); // visit root first
      if(left <= bt->lastindex) // check if left child exists
        {
        preorder_traversal (bt, left);
        }
      if(right <= bt->lastindex) // check if right child exists
        {
        preorder_traversal (bt, right);
        }
    }
    }

void postorder_traversal (Tree *bt, int index) // Postorder → Left → Right → Root
    {
  if (index <= bt->lastindex)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left <= bt->lastindex) // check if left child exists
        {
        postorder_traversal (bt, left);
        }
      if(right <= bt->lastindex) // check if right child exists
        {
        postorder_traversal (bt, right);
        }
      printf ("%d ", bt->tree[index]); // visit root last
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
  printf("\n inorder traversal \n");
  inorder_traversal (&bt, 0);
  printf("\n preorder traversal \n");
  preorder_traversal (&bt, 0);
  printf("\n postorder traversal \n");
  postorder_traversal (&bt, 0);
  return 0;
  }