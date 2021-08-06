#include<bits/stdc++.h>
using namespace std;

struct info
{
	int data, p, id;
	info(){}
	info(int _data, int _p, int _id)
	{
		data = _data;
		p = _p;
		id = _id;
	}
	bool operator < (const info &x)const{
		return p < x.p ||(p == x.p && id > x.id);
	}
};

int main()
{
	priority_queue<info> pq;
	int x,y,i=1;
	info a[100];

	while(cin>>x>>y)
	{
		a[j++] = info(x,y,i);
		pq.push(info(x,y,i++));
	}

	while(!pq.empty())
	{
		cout<<pq.top().data<<" "<<pq.top().p<<" "<<pq.top().id<<endl;
		pq.pop();
	}

	sort(a, a+j);

	for(i=0; i<j; i++)
	{
		cout<<a[i].top().data<<" "<<a[i].top().p<<" "<<a[i].top().id<<endl;
	}

	//sort does the opposite order to priority queue
}