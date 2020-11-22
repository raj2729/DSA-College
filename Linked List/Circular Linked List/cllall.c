#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next; 
};

struct node *start=NULL;
void create_cll();
void display_cll();
void insert_beg();
void insert_end();
void insert_bef();
void insert_after();
void delete_beg();
void delete_end();
void delete_after();
void delete_cll();

int main()
{
	int option;
	//clrscr();
	do
	{
		printf("\n---------------------------MAIN MENU---------------------------\n");
		printf("\n 1 : Create a Circular Linked List");
		printf("\n 2 : Display the Circular Linked List");
		printf("\n 3 : Add a node at the beginning of Circular Linked List");
		printf("\n 4 : Add a node at the end of Circular Linked List");
		printf("\n 5 : Add a node before a value in Circular Linked List");
		printf("\n 6 : Add a node after a value in Circular Linked List");
		printf("\n 7 : Delete the node from the beginning in Circular Linked List");
		printf("\n 8 : Delete the node from the end in Circular Linked List");
		printf("\n 9 : Delete the node after a given node in Circular Linked List");
		printf("\n10 : Delete entire Circular Linked List");
		printf("\n11 : EXIT");
		printf("\n---------------------------------------------------------------");
		printf("\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				create_cll();
				printf("\nCircular Linked list is successfully created\n");
				break;
			case 2:
				display_cll();
				break;
			case 3:
				insert_beg();
				break;
			case 4:
				insert_end();			
				break;
			case 5:
				insert_bef();
				break;
			case 6:
				insert_after();
				break;
			case 7:
				delete_beg();
				break;
			case 8:
				delete_end();
				printf("\nThe data is successfully deleted from the end\n");
				break;
			case 9:
				delete_after();
				break;
			case 10:
				delete_cll();
				break;
		}
	}while(option!=11);
	printf("\nThe program has ended");
	//getch();
}

void create_cll()
{
	struct node *new_node,*temp=start;
	int n,i;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&new_node->data);
		new_node->next=start;
		if(temp==NULL)
		{
			start=new_node;
		}
		else
		{
			temp->next=new_node;
		}
		temp=new_node;
	}
}
void display_cll()
{
	struct node *temp=start;
	if(start==NULL)
	{
		printf("Circular Linked List is not created");
	}
	else
	{
		printf("\nThe circular linked list is :\n");
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
	struct node *temp=start,*new_node=(struct node*)malloc(sizeof(struct node));
 	printf("Enter the value to be inserted : ");	
	scanf("%d",&new_node->data);
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	new_node->next=start;
	start=new_node;
	temp->next=start;
	printf("\nThe data is successfully inserted at the beginning\n");
}

void insert_end()
{
	struct node *temp=start,*new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted : ");	
	scanf("%d",&new_node->data);
	new_node->next=start;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	printf("\nThe data is successfully inserted at the end\n");	
}

void insert_bef()
{
	int value;
	struct node *temp=start,*previous,*new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted : ");	
	scanf("%d",&new_node->data);
	printf("Enter value before which the data is to be inserted : ");
	scanf("%d",&value);
	if(start->data==value)
	{
		new_node->next=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		start=new_node;
		
	}
	else
	{
	
		while(temp->data!=value)
		{
			previous=temp;
			temp=temp->next;
		}
		new_node->next=temp;
		previous->next=new_node;
	}	
	printf("\nThe data is successfully inserted\n");	
}

void insert_after()
{
	int value;
	struct node *temp=start,*previous,*new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted : ");	
	scanf("%d",&new_node->data);
	printf("Enter value after which the data is to be inserted : ");
	scanf("%d",&value);
	
	while(previous->data!=value)
	{
		previous=temp;
		temp=temp->next;
	}
	new_node->next=temp;
	previous->next=new_node;
		
	printf("\nThe data is successfully inserted\n");	
}

void delete_beg()
{
	struct node *temp=start;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=start->next;
	free(start);
	start=temp->next;
	printf("\nThe data is successfully deleted from the beginning\n");
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
	free(temp);
	
}

void delete_after()
{
	int data;
	struct node *temp=start,*previous;
	printf("\nEnter the value after which the data is to be deleted : ");
	scanf("%d",&data);
	while(previous->data!=data)
	{
		previous=temp;
		temp=temp->next;
	}
	previous->next=temp->next;
	if(temp==start)
	{
		start=start->next;
	}
	free(temp);
	printf("\nThe data is successfully deleted\n");
}

void delete_cll()
{
	struct node *temp=start,*previous;
	if(start==NULL)
	{
		printf("Circular Linked List is not created");
	}
	else
	{
		while(temp->next!=start)
		{
			delete_end();
		}
		free(temp);
		start=NULL;
		printf("\nCircular Linked List is successfully deleted");
	}
	
}


