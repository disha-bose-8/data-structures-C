//
// Singly Linked List Program - 24-08-2025
//
#include <stdio.h>
#include <stdlib.h>

struct node // structure for one particular node
{
    int data; //store data of the node
    struct node *link; //pointer to the next node
};
typedef struct node NODE;

struct list
{
    NODE *head;// points to the sll
};
typedef struct list LIST;

void init_list(LIST *ptr);
void insert_head(LIST *ptr, int data);
void display(LIST *ptr);
void insert_end(LIST *ptr, int data);
void insert_pos(LIST *ptr, int data, int pos);
int count_node_recur(NODE *cur);
int count_node(LIST *ptr);
void delete_node(LIST *ptr, int data);
void delete_pos(LIST *ptr, int pos);
void delete_alternate(LIST *ptr);
void print_reverse_recur(NODE *cur);
void print_reverse(LIST *ptr);
//int delete_rear(LIST *ptr);
void delete_rear(LIST *ptr);
void delete_front(LIST *ptr);
//int delete_front(LIST *ptr);
void orderlist(LIST *ptr, int ele);
void orderlistdes(LIST *ptr, int ele);
void search(LIST *ptr, int ele);
void sortAscending(LIST *ptr);
void sortDescending(LIST *ptr);
void delete_all(LIST *ptr);
void delete_duplicates(LIST *ptr);
void delete_duplicates_unsorted(LIST *ptr);
void delete_reverse(LIST *ptr);
void check_order(LIST *ptr);
void insert_after(LIST *ptr, int value, int data);
void insert_before(LIST *ptr, int value, int data);
void delete_after(LIST *ptr, int value);
void delete_before(LIST *ptr, int value);
void sum(LIST *ptr);
void search_all(LIST *ptr, int ele);

int main()
{
    LIST l;
    init_list(&l);
    int n, ch, pos;

    while (1)
    {
    	printf("\n");
    	display(&l);
    	printf("\n1..Insert at head\n");
    	printf("2..Insert at end\n");
    	printf("3..Display\n");
    	printf("4..Insert at a given position\n");
    	printf("5..Count number of nodes (recursion)\n");
    	printf("6..Delete node by value\n");
    	printf("7..Delete node at a given position\n");
    	printf("8..Delete alternate nodes\n");
    	printf("9..Print reverse order\n");
    	printf("10..Delete at rear\n");
    	printf("11..Delete at front\n");
    	printf("12..Insert in sorted order (ascending)\n");
    	printf("13..Insert in sorted order (descending)\n");
    	printf("14..Search element\n");
    	printf("15..Sort Ascending\n");
    	printf("16..Sort Descending\n");
    	printf("17..Delete all nodes\n");
    	printf("18..Delete duplicates (sorted list only)\n");
    	printf("19..Delete duplicates (unsorted)\n");
    	printf("20..Delete reverse order\n");
    	printf("21..Check order\n");
    	printf("22..Insert after a given value\n");
    	printf("23..Insert before a given value\n");
    	printf("24..Delete after a given value\n");
    	printf("25..Delete before a given value\n");
    	printf("26..Sum of all nodes\n");
    	printf("27..Search for all pos\n");
    	printf("28..Exit\n");
    	scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &n);
            insert_head(&l, n);
            break;
        case 2:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &n);
            insert_end(&l, n);
            break;
        case 3:
            display(&l);
            break;
        case 4:
            printf("\nEnter the element and position: ");
            scanf("%d %d", &n, &pos);
            insert_pos(&l, n, pos);
            break;
        case 5:
            printf("Counting nodes using recursion...\n");
            printf("Number of nodes = %d\n", count_node(&l));
            break;
        case 6:
            printf("Enter the element to be deleted: ");
            scanf("%d", &n);
            delete_node(&l, n);
            break;
        case 7:
            printf("\nEnter the position to delete: ");
            scanf("%d", &pos);
            delete_pos(&l, pos);
            break;
        case 8:
            delete_alternate(&l);
            break;
        case 9:
            printf("The nodes in reverse order:\n");
            print_reverse(&l);
            printf("\n");
            break;
        case 10:
        	//printf("Deleted rear node: %d\n", delete_rear(&l));
	        delete_rear(&l);
        	printf("Deleted rear node.\n");
        	printf("\n");
        	break;
        case 11:
        	delete_front(&l);
	        printf("Deleted front node.\n");
	        break;
        case 12:
        	printf("Enter data: ");
        	scanf("%d", &n);
        	orderlist(&l, n);
        	break;
        case 13:
        	printf("Enter data: ");
	        scanf("%d", &n);
	        orderlistdes(&l, n);
        	break;
        case 14:
        	printf("Enter element to search: ");
	        scanf("%d", &n);
	        search(&l, n);
	        break;
        case 15:
        	sortAscending(&l);
	        display(&l);
	        break;

        case 16:
        	sortDescending(&l);
	        display(&l);
	        break;

        case 17:
        	delete_all(&l);
	        printf("All nodes deleted.\n");
	        break;

        case 18:
        	delete_duplicates(&l);
	        printf("Duplicate nodes deleted (if any).\n");
	        break;

        case 19:
        	delete_duplicates_unsorted(&l);
	        printf("Duplicate nodes removed from unsorted list.\n");
	        break;

        case 20:
        	delete_reverse(&l);
        	printf("Deleted reverse order.\n");
        	break;

        case 21:
        	check_order(&l);
        	printf("checking order\n");
        	break;

        case 22: {
        	int value, data;
        	printf("Enter the value after which to insert: ");
        	scanf("%d", &value);
        	printf("Enter data to insert: ");
        	scanf("%d", &data);
        	insert_after(&l, value, data);
        	break;
        }

        case 23: {
        	int value, data;
        	printf("Enter the value before which to insert: ");
        	scanf("%d", &value);
        	printf("Enter data to insert: ");
        	scanf("%d", &data);
        	insert_before(&l, value, data);
        	break;
        }

        case 24: {
	        int value;
	        printf("Enter the value after which to delete: ");
	        scanf("%d", &value);
	        delete_after(&l, value);
	        break;
        }

        case 25: {
	        int value;
	        printf("Enter the value before which to delete: ");
	        scanf("%d", &value);
	        delete_before(&l, value);
	        break;
        }

        case 26: {
	        sum(&l);
        	break;
        }

        case 27:
        	printf("Enter the element to search: ");
        	scanf("%d", &n);
        	search_all(&l, n);
        break;

        case 28:
        	printf("Exiting program.\n");
			exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}

