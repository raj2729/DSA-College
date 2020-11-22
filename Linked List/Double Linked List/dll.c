# include <stdio.h>
# include <stdlib.h>
struct node 
{ 
    int data; 
    struct node *next; 
    struct node *pre;  
}; 
struct node *start=NULL;
void create ()
{
	struct node *temp=start,*newnode;
	int val,n,i;
	printf("\nHow many values you want to enter : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
        	newnode=(struct node *) malloc (sizeof(struct node));
    		printf("Enter data : ");
    		scanf("%d",&newnode->data);
        	if (start == NULL)
        	{
	            newnode->next=NULL;
	            newnode->pre=NULL;
	            start=newnode;
	            temp=newnode;
	      }
	      else
	      {
	            temp->next=newnode;
	            newnode->pre=temp;
	            newnode->next=NULL;
	            temp=newnode;
	      }
	}
	printf("\nThe Doubly Linked List is successfully created");
}
void display()
{
    struct node *temp; 
    temp=start; 
    printf("The Double Linked List is : \n");
    while (temp!=NULL) 
    { 
        printf("%d\n",temp->data); 
        temp=temp->next; 
    }
}
void insert_beg()
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node)); 
	printf("\nEnter the value to be added in the beginning : "); 
	scanf("%d",&newnode->data); 
	newnode->next=start;
	newnode->pre=NULL;
	start=newnode;
	printf("\nThe data has been successfully added");
}
void insert_end()
{
	struct node *temp,*previous,*newnode=(struct node *)malloc(sizeof(struct node)); 
	temp=start;
	printf("\nEnter the value to be added in the end : "); 
	scanf("%d",&newnode->data); 
	newnode->next=NULL;
	while(temp->next!=NULL)
	{
		previous=temp;
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->pre=previous;
	printf("\nThe data has been successfully added");
}
void insertafter()
{
	struct node *temp,*p,*newnode; 
	int num; 
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter the value to be added: "); 
	scanf("%d",&newnode->data); 
	printf("\nEnter the node after which you want to add: "); 
	scanf("%d",&num); 
	 
	temp=start; 
	while (temp->next!=NULL&&temp->data!=num) 
	{ 
		temp=temp->next; 
	}
	if(temp->next==NULL)
	{
		printf("The entered data %d could not be found in the list",num); 
	}
	else
	{
		p=temp->next;
		newnode->next=p;
		newnode->pre=temp;
		temp->next=newnode;
		if(p != NULL)
		      p->pre=newnode;
		printf("\nThe data has been successfully added");
	}
}
void insertbefore()
{
    	struct node *temp,*p,*newnode; 
    	int num,val; 
    	printf("\nEnter the value to be added: "); 
    	scanf("%d",&val); 
    	printf("\nEnter the node before which you want to add: "); 
    	scanf("%d",&num); 
    	newnode=(struct node *)malloc(sizeof(struct node)); 
    	newnode->data=val; 
    	temp=start;
     	while (temp->next!=NULL&&temp->data != num)
     	{
        	p=temp;
        	temp=temp->next;
     	} 
     	if(temp->next==NULL)
     	{
    		printf("The entered data %d could not be found in the list",num); 
     	} 
     	else
     	{
	    if(temp==start)
	    {
	        newnode->next=temp;
	        temp->pre=newnode;
	        newnode->pre=NULL;
	        start=newnode;
	    }
	    else
	    {
	        newnode->next=temp;
	        temp->pre=newnode;
	        newnode->pre=p;
	        p->next=newnode;
	    } 
	    printf("\nThe data has been successfully added");
	}
}
void delete_after()
{
	struct node *temp=start,*previous=start;
	int value; 
	if(temp==NULL)
	{
		printf("\nThe doubly linked list is empty");
	}
	else
	{
		printf("\nEnter the node after which you want to delete : "); 
	    	scanf("%d",&value);
		while(previous!=NULL&&previous->data!=value)
		{
			previous=previous->next;
		}
		if(previous->data!=value&&previous->next==NULL)
		{
			printf("The entered data %d could not be found in the list",value); 
		}
		else
		{
			temp=previous->next;
			previous->next=temp->next;
			temp->next->pre=previous;
			free(temp);
			printf("\nThe data has been successfully deleted");
		}
	}
}
void delete_before()
{
	struct node *temp=start,*previous;
	int value; 
	if(temp==NULL)
	{
		printf("\nThe doubly linked list is empty");
	}
	else
	{
	
		printf("\nEnter the node before which you want to delete : "); 
	    	scanf("%d",&value);
		while(temp!=NULL&&temp->data!=value)
		{
			temp=temp->next;
		}
		if(temp->next==NULL)
		{
			printf("The entered data %d could not be found in the list",value); 
		}
		else
		{
			previous=temp->pre;
			temp->pre=previous->pre;
			previous->pre->next=temp;
			free(previous);
			printf("\nThe data has been successfully deleted");
		}
	}
	
}
void delete_beg()
{
	struct node *temp=start;
	if(temp==NULL)
	{
		printf("\nThe doubly linked list is empty");
	}
	else
	{
		start=start->next;
		start->pre=NULL;
		free(temp);
		printf("\nThe data has been successfully deleted");
	}
}
void delete_end()
{
	struct node *temp=start,*previous;
	if(temp==NULL)
	{
		printf("\nThe doubly linked list is empty");
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		previous=temp->pre;
		previous->next=NULL;
		free(temp);
		printf("\nThe data has been successfully deleted");
	}
}
void delete_dll()
{
	struct node *temp=start;
	if(temp==NULL)
	{
		printf("\nThe doubly linked list is empty");
	}
	else
	{
		while(start->next!=NULL)
		{
			temp=start;
			start=start->next;
			start->pre=NULL;
			free(temp);
		}
		temp=start;
		free(temp);
		start=NULL;
		printf("\nThe doubly linked list is successfully deleted");
	}
}
void delete_value()
{
    struct node *temp,*previous;
    int val;
    printf("\nEnter the value to be deleted: ");
    scanf("%d",&val);
    temp=start;
    while (temp != NULL && temp->data != val)
    {
        temp=temp->next;
    } 
    if(temp==NULL)
        printf("\nThe doubly linked list is empty");
    else if(temp==start)
    {
        temp->next->pre=NULL;
        start=temp->next;
        free(temp);
    }
    else
    {
        previous=temp->pre;
        previous->next=temp->next;
        if(temp->next!=NULL)
            temp->next->pre=previous;
        free(temp);
    } 
    printf("\nThe data has been successfully deleted");
}
void main() 
{ 
	int ch; 
	    
	do 
	{ 
        printf("\n------------------DOUBLY LINKED LIST----------------");
	  printf("\n 1. Create Double Linked List");
	  printf("\n 2. Display Double Linked List");
	  printf("\n 3. Insert node in the beginning Double Linked List");
	  printf("\n 4. Insert node in the end Double Linked List");
	  printf("\n 5. Insert node after a node in Double Linked List");
	  printf("\n 6. Insert node before a node Double Linked List");
	  printf("\n 7. Delete node after a node in Double Linked List");
	  printf("\n 8. Delete node before a node Double Linked List");
	  printf("\n 9. Delete node in the beginning Double Linked List");
	  printf("\n10. Delete node in the end Double Linked List");
	  printf("\n11. Delete a node in Double Linked List");
	  printf("\n12. Delete entire Linked List");
	  printf("\n13. Exit\n"); 
        printf("\nEnter your choice: ");
        scanf("%d",&ch); 
        switch (ch) 
        { 
            case 1: 
                create(); 
                break; 
            case 2: 
                display(); 
                break; 
            case 3:
            	insert_beg();
            	break;
            case 4:
            	insert_end();
            	break;
            case 5: 
                  insertafter(); 
                  break; 
            case 6: 
                  insertbefore(); 
                  break; 
            case 7:
            	delete_after();
            	break;
            case 8:
            	delete_before();
            	break;
            case 9:
            	delete_beg();
            	break;
            case 10:
            	delete_end();
            	break;
            case 11: 
            	delete_value(); 
            	break; 
            case 12:
            	delete_dll();
            	break;
        } 
    } while (ch !=13 ); 
    printf("The program has been ended");
}
