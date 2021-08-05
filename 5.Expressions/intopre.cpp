#include <bits/stdc++.h>
using namespace std;
 
bool isOperator(char c)
{
    return !(c>='a'&&c<='z') &&
           !(c>='A'&&c<='Z') &&
           !(c>='0'&&c<= '9');
}
 
int getPriority(char C)
{
    if(C=='-'||C=='+') return 1;

    else if(C=='*'||C=='/') return 2;

    else if(C=='^') return 3;

    return 0;
}
 
string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    stack<char> char_stack;
    string output;
 
    for (int i=0;infix[i]; i++) 
    {
        char c = infix[i];

        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<= '9'))
            output += c;
 
        else if (c == '(')
            char_stack.push('(');
 
        else if (c == ')') {
            while (char_stack.top() != '(') 
            {
                output += char_stack.top();
                char_stack.pop();
            }
 
            char_stack.pop();
        }
 
        else
        {
            if (isOperator(char_stack.top()))
            {
                if(c == '^')
                {
                      while (getPriority(c) <= getPriority(char_stack.top()))
                       {
                         output += char_stack.top();
                         char_stack.pop();
                       }
                     
                }
                else
                {
                    while (getPriority(c) < getPriority(char_stack.top()))
                       {
                         output += char_stack.top();
                         char_stack.pop();
                       }
                     
                }
 
                char_stack.push(c);
            }
        }
    }
    return output;
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
    string s = ("x+y*z/w+u");
    cout << infixToPrefix(s) << std::endl;
    return 0;
}