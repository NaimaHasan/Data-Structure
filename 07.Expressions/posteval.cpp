#include<bits/stdc++.h>
using namespace std;

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
    char exp[] = "231*+9-";
    printf("%lf\n",evaluatePostfix(exp));
    return 0;
}

