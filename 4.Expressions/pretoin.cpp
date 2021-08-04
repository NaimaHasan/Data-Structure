#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) 
{
   return (c=='+') || (c=='-') || (c=='/') || (c=='*') || (c=='^');
}

string preToInfix(string exp) 
{
  stack<string> s;
 
  for (int i=exp.size()-1;exp[i];i--) 
  {

    char c = exp[i];

    if (isOperator(exp[i])) 
    {
      string op1 = s.top();  s.pop();
      string op2 = s.top();  s.pop();
 
      string temp = "(" + op1 + exp[i] + op2 + ")";
 
      s.push(temp);
    }
 
    else 
      s.push(string(1,exp[i]));
    
  }
  return s.top();
}

int main() {
  string exp = "*-A/BC-/AKL";
  cout<< preToInfix(exp) << endl;
  return 0;
}