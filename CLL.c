//
// Created by disha on 24-08-2025.
//
//program to implement circular singly linked list
//pointer points to the last node
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	 struct node *link;
};

typedef struct node NODE;

//last : pointer to last node
struct list
{
	NODE *last;
};

typedef struct list clist_t;

void init_list(clist_t *);
void insert_front(clist_t *, int);
void insert_end(clist_t*,int);
void delete_node(clist_t*, int);
void display(clist_t*);

int main()
{
	int ch,data,pos;
	clist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.Delete a node");
		printf("\n5..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the data...");
			             scanf("%d",&data);
						 insert_front(&l,data);
						 break;
			case 2:printf("\nEnter the data...");
			             scanf("%d",&data);
						 insert_end(&l,data);
						 break;
			case 3:display(&l);
			             break;

			case 4:printf("\nEnter the data...");
			             scanf("%d",&data);
						 delete_node(&l,data);
                         break;

			case 5:exit(0);
		}
	}
}

void init_list(clist_t * ptr)
{
	ptr->last=NULL;
}

void insert_front(clist_t *ptr, int data)
{
	  NODE *temp,*last;
	//create node and populate
		temp=(NODE*)malloc(sizeof(NODE));
        temp->data=data;
		temp->link=temp;

	    last =ptr->last;  //get the address the last node;

		if(last==NULL) //first node (no node)
		 ptr->last=temp;
		else
		{
			temp->link=last->link;
			last->link=temp;
		}
}

	void insert_end(clist_t *ptr, int data)
{
		NODE *temp,*last;

	//create node and populate

		temp=(NODE*)malloc(sizeof(NODE));
	    temp->data=data;
		temp->link=temp;

	    last =ptr->last;

	     if(last==NULL)  // if empty list
			 ptr->last=temp; // first node
		 else
		 {
			temp->link=last->link;  // link after the last node
			last->link=temp;
			ptr->last=temp; // make last point to new last node
		}

}

	  void display(clist_t* ptr)
	  {
		  NODE *pres, *last,*prev;
		  if(ptr->last==NULL)
			  printf("Empty List\n");
		  else
		  {
			  last=ptr->last; //copy last nodes address
			  pres=last->link; // point to the first node

			  while(pres!=last)
			  {
				  printf("%d ->",pres->data);
			     pres=pres->link;
			  }
			   printf("%d ",pres->data); // print the last node
		  }
	  }

	 void delete_node(clist_t* ptr, int  data)
	 {

		 NODE *last,*pres,*prev;
		 last=ptr->last; //copy addres of the last node
		 pres=last->link; //point to the first node
		 prev=last;


		 while((pres->data!=data)&&(pres!=last))
		 {
			 prev=pres;
			 pres=pres->link;
		 }
		 if(pres->data==data)
		 {
			 //if only one node ?
			 if(pres->link==pres)
				 ptr->last=NULL;
			 else
			 {
				 prev->link=pres->link;  // link the previous node to next node
				 if(pres==last)// if deleting last node
				   ptr->last=prev; // change last
			 }
            free(pres);
		 }
       else
           printf("data not found..\n");
	 }