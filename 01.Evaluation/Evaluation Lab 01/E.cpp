//Given an integer N, and N integers, find the frequency of distinct values in the array in increasing order of values.

#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long int n, array[100005], i, count = 0, current;
	bool hasPrinted = false;

        scanf("%lld", &n);

        for(i = 0; i < n; i++) scanf("%lld", &array[i]);

        sort(array, array+n);

	current = array[0];
        count++;

	for(i = 1; i < n; i++)
	{
		if(array[i] != current)
		{
			printf("%lld %lld\n", current, count);
			current = array[i];
			count = 1;
			hasPrinted = true;
		}
		else
		{
			hasPrinted = false;
			count++;
		}
	}

	if( !hasPrinted || count == 1) printf("%lld %lld\n", current, count);

        return 0;
}
