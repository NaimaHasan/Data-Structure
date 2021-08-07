//find the number of distinct values in the array.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n, array[100005], i, count = 0, check;

	scanf("%lld", &n);

	for(i = 0; i < n; i++) scanf("%lld", &array[i]);

	sort(array, array+n);

	check = array[0];
	count++;

	for(i = 1; i < n; i++)
		if(array[i] != check)
		{
			check = array[i];
			count++;
		}
	printf("%lld\n", count);
	return 0;
}
