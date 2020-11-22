#include<stdio.h> 
#include<stdlib.h>
int queue[4],front=-1,rear=-1,max=4; 
void enqueue()
{
	if(rear==max-1) 
            printf("\nQueue is Full"); 
      else 
      { 
            
            if(front==-1&&rear==-1) 
            {
            	front=0,rear=0;
		}
            else rear++;   
		printf("\nEnter value :");   
            scanf("%d",&queue[rear]); 
            printf("\n%d is successfully added to the queue\n",queue[rear]);      
//            printf("\nFront=%d\n",front);
      }       
}
int dequeue()
{
	if(front>rear) 
      { 
      	return -1;
      } 
      else 
      {   
            return queue[front++];
      } 
}
void display()
{
	int i;
      if(front==-1||front>rear) 
            printf("\nQueue is Empty"); 
      else 
      { 
      	printf("\nQueue Elements are:\n"); 
            for(i=front; i<=rear; i++) 
            { 
                  printf("%d\n",queue[i]); 
                  
            } 
            printf("\n");
	}
}
void is_queue_empty()
{
	if(front>rear)
	{
		printf("\nThe Queue is Empty");
	}
	else
	{
		printf("\nThe Queue is not Empty");
	}
}

void is_queue_full()
{
	if(rear==max-1)
	{
		printf("\nThe Queue is Full");
	}
	else
	{
		printf("\nThe Queue is not Full");
	}
}

int peek()
{
	if(front>rear||rear==max) return -1;
	else return queue[front];
}

int main() 
{ 
	int choice,value; 
      while(choice) 
	{ 
	     	printf("\n----------MAIN MENU------------"); 
	    	printf("\n1. Insert element in Queue");
		printf("\n2. Delete element in Queue");
		printf("\n3. Display elements in Queue");
		printf("\n4. Check if Queue is empty");
		printf("\n5. Check if Queue is full");
		printf("\n6. Peek");
		printf("\n7. Exit"); 
	    	printf("\n-------------------------------");
     		printf("\nEnter the Choice:"); 
	      scanf("%d",&choice); 
	      switch(choice) 
	      { 
	      	case 1: 
	            	enqueue();
	            	break; 
	        	case 2: 
	            	value=dequeue();
	            	if(value!=-1) printf("\nDeleted Element is %d",value); 
	            	else printf("\nQueue is empty"); 
				break; 
	        	case 3: 
	        		display();
	            	break;
			case 4:
				 is_queue_empty();
				 break;
			case 5:
				 is_queue_full();
				 break;
			case 6:
				 value=peek();
				 if(value!=-1) printf("\nTop element is %d",value);
				 else printf("\nThe Queue is empty");
				 break;	 
	      	case 7: 
	                	exit(0); 
	            default: 
                		printf("Please select appropriate option"); 
            } 
      } 
      printf("\nThe program has ended");

    return 0; 

}

