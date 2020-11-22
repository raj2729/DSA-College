#include<stdio.h>  
#include<stdlib.h> 
struct node    
{   
    int data; 
    struct node *next;
};   
struct node *front;   
struct node *rear;    
void enqueue();   
void dequeue();   
void display(); 
int peek();  
int main ()   
{   
    int choice,value;    
    do   
    {      
    	  printf("\n---------Queue---------");
        printf("\n1. Insert an element");
	  printf("\n2. Delete an element");
	  printf("\n3. Display queue");
	  printf("\n4. PEEK");
	  printf("\n5. Exit");   
        printf("\nEnter your choice : ");   
        scanf("%d",& choice);   
        switch(choice)   
        {   
            case 1:   
            	enqueue();   
            	break;   
            case 2:   
            	dequeue();   
	            break;   
            case 3:   
	            display();   
	            break;   
	      case 4:
	      	value = peek();
	      	if(value!=-1) printf("\nTop Element is : %d",value);
	      	else printf("\nQueue is empty");
	      	break;
            case 5:     
	            exit(0);   
	            break;   
            default:    
	            printf("\nEnter valid choice ");   
        }   
    } while(choice != 5) ;
    printf("\nThe program has ended ");  
    return 0;
}   
void enqueue()   
{   
      struct node *temp;   
      int value;    
      temp = (struct node *) malloc (sizeof(struct node));    
      printf("\nEnter value to be inserted : ");   
      scanf("%d",&value);   
      temp -> data = value;   
      if(front == NULL)   
      { 
            rear = temp;       
		front=rear; 
      }   
      else    
      {   
            rear -> next = temp;   
            rear = temp;   
               
      }  
      printf("\n%d has been successfully inserted into queue",value);
	rear->next = NULL; 
     
}      
void dequeue()   
{   
	struct node *temp;   
	if(front == NULL)   
	{   
      	printf("\nQueue UNDERFLOW");   
      	return;   
	}   
	else    
	{   
      	printf("\nElement %d has been deleted\n",front->data); 
      	temp = front;   
		if(front->next==NULL)
		{
			front=NULL,rear=NULL;	
		}  
		else front=front->next;
      	free(temp);   
	}   
}   
void display()   
{   
	struct node *temp= front;   
	if(front == NULL)   
	{   
      	printf("\nQueue is empty");   
	}   
	else   
	{    
      	printf("\nElements in Queue are :\n");   
      	while(temp != NULL)    
      	{   
      		printf("%d\n",temp -> data);   
      		temp = temp -> next;   
      	} 
      	printf("\n"); 
	}  
}

int peek()
{
	if(front==NULL)
	{
		return -1;
	}
	else return front->data;
}
