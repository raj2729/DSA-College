//For example, given an infix expression (A – B / C) * (A / K – L)

//STEP 1: Reverse the infix string. Note that while
//reversing the string you must interchange left
//and right parentheses.
//(L – K / A) * (C / B – A)

//STEP 2: Obtain the corresponding postfix expression of the infix 
//expression obtained as a result of Step 1.
//The expression is: (L – K / A) * (C / B – A)
//Therefore, [L – (K A /)] * [(C B /) – A]
//= [LKA/–] * [CB/A–]
//= L K A / – C B / A – *

//STEP 3: Reverse the postfix expression to get the
//prefix expression
//Therefore, the prefix expression is * – A / B
//C – /A K L
#include<stdio.h>
#include<string.h>

char infix[100], postfix[100], temp[100],stack[100];
int top=-1;

void push(char s[],char value)
{	
	s[++top] = value;
}

char pop(char s[])
{
    if(top == -1)
        return -1;
    else
        return s[top--];
}

void reverse(char str[])
{
	int len, i;
	len=strlen(str);
	for(i=len-1;i>=0;i--)
	{
		if (str[i] == '(')
			temp[len-1-i] = ')';
		else  if ( str[i] == ')')
			temp[len-1-i] = '(';
		else
			temp[len-1-i] = str[i];
	}
	temp[len] = NULL;
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

void InfixtoPostfix(char source[], char target[])
{
	int i=0, j=0;
	char temp;
	while(source[i]!=NULL)
	{
		if(source[i]=='(')
			{
				push(stack, source[i]);
				i++;
			}
		else if(source[i] == ')')
		{
			while((top!=-1) && (stack[top]!='('))
			{
				target[j] = pop(stack);
				j++;
			}
			i++;
		}
		else if(isalnum(source[i]))
		{
			target[j] = source[i];
			j++;
			i++;
		}
		else if(source[i]=='+'||source[i]=='–'||source[i]=='*'||source[i]=='/' || source[i] == '%')
		{
			while(top!=-1&&(priority(stack[top])>=priority(source[i])))
			{
				target[j] = pop(stack);
				j++;
		 	}
			push(stack, source[i]);
			i++;
		}
		else
		{
			printf("\n INCORRECT ELEMENT IN EXPRESSION");
//			exit(1);
			return;
		}
	}
	while(top!=-1)
	{
		target[j] = pop(stack);
		j++;
	}
	target[j]=NULL;
}

int main()
{
	int i,l;
	printf("Enter the expression : ");
	gets(infix);
	reverse(infix);
	InfixtoPostfix(infix, postfix);
	printf("\n The corresponding postfix expression is : %s",postfix);
	reverse(postfix);
	printf("\n The prefix expression is : %s",temp);
	return 0;
}

