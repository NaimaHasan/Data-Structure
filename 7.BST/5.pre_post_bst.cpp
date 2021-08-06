#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node()
    {
        left=NULL;
        right=NULL;
    }

    node(int _data)
    {
        data=_data;
        left=NULL;
        right=NULL;
    }
};

int preindex = 0;

node *buildTree(int pre[], int post[], int low, int high, int size)
{
    if (preindex >= size || low > high) return NULL;

    node *root = new node(pre[preindex]);
    preindex++;
    
    if (low == high || preindex >= size) return root;
    int i;
    
    for (i=low; i<=high; i++)
        if (post[i] == pre[preindex]) 
            break;
    
    if (i <= high)
    {
        root->left = buildTree(pre, post, low, i, size);
        root->right = buildTree(pre, post, i + 1, high-1, size);
    }

    return root;
}

void printInorder(node *root) 
{
    node *cur=root;

    if(cur == NULL) return;

    printInorder(cur->left);
    printf("%d ", cur->data);
    printInorder(cur->right);
}

int main()
{
    int preorder[1000],postorder[1000],n,i;
    
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &preorder[i]);
    for(i=0; i<n; i++) scanf("%d", &postorder[i]);

    node *root = buildTree(preorder, postorder, 0, n-1, n);
    printInorder(root);
}

 