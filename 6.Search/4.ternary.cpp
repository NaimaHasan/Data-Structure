//Max area of a rectangle with fixed perimeter
//just divide by 4 man
#include<bits/stdc++.h>
using namespace std;

double k;

double func(double a)
{
	return a * ((k - 2*a)/2);
}

int main()
{
	double low, high, mid1, mid2, ans, i;

	scanf("%lf", &k);
	low = 0;
	high = k;

	for(i=0;i<100;i++)
	{
		mid1 = low + (high-low)/3;
		mid2 = high - (high-low)/3;

		double x = func(mid1);
		double y = func(mid2);

		if(x>y) high = mid2;
		else low = mid1;
	}

	printf("%lf\n", mid1);

	return 0;
}