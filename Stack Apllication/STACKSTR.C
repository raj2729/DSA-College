#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node *next;
};
struct node *top;

void push(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=top;
	top=temp;
}
char pop()
{
	struct node *temp=top;
	top=top->next;
	return temp->data;
}
void reverse_string_by_stack(char c[],int l)
{
	int i;
	for(i=0;i<=l-1;i++)
	{
		push(c[i]);
	}
	for(i=0;i<=l-1;i++)
	{
		c[i]=pop();
	}
	printf("Reversed string is : %s",c);
}
void main()
{
	char c[100];
	int l;
	clrscr();
	printf("Enter a string : ");
	gets(c);
	l=0;
	while(c[l]!=0)
	{
		l++;
	}
	reverse_string_by_stack(c,l);
	getch();
}
