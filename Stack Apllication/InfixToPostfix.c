#include<stdio.h>

char post[100];
int top = -1;

void push(char value)
{	
	post[++top] = value;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return post[top--];
}

int priority(char value)
{
    if(value == '(')
        return 0;
    if(value == '+' || value == '-')
        return 1;
    if(value == '*' || value == '/'|| value == '%')
        return 2;
    return 0;
}

int main()
{
	char exp[100];
	char x,temp;
	int i,l;
	printf("Enter the expression : ");
	gets(exp);
	printf("\nThe corresponding postfix expression is : ");
	l=0;
	while(exp[l]!=NULL)
	{
		l++;
	}
	for(i=0;i<=l-1;i++)
    	{
		if(isalnum(exp[i]))
			printf("%c ",exp[i]);
		else if(exp[i] == '(')
            	push(exp[i]);
		else if(exp[i] == ')')
		{
			while(top!=-1&&((x=pop())!='('))
			{
				printf("%c ", x);
			}		
		            		
      	}
      	else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='%')
      	{
	            while(top!=-1&&(priority(post[top]) >= priority(exp[i])))
	                printf("%c ",pop());
	            push(exp[i]);
      	}
      	else
      	{
      		printf("\nINVALID element in the expression");
				return;
		}
	}
    
	while(top != -1)
	{
		printf("%c ",pop());
	}
	return 0;
}
