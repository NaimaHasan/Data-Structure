#include<bits/stdc++.h>
using namespace std;

int mat[100][100];

int main()
{
	int n,m,u,v,i,j,outd=0,ind=0;

	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) for(j=0; j<n; j++) mat[i][j]=0;

	while(m--)
	{
		scanf("%d%d", &u, &v);
		mat[u][v] = 1;
		mat[v][u] = 1;
	}

	//whether u and v is directly connected
	if(mat[u][v]) printf("Yes\n");
	else printf("No\n");

	//outdegree of u
	for(i=0; i<n; i++) outd += mat[u][i];

	//indegree of u
	for(i=0; i<n; i++) ind += mat[i][u];
}