#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	queue<int> q;

	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++) q.push(i);

	while(q.size() != 1){
		for(int j = 1; j <= k; j++){
			if(j!=k)
				q.push(q.front());
			q.pop();
		}
	}

	printf("%d\n", q.front());

	return 0;
}
