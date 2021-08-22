#include<bits/stdc++.h>
using namespace std;
 
int prec(char c) 
{
    if(c=='^') return 3;

    else if(c=='/'||c=='*') return 2;

    else if(c=='+'||c=='-') return 1;

    else return -1;
}

void infixToPostfix(string s) 
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
    printf("%s\n", result.c_str());
}
 

int main() 
{
    string exp = "3−5∗7∗(a−5∗(3/8)∗7+3∗b)";
    infixToPostfix(exp);
    return 0;
}