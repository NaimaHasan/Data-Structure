#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
    return (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
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

int preeval(string post)
{
	stack<int> opStack, opeStack;

	for(int i = 0; i < post.length(); i++)
	{
		if(!isOperator(post[i])) opStack.push(post[i] - '0');
		else opeStack.push(post[i]);
	}

	while(!opeStack.empty())
	{
		int x, y;

		x = opStack.top();
		opStack.pop();
		y = opStack.top();
		opStack.pop();

		if(opeStack.top() == '+')
		{
			opStack.push(x+y);
			opeStack.pop();
		}
		else if(opeStack.top() == '-')
		{
			opStack.push(x-y);
			opeStack.pop();
		}
		else if(opeStack.top() == '*')
		{
			opStack.push(x*y);
			opeStack.pop();
		}
		else if(opeStack.top() == '/')
		{
			opStack.push(x/y);
			opeStack.pop();
		}
        else if(opeStack.top() == '^')
        {
            opStack.push((int)pow(x, y));
            opeStack.pop();
        }
	}

	return opStack.top();
}
 

int main() 
{
    string exp = "+1-*2^-^345+4*321";
    exp = prefixToPostfix(exp);
    printf("%s\n", exp.c_str());
    printf("%d\n", preeval(exp));
    return 0;
}


