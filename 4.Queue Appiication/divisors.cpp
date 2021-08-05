//Blazing fast
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, i, cnt, sq,x;
	queue<int> q,p;
	q.push(1);

	scanf("%d", &n);
	sq = sqrt(n);

	for(i = 2; i <= sq; i++)
	{
		cnt = 0;
		while(n % i == 0)
		{
			n /= i;
			cnt++;
		}
		if(cnt)
		{
			printf("%d %d\n",i,cnt);
			for(int j = i; cnt > 0; cnt--, j*=i)
			{
				for(int k = 0; k < q.size(); k++)
				{
					p.push(q.front() * j);
					q.push(q.front());
					q.pop();
				}
			}
			for(i = 0; i < p.size(); i++)
			{
				printf("%d ", p.front());
				p.push(p.front());
					p.pop();
			}
			printf("\n");
			for(int j = 0; j < p.size(); j++)
			{
				q.push(p.front());
				p.pop();
			}
			for(i = 0; i < q.size(); i++)
			{
				printf("%d ", q.front());
				q.push(q.front());
					q.pop();
			}
			printf("\n");
			//sq = sqrt(n);
		}
	}
	if(n > 1)
	{
		q.push(n);
	}
	// for(i = 0; i < q.size(); i++)
	// {
	// 	printf("%d ", q.front());
	// 	q.pop();
	// }
	return 0;
}