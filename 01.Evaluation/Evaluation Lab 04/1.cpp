// Given a sorted array with N elements, take Q queries. 
// Each query will give you X. You will have to find out how many times X occurs in the array. 

#include <bits/stdc++.h>

int * bound(int a[], int low, int high, int key)
{
	int mid, ans = 0;

	while(low <= high)
	{
		mid = (low+high)/2;

		if(a[mid] >= key)
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return &a[ans];
}

int main()
{
	int input[100], n, q, x, i, count;
	int *aPtr;

	scanf("%d", &n);

	for(i = 0; i < n; i++) scanf("%d", &input[i]);

	scanf("%d", &q);

	for(i = 0; i < q; i++)
	{
		scanf("%d", &x);
		count = 0;

		aPtr = bound(input, 0, n-1, x);

		while( *aPtr == x ){
			count++;
			aPtr++;
		}

		printf("%d\n", count);
	}

	return 0;
}

// #include<stdio.h>
// #include <bits/stdc++.h>
// using namespace std;

// int find(int a[], int low, int high, int x)
// {
// 	long long int ans=-1,mid;
// 	while(low<=high)
// 	{
// 		mid=(low+high)/2;
// 		if(a[mid]<x) low=mid+1;
// 		else if(a[mid]>x) high=mid-1;
// 		else 
// 		{
// 			ans=mid;
// 			high=mid-1;
// 		}
		
// 	}
// 	return ans;
// }

// int main()
// {
// 	int a[10000],n,q,c,i,m,j,k=0;
// 	scanf("%d%d",&n,&q);
// 	for(i=0;i<n;i++) scanf("%d",&a[i]);
// 	for(i=0;i<q;i++)
// 	{
// 	    	scanf("%d",&c);
// 	    	m=find(a,0,n-1,c);
// 	    	for(j=m;j<n;j++)
// 	    	{
// 	    		if(a[j]==c) k++;
// 	    		if(a[j]!=c) break;
// 	    	}
// 	    	printf("%d occurs %d times\n",c,k);

	    
// 	}
// 	return 0;
// }
