#include<stdio.h>
int main()
{
	int a[1000],n,i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);


    for (i=0;i<n-1;i++) 
    {

    	j=i;
        t=a[j+1];

        while(j>=0 && a[j]>t)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=t;

    }
}

//best case O(n); worst case O(n^2)
//selects element starting from 1 to n one by one and goes backward till the element is smaller
//if the element is bigger then loop breaks. Then inserts the selected element to next spot

// loop invariant condition is that the subarray a[0 to i-1] is always sorted.

// Stable: Yes
