#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *rlink;
    struct node *llink;
};

typedef struct node NODE;

struct dlist {
    NODE *head;
    int no_of_nodes;
};

typedef struct dlist DLIST;

/* Function prototypes */
void init_list(DLIST *);
void insert_head(DLIST *, int);
void insert_tail(DLIST *, int);
void insert_pos(DLIST *, int, int);
void insert_after(DLIST *, int, int);
void insert_before(DLIST *, int, int);
void orderlist(DLIST *, int);
void orderlistdes(DLIST *, int);

void delete_first(DLIST *);
void delete_last(DLIST *);
void delete_node(DLIST *, int);
void delete_pos(DLIST *, int);
void delete_after(DLIST *, int);
void delete_before(DLIST *, int);
void delete_alt(DLIST *);

void display(DLIST *);
void display_reverse(DLIST *);
void display_alternate(DLIST *);

void count(DLIST *);
void search(DLIST *, int);
void sum(DLIST *);
void sortAscending(DLIST *);
void sortDescending(DLIST *);
void free_list(DLIST *);


/* MAIN */
int main() {
    int ch, data, pos, value;
    DLIST l;
    init_list(&l);

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1..Insert Head\n2..Insert Tail\n3..Display\n4..Delete First\n5..Delete Last\n");
        printf("6..Delete by Value\n7..Delete by Position\n8..Insert at Position\n");
        printf("9..Insert After Value\n10..Insert Before Value\n11..Delete Before Value\n");
        printf("12..Delete After Value\n13..Display Reverse\n14..Count Nodes\n15..Search Element\n");
        printf("16..Delete Alternate Nodes\n17..Sum of Nodes\n18..Sort Ascending\n19..Sort Descending\n");
        printf("20..Insert in Sorted (Asc)\n21..Insert in Sorted (Desc)\n22..Display Alternate\n");
        printf("23..Exit\n");

        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_head(&l, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_tail(&l, data);
            break;
        case 3:
            display(&l);
            break;
        case 4:
            delete_first(&l);
            break;
        case 5:
            delete_last(&l);
            break;
        case 6:
            printf("Enter value: ");
            scanf("%d", &data);
            delete_node(&l, data);
            break;
        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete_pos(&l, pos);
            break;
        case 8:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insert_pos(&l, data, pos);
            break;
        case 9:
            printf("Enter value and new data: ");
            scanf("%d %d", &value, &data);
            insert_after(&l, value, data);
            break;
        case 10:
            printf("Enter value and new data: ");
            scanf("%d %d", &value, &data);
            insert_before(&l, value, data);
            break;
        case 11:
            printf("Enter value: ");
            scanf("%d", &value);
            delete_before(&l, value);
            break;
        case 12:
            printf("Enter value: ");
            scanf("%d", &value);
            delete_after(&l, value);
            break;
        case 13:
            display_reverse(&l);
            break;
        case 14:
            count(&l);
            break;
        case 15:
            printf("Enter element to search: ");
            scanf("%d", &value);
            search(&l, value);
            break;
        case 16:
            delete_alt(&l);
            break;
        case 17:
            sum(&l);
            break;
        case 18:
            sortAscending(&l);
            break;
        case 19:
            sortDescending(&l);
            break;
        case 20:
            printf("Enter data: ");
            scanf("%d", &data);
            orderlist(&l, data);
            break;
        case 21:
            printf("Enter data: ");
            scanf("%d", &data);
            orderlistdes(&l, data);
            break;
        case 22:
            display_alternate(&l);
            break;
        case 23:
            free_list(&l);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}


/* INITIALIZATION */
void init_list(DLIST *ptr) {
    ptr->head = NULL;
    ptr->no_of_nodes = 0;
}


/* DISPLAY FUNCTIONS */
void display(DLIST *ptr) {
    NODE *cur = ptr->head;
    if (cur == NULL) {
        printf("Empty List\n");
        return;
    }
    while (cur != NULL) {
        printf("%d<->", cur->data);
        cur = cur->rlink;
    }
    printf("NULL\n");
}

void display_reverse(DLIST *ptr) {
    NODE *cur = ptr->head;
    if (cur == NULL) {
        printf("Empty List\n");
        return;
    }
    while (cur->rlink != NULL)
        cur = cur->rlink;
    while (cur != NULL) {
        printf("%d<->", cur->data);
        cur = cur->llink;
    }
    printf("NULL\n");
}

void display_alternate(DLIST *ptr) {
    if (ptr->head == NULL) {
        printf("Empty List\n");
        return;
    }
    NODE *start = ptr->head;
    NODE *end = ptr->head;
    while (end->rlink != NULL)
        end = end->rlink;
    printf("Alternate: ");
    while (start != NULL && end != NULL && start != end && start->llink != end) {
        printf("%d %d ", start->data, end->data);
        start = start->rlink;
        end = end->llink;
    }
    if (start == end)
        printf("%d", start->data);
    printf("\n");
}


/* INSERT FUNCTIONS */
void insert_head(DLIST *ptr, int data) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = ptr->head; // address of first node
    temp->llink = NULL;
    if (ptr->head != NULL) // more than one node present
        ptr->head->llink = temp; // first node's llink points to new node
    ptr->head = temp;
    ptr->no_of_nodes++;
}

