//In this problem, you need to convert a binary number into decimal using recursion.

#include <stdio.h>
#include <string.h>

unsigned long long int binaryToDecimal( char binary[], int index )
{
	if(index < 0) return 0;
	
	int value = binary[index] - '0';
	return ((value + binaryToDecimal(binary, index - 1)) * 2);
}

int main()
{
	unsigned long long int decimal;
	char binary[64];
	
	scanf("%s", binary);
	decimal = binaryToDecimal(binary, strlen(binary) - 1);
	printf("%llu\n", decimal/2);
	return 0;
}
