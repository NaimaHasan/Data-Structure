#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	node *left, *right;

	node()
	{
		left=NULL;
		right=NULL;
	}

	node(int _val)
	{
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

	node * search(int x)
	{
		
		node *cur=root;
		while(cur!=NULL)
		{
			
			if(cur->val<x) cur=cur->right;
			else if(cur->val>x) cur=cur->left;
			else if(cur->val==x) return cur;
			
		}
          return NULL;
	}

	void insert(int x)
	{
		node *cur=root;
		if(root==NULL)
		{
			root= new node(x);
			return;
		}

		while(1)
		{
			if(cur->val<x)
			{
				if(cur->right==NULL)
				{
					cur->right=new node(x);
					break;
				}

				else cur= cur->right;
			}

			else
			{
				if(cur->left==NULL)
				{
					cur->left= new node(x);
					break;
				}
				else cur=cur->left;
			}
		}
	}

	node * upper(int x)
	{
		node *ans=new node();
		node *cur=root;
		while(cur!=NULL)
		{
			
			if(cur->val<=x) cur=cur->right;
			else
			{
				ans=cur;
				cur=cur->left;
			}
		}
		return ans;
	}

	node * lower(int x)
	{
		node *ans=new node();
		node *cur=root;
		while(cur!=NULL)
		{
			
			if(cur->val<x) cur=cur->right;
			else
			{
				ans=cur;
				cur=cur->left;
			}
		}
		return ans;
	}

    
  
	void inorder(node *root) 
	{
		node *cur=root;

    		if(cur == NULL) return;

    		inorder(cur->left);
        	printf("%d ", cur->val);
        	inorder(cur->right);
     }

     void preorder(node *root) 
	{
		node *cur=root;

    		if(cur == NULL) return;

    		printf("%d ", cur->val);
    		preorder(cur->left);
        	preorder(cur->right);
     }

     void postorder(node *root) 
	{
		node *cur=root;

    		if(cur == NULL) return;

		preorder(cur->left);
        	preorder(cur->right);
        	printf("%d ", cur->val);
     }

    
     node* del(node* root, int x) 
	{ 
    
    		if(root == NULL) return root; 
  
    		if(x<root->val)  root->left=del(root->left,x); 
    		else if(x>root->val) root->right=del(root->right,x); 

   		else
    		{ 
      		if (root->left == NULL) 
        		{ 
            		node *temp = root->right; 
            		free(root); 
            		return temp; 
        		} 
       		else if (root->right == NULL) 
       		{ 
           		node *temp = root->left; 
            		free(root); 
            		return temp; 
        		} 
  
        		node* temp = upper(root->val); 
  			root->val = temp->val; 
  			root->right = del(root->right, temp->val); 
    		} 
    		return root; 
	} 

};

int main() 
{ 

      /*      82 
           /     \ 
          70      90 
         /  \    /  \ 
       60   75  85   100 */
    bst k; 
    node *b, *c, *d, *m;
    k.insert(82); 
    k.insert(70); 
    k.insert(60); 
    k.insert(75); 
    k.insert(90); 
    k.insert(85); 
    k.insert(100);

    b=k.upper(31);
    c=k.lower(75);
    d=k.search(52);

    printf("%d %d\n",b->val,c->val);
    if(d!=NULL) printf("YES\n");
    else printf("NO\n");
    k.root=k.del(k.root,70);
    k.inorder(k.root);

 }