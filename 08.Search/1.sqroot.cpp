#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	double low,high,mid;

	scanf("%lld",&n);
	low=1;
	high=n;

	while(high-low>0.000001)
	{
		mid = (low + high)/2;

		if(mid*mid > n) high = mid;

		else low = mid;
	}

	printf("%0.08f\n", low);
}