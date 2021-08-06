#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
};

int dis[100][100], vi[100][100];
node previ[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(node source, node dest, char mat[][1000], int n, int m){
	queue<node> q;
	node u, v;

	memset(dis, 0, sizeof(dis));
	memset(vi, 0, sizeof(vi));
	memset(previ, 0, sizeof(previ));
	
	q.push(source);
	dis[source.x][source.y] = 0;
	vi[source.x][source.y] = 1;   

	while(!q.empty()){
		u = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];

			if(v.x >= 0 && v.x < n && v.y >= 0 && v.y < m && mat[v.x][v.y] != mat[u.x][u.y] && !vi[v.x][v.y]){
				q.push(v);
				dis[v.x][v.y] = dis[u.x][u.y] + 1;
				vi[v.x][v.y] = 1;
				previ[v.x][v.y] = u;
			}
		}
	}

	return dis[dest.x][dest.y];
}

void printPath(node start, node n){
	if(previ[n.x][n.y].x == start.x && previ[n.x][n.y].y == start.y)
		printf("(%d, %d) -> (%d, %d) ", start.x, start.y, n.x, n.y);
	else{
		printPath(start, previ[n.x][n.y]);
		printf("-> (%d, %d) ", n.x, n.y);
	}
}

int main(){
	char matrix[1000][1000];
	int n, m, length;
	node start, end;

	scanf("%d %d", &n, &m);
	start.x = 0; start.y = 0;
	end.x = n-1; end.y = m-1;

	getchar();
	for(int i = 0; i < n; i++){
		fgets(matrix[i], 1000, stdin);
	}

	/*for(int i = 0; i <n; i++){
		for(int j = 0; j < m; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}*/



	length = bfs(start, end, matrix, n, m);

	printf("Shortest path length = %d\n", length);

	printf("Shortest path = ");
	printPath(start, end);
	printf("\n");

	return 0;
}