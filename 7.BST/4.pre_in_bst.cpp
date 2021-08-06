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
 
int preIndex = 0;

int search(int arr[], int low, int high, int value)
{
    int i;
    for (i=low; i<=high; i++) 
        if (arr[i] == value)
            return i;
    
    return i;
}

node *buildTree(int in[], int pre[], int low, int high)
{
    if (low > high) return NULL;

    node *cur = new node(pre[preIndex++]);
    
    if (low == high) return cur;

    int inIndex = search(in, low, high, cur->data);

    cur->left = buildTree(in, pre, low, inIndex - 1);
    cur->right = buildTree(in, pre, inIndex + 1, high);

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
    int inorder[1000],preorder[1000],n,i;
    
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d", &inorder[i]);
    for(i=0; i<n; i++) scanf("%d", &preorder[i]);

    node *root = buildTree(inorder, preorder, 0, n-1);
    printInorder(root);
}
