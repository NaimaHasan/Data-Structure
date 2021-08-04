#include<bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;

queue<int>q;

int bfs(int s, int color[],vector<int> adj[],int depth[])
{
    int i,x,u;
    while(!q.empty()) q.pop();

    q.push(s);
    color[s]=GREY;

    while(!q.empty())
    {
        u=q.front();
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
    return depth[u];
}

int dfs(int s, int color[],vector<int> adj[]) {
    color[s]=GREY; 
    int k=0,i=0;
    int child=adj[s][i];
    if(color[child]==WHITE)
    {
        color[child]=GREY; 
        k = k + dfs(child,color,adj) + 1;
    }
    i=i+1;
    return k;
}




int main()
{
    int t,u,v,n,i,r,m,d,j;
    scanf("%d\n",&t);

    for(j=1;j<=t;j++)
    {
        r=0;
        vector<int> adj[50001];
        //int depth[50001]={0};
        int color[50001]={WHITE};

        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            
        }

        for(i=1;i<=n;i++)
        {
            d=dfs(i,color,adj);
            //memset(depth,0,sizeof(depth));
            memset(color,0,sizeof(color));
            if(d>r)
            {
                r=d;
                m=i;
            }
        }
        printf("Case %d: %d\n",j,m);

    }
}