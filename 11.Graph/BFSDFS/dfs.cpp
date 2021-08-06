#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2

vector<int> adjacent[10000];
int counting=0,n,m;
int previous_node[10000],color[10000];
int starting_time[10000],finishing_time[10000];
int time_;

void dfs_visit(int v)
{
    color[v]=GREY;
    time_++;
    starting_time[v]=time_;

    for(int w:adjacent[v])
    {
        if(color[w]==WHITE)
        {
            previous_node[w]=v;
            dfs_visit(w);
        }
       
    }
    color[v]=BLACK;
    time_++;
    finishing_time[v]=time_;
}

void dfs()
{
    for(int i=0;i<n;i++)
    {
        color[i]=WHITE;
        previous_node[i]=0;
        starting_time[i]=INT_MAX;
        finishing_time[i]=INT_MAX;
    }
    time_ = 0;
    
    for(int i=0;i<n;i++)
    {
        if(color[i]==WHITE)
            dfs_visit(i);
    }
}

void input()
{
    int i,u,v,w;
    scanf("%d %d", &n, &m);
    
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d", &u,&v);
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        
    }
}

int main()
{
    input();
    dfs();
    return 0;
}