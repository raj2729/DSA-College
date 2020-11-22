#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],value,n,i,last;
	//clrscr();
	printf("Enter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter value : ");
		scanf("%d",&a[i]);
	}
	printf("\nEnter the value to be searched : ");
	scanf("%d",&value);
	last=a[n-1];
	a[n-1]=value;
	i=0;
	while(a[i]!=value)
	{
		i++;
	}
	a[n-1]=last;
	if(a[i]==value) printf("\nValue found at index %d",i);
	else printf("\nValue not found");
	//getch();
}















