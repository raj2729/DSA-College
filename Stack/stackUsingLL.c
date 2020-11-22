#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void push(int data);
int pop();
int peek();
void display_stack();
int main()
{
	int option,value;
	do
	{
		printf("\n------------------MAIN MENU------------------");
		printf("\n1 : PUSH");
		printf("\n2 : POP");
		printf("\n3 : PEEK");
		printf("\n4 : Display Stack");
		printf("\n5 : EXIT");
		printf("\n---------------------------------------------");
		printf("\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the value to be pushed on stack : ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				value=pop();
				if(value!=-1) printf("\nThe value deleted from the stack is : %d",value);
				else printf("\nThe stack is empty");
				break;
			case 3:
				value = peek();
				if(value!=-1) printf("\nThe top element is : %d",value);
				else printf("\nThe stack is empty");
				break;

			case 4:
				display_stack();
				break;
			
		}
	}while(option!=5);
	printf("\nThe program has ended");
}
void push(int data)
{
	struct node *temp=start;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=start;
	start=newnode;
	newnode->data=data;
}
int pop()
{
	struct node *temp=start;
	int temp1;
	if(temp==NULL)
	{
		return -1;
	}
	else
	{
		start=start->next;
		temp1=temp->data;
		free(temp);
		return temp1;
	}
		
}
int peek()
{
	if(start==NULL) return -1;
	else return start->data;
}
void display_stack()
{
	struct node *temp=start;
	printf("\nThe Stack elements are :\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
