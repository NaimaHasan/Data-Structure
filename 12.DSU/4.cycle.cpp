#include<bits/stdc++.h>
using namespace std;

struct DSU{
	int par[10005];
	int sz[10005];

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
		if(sz[root_u] < sz[root_v]){
			par[root_u] = root_v;
			sz[root_v] += sz[root_u];
		}
		else{
			par[root_v] = root_u;
			sz[root_u] += sz[root_v];
		}
	}

	bool isConnected(int u, int v)
	{
		return find_root(u) == find_root(v);
	}

	void init(int n)
	{
		for(int i=1; i<=n; i++){ 
			par[i] = i;
			sz[i] = 1;
		}
	}
};

int main()
{
	int n, m, u, v, fl = 1;
	DSU dsu;

	scanf("%d", &n);
	dsu.init(n);

	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &u, &v);
		if(dsu.isConnected(u, v))
			fl = 0;
		dsu.union_nodes(u, v);
	}

	if(fl) printf("No cycle");
	else printf("Cycle");

	return 0;
}