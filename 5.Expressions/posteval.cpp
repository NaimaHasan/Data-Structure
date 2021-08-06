#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
    return (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int posteval(string post)
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
    string exp = "1234^5-432*+^*+1-";
    printf("%d\n", posteval(exp));
    return 0;
}


