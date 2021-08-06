#include<bits/stdc++.h>
using namespace std;

struct info
{
	int data, p;
	info(){}
	info(int _data, int _p)
	{
		data = _data;
		p = _p;
	}
	bool operator < (const info &x)const{
		return p < x.p;
	}
};

int main()
{
	priority_queue<info> pq;
	int x,y;

	while(cin>>x>>y)
	{
		pq.push(info(x,y));
	}

	while(!pq.empty())
	{
		cout<<pq.top().data<<" "<<pq.top().p<<endl;
		pq.pop();
	}

}