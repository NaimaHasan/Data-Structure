//15
//15
//15
#include <bits/stdc++.h>

int main(){
        long long int n, array[100005], i, count = 0, current;
	bool hasPrinted = false;

        scanf("%lld", &n);

        for(i = 0; i < n; i++)
                scanf("%lld", &array[i]);

        std::sort(array, array+n);

	current = array[0];
        count++;

	for(i = 1; i < n; i++){
		if(array[i] != current){
			printf("%lld %lld\n", current, count);
			current = array[i];
			count = 1;
			hasPrinted = true;
		}
		else{
			hasPrinted = false;
			count++;
		}
	}

	if( !hasPrinted || count == 1) printf("%lld %lld\n", current, count);

        return 0;
}
