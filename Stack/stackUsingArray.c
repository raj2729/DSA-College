#include<stdio.h>
#include<conio.h>
void push(int data);
int pop();
int peek();
void display_stack();
int a[100],top=-1,max=100;
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
				break;
			case 3:
				value = peek();
				if(value!=-1) printf("\nThe top element is : %d",value);
				break;

			case 4:
				display_stack();
				break;
			
		}
	}while(option!=5);
	printf("\nThe program has ended");
	//getch();
}
void push(int value)
{
	if(top==max-1)
		printf("\nNo more elements can be inserted as the stack is full");
	else
	{
		top+=1;
		a[top]=value;
		printf("The value %d is pushed on stack",value);
	}
}
int pop()
{
	int val;
	if(top==-1)
	{
		printf("\nNo element can be deleted as the stack is empty");
		return -1;
	}
	else
	{
		val=a[top];
		top--;
		return val;
	}
}
int peek()
{
	if(top==-1)
	{
		printf("\nThe Stack is empty");
		return -1;
	}
	else return a[top];
}
void display_stack()
{
	int i;
	if(top==-1)
		printf("\nThe Stack is empty");
	else
	{
		printf("\nThe elements in Stack are :\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",a[i]);
		}
	}
}























