#include<bits/stdc++.h>
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
 
double evaluatePostfix(string exp)
{
    stack<double> s;
    int i;
 
    for (i = 0; exp[i]; i++)
    {
        if(isdigit(exp[i])) s.push(exp[i] - '0');
        else
        {
            double o1 = s.top();
            s.pop();
            double o2 = s.top();
            s.pop();

            switch(exp[i]) 
            {
                case '+':
                    s.push(o1 + o2);
                    break;
                case '-':
                    s.push(o1 - o2);
                    break;
                case '*':
                    s.push(o1 * o2);
                    break;
                case '/':
                    s.push(o1 / o2);
                    break;
            }
        }
    }
    return s.top();
}

int main() 
{
    string exp = "1+2*(3+4-5)-1";
    string post = infixToPostfix(exp);
    printf("%lf\n",evaluatePostfix(post));
    return 0;
}