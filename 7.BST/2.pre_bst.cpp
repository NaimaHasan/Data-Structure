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

node *createBST(int preOrder[], int low, int high) 
{
    if (low == high) return new node(preOrder[low]);
    
    node *root = new node(preOrder[low]);

    int index = -1;

    for (int i = low + 1; i <= high; i++) 
    {
        if (preOrder[i] > preOrder[low]) 
        {
            index = i;
            break;
        }
    }
    
    if (index == -1) 
    {
        root->left = createBST(preOrder, low + 1, high);
        root->right = NULL;
    }
    
    else 
    {
        root->left = createBST(preOrder, low + 1, index - 1);
        root->right = createBST(preOrder, index, high);
    }
    
    return root;
}

int main() 
{
    int preOrder[1000],n;
    
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d", &preOrder[i]);

    node *root = createBST(preOrder, 0, n-1);
    inorder(root);
}
