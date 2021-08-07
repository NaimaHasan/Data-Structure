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
	int i, n, m, u, v, qu, qv, fl = 1;
	DSU dsu;
	queue<pair<int, int>> input;

	scanf("%d", &n);
	dsu.init(n);

	scanf("%d", &m);
	for(i = 0; i < m; i++){
		scanf("%d %d", &u, &v);
		input.push(pair<int, int>(u,v));
	}

	scanf("%d %d", &qu, &qv);

	for(i = 0; i < m; i++){
		u = input.front().first;
		v = input.front().second;
		input.pop();

		if(u != qu || v != qv)
			dsu.union_nodes(u, v);
	}

	int countU = 0, countV = 0, rootQU = dsu.find_root(qu), rootQV = dsu.find_root(qv);

	if(rootQU == rootQV)
		printf("0\n");
	else {
		for(i = 1; i <= n; i++){
			if(dsu.find_root(i) == rootQU)
				countU++;
			else if(dsu.find_root(i) == rootQV)
				countV++;
		}
		printf("%d\n", countU * countV);
	}

	return 0;
}