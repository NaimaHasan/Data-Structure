#include <bits/stdc++.h>

int * bound(int a[], int low, int high, int key){
	int mid, ans = 0;

	while(low <= high){
		mid = (low+high)/2;

		if(a[mid] >= key){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}

	return &a[ans];
}

int main(){
	int input[100], n, q, x, i, count;
	int *aPtr;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
		scanf("%d", &input[i]);

	scanf("%d", &q);

	for(i = 0; i < q; i++){
		scanf("%d", &x);
		count = 0;

		aPtr = bound(input, 0, n-1, x);

		while( *aPtr == x ){
			count++;
			aPtr++;
		}

		printf("%d\n", count);
	}

	return 0;
}
