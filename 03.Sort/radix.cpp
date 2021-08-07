#include <bits\stdc++.h>

void counting_sort(int A[], int m, int n){
	int C[10005], B[10005], i, j;

	for(i = 0; i <= 9; i++)
		C[i] = 0;

	for(j = 1; j <= n; j++)
		C[(A[j] % m)/(m/10)]++;

	for(i = 0; i <= 9; i++)
		C[i] += C[i-1];

	for(j = n; j >= 1; j--){
		B[C[(A[j] % m)/(m/10)]] = A[j];
		C[(A[j] % m)/(m/10)]--;
	}

	for(j = 1; j <= n; j++)
		A[j] = B[j];
}

void radix_sort(int A[], int k, int n){
	for(int i = 10; k != 0; k /= 10, i*=10)
		counting_sort(A, i, n);
}

int main(){
	int a[10005],n, i, k;
	scanf("%d %d",&n, &k);

	for(i=1;i<=n;i++) scanf("%d", &a[i]);

	radix_sort(a, k, n);

	for(i=1;i<=n;i++) printf("%d ", a[i]);

	return 0;
}

// Stable: Yes
