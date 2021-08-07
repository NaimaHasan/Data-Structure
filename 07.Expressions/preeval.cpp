#include <bits/stdc++.h>
using namespace std;

double evaluatePrefix(string exp)
{
    stack<double> s;
 
    for(int i = exp.size() - 1; i >= 0; i--) 
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
    string exp = "+9*26";
    printf("%lf\n",evaluatePrefix(exp));
    return 0;
}