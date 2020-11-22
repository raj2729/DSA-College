#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coeff;
	int pow;
	struct node* next;
};

struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* start3 = NULL;

void create(struct node** poly);
void display(struct node* poly);
void add(struct node** result, struct node* first, struct node* second);

int main()
{
	printf("\nEnter First polynomial:\n");
	create(&start1);//SINCE , start1 will refer to NULL and then
	//we wont be able to create a linked list
	printf("\n\nEnter Second polynomial:\n");
	create(&start2);
	printf("\nFirst Polynomial expression is : ");
	display(start1);
	printf("\nSecond Polynomial expression is : ");
	display(start2);
	add(&start3, start1, start2);
	printf("\n\nAddition of given Polynomial Expressions is : ");
	display(start3);
	return 0;
}


void create(struct node **start)
{
	int c, p, choice;
	struct node *temp = (struct node*)malloc(sizeof(struct node)),*newnode;
	*start=temp;
	do{
		printf("\nEnter Coeffecient: ");
		scanf("%d", &c);
		printf("Enter its Power: ");
		scanf("%d", &p);
		temp->coeff = c;
		temp->pow = p;
		temp-> next = NULL;
		printf("\nEnter 1 to Add more terms or 0 to Stop : ");
		scanf("%d", &choice);
		if(choice==1)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			temp->next = newnode;
			temp = temp->next;
			temp->next = NULL;
		}
	}while(choice!=0);	
}

void display(struct node *temp)
{
	while(temp != NULL)
	{
		printf("%dx^%d", temp->coeff, temp->pow);
		temp = temp->next;
		if(temp != NULL)
			printf(" + ");
	}
	printf(" = 0\n");
}

void add(struct node** result, struct node* first, struct node* second)
{
 	struct node* temp = (struct node*)malloc(sizeof(struct node));
 	temp->next = NULL;
 	*result = temp;
 	while(first && second)
 	{
 		if(first->pow > second->pow)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}
 		else if(first->pow < second->pow)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 		else
 		{
 			temp->coeff = first->coeff + second->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 			second = second->next;
 		}

 		if(first && second)
 		{
 			temp->next = (struct node*)malloc(sizeof(struct node));
 			temp = temp->next;
 			temp->next = NULL;
 		}
 	}
 	while(first || second)
 	{
 		temp->next = (struct node*)malloc(sizeof(struct node));
 		temp = temp->next;
 		temp->next = NULL;
 			
 		if(first)
 		{
 			temp->coeff = first->coeff;
 			temp->pow = first->pow;
 			first = first->next;
 		}

 		else if(second)
 		{
 			temp->coeff = second->coeff;
 			temp->pow = second->pow;
 			second = second->next;
 		}
 	}
}
