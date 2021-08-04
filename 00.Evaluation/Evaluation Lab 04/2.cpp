#include <bits/stdc++.h>

int main(){
	int i;
	double low, high, mid, ans, n;

	scanf("%lf", &n);

	low = 0;
	high = n;

	while( high - low > 0.0001){
	// for(i = 0; i < 1000; i++){
		mid = (low + high) / 2;

		ans = (mid * mid * mid);

		if(ans > n)
			high = mid;
		else if(ans < n)
			low = mid;
	}

	printf("%lf\n", mid);

	return 0;
}
