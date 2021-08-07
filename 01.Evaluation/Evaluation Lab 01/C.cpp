// Given an integer N, and N integers, sort them in such an order so that all the non-negative numbers 
// come before all the negative numbers. The non-negative numbers should be sorted in increasing order 
// and the negative numbers should be sorted in decreasing order. 0 (zero) is considered a non-negative number.

#include <stdio.h>
#include <algorithm>
using namespace std;
bool comp (long long int a, long long int b)
{
	if(a<0 && b>=0) return false;
	if(a>=0 && b<0) return true;
	if(a>=0) return a<b;
	return a>b;
}

int main()
{
	long long int a[1000],n;
	int i;
      scanf("%lld", &n);
	  
	for(i=0;i<n;i++) scanf("%lld",&a[i]);

      sort(a,a+n,comp);

      for(i=0;i<n;i++) 
      {
      	if(i!=n-1) printf("%lld ",a[i]);
            else printf("%lld\n",a[i]);
      }
      return 0;
}