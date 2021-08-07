#include<bits/stdc++.h>
using namespace std;


struct node
{
    char value;
    node* left, *right;
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '^')
        return true;
    return false;
}


void inorder(node *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}


node* newNode(char v)
{
    node *temp = new node;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};



node* constructTree(char postfix[])
{
    stack<node *> st;
    node *t, *t1, *t2;

    
    
    for (int i=0; i<strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else 
        {
            t = newNode(postfix[i]);

            
            t1 = st.top(); 
            st.pop();      
            t2 = st.top();
            st.pop();

            
            t->right = t1;
            t->left = t2;

            
            st.push(t);
        }
    }

    
    
    t = st.top();
    st.pop();

    return t;
}


int main()
{
    char postfix[] = "ab+ef*g*-";
    node * r = constructTree(postfix);
    printf("infix expression is \n");
    inorder(r);
    return 0;
}