#include <bits/stdc++.h>
using namespace std;

int prec(char c) 
{
    if(c=='^') return 3;

    else if(c=='/'||c=='*') return 2;

    else if(c=='+'||c=='-') return 1;

    else return -1;
}

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
 
string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
 
    for (int i=0;infix[i];i++) 
    {
        if (infix[i] == '(') 
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') 
        {
            infix[i] = '(';
            i++;
        }
    }
 
    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string s = ("1+2*(3^4-5)^(4+3*2)-1");

    printf("%s\n", infixToPrefix(s).c_str());
    return 0;
}