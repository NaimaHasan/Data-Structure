#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[1000];
	int i;
	bool flag = false;
	stack<char> st;
	scanf("%s",s);

	for(i = 0; s[i]; i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
		if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
		{
			flag = true;
			st.pop();
		} 
		else flag = false;
	}

	if(flag) printf("Brackets are balanced\n");
	else printf("Brackets are not balanced\n");
}