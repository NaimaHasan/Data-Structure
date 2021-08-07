// In this problem, you are given a string of parentheses. 
// You have to find the maximum depth the parentheses expression have. 
// Depth of parentheses at any moment is the number of open parentheses.

#include <stdio.h>

int main(){
	char brackets[205];
	int depth = 0, maxDepth = 0;

	fgets(brackets, 205, stdin);

	for(int i = 0; brackets[i]; i++)
	{
		if(brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') depth++;
		
		if(brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}')
		{
			if(depth > maxDepth) maxDepth = depth;
			depth--;
		}
	}

	printf("%d\n", maxDepth);

	return 0;
}
