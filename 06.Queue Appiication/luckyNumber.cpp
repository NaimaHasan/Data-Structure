#include<bits/stdc++.h>
using namespace std;

int main()
{
	queue<int>q; 
	q.push(0);

	while(!q.empty())
	{
		int x=q.front();
		q.pop();

		if(x>=10000) break;
		if(x) printf("%d\n",x);

		int a = x*10 + 4;
		int b = x*10 + 7;

		q.push(a);
		q.push(b);
	}

}