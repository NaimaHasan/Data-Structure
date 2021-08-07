//In this problem, you need to count the number of vowels in an input string. 

#include <stdio.h>

int vowelCount(char str[], int index, int count)
{
	if( !str[index] ) return count;	
	
	char c = str[index];
	
	if( c=='a'||c =='e'||c=='i'||c=='o'||c=='u') count++;
	if( c=='A'||c =='E'||c=='I'||c=='O'||c=='U') count++;
                
	count = vowelCount(str, index+1, count);
	
	return count;
}

int main(){
	char str[205];
	fgets(str, 205, stdin);
	int c = vowelCount( str, 0, 0);
	printf("%d\n", c);
	return 0;	
}
