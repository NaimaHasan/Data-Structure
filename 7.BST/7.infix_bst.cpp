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

int prec(char c) 
{
    if(c=='^') return 3;

    else if(c=='/'||c=='*') return 2;

    else if(c=='+'||c=='-') return 1;

    else return -1;
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

string infixToPostfix(string s) 
{
 
    stack<char> st; 
    string result;
    s = '(' + s + ')';
 
    for(int i = 0; i < s.length(); i++) 
    {
        char c = s[i];
 
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<= '9'))
            result += c;
 
        else if(c=='(') st.push('(');
 
        else if(c==')') 
        {
            while(st.top()!='(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        else 
        {
            while(!st.empty() && prec(c) <= prec(st.top())) 
            {
                result+=st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
    return result;
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
    string infix = "a+b-e*f*g";
    node * r = constructTree(infixToPostfix(infix));
    printf("infix expression is \n");
    inorder(r);
    return 0;
}