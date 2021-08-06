#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
};

int dis[1000][1000],vi[1000][1000];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
node previous[1000][1000];

int bfs(char mat[][1000], int n , int m)
{
	node u,v,source,des;
	queue<node>q;
	memset(dis,0,sizeof(dis));
	memset(vi,0,sizeof(vi));
	memset(previous,0,sizeof(previous));

    source.x=0; source.y=0;
    des.x=n-1; des.y=m-1; 
	dis[source.x][source.y]=0;
	vi[source.x][source.y]=1;
	
	q.push(source);
    
    while(!q.empty())
    {
    	u=q.front(); q.pop();

		for(int i=0;i<4;i++)
    	{
    		v.x=u.x+dx[i];
    		v.y=u.y+dy[i];
    		if(v.x>=0 && v.x<n && v.y>=0 && v.y<m && mat[v.x][v.y]!=mat[u.x][u.y] && !vi[v.x][v.y])
    		{
    			q.push(v);
    			previous[v.x][v.y]=u;
    			dis[v.x][v.y]=dis[u.x][u.y]+1;
    			vi[v.x][v.y]=1;
    		}
    	}
    }
    return dis[des.x][des.y];
}

void printResults(int n,int m,char mat[][1000])
{
    int i,val,d[1000],a,b,temp;
    val=bfs(mat,n,m);
    if(val==0 && n!=1 && m!=1) printf("No shortest path found\n");
    else
    {
        printf("Shortest path length = %d\n",val);
        printf("Shortest path = ");

        a=n-1; b=m-1; d[0]=m-1; d[1]=n-1;
        for(i=2;i<2*(val+1);i=i+2)
        {
            d[i]=previous[a][b].y; d[i+1]=previous[a][b].x;
            temp=a;
            a=previous[a][b].x;
            b=previous[temp][b].y;
        }

        for(i=2*(val+1)-1;i>=0;i=i-2)
        {
           if(i==1) printf("(%d,%d)\n",d[i],d[i-1]);
           else printf("(%d,%d)->",d[i],d[i-1]);
        }
    }
   
}

void getInput(int n, char mat[][1000])
{
    int i;
    getchar();
    for(i=0;i<n;i++) fgets(mat[i],1000,stdin);

}


int main()
{
	int n,m;
	char mat[1000][1000];
    scanf("%d%d",&n,&m);
    getInput(n,mat);
    printResults(n,m,mat);
    return 0;
	
}

