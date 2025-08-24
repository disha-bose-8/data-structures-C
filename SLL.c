//
// Corrected Linked List Program - 24-08-2025
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
    	printf("11..Exit\n");
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
        	printf("Exit\n");
        	exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
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
    print_reverse_recur(ptr->head);
}

void print_reverse_recur(NODE *cur)
{
    if (cur == NULL)
        return;
    print_reverse_recur(cur->link);
    printf("%d -> ", cur->data);
}

void delete_node(LIST *ptr, int data) //delete a particluar node by value
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



/*
 #include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct list
{
	node_t *head;
};
typedef struct list list_t;
void init_list(list_t*);
void delete_node(list_t *, int);
void insert_head(list_t *, int);
void insert_end(list_t*,int);
void insert_pos(list_t *, int,int);
void display(list_t *);
void delete_pos(list_t *, int);
int count_node(list_t *);
int count_node_recur(node_t*);
void print_reverse(list_t*);
void print_reverse_recur(node_t*);
//void delete_alternate(list_t *);

int main()
{
   list_t l;
   init_list(&l);
    int n,ch,pos;
   while(1)
   {
	   display(&l);
	   printf("\n1..Insert at head\n");
	   printf("2..Insert at end\n");
	   printf("3..display\n");
	   printf("4..Insert at a given position\n");
	   printf("5..Delete  node given its value\n");
	   printf("6..Delete  node given its position\n");
	   printf("7..count number of nodes-recursion\n");
	   printf("8..print the list in reverse\n");
	   printf("9..exit\n");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		   case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						 insert_head(&l,n);
						 break;
			case 2: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						 insert_end(&l,n);
						 break;
			case 3: display(&l);
			              break;

			case 4: printf("\nEnter the element and position ..");
						  scanf("%d %d",&n,&pos);
						  insert_pos(&l,n,pos);
                          break;
          case 5: printf("\nEnter the element to be deleted ..");
						scanf("%d",&n);
						  delete_node(&l,n);
                          break;
           case 6: printf("\nEnter the position of node ..");
						scanf("%d",&pos);
						  delete_pos(&l,pos);
                          break;
           case 7: printf("Count the no of nodes using recurion");
                        int k= count_node(&l);
						printf("\nthe number of nodes = %d\n",k);
                         break;
             case 8: printf("print the list in reverse");
                        print_reverse(&l);

                         break;
			case 9:exit(0);
	   }
   }
}

    void print_reverse(list_t *ptr)
	{
		print_reverse_recur(ptr->head);
	}


	void print_reverse_recur(node_t *cur)
	{
		if(cur->link!=NULL)
			print_reverse_recur(cur->link);
		printf("%d -> ",cur->key);
	}


int count_node(list_t *ptr)
 {
	 int count=0;
	 count=count_node_recur(ptr->head);
	 return count;
 }

 int  count_node_recur(node_t *cur)
 {
	 int count=0;
	if(cur->link==NULL)//only one node
      return 1;
    count=1+count_node_recur(cur->link);
	return count;
 }


  void delete_node(list_t *ptr, int data)
  {
	  node_t *cur, *prev;
	  prev=NULL;
	  cur=ptr->head;

	  //move forward until the node is found
	  //or you go beyond the list
	  while((cur!=NULL)&&(cur->key!=data))
	  {
	     prev=cur;
		 cur=cur->link;
	  }
	  if(cur!=NULL) //node  found
	  {
		  //if first node
		  if(prev==NULL) //it is the first node
			  ptr->head=cur->link;
			else
		      prev->link=cur->link;
	  }
	else
		printf("Node not found..\n");
	free(cur);
  }

   void insert_pos(list_t *ptr, int data, int pos)
   {
	   node_t *cur, *temp, *prev;
	   int i;
		//create node and populate
		temp=(node_t*)malloc(sizeof(node_t));
        temp->key=data;
		temp->link=NULL;

		i=1;
		prev=NULL;
		cur=ptr->head;
		//go to the desired position
		while((cur!=NULL) &&(i<pos))
		{
			i++;
			printf("i=%d\n",i);
			prev=cur;
			cur=cur->link;
		}
		if(cur!=NULL) //position is found some where between the first and last
		{
		   if(prev==NULL) //inserting in postion 1
		   {
			ptr->head=temp;
			temp->link=cur;
		}
		else//prev is not NULL, inserting node in the middle
		{
			temp->link=cur;
			prev->link=temp;
		 }
		}
		else // cur NULL
		{
			if(i==pos)//insert at the end
			  prev->link=temp;
			else
				printf("\nInvalid position..");
		}
   }


    void insert_end(list_t *ptr, int data)
	{
		node_t *cur, *temp;
		//create node and populate
		temp=(node_t*)malloc(sizeof(node_t));
        temp->key=data;
		temp->link=NULL;

		//is the list empty?

		if(ptr->head==NULL)
			ptr->head=temp;
		else
		{
			 //list not empty, go to end of list
			cur=ptr->head; //copy address of the first node
			while(cur->link!=NULL)
			    cur=cur->link;

			cur->link=temp;
		}
	}


     void display(list_t *ptr)
	 {
		 node_t *cur;
        //is list empty ?
		if(ptr->head==NULL)
		   printf("\nEmpty list.\n");
	   else
	   {
		   //copy the address of the first node
		   cur=ptr->head;
		   while(cur!=NULL)
		   {
			   printf("%d-->",cur->key);
			   cur=cur->link;
		   }
	   }
	 }

	void insert_head(list_t *ptr, int data)
	{
	    node_t *temp;
		temp=(node_t*)malloc(sizeof(node_t));
        temp->key=data;
		temp->link=NULL;

		//is list empty ?
		if(ptr->head==NULL)
			ptr->head=temp;
		else
		{
			temp->link=ptr->head;
			ptr->head=temp;
		}
	}

void init_list(list_t *ptr)
{
    ptr->head=NULL;
}

 void delete_alternate(list_t *ptr)
 {
	 node_t* cur, *prev;
	 cur=ptr->head;
	 prev=NULL;

	 while(cur!=NULL)
	 {
		 if(prev==NULL)
			 ptr->head=cur->link;
		 else
		     prev->link=cur->link;
		 prev=cur->link;
		 if(prev!=NULL)
		     cur=prev->link;
		 else
			 cur=NULL;
    }

 }

  void delete_pos(list_t *ptr, int pos)
  {

	  node_t *cur, *prev;
	  cur=ptr->head;
	  prev=NULL;

	  int i =1;
	  //move forward until the postion is found
	  while((cur!=NULL)&&(i<pos))
	  {
		  i++;
		  prev=cur;
		  cur=cur->link;
	  }

     if(cur!=NULL)//position found
     {
         //if first position
		 if(prev==NULL)
			 ptr->head=cur->link; //make head point to second node
		else // not the first node
           	prev->link=cur->link;
        free(cur);
     }
   else
	   printf("Invalid Position..\n");
  }

*/

