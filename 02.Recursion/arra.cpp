#include<stdio.h>


void scan(int i, int j, int n, int a[][100])
{
	scanf("%d",&a[i][j]);
	if(i==n-1 && j==n-1) return;
	if(j==n-1) 
	{
		j=0; 
		scan(i+1,j,n,a);
	}
	else scan(i,j+1,n,a);
}


void print(int i, int j, int n, int a[][100])
{
	printf("%d ",a[i][j]);
	if(i==n-1 && j==n-1) return;
	if(j==n-1) 
	{
		j=0; 
		printf("\n");
		print(i+1,j,n,a);
	}
	else print(i,j+1,n,a);
}

void add(int i, int j, int n, int a[][100],int b[][100])
{
	printf("%d ",a[i][j]+b[i][j]);
	if(i==n-1 && j==n-1) return;
	if(j==n-1) 
	{
		j=0; 
		printf("\n");
		add(i+1,j,n,a,b);
	}
	else add(i,j+1,n,a,b);
}


int main()
{
	int a[100][100],n=2,i,j,b[100][100],k=1;
	//for(i=0;i<n;i++) for(j=0;j<n;j++) {a[i][j]=k; k++;}
	//for(i=0;i<n;i++) for(j=0;j<n;j++) b[i][j]=a[i][j];
	scan(0,0,n,a);
	scan(0,0,n,b);
	add(0,0,n,a,b);
	printf("\n");
	print(0,0,n,a);
}