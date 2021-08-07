#include<bits/stdc++.h>
using namespace std;

vector<int> g[100];

int main()
{
	int n,m,u,v,i,j,outd=0,ind=0;

	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) g[i].clear();

	while(m--)
	{
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	//whether u and v is directly connected
	sort(g[u].begin(),g[u].end());
	if(find(g[u].begin(),g[u].end(),v)) printf("Yes\n");
	else printf("No\n");

	//outdegree of u
	outd = g[u].size();

	//indegree of u
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			v = g[i][j];
			if(v == u) ind++;
		}
}