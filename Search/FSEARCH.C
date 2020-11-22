#include<stdio.h>
#include<conio.h>
int fib_search(int a[],int n,int value);
int min(int x,int y);
int main()
{
	int a[100],value,n,count,i;
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
	count=fib_search(a,n,value);
	if(count==-1) printf("\nElement not found");
	else printf("\nElement found at index: %d",count);
	//getch();
}
int min(int x,int y)
{
	return (x<=y)? x : y; 
}
int fib_search(int a[],int n,int x)
{ 
    /* Initialize fibonacci numbers */
    
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No. 
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No. 
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci 
  
    /* fibM is going to store the smallest Fibonacci 
       Number greater than or equal to n */
    while (fibM < n) 
    { 
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM  = fibMMm2 + fibMMm1; 
    } 
  
    // Marks the eliminated range from front 
    int offset = -1;
    int count =0;
  
    /* while there are elements to be inspected. Note that 
       we compare arr[fibMm2] with x. When fibM becomes 1, 
       fibMm2 becomes 0 */
    while (fibM > 1) 
    { 
        count++;
        // Check if fibMm2 is a valid location 
        int i = min(offset+fibMMm2, n-1); 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray array from offset to i */
        if (a[i] < x) 
        { 
            fibM  = fibMMm1; 
            fibMMm1 = fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
            offset = i; 
        } 
  
        /* If x is greater than the value at index fibMm2, 
           cut the subarray after i+1  */
        else if (a[i] > x) 
        { 
            fibM  = fibMMm2; 
            fibMMm1 = fibMMm1 - fibMMm2; 
            fibMMm2 = fibM - fibMMm1; 
        } 
  
        /* element found. return index */
        else 
        {
            return i; 
        }
        
    } 
  
    /* comparing the last element with x */
    if(fibMMm1 && a[offset+1]==x)
    {
        return offset+1; 
    }
  else
  {
    /*element not found. return -1 */
    return -1; 
  }
} 

















