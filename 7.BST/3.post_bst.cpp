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

void inorder(node *root) 
{
    node *cur=root;

    if(cur == NULL) return;

    inorder(cur->left);
    printf("%d ", cur->data);
    inorder(cur->right);
}

node *createBST(int postOrder[], int low, int high) 
{
    if (low == high) return new node(postOrder[high]);
    
    node *root = new node(postOrder[high]);

    int index = -1;

    for (int i = high - 1; i >= low; i--) 
    {
        if (postOrder[i] <= postOrder[high]) 
        {
            index = i;
            break;
        }
    }
    
    if (index == -1) 
    {
        root->left = NULL;
        root->right = createBST(postOrder, low, high-1);
    }
    
    else 
    {
        root->left = createBST(postOrder, low, index);
        root->right = createBST(postOrder, index+1, high-1);
    }
    
    return root;
}

int main() 
{
    int postOrder[1000],n;

    scanf("%d", &n);
    
    for(int i=0; i<n; i++) scanf("%d", &postOrder[i]);

    node *root = createBST(postOrder, 0, n-1);
    inorder(root);
}
