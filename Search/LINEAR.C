#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],value,n,i;
	clrscr();
	printf("Enter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter value : ");
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value to be searched : ");
	scanf("%d",&value);
	for(i=0;i<=n-1;i++)
	{
		if(a[i]==value)
		{
			break;
		}
	}
	if(i!=n) printf("\nValue found at index %d",i);
	else printf("\nValue not found");
	getch();
}















