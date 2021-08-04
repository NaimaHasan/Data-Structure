#include <stdio.h>

void vowelCount(char str[], int index, int * count){
	if( !str[index] ) return;	
	char c = str[index];

	if( c=='a'||c =='e'||c=='i'||c=='o'||c=='u')
		*count += 1;
	if( c=='A'||c =='E'||c=='I'||c=='O'||c=='U')
                *count += 1;
	vowelCount(str, index+1, count);
	
	return;
}

int main(){
	char str[205];
	int count = 0;

	fgets(str, 205, stdin);

	vowelCount( str, 0, &count);

	printf("%d\n", count);

	return 0;	
}
