#include <bits/stdc++.h>
using namespace std;

#define ORDER 5

struct BTreeNode{
    int keys[ORDER-1] = {0};
    BTreeNode *children[ORDER];
    int keyCnt;
    bool isLeaf;

    BTreeNode(){
        for(int i = 0; i < ORDER; i++){
            children[i] = NULL;
        }
    }
    BTreeNode(bool leafBool){
        for(int i = 0; i < ORDER; i++){
            children[i] = NULL;
        }
        isLeaf = leafBool;
    }
}

struct BTree{
    BTreeNode * root;

    BTree(){
        root = NULL;
    }

    void insert(int k){
        if(root == NULL){
            root = new BTreeNode(true);
            root->keys[0] = k;
            root->keyCnt = 1;
        }
        else if(root->keyCnt == ORDER-1){
            BTreeNode * tmp = new BTreeNode(false);

            tmp->children[0] = root;

            
        }
    }
}

int main(){
    return 0;
}