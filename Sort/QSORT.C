#include<stdio.h>
#include<conio.h>
int partition(int a[],int start,int end);
void quick_sort(int a[],int start,int end);
int main()
{
	int a[100],n,i;
	//clrscr();
	printf("Enter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter value : ");
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("\nThe sorted array is :\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	//getch();
}
int partition(int a[],int start,int end)
{
	int i,pivot=a[end],pindex=start,temp;
	for(i=start;i<=end-1;i++)
	{
		if(a[i]<pivot)
		{
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[pindex];
	a[pindex]=a[end];
	a[end]=temp;
	return pindex;
}
void quick_sort(int a[],int start,int end)
{
	int pindex;
	if(start>=end) return;
	pindex = partition(a,start,end);
	quick_sort(a,start,pindex-1);
	quick_sort(a,pindex+1,end);
}








