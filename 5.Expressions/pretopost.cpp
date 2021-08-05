#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (c=='+') || (c=='-') || (c=='/') || (c=='*') || (c=='^');
}
 

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

int main()
{
    string exp = "*-A/BC-/AKL";

    printf("%s\n", prefixToPostfix(exp).c_str());
    return 0;
}