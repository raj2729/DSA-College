#include<stdio.h>
#include<conio.h>
void main()
{
	int a[100],value,n,i,hole;
	clrscr();
	printf("Enter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter value : ");
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		value=a[i];
		hole=i;
		while(hole>0&&a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
	}

	printf("\nThe sorted array is :\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}