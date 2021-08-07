#include<bits/stdc++.h>
using namespace std;

void print_q(queue<int> x){
	for(int i = 0; i < x.size(); i++)
	{
		printf("%d ", x.front());
		x.push(x.front());
		x.pop();
	}
	printf("\n");
}

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
			// printf("%d %d\n",i,cnt);
			for(int j = i; cnt > 0; cnt--, j*=i)
			{
				for(int k = 0; k < q.size(); k++)
				{
					p.push(q.front() * j);
					q.push(q.front());
					q.pop();
				}
			}

			while(!p.empty())
			{
				q.push(p.front());
				p.pop();
			}
			// sq = ceil(sqrt(n)) + 1;
		}
	}

	if(n > 1)
	{
		for(int k = 0; k < q.size(); k++)
		{
			p.push(q.front() * n);
			q.push(q.front());
			q.pop();
		}

		while(!p.empty())
		{
			q.push(p.front());
			p.pop();
		}
	}

	sort(q);

	print_q(q);

	return 0;
}