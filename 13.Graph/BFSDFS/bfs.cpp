#include<bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

queue<int>q;
vector<int> adj[10000];
int depth[10000]={0};
int color[10000]={WHITE};

void bfs(int s)
{
    int i,x;
    while(!q.empty()) q.pop();

    q.push(s);
    color[s]=GREY;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            int x=adj[u][i];
            if(color[x]==WHITE)
            {
                color[x]=GREY;
                depth[x]=depth[u]+1;
                q.push(x);
            }
        }
        color[u]=BLACK;
    }
}

int main()
{
    int t,u,v,n,m,i;

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(0);
}