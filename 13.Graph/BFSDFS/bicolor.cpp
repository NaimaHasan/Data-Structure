#include<bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

queue<int>q;

bool bfs(int s, int color[],vector<int> adj[],int depth[])
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
            else if (depth[x]==depth[u]) return false;
        }
        color[u]=BLACK;
    }
    return true;

}

int main()
{
    int t,u,v,n,m,i;
    while(1)
    {
        vector<int> adj[10000];
        int depth[10000]={0};
        int color[10000]={WHITE};
        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(bfs(0,color,adj,depth)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }

}