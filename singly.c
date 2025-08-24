//
// Created by disha on 24-08-2025.
//
/* WAP to insert_front, insert_end, delete_front, delete_end and display the content of list*/
#include<stdio.h>
#include<stdlib.h> /* Dynamic memory allocation like, malloc, calloc, realloc, and free*/
/* node definition*/
typedef struct node
{
 int data; /* holds value*/
 struct node *link; /*holds the address of next node*/
} NODE;

NODE *create_node(int value)
{
    /* create a temp node and allocate memory*/
 struct node *temp=(NODE*)malloc(sizeof(NODE));
 temp->data=value;
 temp->link=NULL;
 return temp;

}

void insert_front(int value, NODE **start) /* callled func*/
{
  struct node *temp=create_node(value);
  if(*start==NULL) /*list is empty*/
  *start=temp;
  else
  {
  temp->link=*start;
  *start=temp;
  }
}
/*Insert a node at the end/ appending a node*/
void insert_end(int value, NODE **start)
{
  NODE *temp=create_node(value);
  if(*start==NULL)
  {
    *start=temp;
  }
  else
  {
    NODE *current=*start;
    while(current->link!=NULL)
    {
      current=current->link;
    }
    current->link=temp;
  }
}

void delete_end(NODE **start)
{
  if(*start==NULL)
  {
    printf("The list is empty");

  }
  else if((*start)->link==NULL) /* one ele in a list*/
  {
   printf("The deleted ele is %d\n", (*start)->data);
   free(*start);
   *start=NULL;
  }
  else
  {
    NODE *current=*start;
    while(current->link->link!=NULL)
    {
      current=current->link;
    }
    printf("The del ele is %d\n", current->link->data);
    free(current->link);
    current->link=NULL;
  }
}
void delete_front(NODE **start)
{
struct node *temp;
int value;
if(*start==NULL)
printf("The list is empty\n");
else
{
    temp=*start;
    *start=(*start)->link;
    printf("The deleted element is %d", temp->data);
    free(temp);
    return;
}
}
void display(NODE *start)
{
  if(start==NULL)
  printf("The list is empty");
  else
  {
    printf("The elements in the list are\n");
    while(start!=NULL)
    {
      printf("\t%d", start->data);
      start=start->link;
    }
  }
}

int  search(int value, NODE *start)
{
  int position=1;
  while(start!=NULL)
  {
    if(start->data==value)
    return position;
    start=start->link; /* go to the next node*/
    position++;   /* increment the ptr*/
  }
 return -1; /* if the ele is not found*/
}
int main()
{
 int choice, value;
 NODE *start=NULL; /* NODE* start=NULL*/
 printf("Enter the choice\n1) Insert_front \n2) Delete_front \n3) Insert_end \n4) Delete_end  \n5) Display \n6) Search");
 while(1)
 {
 printf("\nEnter the choice\n");
 scanf("%d", &choice);
 switch(choice)
 {
  case 1: printf("Enter the value\n");
          scanf("%d", &value);
          insert_front(value, &start); /*calling function*/
          break;
  case 2: delete_front(&start);
          break;
  case 3: printf("Enter the value\n");
          scanf("%d", &value);
          insert_end(value, &start); /*calling function*/
          break;
  case 4: delete_end(&start);
          break;
  case 5: display(start);
          break;
  case 6: printf("Enter the value");
          scanf("%d", &value);
          int pos=search(value, start); /*calling function*/
          if(pos!=-1)
          printf("The element %d is found at %d\n", value, pos);
          else
          printf("The element %d not is found the list", value);
          break;

  default: printf("Invalid choice\n");
           exit(1);
 }
 }
 return 0;
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

// Check if the list is in ascending order
int isAscending(LIST *ptr) {
if (!ptr->head || !ptr->head->link) return 1; // 0 or 1 node is considered ascending

NODE *cur = ptr->head;
while (cur->link) {
if (cur->data > cur->link->data) return 0; // violation
cur = cur->link;
}
return 1;
}

// Check if the list is in descending order
int isDescending(LIST *ptr) {
if (!ptr->head || !ptr->head->link) return 1; // 0 or 1 node is considered descending

NODE *cur = ptr->head;
while (cur->link) {
if (cur->data < cur->link->data) return 0; // violation
cur = cur->link;
}
return 1;
}

// Check the order and print result
void checkOrder(LIST *ptr) {
if (isAscending(ptr)) {
printf("List is in ascending order.\n");
} else if (isDescending(ptr)) {
printf("List is in descending order.\n");
} else {
printf("List is unordered.\n");
}
}
*/

