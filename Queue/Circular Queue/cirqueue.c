#include <stdio.h> 
#define MAX 5 
int cqueue[MAX],front = -1,rear = -1; 

void enqueue() 
{ 
	int value;
	if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) 
	{ 
      	printf("\nCircular Queue is full"); 
      	return; 
	} 
	else
	{
		printf("\nEnter data to be inserted : ");
	      scanf("%d", &value);
		if (front == -1) 
	    	{ 
	        	front = 0; 
	        	rear = 0; 
	        	cqueue[rear] = value; 
	    	} 
	    	else if (rear == MAX - 1&& front!=0) 
	    	{ 
	      	rear = 0; 
	        	cqueue[rear] = value; 
	
	    	} 
	    	else 
	      {
	      	rear = rear + 1;
	      	cqueue[rear] = value;
		}
	}
	
    	
} 
int dequeue() 
{ 
	int value;
    if (front == -1) 
    { 
        return -1;
    } 
    else
    {
	    value = cqueue[front]; 
	    if (front == rear) 
	    { 
	        front = -1; 
	        rear = -1; 
	    } 
	    else if (front == MAX - 1) 
	    { 
	        front = 0; 
	    } 
	    else 
	    {
	    	  front = front + 1;
	    }
	    return value;
	             
	}
} 
void display() 
{ 
    int front_position = front, rear_position = rear; 
    if (front == -1) 
    { 
        printf("\nCircular Queue is empty"); 
    } 
    else
    {
    
	    	printf("\nQueue elements are :\n"); 
	    	if (front_position <= rear_position) 
	    	{
	    
		      while (front_position <= rear_position) 
		    	{ 
		        	printf("%d\n", cqueue[front_position]); 
		        	front_position++; 
		    	} 
		}
	    else 
	    { 
	        while (front_position <= MAX - 1) 
	        { 
	            printf("%d\n", cqueue[front_position]); 
	            front_position++; 
	        } 
	        front_position = 0; 
	        while (front_position <= rear_position) 
	        { 
	            printf("%d\n", cqueue[front_position]); 
	            front_position++; 
	        } 
	    } 
	    printf("\n"); 
 	}
} 

//int peek()
//{
//	if(front==-1)
//	{
//		return -1;
//	}
//	else return cqueue[front];
//}

int main() 
{ 
    int choice,value; 
    do 
    { 
        printf("\n-------------Circular Queue-------------"); 
	  printf("\n1. Insert element into Circular Queue"); 
        printf("\n2. Delete element from Circular Queue");
        printf("\n3. Display Circular Queue"); 
//        printf("\n4. Top Element");
        printf("\n4. EXIT"); 
        printf("\nEnter your choice : "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
            case 1: 
                enqueue();
                break;
            case 2: 
                value=dequeue(); 
                if(value!=-1) 
		    		printf("\n%d has been successfully deleted",value);
		    	else printf("\nCircular Queue is empty");
                break; 
            case 3: 
                display(); 
                break; 
//            case 4: 
//            	value = peek();
//            	if(value!=-1) 
//		    		printf("\nTop Element is : %d",value);
//		    	else printf("\nCircular Queue is empty");
//                break; 
            default: 
                printf("\nEnter a valid choice");
        } 
    } 
    while (choice != 4); 
    printf("\nThe program has ended");
    return 0; 
}
