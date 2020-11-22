#include<stdio.h>
int stack[20];
int top = -1;
void push(int value)
{
	stack[++top]=value;
}
int pop()
{
	return stack[top--];
}
int main()
{
        char exp[20];
        int n1,n2,n3,num,i,l;
        printf("Enter prefix expression : ");
        gets(exp);
        l=0;
        while(exp[l]!=NULL) 
	  {
	  	l++;
	  }
        i=l-1;
        while(exp[i] != 0)
        {
                if(isdigit(exp[i]))
                {
                        num = exp[i] - 48;
                        push(num);
                }
                else
                {
                        n1 = pop();
                        n2 = pop();
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
                                    n3 = n1 / n2;
                                    break;
                                }
                        }
                        push(n3);
                }
                i--;
        }
        printf("\nThe result of prefix expression \" %s \" =  %d\n",exp,pop());
        return 0;
}
