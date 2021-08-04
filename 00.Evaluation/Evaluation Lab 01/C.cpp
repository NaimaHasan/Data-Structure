//15
//15
#include <bits/stdc++.h>

bool comp( long long int n1, long long int n2 ){
	if( n1 < 0 && n2 < 0 )
		if( n1 > n2 )
			return true;
	if( n1 >= 0 && n2 >= 0 )
		if( n1 < n2)
			return true;
	if( n1 >= 0 && n2 < 0)
		return true;
	return false;
}

int main(){
	long long int size, array[100005], i;

	scanf("%lld", &size);
	for(i = 0; i < size; i++)
		scanf("%lld", &array[i]);

	std::sort(array, array+size, comp);

	for(i = 0; i < size; i++)
		printf("%lld%s", array[i], i==size-1?"\n":" ");

	return 0;
}
