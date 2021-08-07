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

int max(int arr[], int low, int high)
{
    int i, max = arr[low], maxind = low;
    for (i = low + 1; i <= high; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}

  
node *buildTree(int inorder[], int low, int high)
{
    if (low > high) return NULL;

    int i = max(inorder, low, high);
    node *cur = new node(inorder[i]);

    if (low == high) return cur;
    
    cur->left = buildTree(inorder, low, i-1);
    cur->right = buildTree(inorder, i+1, high);

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
    int inorder[1000],n;
    
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d", &inorder[i]);

    node *cur = buildTree(inorder, 0, n-1);
    printInorder(cur);
}

  