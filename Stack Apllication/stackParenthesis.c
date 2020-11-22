#include<stdio.h>
#include<conio.h>
char stack[100];
int top=-1;

void push(char value)
{
	if(top==99)
		printf("\nStack Overflow");
	else
	{
		top+=1;
		stack[top]=value;
	}
}
char pop()
{
	int val;
	if(top==-1)
	{
		printf("\nThe Stack is empty");
//		return -1;
	}
	else
	{
		return stack[top--];
	}
}

int main()
{
	int l,i,flag=1;
	char temp;
	printf("\nEnter expression : ");
	gets(stack);
	l=0;
	while(stack[l]!=NULL)
	{
		l++;
	}
	for(i=0;i<=l-1;i++)
	{
		if(stack[i]=='('||stack[i]=='{'||stack[i]=='[')
		{
			push(stack[i]);
		}
		if(stack[i]==')'||stack[i]=='}'||stack[i]==']')
		{
			if(top==-1)
			{
				flag=0;
			}
			else
			{
				temp=pop();
				if(stack[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(stack[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(stack[i]==']' && (temp=='(' || temp=='{'))
					flag=0;
			}
		}
		
	}
//	if(top!=-1) 
//		flag=0;
	if(flag==0)
	{
		printf("\nParenthesis are not balanced");
	}
	else
	{
		printf("\nParenthesis are balanced");
	}
}



























