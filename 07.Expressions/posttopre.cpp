#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c=='+') || (c=='-') || (c=='/') || (c=='*') || (c=='^');
}

string postfixToPrefix(string exp)
{
    stack<string> s;
 
    for (int i=0;i<exp[i];i++) 
    {
        if (isOperator(exp[i])) 
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
 
            string temp = exp[i] + op2 + op1;
            s.push(temp);
        }
 
        else s.push(string(1,exp[i]));
        
    }
    
    return s.top();
}

int main()
{
    string exp = "ABC/-AK/L-*";

    printf("%s\n", postfixToPrefix(exp).c_str());
    return 0;
}