//Dividing rectangle with max area
//see lecture unsure
#include<bits/stdc++.h>
using namespace std;

double k,d;

double func(double a)
{
	return a*(k-2*a)/2;
}

int main()
{
	double low,high,mid1,mid2,ans,i;

	scanf("%lf%lf",&d,&k);
	low=1;
	high=d;

	for(i=0;i<100;i++)
	{
		mid1 = low + (high-low)/3;
		mid1 = high - (high-low)/3;

		double x = func(mid1);
		double y = func(mid2);

		if(x>y) high = mid2;
		else low = mid1;
	}

	printf("%lf\n", mid1);
}