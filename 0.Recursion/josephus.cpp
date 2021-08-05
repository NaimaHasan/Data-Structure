#include <bits/stdc++.h>

int josephus(int n, int k){
	if (n == 1) return 1;

	return ((josephus(n-1, k) + (k-1)) % n) + 1;
}

int main(){
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d\n", josephus(n, k));

	return 0;
}