void insert_tail(DLIST *ptr, int data) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = NULL;
    temp->llink = NULL;
    if (ptr->head == NULL) {
        ptr->head = temp;
    } else {
        NODE *cur = ptr->head;
        while (cur->rlink != NULL)
            cur = cur->rlink;
        cur->rlink = temp;
        temp->llink = cur;
    }
    ptr->no_of_nodes++;
}

void insert_pos(DLIST *ptr, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insert_head(ptr, data);
        return;
    }
    NODE *cur = ptr->head;
    int i = 1;
    while (cur != NULL && i < pos - 1) { // stop at node before desired position ***
        cur = cur->rlink;
        i++;
    }
    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = cur->rlink;
    temp->llink = cur;
    if (cur->rlink != NULL)
        cur->rlink->llink = temp;
    cur->rlink = temp;
    ptr->no_of_nodes++;
}

void insert_after(DLIST *ptr, int value, int data) {
    NODE *cur = ptr->head;
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;
    if (cur == NULL) {
        printf("Value not found\n");
        return;
    }
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = cur->rlink;
    temp->llink = cur;
    if (cur->rlink != NULL)
        cur->rlink->llink = temp;
    cur->rlink = temp;
    ptr->no_of_nodes++;
}

void insert_before(DLIST *ptr, int value, int data) {
    NODE *cur = ptr->head;
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;
    if (cur == NULL) {
        printf("Value not found\n");
        return;
    }
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->rlink = cur;
    temp->llink = cur->llink;
    if (cur->llink != NULL)
        cur->llink->rlink = temp;
    else
        ptr->head = temp;
    cur->llink = temp;
    ptr->no_of_nodes++;
}

void orderlist(DLIST *ptr, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = temp->llink = NULL;
    if (ptr->head == NULL || ele < ptr->head->data) {
        temp->rlink = ptr->head;
        if (ptr->head != NULL)
            ptr->head->llink = temp;
        ptr->head = temp;
        return;
    }
    NODE *cur = ptr->head;
    while (cur->rlink != NULL && cur->rlink->data < ele)
        cur = cur->rlink;
    temp->rlink = cur->rlink;
    if (cur->rlink != NULL)
        cur->rlink->llink = temp;
    cur->rlink = temp;
    temp->llink = cur;
}

void orderlistdes(DLIST *ptr, int ele) {
    NODE *temp = malloc(sizeof(NODE));
    temp->data = ele;
    temp->rlink = temp->llink = NULL;
    if (ptr->head == NULL || ele > ptr->head->data) {
        temp->rlink = ptr->head;
        if (ptr->head != NULL)
            ptr->head->llink = temp;
        ptr->head = temp;
        return;
    }
    NODE *cur = ptr->head;
    while (cur->rlink != NULL && cur->rlink->data > ele)
        cur = cur->rlink;
    temp->rlink = cur->rlink;
    if (cur->rlink != NULL)
        cur->rlink->llink = temp;
    cur->rlink = temp;
    temp->llink = cur;
}


/* DELETE FUNCTIONS */
void delete_first(DLIST *ptr) {
    if (ptr->head == NULL) {
        printf("Empty List\n");
        return;
    }
    NODE *cur = ptr->head;
    ptr->head = cur->rlink;
    if (ptr->head != NULL)
        ptr->head->llink = NULL;
    free(cur);
    ptr->no_of_nodes--;
}