void search_all(LIST *ptr, int ele) {
	if (ptr->head == NULL) {   // check if list is empty
		printf("List is empty.\n");
		return;
	}

	NODE *cur = ptr->head;     // start from the first actual node
	int pos = 1;                      // position counter
	int found = 0;                     // flag if element exists

	while (cur != NULL) {             // traverse entire list
		if (cur->data == ele) {
			printf("Element %d found at position %d\n", ele, pos);
			found = 1;
		}
		cur = cur->link;              // move to next node
		pos++;
	}

	if (!found) {
		printf("Element %d not found in the list.\n", ele);
	}
}



void sum(LIST *ptr) {
	int sum=0;
	if (ptr->head == NULL) {
		printf("Empty list.\n");
		return;
	}
	NODE *cur=ptr->head;
	while (cur != NULL) {
		sum += cur->data;
		cur = cur->link;
	}
	printf("Sum of all nodes = %d\n", sum);
}

void sortAscending(LIST *ptr) {
	if (ptr->head == NULL || ptr->head->link == NULL) { // no node or only one node
		return; // empty or single node
	}

	NODE *i, *j;
	int temp;
	for (i = ptr->head; i->link != NULL; i = i->link) {
		for (j = i->link; j != NULL; j = j->link) {
			if (i->data > j->data) {
				// swap
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

void sortDescending(LIST *ptr) {
	if (ptr->head == NULL || ptr->head->link == NULL) {
		return;
	}

	NODE *i, *j;
	int temp;
	for (i = ptr->head; i->link != NULL; i = i->link) {
		for (j = i->link; j != NULL; j = j->link) {
			if (i->data < j->data) {
				// swap
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}


void search(LIST *ptr, int ele) {
	NODE *cur = ptr->head;
	int pos = 1;  // start from position 1

	while (cur != NULL) {
		if (cur->data == ele) {
			printf("Element %d found at position %d\n", ele, pos);
			return;
		}
		cur = cur->link;
		pos++;
	}

	printf("Element %d not found!\n", ele);
}

void init_list(LIST *ptr) //initialize ll
{
    ptr->head = NULL; //list is empty initially
}

void insert_head(LIST *ptr, int data) //keep inserting at front
{
    NODE *temp = (NODE *)malloc(sizeof(NODE)); //create node
    temp->data = data;
    temp->link = ptr->head; /*
	ptr->head currently points to the first node of the list (or NULL if the list is empty).
    By doing this, the new node’s link points to the current first node.
    This effectively inserts the new node before the existing nodes.*/
    ptr->head = temp; //Updates the head pointer of the list to point to the new node.
}

void display(LIST *ptr)
{
    NODE *cur = ptr->head;
    if (cur == NULL)
    {
        printf("\nEmpty list.\n");
        return;
    }
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}

void insert_end(LIST *ptr, int data) //keep inserting at end
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));// create node
    temp->data = data;
    temp->link = NULL;

    if (ptr->head == NULL) //list empty
    {
        ptr->head = temp;
        return;
    }

    NODE *cur = ptr->head; //list not empty, go to end of list ptr->head gives first element address
    while (cur->link != NULL) //keep traversing till end
        cur = cur->link;
    cur->link = temp;

}

void insert_pos(LIST *ptr, int data, int pos) //insert at particular position
{
    if (pos <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->link = NULL;

    if (pos == 1)
    {
        temp->link = ptr->head;
        ptr->head = temp;
        return;
    }

    NODE *cur = ptr->head;
    NODE *prev = NULL;
    int i = 1;

    while ((cur != NULL) && (i < pos))
    {
        prev = cur; //move previous to current node pointer to the current node*****
        cur = cur->link; //traversing
        i++;
    }

    if (i == pos)
    {
        prev->link = temp;
        temp->link = cur;
    }
    else
    {
        printf("Invalid position..\n");
        free(temp);
    }
}

int count_node(LIST *ptr)
{
    //return count_node_recur(ptr->head);

	//no recursion method
	if (ptr->head == NULL)
		return 0;
	NODE *cur = ptr->head;
	int count = 0;
	while (cur != NULL) { //or directly cur->link!=NULL
		cur = cur->link;
		count++;
	}
	return count;
}

/*
int count_node_recur(NODE *cur)
{
    if (cur == NULL)
        return 0;
    return 1 + count_node_recur(cur->link);
}
*/

void print_reverse(LIST *ptr)
{
    //print_reverse_recur(ptr->head);
	NODE *prev = NULL;
	NODE *cur = ptr->head;
	NODE *next = NULL;
	while (cur != NULL) {
		next = cur->link;
		cur->link = prev;
		prev = cur;
		cur = next;
	}
	ptr->head = prev;
}

/*
void print_reverse_recur(NODE *cur)
{
    if (cur == NULL)
        return;
    print_reverse_recur(cur->link);
    printf("%d -> ", cur->data);
}
*/

void delete_node(LIST *ptr, int data) //delete a particular node by value
{
    NODE *cur = ptr->head, *prev = NULL;

    while (cur != NULL && cur->data != data)
    {
        prev = cur;
        cur = cur->link;
    }

    if (cur == NULL)
    {
        printf("Node not found..\n");
        return;
    }

    if (prev == NULL) // deleting first node
        ptr->head = cur->link;
    else
        prev->link = cur->link;

    free(cur);
}

void delete_pos(LIST *ptr, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position..\n");
        return;
    }

    NODE *cur = ptr->head, *prev = NULL;
    int i = 1;

    while (cur != NULL && i < pos)
    {
        prev = cur;
        cur = cur->link;
        i++;
    }

    if (cur == NULL)
    {
        printf("Invalid position..\n");
        return;
    }

    if (prev == NULL)
        ptr->head = cur->link; // delete first node
    else
        prev->link = cur->link;

    free(cur);
}

void delete_front(LIST *ptr) {
	if (ptr->head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}

	NODE *temp = ptr->head;   // store current head
	ptr->head = ptr->head->link;  // move head to next node
	free(temp);               // free memory of old head
}

/*
int delete_front(LIST *ptr)
	{
	if (ptr->head == NULL)
		return 9999;
	else {
		NODE *first = ptr->head;
		NODE *second = first->link;
		int x;
		x=first->data;
		free(first);
		ptr->head = second;
		return(x);
	}
	}
	*/


void delete_alternate(LIST *ptr) //function deletes every second node in the linked list
{
    NODE *cur = ptr->head;
    NODE *temp; //temporary pointer to store the node to delete.

    while (cur != NULL && cur->link != NULL)
    {
        temp = cur->link;        // node to delete (next node to the first)
        cur->link = temp->link;  // unlink alternate node (Unlinks the node to delete by making cur point to the node after temp)
        free(temp);              // free memory
        cur = cur->link;         // move to next "kept" node
    }
}

/*
int delete_rear(LIST *ptr) {
	if (ptr->head == NULL)
		return 9999; // List empty

	NODE *cur = ptr->head;
	NODE *prev = NULL;
	int x;

	// If only one node
	if (cur->link == NULL) {
		x = cur->data;
		free(cur);
		ptr->head = NULL;
		return x;
	}

	// Traverse to the last node
	while (cur->link != NULL) {
		prev = cur;
		cur = cur->link;
	}

	x = cur->data;   // save data of last node
	prev->link = NULL; // unlink last node
	free(cur);       // free memory
	return x;
}
*/

void delete_rear(LIST *ptr) {
	if (ptr->head == NULL) {
		printf("List is empty. Nothing to delete.\n");
		return;
	}

	NODE *cur = ptr->head;
	NODE *prev = NULL;

	// If only one node
	if (cur->link == NULL) {
		free(cur);
		ptr->head = NULL;
		return;
	}

	// Traverse to last node
	while (cur->link != NULL) {
		prev = cur;
		cur = cur->link;
	}

	// cur is last node, prev is second-last
	prev->link = NULL;
	free(cur);
}

void orderlist(LIST *ptr, int ele) { //insert in a sorted array (ascending)
	NODE *temp = malloc(sizeof(NODE));
	temp->data = ele;
	temp->link = NULL;

	// Case 1: Empty list or insert at front
	if (ptr->head == NULL || ele < ptr->head->data) {
		temp->link = ptr->head;
		ptr->head = temp;
		return;
	}

	NODE *cur = ptr->head;
	NODE *prev = NULL;

	// Traverse until we find correct position
	while (cur != NULL && cur->data < ele) {
		prev = cur;
		cur = cur->link;
	}

	// Insert between prev and cur
	prev->link = temp;
	temp->link = cur;
}

void orderlistdes(LIST *ptr, int ele) {
	NODE *temp = malloc(sizeof(NODE));
	temp->data = ele;
	temp->link = NULL;

	// Empty or insert at front (if ele > head->data)
	if (ptr->head == NULL || ele > ptr->head->data) {
		temp->link = ptr->head;
		ptr->head = temp;
		return;
	}

	NODE *cur = ptr->head;
	NODE *prev = NULL;

	while (cur != NULL && cur->data > ele) { // Notice '>' instead of '<'
		prev = cur;
		cur = cur->link;
	}

	prev->link = temp;
	temp->link = cur;

}

void delete_all(LIST *ptr) {
	NODE *cur = ptr->head;
	NODE *temp;
	while (cur) {
		temp = cur;
		cur = cur->link;
		free(temp);
	}
	ptr->head = NULL;
}

void delete_duplicates(LIST *ptr) {
	NODE *cur = ptr->head;
	while (cur && cur->link) {
		if (cur->data == cur->link->data) {
			NODE *dup = cur->link;
			cur->link = dup->link;
			free(dup);
		} else {
			cur = cur->link;
		}
	}
}

void delete_reverse(LIST *ptr) {
	while (ptr->head != NULL) {
		delete_rear(ptr);  // delete last node
	}
}
/*
 void delete_reverse(LIST *ptr) {
    if (!ptr->head) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    NODE *cur;
    NODE *prev;

    while (ptr->head != NULL) {
        cur = ptr->head;
        prev = NULL;

        // Traverse to last node
        while (cur->link != NULL) {
            prev = cur;
            cur = cur->link;
        }

        // cur is last node, prev is second-last
        if (prev) {
            prev->link = NULL;
        } else {
            // Only one node in list
            ptr->head = NULL;
        }

        printf("Deleting node with value: %d\n", cur->data);
        free(cur);
    }
}
*/
void check_order(LIST *ptr) {
	if (!ptr->head || !ptr->head->link) {
		printf("List has 0 or 1 node. Considered sorted.\n");
		return;
	}

	NODE *cur = ptr->head;
	int ascending = 1;
	int descending = 1;

	while (cur->link) {
		if (cur->data < cur->link->data) {
			descending = 0;  // Not descending
		} else if (cur->data > cur->link->data) {
			ascending = 0;   // Not ascending
		}
		cur = cur->link;
	}

	if (ascending) {
		printf("List is in ascending order.\n");
	} else if (descending) {
		printf("List is in descending order.\n");
	} else {
		printf("List is unordered.\n");
	}
}

void delete_duplicates_unsorted(LIST *ptr) {
	if (!ptr->head) return;

	NODE *cur = ptr->head;
	while (cur != NULL) {
		NODE *runner = cur;
		while (runner->link != NULL) {
			if (runner->link->data == cur->data) {
				NODE *dup = runner->link;
				runner->link = dup->link;
				free(dup);
			} else {
				runner = runner->link;
			}
		}
		cur = cur->link;
	}
}

void insert_after(LIST *ptr, int value, int data) {
	NODE *cur = ptr->head;

	// search for the value
	while (cur != NULL && cur->data != value)
		cur = cur->link;

	if (cur == NULL) {
		printf("\nValue %d not found.\n", value);
		return;
	}

	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->data = data;
	temp->link = cur->link;
	cur->link = temp;
}

void insert_before(LIST *ptr, int value, int data) {
	// empty list
	if (ptr->head == NULL) {
		printf("\nList is empty.\n");
		return;
	}

	// if we insert before the head node
	if (ptr->head->data == value) {
		NODE *temp = (NODE *)malloc(sizeof(NODE));
		temp->data = data;
		temp->link = ptr->head;
		ptr->head = temp;
		return;
	}

	NODE *cur = ptr->head;
	// search for node before the target
	while (cur->link != NULL && cur->link->data != value)
		cur = cur->link;

	if (cur->link == NULL) {
		printf("\nValue %d not found.\n", value);
		return;
	}

	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->data = data;
	temp->link = cur->link;
	cur->link = temp;
}

void delete_after(LIST *ptr, int value) {
	if (ptr->head == NULL) {
		printf("\nList is empty.\n");
		return;
	}

	NODE *cur = ptr->head;
	while (cur != NULL && cur->data != value) {
		cur = cur->link;
	}

	if (cur == NULL) {
		printf("\nValue %d not found.\n", value);
		return;
	}

	if (cur->link == NULL) {
		printf("\nNo node exists after %d.\n", value);
		return;
	}

	NODE *temp = cur->link;
	cur->link = temp->link;
	printf("\nDeleted node with data %d after %d.\n", temp->data, value);
	free(temp);
}

void delete_before(LIST *ptr, int value) {
	if (ptr->head == NULL || ptr->head->link == NULL) {
		printf("\nList is too short.\n");
		return;
	}

	// case: delete head before value
	if (ptr->head->link->data == value) {
		NODE *temp = ptr->head;
		ptr->head = ptr->head->link;
		printf("\nDeleted node with data %d before %d.\n", temp->data, value);
		free(temp);
		return;
	}

	NODE *prev = NULL, *cur = ptr->head;

	while (cur->link != NULL && cur->link->data != value) {
		prev = cur;
		cur = cur->link;
	}

	if(cur->link == NULL) {
		printf("\nValue %d not found.\n", value);
		return;
	}

	if (prev == NULL) {
		printf("\nNo node exists before %d.\n", value);
		return;
	}

	prev->link = cur->link;
	printf("\nDeleted node with data %d before %d.\n", cur->data, value);
	free(cur);
}
