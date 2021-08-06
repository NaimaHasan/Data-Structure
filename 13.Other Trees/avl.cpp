#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int key, height;
    node *left, *right;
    node()
    {
        key = height = 0;
        left = right = NULL;
    }
 
    node(int _key) 
    {
        key = _key;
        height = 1;
        left = right = NULL;
    }
};
 
struct AVLTree 
{
    node *root;

    AVLTree()
    {
        root=NULL;
    }

    int height(node *cur) 
    {
        if (cur == NULL) return 0;
        return cur->height;
    }
 
    node *rightRotate(node *cur) 
    {
        node *x = cur->left;
        node *y = x->right;
 
        
        x->right = cur;
        cur->left = y;
 
        cur->height = max(height(cur->left), height(cur->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }
 
    node *leftRotate(node *cur) 
    {
        node *x = cur->right;
        node *y = x->left;
 
        
        x->left = cur;
        cur->right = y;
 
        
        cur->height = max(height(cur->left), height(cur->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
 
        return x;
    }
 
    
    int getBalance(node *cur) 
    {
        if (cur == NULL) return 0;
 
        return height(cur->left) - height(cur->right);
    }
 
    node *insert(node *cur, int key) 
    {
 
        /* 1.  Perform the normal BST insertion */
        if (cur == NULL) return new node(key);
 
        if (key < cur->key) cur->left = insert(cur->left, key);
        else if (key > cur->key) cur->right = insert(cur->right, key);
        else return cur;

        /* 2. Update height of this ancestor node */
        cur->height = 1 + max(height(cur->left), height(cur->right));
        
        /* 3. Get the balance factor of this ancestor node*/
        int balance = getBalance(cur);
 
        if (balance > 1 && key < cur->left->key) return rightRotate(cur);
        if (balance < -1 && key > cur->right->key) return leftRotate(cur);
 
        // Left Right Case
        if (balance > 1 && key > cur->left->key) 
        {
            cur->left = leftRotate(cur->left);
            return rightRotate(cur);
        }
 
        // Right Left Case
        if (balance < -1 && key < cur->right->key) 
        {
            cur->right = rightRotate(cur->right);
            return leftRotate(cur);
        }
        return cur;
    }
 
    void preorder(node *root) 
    {
        node *cur=root;

        if(cur == NULL) return;

        printf("%d ", cur->key);
        preorder(cur->left);
        preorder(cur->right);
     }
};
 
int main() 
{
    AVLTree tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    /* The constructed AVL Tree would be
         30
        /  \
      20   40
     /  \     \
    10  25    50
    */
    tree.preorder(tree.root);
    cout<<endl;
}
