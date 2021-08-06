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

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) 
        if (arr[i] == value)
            break;
    
    return i;
}

node *buildTree(int in[], int post[], int inStrt, int inEnd, int postStrt, int postEnd)
{
    if (inStrt > inEnd) return NULL;

    
    node *cur = new node(post[postEnd]);

    if (inStrt == inEnd) return cur;

    int i = search(in, inStrt, inEnd, cur->data);

    
    cur->left = buildTree(in, post, inStrt, i-1, postStrt, postStrt-inStrt+i-1);
    cur->right = buildTree(in, post, i+1, inEnd, postEnd-inEnd+i, postEnd-1);

    return cur;
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
   int inorder[1000],postorder[1000],n,i;
    
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &inorder[i]);
    for(i=0; i<n; i++) scanf("%d", &postorder[i]);

    node *root = buildTree(inorder, postorder, 0, n-1, 0, n-1);
    printInorder(root);
}

 