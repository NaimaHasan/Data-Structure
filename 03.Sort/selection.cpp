#include<stdio.h>
int main()
{
	int a[1000],n,i,j,t,min;
    //int inversion;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);


    for (i=0;i<n-1;i++) 
    {

    	min=i;

    	for(j=i+1;j<n-1;j++)
    	{
    		if(a[j]<a[min]) 
            {
                min=j;
                //inversion++;
            }
    	}

        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }

}

//best case O(n^2); worst case O(n^2)
//selects the first element as minimum. 
//finds if any element next is smaller than the selected element.
//if smaller swaps the place of selected element and minimum element

//The loop invariant for selection sort is that the elements of the newly sorted array up to the current index, 
//a[0..i] will contain the i smallest elements of our original input, a[0..n-1]


//there are two loop invariant condition:
//1. In the outer loop, array is sorted for first i elements.
//2. In the inner loop, min is always the minimum value in A[i to j].