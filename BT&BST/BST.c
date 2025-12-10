#include <stdio.h>
#include <stdlib.h>

//------------------------------------------
// STRUCTURE DEFINITION
//------------------------------------------
typedef struct node {
    int data;                // value stored in this node
    struct node* lchild;     // pointer to left child
    struct node* rchild;     // pointer to right child
} NODE;

//------------------------------------------
// INSERT FUNCTION
//------------------------------------------

/*Why NODE** root ?
root is a pointer to the address of the root node.
Because:
If the tree is empty, you will change root inside this function.
To modify the caller’s root pointer → you must pass its address.
So NODE** means:
"I want to modify the original NODE* root stored in main.”*/

void insert(NODE** root, int num) { // ROOT IS A POINTER TO THE ADDRESS OF THE ROOT NODE
    // Create a new node dynamically
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = num;
    temp->lchild = temp->rchild = NULL; // initialize children as NULL

    // Case 1: if tree is empty → new node becomes root
    if (*root == NULL) {
        *root = temp;
        return;
    }

    // Otherwise, find correct place to insert
    NODE* current = *root;  // start from root
    NODE* prev = NULL;      // to keep track of parent

    // Traverse until current becomes NULL
    // (that’s where the new node will go)
    while (current != NULL) {
        prev = current; // move parent pointer
        if (num < current->data)
            current = current->lchild;  // go left if smaller
        else
            current = current->rchild;  // go right if greater or equal
    }

    // Attach new node to correct side of parent (prev)
    if (num < prev->data)
        prev->lchild = temp; // insert as left child
    else
        prev->rchild = temp; // insert as right child
}

//------------------------------------------
// INORDER TRAVERSAL (Left → Root → Right)
//------------------------------------------
void inorder(NODE* root) {
    if (root) {
        inorder(root->lchild);          // visit left subtree
        printf("%d ", root->data);      // print
        inorder(root->rchild);          // visit right subtree
    }
}
// For BST, inorder gives elements in sorted order.

//------------------------------------------
// PREORDER TRAVERSAL (Root → Left → Right)
//------------------------------------------
void preorder(NODE* root) {
    if (root) {
        printf("%d ", root->data);      // print root first
        preorder(root->lchild);         // then left
        preorder(root->rchild);         // then right
    }
}
// Useful for creating or copying tree structures.

//------------------------------------------
// POSTORDER TRAVERSAL (Left → Right → Root)
//------------------------------------------
void postorder(NODE* root) {
    if (root) {
        postorder(root->lchild);        // left subtree
        postorder(root->rchild);        // right subtree
        printf("%d ", root->data);      // then print root
    }
}
// Used for deleting or freeing tree from bottom up.

//------------------------------------------
// FIND MINIMUM VALUE NODE
//------------------------------------------
NODE* findMin(NODE* root) {
    // The smallest element is always in the leftmost node
    while (root && root->lchild != NULL)
        root = root->lchild;
    return root;
}

//------------------------------------------
// DELETE A NODE
//------------------------------------------
NODE* deleteNode(NODE* root, int key) {
    // Base case: tree empty or end reached
    if (root == NULL)
        return root;

    // Recur down to find the node to be deleted
    if (key < root->data)
        root->lchild = deleteNode(root->lchild, key);
    else if (key > root->data)
        root->rchild = deleteNode(root->rchild, key);
    else {
        // Node found — now handle 3 possible cases

        // Case 1: Node with only right child or no child
        if (root->lchild == NULL) {
            NODE* temp = root->rchild;  // store right subtree
            printf("Node deleted: %d\n", root->data);
            free(root);                 // delete current node
            return temp;                // return right child to parent
        }

        // Case 2: Node with only left child
        else if (root->rchild == NULL) {
            NODE* temp = root->lchild;  // store left subtree
            printf("Node deleted: %d\n", root->data);
            free(root);
            return temp;                // return left child to parent
        }

        // Case 3: Node with two children
        // Find inorder successor (smallest in right subtree)
        NODE* temp = findMin(root->rchild);

        // Copy inorder successor’s data into current node
        root->data = temp->data;

        // Delete the inorder successor recursively
        root->rchild = deleteNode(root->rchild, temp->data);
    }

    return root; // return unchanged root pointer
}

