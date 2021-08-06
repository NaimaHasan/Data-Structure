#include<bits/stdc++.h>
using namespace std;
 
int prec(char c) 
{
    if(c=='^') return 3;

    else if(c=='/'||c=='*') return 2;

    else if(c=='+'||c=='-') return 1;

    else return -1;
}

bool isOperator(char ch){
    return (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void traverse_stack(stack<int> & st) {
    if(st.empty())
        return;
    int x = st.top();
    printf("%d ", x);
    st.pop();
    traverse_stack(st);
    st.push(x);
}
void traverse_stackx(stack<int> & st) {
    if(st.empty())
        return;
    int x = st.top();
    printf("%c ", x);
    st.pop();
    traverse_stackx(st);
    st.push(x);
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

int ineval(string post)
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
    string exp = "1+2*(3^4-5)^(4+3*2)-1";
    string post = infixToPostfix(exp);
    printf("%d\n", ineval(post));
    return 0;
}


