#include<stdio.h>
#include<conio.h>
int partition(int a[],int start,int end);
void quick_sort(int a[],int start,int end);
void sel_sort(int a[],int n);
int main()
{
	int a[100],n,i,j,temp,iMin,choice;
	//clrscr();
	printf("Enter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter value : ");
		scanf("%d",&a[i]);
	}
	printf("\n--------Sorting--------");
	printf("\n1. Selection Sort");
	printf("\n2. Quick Sort");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			sel_sort(a,n);
			printf("\nThe sorted array is :\n");
			for(i=0;i<=n-1;i++)
			{
				printf("%d\n",a[i]);
			}
			break;
		case 2:
			quick_sort(a,0,n-1);
			printf("\nThe sorted array is :\n");
			for(i=0;i<=n-1;i++)
			{
				printf("%d\n",a[i]);
			}
			break;
		default:
			printf("\nEnter a valid option");
	}
	printf("\nThe program has ended");
}

void sel_sort(int a[],int n)
{
	int i,j,iMin,temp;
	for(i=0;i<=n-1;i++)
	{
			iMin=i;
			for(j=i+1;j<=n-1;j++)
			{
				if(a[j]<a[iMin]) iMin=j;
			}
			temp=a[i];
			a[i]=a[iMin];
			a[iMin]=temp;
	}		
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

