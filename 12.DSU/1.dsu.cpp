#include<bits/stdc++.h>
using namespace std;

int par[1000001];

int find_root(int u)
{
	if(u == par[u]) return u;
	return par[u] = find_root(par[u]);
}

void union_nodes(int u, int v)
{
	int root_u = find_root(u);
	int root_v = find_root(v);
	if(root_u == root_v) return;
	par[root_u] = root_v;
}

void init(int n)
{
	for(int i=1; i<=n; i++) par[i] = i;
}

int main()
{
	int n,m,u,v,q,fl=0;
	scanf("%d",&n);
	init(n);
	scanf("%d",&m);

	while(m--)
	{
		scanf("%d%d",&u, &v);
		if(find_root(u) == find_root(v)) fl = 1;
		union_nodes(u,v);
	}
}