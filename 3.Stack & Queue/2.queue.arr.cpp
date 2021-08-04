#include<bits/stdc++.h>
using namespace std;

struct  myqueue
{
	int a[100],i,j,sz;

	myqueue()
	{
		i=j=sz=0;
	}

	void push(int val)
	{
		if(sz==100) return;

		a[j]=val;
		j++;

		if(j==100) j=0;

		sz++;
	}

	void pop()
	{
		if(sz==0) return;
		i++;
		if(i==100) i=0;
		sz--;
	}

	int peek()
	{
		return a[i];
	}
};

int main()
{
	myqueue b;
	b.push(100);
	b.push(200);
	b.pop();
	printf("%d\n",b.peek());
	return 0;
}