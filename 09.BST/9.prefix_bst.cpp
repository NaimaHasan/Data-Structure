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

string prefixToPostfix(string exp)
{
 
    stack<string> s;
    
    for (int i=exp.size()-1;exp[i]; i--)
    {
        if (isOperator(exp[i]))
        {
            
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
 
            string temp = op1 + op2 + exp[i];
            s.push(temp);
        }
 
        else s.push(string(1,exp[i]));
    }

    return s.top();
}


node* constructTree(string postfix)
{
    stack<node *> st;
    node *t, *t1, *t2;

    
    
    for (int i=0; i<postfix.length(); i++)
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
    string prefix = "+1-*2^-^345+4*321";
    node * r = constructTree(prefixToPostfix(prefix));
    printf("infix expression is \n");
    inorder(r);
    return 0;
}