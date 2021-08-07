// In this problem, you are given a list of numbers L. After that there will be some queries:

// I X: means you need to insert the number X in the list.
// U X: means you need to find how many numbers greater than X are on the list L.
// L X: means you need to find how many numbers less than or equal to X are on the list L.


#include <bits/stdc++.h>
using namespace std;
struct node
{
	int r_size, l_size;
	node *left, *right;
	pair<int,int> val;
	node()
	{
		r_size=0;
		l_size=0;
		left=NULL;
		right=NULL;
	}

	node(pair<int,int> _val)
	{
		r_size=0;
		l_size=0;
		val=_val;
		left=NULL;
		right=NULL;
	}
};

struct bst
{
	node *root;

	bst()
	{
		root=NULL;
	}

	void update(int x)
	{
		node *cur=root;
		while(cur!=NULL)
		{
			if(cur->val.first<x) cur->r_size++, cur=cur->right;
			else if(cur->val.first>x) cur->l_size++, cur=cur->left;
			else if(cur->val.first==x && cur->val.second==1) cur->l_size++, cur=cur->left;
			else if(cur->val.first==x && cur->val.second==0)
			{
				cur->val.second=1;
				return;
			} 
		}
        return;
	}

	void insert(pair<int,int> x)
	{
		node *cur=root;
		if(root==NULL)
		{
			root=new node(x);
			return;
		}

		while(1)
		{
			if(cur->val.first<x.first)
			{
				if(x.second==1) cur->r_size++;
				if(cur->right==NULL)
				{
					cur->right=new node(x);
			        break;
				}
				else cur=cur->right;
			}

			else
			{
				if(x.second==1) cur->l_size++;
				if(cur->left==NULL)
				{
					cur->left=new node(x);
					break;
				}

				else cur=cur->left;
			}
		}
	}

	int greater(node *cur, int x)
	{
		if(cur==NULL) return 0;
		if(cur->val.first<=x) return greater(cur->right,x);
		else return cur->r_size + greater(cur->left,x) + cur->val.second;
	}

    int smaller(node *cur, int x)
	{
		if(cur==NULL) return 0;
		if(cur->val.first>x) return smaller(cur->left,x);
		else return cur->l_size + smaller(cur->right,x) + cur->val.second;
	}
};

int s[200010],n,q;
pair<int,int> a[200010];
bst b;

void input()
{
    char c;
    int p,k,x;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d",&x), a[i]=make_pair(x,1);
    for(int j=0,k=0;j<q;j++)
    {
    	scanf(" %c%d",&c,&p), s[k++]=c, s[k++]=p; 
    	if(c=='I') a[n++]=make_pair(p,0);
    }
    sort(a,a+n);
}

void output()
{
	node *x;
	for(int i=0;i<2*q;i++)
	{
		if(s[i]=='I') b.update(s[i+1]);
		if(s[i]=='U') printf("%d\n", b.greater(b.root, s[i+1]));
		if(s[i]=='L') printf("%d\n", b.smaller(b.root, s[i+1]));
	}
}

void insert_(int low,int high)
{
	if(low>high) return;
	int mid=(low+high)/2;
	b.insert(a[mid]);
	insert_(low,mid-1);
	insert_(mid+1,high);
}

int main() 
{ 
	input();
    insert_(0,n);
    output();
    return 0;
}


/*All the values to be inserted to the bst has been stored to an array 
paired with an identifier.
Initially,
-The indentifier is set to 1 for the initial list of numbers.
-The indentifier is set to 0 for the numbers to be inserted from query.

The array is then,
-Sorted and the median is chosen recursively and inserted to the bst.
-While inserting, the number of nodes in the left sub-tree and right sub-tree
is counted and increment occurs only when the identifier is 1.

The queries are also stored in an array. 
Whenever an insert query is found, the node from the query is searched 
And along the way,
-The number of nodes in the left sub-tree and right sub-tree is incremented accordingly 
-The value of the identifier of the node is set to 1

All the values to be inserted were inserted at once after sorting to optimize the code. But that would 
have given wrong output for other queries. Thats why the identifier is used and updated accordingly.


Insert operation: In case of insert operation, for each iteration, 
the cur node is either shifted to the left sub-tree or the right sub-tree. 
Thus, the complexity of the loop depends on the height of the binary search tree. 
Height of a binary search tree is always log(n) as it has been optimized. 
So, the time complexity of insert operation is O(1) in best case and O(log(n)) in worst case.

Greater operation: In case of greater operation, for each recursive iteration, 
the cur node is either shifted to the left sub-tree or the right sub-tree. 
So, the time complexity of greater operation will also be O(log(n)) in best case and O(log(n)) in worst case like insert operation.

Smaller operation: In case of smaller operation, for each recursive iteration, 
the cur node is either shifted to the left sub-tree or the right sub-tree. 
So, the time complexity of smaller operation will also be O(log(n)) in best case and O(log(n)) in worst case like insert operation.*/