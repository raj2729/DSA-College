#include<stdio.h>
int stack[20];
int top = -1;
void push(int value)
{
	if(top==99)
		printf("\nStack Overflow");
	else
	{
		top+=1;
		stack[top]=value;
	}
}
int pop()
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
        char exp[20];
        int n1,n2,n3,num,i;
        printf("Enter postfix expression : ");
        gets(exp);
        i=0;
        while(exp[i] != 0)
        {
                if(isdigit(exp[i]))
                {
                        num = exp[i] - 48;
                        push(num);
                }
                else
                {
                        n2 = pop();
                        n1 = pop();
                        switch(exp[i])
                        {
                                case '+':
                                {
                                    n3 = n1 + n2;
                    			break;
                                }
                                case '-':
                                {
                                    n3 = n1 - n2;
                                    break;
                                }
                                case '*':
                                {
                                    n3 = n1 * n2;
                                    break;
                                }
                                case '/':
                                {
                                    n3 = n1/n2;
                                    break;
                                }
                        }
                        push(n3);
                }
                i++;
        }
        printf("\nThe result of postfix expression \" %s \" =  %d\n",exp,pop());
        return 0;
}
