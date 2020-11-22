#include <stdio.h>
#include <conio.h>
int deque[10];
int left=-1,right=-1,max=10;
void input_deque();
void output_deque();
void insert_left();
void insert_right();
int delete_left();
int delete_right();
void display();
int main()
{
	int option;
	do
	{
		printf("\n-------Double Ended Queue(D Queue)-------");
		printf("\n1. Input restricted deque");
		printf("\n2. Output restricted deque");
		printf("\n3. EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				input_deque();
				break;
			case 2:
				output_deque();
				break;
		}
	}while(option!=3);
	printf("\nThe program has ended");
	return 0;
}
void input_deque()
{
	int choice,value;
	do
	{
		printf("\n-----Input Restricted Dequeue-----");
		printf("\n1. Insert at right");
		printf("\n2. Delete from left");
		printf("\n3. Delete from right");
		printf("\n4. Display Dequeue");
		printf("\n5. EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_right();
				break;
			case 2:
				value=delete_left();
				if(value!=-1) printf("\n%d is successfully deleted",value);
				else printf("\nQueue is empty");
				break;
			case 3:
				value=delete_right();
				if(value!=-1) printf("\n%d is successfully deleted",value);
				else printf("\nQueue is empty");
				break;
			case 4:
				display();
				break;
		}
	}while(choice!=5);
	
}
void output_deque()
{
	int choice,value;
	do
	{
		printf("\n-----Output Restricted Dequeue-----");
		printf("\n1. Insert at right");
		printf("\n2. Insert at left");
		printf("\n3. Delete from left");
		printf("\n4. Display");
		printf("\n5. EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_right();
				break;
			case 2:
				insert_left();
				break;
			case 3:
				value=delete_left();
				if(value!=-1) printf("\n%d is successfully deleted",value);
				else printf("\nQueue is empty");
				break;
			case 4:
				display();
				break;
		}
	}while(choice!=5);
}
void insert_right()
{
	int value;
	printf("\nEnter the value to be inserted from right :");
	scanf("%d", &value);
	if((left==0&&right==max-1||(right==left-1)))
	{
		printf("\nQueue is Full");
	}
	else
	{
		if(left==-1) 
		{
			left = 0;
			right = 0;
		}
		else if(right == max-1)
		{
			
			right = 0;
			
		}
		else
		{
			right+=1;
		}
		deque[right] = value ;
	}
}
void insert_left()
{
	int value;
	printf("\nEnter the value to be inserted :");
	scanf("%d", &value);
	if((left==0 && right==max-1)||(left== right+1))
	{
		printf("\nQueue is Full");
	}
	else
	{
		if (left==-1)
		{
			left = 0;
			right = 0;
		}
		else if(left == 0)
		{
			
			
			left=max-1;
		}
		else
		{
			left=left-1;
		}
		
		deque[left] = value;
	}
}
int delete_left()
{
	int value;
	if(left==-1)
	{
//		printf("\nQueue is Empty");
		return -1;
	}
	else
	{
	
//		printf("\nThe deleted element is : %d", deque[left]);
		value =  deque[left];
		if(left == right) // =>Only a single element is present
		{
			left=-1;
			right=-1;
		}
		else if(left==max-1)
		{
			
			
			left = 0;
		}
		else
		{
			left = left+1;
		}
		return value;
	}
}
int delete_right()
{
	int value;
	if(left==-1)
	{
//		printf("\nQueue is Empty");
		return -1;
	}
	else
	{
//	      printf("\nThe element deleted is : %d", deque[right]);
		value = deque[right];
		if(left == right) 
		{
			left=-1;
			right=-1;
		}
		else if(right == 0)
		{
			
			right=max-1;
		}
		else
		{
			right=right-1;
		}
		return value;
	}
}
void display()
{
	int front = left, rear = right;
	if(front==-1)
	{
		printf("\nQueue is empty");
	}
	else
	{
	
		printf("\nThe elements of the queue are :\n");
		if(front <= rear )
		{
			while(front <= rear)
			{
				printf("%d\n",deque[front]);
				front++;
			}
		}
		else
		{
			while(front<=max-1)
			{
				printf("%d\n", deque[front]);
				front++;
			}
			front = 0;
			while(front <= rear)
			{
				printf("%d\n",deque[front]);
				front++;
			}
		}
		printf("\n");
	}
}
