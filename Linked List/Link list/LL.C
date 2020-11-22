#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void create_ll();
void display_ll();
void insert_beginning();
void insert_end();
void insert_after();
void delete_node();
void search_value();
int main()
{
	int option;
	//clrscr();
	do
	{
		printf("\n------------------MAIN MENU------------------\n");
		printf("\n1 : Create a Linked List");
		printf("\n2 : Display the Linked List");
		printf("\n3 : Add a node at the beginning of Linked List");
		printf("\n4 : Add a node at the end of Linked List");
		printf("\n5 : Add a node after a node in the Linked List");
		printf("\n6 : Delete a given node in a Linked List");
		printf("\n7 : Search a value in the Linked List");
		printf("\n8 : EXIT");
		printf("\n---------------------------------------------");
		printf("\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				create_ll();
				printf("\nLinked list is successfully created\n");
				break;
			case 2:
				display_ll();
				break;
			case 3:
				insert_beginning();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_after();
				break;
			case 6:
				delete_node();
				break;
			case 7:
				search_value();
				break;
		}
	}while(option!=8);
	printf("\nThe program has ended");
	//getch();
}
void create_ll()
{
	struct node *new_node,*temp;
	int value,n,i;
	printf("\nEnter number of elements to be inserted : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter value : ");
		scanf("%d",&value);	
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data = value;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new_node;
			new_node->next=NULL;
		}
	}
}
void display_ll()
{
	struct node *temp=start;
	printf("\nThe Linked List is :\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void insert_beginning()
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to be inserted : ");
	scanf("%d",&new_node->data);
	new_node->next=start;
	start=new_node;
	printf("\nThe data is successfully inserted at the beginning\n");
}
void insert_end()
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	struct node *temp=start;
	printf("\nEnter the value to be inserted : ");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new_node;
	printf("\nThe data is successfully inserted at the end\n");
}
void insert_after()
{
	int value;
	struct node *temp=start,*previous;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value to be inserted : ");
	scanf("%d",&new_node->data);
	printf("\nEnter the value after which the data has to be inserted :");
	scanf("%d", &value);
	while(previous->next!=NULL&&previous->data!= value)
	{
		previous = temp;
		temp= temp->next;
	}
	if(previous->next!=NULL)
	{
		previous->next=new_node;
		new_node->next=temp;
		printf("\nThe data is successfully inserted\n");
	}
	else printf("\nThe data after which the element is to be inserted is not present in Linked List\n");
}
void delete_node()
{
	int value;
	struct node *temp=start,*previous;
	printf("Enter the data to be deleted : ");
	scanf("%d",&value);
	while(temp!=NULL&&temp->data!=value)
	{
		previous=temp;
		temp=temp->next;
	}
	if(temp==start)
	{
		start=start->next;
		free(temp);
	}
	else if(temp!=NULL)
	{
		previous->next=temp->next;
		free(temp);
		printf("\nThe data is successfully deleted\n");
	}
	else printf("\nValue not found . Try again\n");
}
void search_value()
{
	int value,count=0;
	struct node *temp=start;
	printf("\nEnter the value to be searched : ");
	scanf("%d",&value);
	while(temp!=NULL&&temp->data!=value)
	{
		count++;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("\nValue is not present in the linked list\n");
	}
	else
	{
		printf("\nValue found at position %d\n",count+1);
	}
}















