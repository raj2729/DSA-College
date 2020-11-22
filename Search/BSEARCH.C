#include<stdio.h>
#include<conio.h> 
int main()
{
	int a[100],value,n,i,beg,end,mid,found;
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
	beg=0,end=n-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(a[mid]==value)
		{
			printf("\nValue found at index %d(position %d)",mid,mid+1);
			found=1;
			break;
		}
		else if(value<a[mid]) end=mid-1;
		else beg=mid+1;

	}
	if(found!=1) printf("Value not found");
	//getch();
}