void delete_last(DLIST *ptr) {
    if (ptr->head == NULL) {
        printf("Empty List\n");
        return;
    }
    NODE *cur = ptr->head;
    while (cur->rlink != NULL)
        cur = cur->rlink;
    if (cur->llink != NULL)
        cur->llink->rlink = NULL;
    else
        ptr->head = NULL;
    free(cur);
    ptr->no_of_nodes--;
}

void delete_node(DLIST *ptr, int data) {
    NODE *cur = ptr->head;
    while (cur != NULL && cur->data != data)
        cur = cur->rlink;
    if (cur == NULL) {
        printf("Node not found\n");
        return;
    }
    if (cur->llink != NULL)
        cur->llink->rlink = cur->rlink;
    else
        ptr->head = cur->rlink;
    if (cur->rlink != NULL)
        cur->rlink->llink = cur->llink;
    free(cur);
    ptr->no_of_nodes--;
}

void delete_pos(DLIST *ptr, int pos) {
    if (pos < 1 || ptr->head == NULL) {
        printf("Invalid position\n");
        return;
    }
    NODE *cur = ptr->head;
    int i = 1;
    while (cur != NULL && i < pos) {
        cur = cur->rlink;
        i++;
    }
    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (cur->llink != NULL)
        cur->llink->rlink = cur->rlink;
    else
        ptr->head = cur->rlink;
    if (cur->rlink != NULL)
        cur->rlink->llink = cur->llink;
    free(cur);
    ptr->no_of_nodes--;
}

void delete_before(DLIST *ptr, int value) {
    NODE *cur = ptr->head;
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;
    if (cur == NULL || cur->llink == NULL) {
        printf("No node before given value\n");
        return;
    }
    NODE *del = cur->llink;
    if (del->llink != NULL)
        del->llink->rlink = cur;
    else
        ptr->head = cur;
    cur->llink = del->llink;
    free(del);
    ptr->no_of_nodes--;
}

void delete_after(DLIST *ptr, int value) {
    NODE *cur = ptr->head;
    while (cur != NULL && cur->data != value)
        cur = cur->rlink;
    if (cur == NULL || cur->rlink == NULL) {
        printf("No node after given value\n");
        return;
    }
    NODE *del = cur->rlink;
    cur->rlink = del->rlink;
    if (del->rlink != NULL)
        del->rlink->llink = cur;
    free(del);
    ptr->no_of_nodes--;
}

void delete_alt(DLIST *ptr) {
    NODE *cur = ptr->head;
    while (cur != NULL && cur->rlink != NULL) {
        NODE *temp = cur->rlink;
        cur->rlink = temp->rlink;
        if (temp->rlink != NULL)
            temp->rlink->llink = cur;
        free(temp);
        cur = cur->rlink;
    }
}


/* EXTRA FUNCTIONS */
void count(DLIST *ptr) {
    printf("Count = %d\n", ptr->no_of_nodes);
}

void search(DLIST *ptr, int ele) {
    NODE *cur = ptr->head;
    int i = 1;
    while (cur != NULL) {
        if (cur->data == ele) {
            printf("Element found at position %d\n", i);
            return;
        }
        cur = cur->rlink;
        i++;
    }
    printf("Element not found\n");
}

void sum(DLIST *ptr) {
    int s = 0;
    NODE *cur = ptr->head;
    while (cur != NULL) {
        s += cur->data;
        cur = cur->rlink;
    }
    printf("Sum = %d\n", s);
}

void sortAscending(DLIST *ptr) {
    for (NODE *i = ptr->head; i != NULL; i = i->rlink) {
        for (NODE *j = i->rlink; j != NULL; j = j->rlink) {
            if (i->data > j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void sortDescending(DLIST *ptr) {
    for (NODE *i = ptr->head; i != NULL; i = i->rlink) {
        for (NODE *j = i->rlink; j != NULL; j = j->rlink) {
            if (i->data < j->data) {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void free_list(DLIST *ptr) {
    NODE *cur = ptr->head;
    while (cur != NULL) {
        NODE *next = cur->rlink;
        free(cur);
        cur = next;
    }
    ptr->head = NULL;
    ptr->no_of_nodes = 0;
}
