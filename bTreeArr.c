//
// Created by disha on 16-09-2025.
//
/* WAP to implement binary tree using array data structure and perform inorder, preorder and postorder traversals.
Parent (index = i)
Left child = 2*i + 1
Right child = 2*i + 2
*/

#include <stdio.h>
#include <stdlib.h>

#define size 20 // Maximum number of nodes this tree can hold (since it’s array-based).

typedef struct Btree // Array representation of Binary Tree
    {
  int tree[size]; // array to hold tree elements
  int last_index; // index of the last element in the tree (-1 if empty)
    } Tree;

void init (Tree *bt) // Initialize the binary tree
    {
  bt->last_index = -1;
    }

void insert (Tree *bt, int data)
    {
  if (bt->last_index == size - 1) // if (bt->last_index+1>=size-1)
    {
      printf ("Tree is full\n");
      return;
    }
  bt->last_index++; // increment last index
  bt->tree[bt->last_index] = data; // insert data at last index
    }

void inorder_traversal (Tree *bt, int index) // Inorder → Left → Root → Right
    {
    if (index <= bt->last_index) // index: the current node’s position in the array representation of the tree.
      {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left <= bt->last_index) // check if left child exists (visit left subtree)
        {
        // left becomes the current index for the next recursive call
        inorder_traversal (bt, left); // recursion call next set of code won't be executed until this call is completed goes back to start
        }
      printf ("%d ", bt->tree[index]);
      if(right <= bt->last_index)
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
  if (index <= bt->last_index)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      printf ("%d ", bt->tree[index]); // visit root first
      if(left <= bt->last_index) // check if left child exists
        {
        preorder_traversal (bt, left);
        }
      if(right <= bt->last_index) // check if right child exists
        {
        preorder_traversal (bt, right);
        }
    }
    }

void postorder_traversal (Tree *bt, int index) // Postorder → Left → Right → Root
    {
  if (index <= bt->last_index)
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      if(left <= bt->last_index) // check if left child exists
        {
        postorder_traversal (bt, left);
        }
      if(right <= bt->last_index) // check if right child exists
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