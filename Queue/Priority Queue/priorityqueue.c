#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data,priority;
	struct queue *next;
};
struct queue *front=NULL;
void insert()
{
	struct queue *newnode,*temp;
	newnode=(struct queue*) malloc(sizeof(struct queue));
	printf("\nEnter a value : ");
	scanf("%d",&newnode->data);
	printf("Enter priority : ");
	scanf("%d",&newnode->priority);
	temp=front;
	
	if(front==NULL ||newnode->priority  < front->priority )
	{
		newnode->next=front;
		front=newnode;
		
	}
	else
	{
		while(temp->next!=NULL&&temp->next->priority <= newnode->priority)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
int delete_queue()
{
	struct queue *temp;
	int value;
	if(front==NULL) return -1;
	else
	{
		temp=front;
		front=front->next;
		value=temp->data;
		free(temp);
		return value;
	}
	
}
void display()
{
	struct queue *temp;
	temp=front;
	if(front==NULL)
	{
		printf("\nThe Queue is empty");		
	}
	else
	{
	
		printf("\nThe elements of Queue are : \n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void main()
{
	int choice,value;
	do
	{
		printf("\n-----Priority Queue-----");
		printf("\n1. Insert element");
		printf("\n2. Delete element");
		printf("\n3. Display queue");
		printf("\n4. EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				value=delete_queue();
				printf("\n%d has been deleted successfully",value);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nThe program has ended");
				break;
			default:
				printf("\nEnter a valid choice");
		}
	}while(choice!=4);
}
