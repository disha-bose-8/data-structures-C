#include <stdio.h>
#include <stdlib.h>

void inorder(int *t, int i) {
  if (i >= 100 || t[i] == -1) return;
  inorder(t, 2 * i + 1);
  printf("%d ", t[i]);
  inorder(t, 2 * i + 2);
}

void preorder(int *t, int i) {
  if (i >= 100 || t[i] == -1) return;
  printf("%d ", t[i]);
  preorder(t, 2 * i + 1);
  preorder(t, 2 * i + 2);
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
  t[i] = x;
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
