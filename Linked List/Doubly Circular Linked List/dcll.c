#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data; 
      struct node *next; 
    	struct node *pre; 
};

struct node *start=NULL;
void create_dcll();
void display_dcll();
void insert_beg();
void insert_end();
//void insert_bef();
//void insert_after();
void delete_beg();
void delete_end();
void delete_node();
void delete_dcll();

int main()
{
	int option;
	//clrscr();
	do
	{
		printf("\n---------------------------MAIN MENU---------------------------\n");
		printf("\n 1 : Create a Doubly Circular Linked List");
		printf("\n 2 : Display the Doubly Circular Linked List");
		printf("\n 3 : Add a node at the beginning of Doubly Circular Linked List");
		printf("\n 4 : Add a node at the end of Doubly Circular Linked List");
//		printf("\n 5 : Add a node before a value in Doubly Circular Linked List");
//		printf("\n 6 : Add a node after a value in Doubly Circular Linked List");
		printf("\n 5 : Delete the node from the beginning in Doubly Circular Linked List");
		printf("\n 6 : Delete the node from the end in Doubly Circular Linked List");
//		printf("\n 9 : Delete the node after a given node in Doubly Circular Linked List");
		printf("\n 7 : Delete the node a given node in Doubly Circular Linked List");
		printf("\n 8 : Delete entire Doubly Circular Linked List");
		printf("\n 9 : EXIT");
		printf("\n---------------------------------------------------------------");
		printf("\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				create_dcll();
				printf("\nDoubly Circular Linked list is successfully created\n");
				break;
			case 2:
				display_dcll();
				break;
			case 3:
				insert_beg();
				break;
			case 4:
				insert_end();			
				break;
			case 5:
				delete_beg();
				printf("\nThe data is successfully deleted from the beginning");
				break;
			case 6:
				delete_end();
				printf("\nThe data is successfully deleted from the end\n");
				break;
			case 7:
				delete_node();
				break;
			case 8:
				delete_dcll();
				break;
		}
	}while(option!=9);
	printf("\nThe program has ended");
	//getch();
}

void create_dcll()
{
	struct node *newnode,*temp=start;
	int n,i;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->next=start;
		if(temp==NULL)
		{
	            newnode->pre=NULL;
			start=newnode;
		}
		else
		{
			
			newnode->pre=temp;
			temp->next=newnode;
			start->pre=newnode;
		}
		temp=newnode;
	}
}
void display_dcll()
{
	struct node *temp=start;
	if(start==NULL)
	{
		printf("\nDoubly Circular Linked List is not created");
	}
	else
	{
		printf("\nThe Doubly Circular linked list is :\n");
		while(temp->next!=start)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);
	}
}

void insert_beg()
{
	struct node *temp=start,*newnode=(struct node*)malloc(sizeof(struct node));
 	printf("Enter the value to be inserted : ");	
	scanf("%d",&newnode->data);
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	newnode->pre=temp;
	newnode->next=start;
	start->pre=newnode;
	start=newnode;
	temp->next=start;
	printf("\nThe data is successfully inserted at the beginning\n");
}

void insert_end()
{
	struct node *temp=start,*newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted : ");	
	scanf("%d",&newnode->data);
	newnode->next=start;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->pre=temp;
	start->pre=newnode;
	printf("\nThe data is successfully inserted at the end\n");	
}

//void insert_bef()//For Circular Linked List
//{
//	int value;
//	struct node *temp=start,*previous,*new_node=(struct node*)malloc(sizeof(struct node));
//	printf("Enter the value to be inserted : ");	
//	scanf("%d",&new_node->data);
//	printf("Enter value before which the data is to be inserted : ");
//	scanf("%d",&value);
//	if(start->data==value)
//	{
//		new_node->next=start;
//		while(temp->next!=start)
//		{
//			temp=temp->next;
//		}
//		temp->next=new_node;
//		start=new_node;
//		
//	}
//	else
//	{
//	
//		while(temp->data!=value)
//		{
//			previous=temp;
//			temp=temp->next;
//		}
//		new_node->next=temp;
//		previous->next=new_node;
//	}	
//	printf("\nThe data is successfully inserted\n");	
//}
//
//void insert_after()//For Circular Linked List
//{
//	int value;
//	struct node *temp=start,*previous,*new_node=(struct node*)malloc(sizeof(struct node));
//	printf("Enter the value to be inserted : ");	
//	scanf("%d",&new_node->data);
//	printf("Enter value after which the data is to be inserted : ");
//	scanf("%d",&value);
//	
//	while(previous->data!=value)
//	{
//		previous=temp;
//		temp=temp->next;
//	}
//	new_node->next=temp;
//	previous->next=new_node;
//		
//	printf("\nThe data is successfully inserted\n");	
//}

void delete_beg()
{
	struct node *temp=start,*previous;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=start->next;
	free(start);
	start=temp->next;
	start->pre=temp;
	
}

void delete_end()
{
	struct node *temp=start,*previous;
	while(temp->next!=start)
	{
		previous=temp;
		temp=temp->next;
	}
	previous->next=start;
	start->pre=previous;
	free(temp);	
}

//void delete_after()//For Circular Linked List
//{
//	int data;
//	struct node *temp=start,*previous;
//	printf("\nEnter the value after which the data is to be deleted : ");
//	scanf("%d",&data);
//	while(previous->data!=data)
//	{
//		previous=temp;
//		temp=temp->next;
//	}
//	previous->next=temp->next;
//	if(temp==start)
//	{
//		start=start->next;
//	}
//	free(temp);
//	printf("\nThe data is successfully deleted\n");
//}

void delete_node()
{
	int data;
	struct node *temp=start,*previous;
	printf("\nEnter the data is to be deleted : ");
	scanf("%d",&data);
	while(temp->next!=start&&temp->data!=data)
	{
		previous=temp;
		temp=temp->next;
	}
	if(temp->next==start)
	{
		printf("%d not found\n",data);
	}
	else
	{
		if(temp==start)
		{
			start->pre->next=start->next;
			start=start->next;
		}
		else
		{
			previous->next=temp->next;
			temp->next->pre=previous;
		}
		free(temp);
		printf("\nThe data is successfully deleted");
	}
}

void delete_dcll()
{
	struct node *temp=start,*previous;
	if(start==NULL)
	{
		printf("\nDoubly Circular Linked List is not created");
	}
	else
	{
		while(temp->next!=start)
		{
			delete_end();
		}
		free(temp);
		start=NULL;
		printf("\nDoubly Circular Linked List is successfully deleted");
	}
	
}


