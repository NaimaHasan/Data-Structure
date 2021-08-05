//finding max number among each subsequence
//see lecture and fix
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,a[1000],inf=1000000,k=3;

	deque<int>q;
	scanf("%d",&n);

	for(i=1;i<=n;i++) scanf("%d", &a[i]);

	a[0]=-inf;
	q.push_front(0);

	for(i=0;i<n;i++)
	{
		while(a[q.back()<=a[i]])
			q.pop_back();
		q.push_back(i);
		
		while(q.front() + k < i)
			q.pop_front();
		printf("%d\n", a[q.front()]);
		
	}
}