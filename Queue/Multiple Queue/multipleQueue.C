#include<stdio.h> 
#include<stdlib.h>
int queue[8],max=8; 
int fronta=-1,reara=-1,frontb=max,rearb=max;
void enqueue_a()
{
	if(reara==rearb-1) 
            printf("\nQueue is Full"); 
      else 
      { 
		if(fronta==-1&&reara==-1)
		{
			fronta=0,reara=0;	
		} 
		else reara++;   
		printf("\nEnter value :");   
            scanf("%d",&queue[reara]); 
            printf("\n%d is successfully added to the queue",queue[reara]);        
		
      }       
}
int dequeue_a()
{
	int value;
	if(fronta==-1||fronta>reara) 
      { 
      	return -1;
      } 
      else 
      {   
            value=queue[fronta];
            fronta++;
            if(fronta>reara) 
            {
            	fronta=-1,reara=-1;
		}
            return value;
      } 
}
void display_a()
{
	int i;
      if(fronta==-1||fronta>reara) 
            printf("\nQueue is Empty"); 
      else 
      { 
      	printf("\nQueue Elements are:\n"); 
            for(i=fronta; i<=reara; i++) 
            { 
                  printf("%d\n",queue[i]); 
                  
            } 
            printf("\n");
	}
}

void enqueue_b()
{
	if(rearb==reara+1) 
            printf("\nQueue is Full"); 
      else 
      { 
		if(frontb==max&&rearb==max)
		{
			frontb=max-1,rearb=max-1;	
		} 
		else rearb--;   
		printf("\nEnter value :");   
            scanf("%d",&queue[rearb]); 
            printf("\n%d is successfully added to the queue",queue[rearb]);        
		
      }       
}
int dequeue_b()
{
	int value;
	if(frontb==max||frontb<rearb) 
      { 
      	return -1;
      } 
      else 
      {   
            value=queue[frontb];
            frontb--;
            if(frontb<rearb) 
            {
            	frontb=max,rearb=max;
		}
            return value;
      } 
}
void display_b()
{
	int i;
      if(frontb==max||frontb<rearb) 
            printf("\nQueue is Empty"); 
      else 
      { 
      	printf("\nQueue Elements are:\n"); 
            for(i=frontb;i>=rearb;i--) 
            { 
                  printf("%d\n",queue[i]); 
                  
            } 
            printf("\n");
	}
}

int main() 
{ 
	int choice,value; 
      while(choice) 
	{ 
	     	printf("\n----------MAIN MENU------------"); 
	    	printf("\n1. Insert element in Queue A");
		printf("\n2. Delete element in Queue A");
		printf("\n3. Display elements in Queue A");
		printf("\n4. Insert element in Queue B");
		printf("\n5. Delete element in Queue B");
		printf("\n6. Display elements in Queue B");
		printf("\n7. Exit"); 
	    	printf("\n-------------------------------");
     		printf("\nEnter the Choice:"); 
	      scanf("%d",&choice); 
	      switch(choice) 
	      { 
	      	case 1: 
	            	enqueue_a();
	            	break; 
	        	case 2: 
	            	value=dequeue_a();
	            	if(value!=-1) printf("\n%d is successfully deleted from Queue A",value); 
	            	else printf("\nQueue A is empty"); 
				break; 
	        	case 3: 
	        		display_a();
	            	break;
			case 4: 
	            	enqueue_b();
	            	break; 
	        	case 5: 
	            	value=dequeue_b();
	            	if(value!=-1) printf("\n%d is successfully deleted from Queue B",value); 
	            	else printf("\nQueue B is empty"); 
				break; 
	        	case 6: 
	        		display_b();
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

