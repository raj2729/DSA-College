#include<stdio.h>
#include<conio.h>
void push_a(int data);
int pop_a();
int peek_a();
void display_stack_a();
void push_b(int data);
int pop_b();
int peek_b();
void display_stack_b();

int stack[100],topb=100,topa=-1,max=100;

int main()
{
	int option,value;
	do
	{
		printf("\n------------------MAIN MENU------------------");
		printf("\n1 : PUSH element in A");
		printf("\n2 : POP element from A");
		printf("\n3 : PEEK element in A");
		printf("\n4 : Display Stack A");
		printf("\n5 : PUSH element in B");
		printf("\n6 : POP element from B");
		printf("\n7 : PEEK element in B");
		printf("\n8 : Display Stack B");
		printf("\n9 : EXIT");
		printf("\n---------------------------------------------");
		printf("\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the value to be pushed on stack A : ");
				scanf("%d",&value);
				push_a(value);
				break;
			case 2:
				value=pop_a();
				if(value!=-1) printf("\nThe value deleted from the Stack A is : %d",value);
				else printf("\nStack A is empty");
				break;
			case 3:
				value = peek_a();
				if(value!=-1) printf("\nThe top element in Stack A is : %d",value);
				else printf("\nStack A is empty");
				break;

			case 4:
				display_stack_a();
				break;
			case 5:
				printf("\nEnter the value to be pushed on stack B : ");
				scanf("%d",&value);
				push_b(value);
				break;
			case 6:
				value=pop_b();
				if(value!=-1) printf("\nThe value deleted from the stack B is : %d",value);
				else printf("\nStack B is empty");
				break;
			case 7:
				value = peek_b();
				if(value!=-1) printf("\nThe top element in Stack B is : %d",value);
				else printf("\nStack B is empty");
				break;
			case 8:
				display_stack_b();
				break;
			
		}
	}while(option!=9);
	printf("\nThe program has ended");
}
void push_a(int data)
{
	if(topa==topb-1)
	{
		printf("\nStack Overflow");
	}
	else
	{
		topa++;
		stack[topa]=data;
		printf("\nThe value %d is pushed on Stack A",data);
	}
}
void push_b(int data)
{
	if(topb==topa+1)
	{
		printf("\nStack Overflow");
	}
	else
	{
		topb--;
		stack[topb]=data;
		printf("The value %d is pushed on Stack B",data);
	}
}

int pop_a()
{
	int val;
	if(topa==-1)
	{
		return -1;	
	}
	else
	{
		val=stack[topa];
		topa--;
		return val;
	}
	
}
int pop_b()
{
	int val;
	if(topb==100)
	{
		return -1;	
	}
	else
	{
		val=stack[topb];
		topb++;
		return val;
	}
	
}
int peek_a()
{
	if(topa==-1)
	{
		return -1;
	}
	else
	{
		return stack[topa];
	}
}
int peek_b()
{
	if(topb==100)
	{
		return -1;
	}
	else
	{
		return stack[topb];
	}
}
void display_stack_a()
{
	int i;
	if(topa==-1)
		printf("\nStack A is empty");
	else
	{
		printf("\nThe elements in Stack A are :\n");
		for(i=topa;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}

void display_stack_b()
{
	int i;
	if(topb==100)
		printf("\nStack A is empty");
	else
	{
		printf("\nThe elements in Stack B are :\n");
		for(i=topb;i<=99;i++)//Since for 100 elements indexes are from 0-99
		{
			printf("%d\n",stack[i]);
		}
	}
}





