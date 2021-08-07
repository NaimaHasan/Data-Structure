#include<stdio.h>
int main()
{
	int a[1000],n,i,j,t;
	scanf("%d",&n);

	for(i=0;i<n;i++) scanf("%d",&a[i]);

	for(i=0;i<n-1;i++){
                for(j=0;j<n-1-i;j++){
        	       if(a[j]>a[j+1])
        	       {
        		      t=a[j];
        		      a[j]=a[j+1];
        		      a[j+1]=t;
        	       }
                }
	}
}

//best case O(n); worst case O(n^2)
//compares two consecutive elements and swaps.
//as a result after going through loop each time the largest element gets to last


//so the loop invariant condition is that at the end of i iteration right most i elements are sorted and in place

// Stable: Yes