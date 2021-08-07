#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *next, * prev;
	node()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}

	node(int _data, node *_next)
	{
		data = _data;
		next = _next;
		prev = NULL;
	}

	node(int _data, node * _next, node * _prev)
	{
		data = _data;
		next = _next;
		prev = _prev;
	}
};

struct doubleLinkedList
{
	node *head, *tail;

	doubleLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertFirst(int data)
	{
		node *tmp = new node(data, head);

		if(head) head->prev = tmp;
		head = tmp;

		if(!tail) tail = tmp;
	}

	void insertLast(int data)
	{
		node *tmp = new node( data, NULL, tail );
		if(tail) tail->next = tmp;
		tail = tmp;

		if(!head) head = tmp;
	}
};

struct DSU{
	int par[10005];
	int sz[10005];
	doubleLinkedList lst[10005];

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
			lst[root_v].tail->next = lst[root_u].head;
			lst[root_u].head->prev = lst[root_v].tail;
			lst[root_v].tail = lst[root_u].tail;
			lst[root_u].head = lst[root_v].head;
		}
		else{
			par[root_v] = root_u;
			sz[root_u] += sz[root_v];
			lst[root_u].tail->next = lst[root_v].head;
			lst[root_v].head->prev = lst[root_u].tail;
			lst[root_u].tail = lst[root_v].tail;
			lst[root_v].head = lst[root_v].head;
		}
	}

	bool isConnected(int u, int v)
	{
		return find_root(u) == find_root(v);
	}

	void printSet(int u)
	{
		node *cur = lst[find_root(u)].head;

		// printf("ooga");

		while(cur != NULL){
			printf("%d ", cur->data);
			cur = cur->next;
		}

		printf("\n");
	}

	void init(int n)
	{
		for(int i=1; i<=n; i++){ 
			par[i] = i;
			sz[i] = 1;
			lst[i].insertFirst(i);
		}
	}
};

int main()
{
	int n, m, u, v, q;
	DSU dsu;

	scanf("%d", &n);
	dsu.init(n);

	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &u, &v);
		dsu.union_nodes(u, v);
	}

	scanf("%d", &q);

	dsu.printSet(q);
	// printf("ooga\n");

	return 0;
}