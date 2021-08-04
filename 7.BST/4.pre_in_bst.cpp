#include <stdio.h>
#include <stdlib.h>

struct node {
    char val;
    node* left;
    node* right;

    node()
    {
        left=NULL;
        right=NULL;
    }

    node(char _val)
    {
        val=_val;
        left=NULL;
        right=NULL;
    }
};

struct bt
{
    node *root;

    bt()
    {
        root=NULL;
    }

    int search(char arr[], int strt, int end, char value)
    {
        for (int i = strt; i <= end; i++) 
        {
            if (arr[i] == value)
                return i;
        }
    }

    node* buildTree(char in[], char pre[], int st, int ed)
    {
        node *cur = root;
        int preIndex = 0;
     
        if (st > ed)
            return NULL;

        cur = new node(pre[preIndex++]);
     
        if (st == ed)
            return cur;
     
        
        int inIndex = search(in, st, ed, cur->val);
     
        cur->left = buildTree(in, pre, st, inIndex - 1);
        cur->right = buildTree(in, pre, inIndex + 1, ed);
     
        return cur;
    }


    void inorder(node *root) 
    {
        node *cur=root;

        if(cur == NULL) return;

        inorder(cur->left);
        printf("%d ", cur->val);
        inorder(cur->right);
    }
};
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };

    int len = sizeof(in) / sizeof(in[0]);

    bt k;

    node *tmp = k.buildTree(in, pre, 0, len - 1);
    k.inorder(tmp);
    getchar();
}