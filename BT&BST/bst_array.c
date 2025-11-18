#include <stdio.h>
#include <stdlib.h>

// For a Binary Search Tree, inorder traversal always prints values in sorted order.

/*What is int *t?
t is a pointer to int.
In main, you have int t[100];
When you pass t to a function, it decays into a pointer to its first element.
So in this function, t represents your entire tree stored in an array of size 100.*/

/*
* i is the index in the array representing the current node.
Root node is at index 0.
For any node at index i:
Left child index = 2 * i + 1
Right child index = 2 * i + 2*/

void inorder(int *t, int i) {
  if (i >= 100 || t[i] == -1) return;
  inorder(t, 2 * i + 1); // Recursively traverse the left subtree. 2 * i + 1 is the left child index.
  printf("%d ", t[i]); // Process the current node: print its value.
  inorder(t, 2 * i + 2); // Recursively traverse the right subtree. 2 * i + 2 is the right child index.
}

void preorder(int *t, int i) {
  if (i >= 100 || t[i] == -1) return;
  printf("%d ", t[i]); // First, visit the current node.
  preorder(t, 2 * i + 1); // Then, traverse the left subtree.
  preorder(t, 2 * i + 2); // Finally, traverse the right subtree.
}

void postorder(int *t, int i) {
  if (i >= 100 || t[i] == -1) return;
  postorder(t, 2 * i + 1);
  postorder(t, 2 * i + 2);
  printf("%d ", t[i]);
}

void insert(int *t, int x) {
  int i = 0;
  while (i < 100 && t[i] != -1) {
    if (x < t[i])
      i = 2 * i + 1; // Left child
    else
      i = 2 * i + 2; // Right child
  }
  if (i >= 100) {
    printf("Tree is full!\n");
    return;
  }
  t[i] = x; // Insert the new value at the found position.
}

int main() {
  int t[100], ch, x;
  for (int i = 0; i < 100; i++)
    t[i] = -1;
  //if t[i] != -1, that position has a valid node

  while (1) {
    printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
      case 1:
        printf("Enter the number to insert: ");
      scanf("%d", &x);
      insert(t, x);
      break;
      case 2:
        printf("Inorder: ");
      inorder(t, 0);
      printf("\n");
      break;
      case 3:
        printf("Preorder: ");
      preorder(t, 0);
      printf("\n");
      break;
      case 4:
        printf("Postorder: ");
      postorder(t, 0);
      printf("\n");
      break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice!\n");
    }
  }
}
