#include <bits\stdc++.h>

void counting_sort(int A[], int k1, int k2, int n){
	int C[10005], B[10005], i, j;

	for(i = 1; i <= k2-k1; i++)
		C[i] = 0;

	for(j = 1; j <= n; j++)
		C[A[j] - k1]++;

	for(i = 1; i <= k2-k1; i++)
		C[i] += C[i-1];

	for(j = n; j >= 1; j--){
		B[C[A[j] - k1]] = A[j];
		C[A[j] - k1]--;
	}

	for(j = 1; j <= n; j++)
		A[j] = B[j];
}

int main(){
	int a[10005],n, i, k1, k2;
	scanf("%d %d %d",&n, &k1, &k2);

	for(i=1;i<=n;i++) scanf("%d", &a[i]);

	counting_sort(a, k1, k2, n);

	for(i=1;i<=n;i++) printf("%d ", a[i]);

	return 0;
}