//------------------------------------------
// COUNT TOTAL NODES
//------------------------------------------
int count_nodes(NODE* root) {
    if (root == NULL)
        return 0;
    // 1 (this node) + nodes in left + nodes in right
    return 1 + count_nodes(root->lchild) + count_nodes(root->rchild);
}

//------------------------------------------
// COUNT LEAF NODES (nodes with no children)
//------------------------------------------
int count_leaves(NODE* root) {
    if (root == NULL)
        return 0;

    // If both children are NULL, it's a leaf ******************************************
    if (root->lchild == NULL && root->rchild == NULL)
        return 1;

    // Otherwise sum leaves in left and right subtrees
    return count_leaves(root->lchild) + count_leaves(root->rchild);
}

//------------------------------------------
// COUNT NON-LEAF NODES (at least one child)
//------------------------------------------
int count_nonleaves(NODE* root) {
    // Base case: empty or leaf node → 0 non-leaves
    if (root == NULL || (root->lchild == NULL && root->rchild == NULL))
        return 0;

    // 1 (current node) + non-leaves in left + right subtrees
    return 1 + count_nonleaves(root->lchild) + count_nonleaves(root->rchild);
}

//------------------------------------------
// HEIGHT OF TREE (NEWLY ADDED FUNCTION)
//------------------------------------------
int height(NODE* root) {
    if (root == NULL)
        return -1; // height of empty tree is -1

    int lh = height(root->lchild);
    int rh = height(root->rchild);

    return 1 + (lh > rh ? lh : rh);
}

//------------------------------------------
// DEPTH OF A NODE (NEWLY ADDED FUNCTION)
//------------------------------------------

/*root → current node you are checking
key → value whose depth you want
level → current depth (starts from 0 for root)*/

int depth(NODE* root, int key, int level) {
    if (root == NULL)
        return -1; // not found

    if (root->data == key)
        return level;

    int left = depth(root->lchild, key, level + 1);
    if (left != -1)
        return left;

    return depth(root->rchild, key, level + 1);
}

/*int depthBST(NODE* root, int key) {
    int level = 0;

    while (root != NULL) {
        if (root->data == key)
            return level;

        if (key < root->data)
            root = root->lchild;
        else
            root = root->rchild;

        level++;
    }
    return -1; // not found
}
*/

//------------------------------------------
// MAIN MENU-DRIVEN PROGRAM
//------------------------------------------
int main() {
    NODE* root = NULL;  // start with empty tree
    int ch, num;

    while (1) {
        printf("\n---- BINARY SEARCH TREE MENU ----\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete a Node\n");
        printf("6. Count Total Nodes\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Non-Leaf Nodes\n");
        printf("9. Height of Tree\n");
        printf("10. Depth of a Node\n");
        printf("11. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                insert(&root, num);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the number to be deleted: ");
                scanf("%d", &num);
                root = deleteNode(root, num);
                break;

            case 6:
                printf("Total nodes: %d\n", count_nodes(root));
                break;

            case 7:
                printf("Leaf nodes: %d\n", count_leaves(root));
                break;

            case 8:
                printf("Non-leaf nodes: %d\n", count_nonleaves(root));
                break;

            case 9:
                printf("Height of tree = %d\n", height(root));
                break;

            case 10:
                printf("Enter node value to find depth: ");
                scanf("%d", &num);
                int d;
                d = depth(root, num, 0);
                if (d == -1)
                    printf("Node not found.\n");
                else
                    printf("Depth of node %d = %d\n", num, d);
                break;

            case 11:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
