#include<bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

queue<int>q;
int depth[1005][1005];
int color[1005][1005];
char grid[1005][1005];
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(int sx, int sy)
{
    int i,vx,vy,ux,uy;
    while(!q.empty()) q.pop();

    q.push(sx);
    q.push(sy);

    color[sx][sy] = GREY;
    depth[sx][sy] = 0;

    while(!q.empty())
    {
        ux = q.front();
        q.pop();

        uy = q.front();
        q.pop();

        for(i=0; i<4; i++)
        {
            vx = ux + dx[i];
            vy = uy + dy[i];

            if(vx>=0 && vx<n && vy>=0 && vy<m && grid[vx][vy]!='#' && color[vx][vy]==WHITE)
            {
                color[vx][vy]=GREY;
                depth[vx][vy]=depth[ux][uy]+1;
                q.push(vx);
                q.push(vy);
            }
        }
        color[ux][uy]=BLACK;
    }
    return depth[ux][uy];
}

int main()
{
    int t,u,v,i;

    scanf("%d%d",&n, &m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            color[i][j] = 0;
            depth[i][j] = 100000000;
        }

    for(int i=0; i<n; i++)
        scanf("%s",grid[i]);
    
    printf("%d\n",bfs(0,0));
}