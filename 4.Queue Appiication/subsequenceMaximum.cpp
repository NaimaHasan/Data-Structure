//finding max number among each subsequence

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,a[1000],inf=1000000,k;

	deque<int>q;
	scanf("%d %d", &n, &k);

	for(i = 1; i <= n; i++) scanf("%d", &a[i]);

	a[0]=-inf;
	q.push_back(0);

	for(i = 1; i <= n; i++)
	{
		while(!q.empty() && a[q.back()] <= a[i])
		q.pop_back();
			q.push_back(i);
	
		while(q.front() + k <= i)
			q.pop_front();
		printf("%d\n", a[q.front()]);
		
	}
}