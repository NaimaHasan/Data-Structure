// In this problem, you are given a list of numbers L. After that there will be some queries:

// I X: means you need to insert the number X in the list.
// U X: means you need to find how many numbers greater than X are on the list L.
// L X: means you need to find how many numbers less than or equal to X are on the list L.
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val, r_size, l_size;
	node *left, *right;

	node()
	{
		r_size=0;
		l_size=0;
		left=NULL;
		right=NULL;
	}

	node(int _val)
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

	void insert(int x)
	{
		node *cur=root;
		if(root==NULL)
		{
			root=new node(x);
			return;
		}

		while(1)
		{
			if(cur->val<x)
			{
				cur->r_size++;
				if(cur->right==NULL)
				{
					cur->right=new node(x);
					break;
				}

				else cur=cur->right;
			}

			else
			{
				cur->l_size++;
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
		if(cur->val<=x) return greater(cur->right,x);
		else return cur->r_size + greater(cur->left,x) + 1;
	}

    int smaller(node *cur, int x)
	{
		if(cur==NULL) return 0;
		if(cur->val>x) return smaller(cur->left,x);
		else return cur->l_size + smaller(cur->right,x) + 1;
	}
};

int main() 
{ 
	bst k; 
    char c;
    int n,q,p,a;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a);
    	k.insert(a);
    }
    
    for(int i=0;i<q;i++)
    {
    	scanf(" %c%d",&c,&p);
    	if(c=='I') k.insert(p);
    	if(c=='U') printf("%d\n", k.greater(k.root, p));
    	if(c=='L') printf("%d\n", k.smaller(k.root, p));
    }

    return 0;
}