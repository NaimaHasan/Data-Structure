#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a[10000],x,low,high,mid,ans,i;

	scanf("%d",&n);
	low=1;
	high=n;

	for(i=0;i<n;i++) scanf("%d",&a[i]);

	scanf("%d",&x);

	while(low<=high)
	{
		mid = (low + high)/2;

		if(a[mid]<x) low = mid+1;

		else 
		{
			ans = a[mid];
			high = mid-1;
		}
	}

	printf("%d\n", ans);
}