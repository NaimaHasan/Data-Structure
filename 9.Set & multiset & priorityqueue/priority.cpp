#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<info> pq;
	int x;

	while(cin>>x)
	{
		pq.push(x);
	}

	while(!pq.empty())
	{
		cout<<pq.top().data<<endl;
		pq.pop();
	}

}