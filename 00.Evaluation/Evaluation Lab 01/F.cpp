//15
//15
//15
#include <stdio.h>

void printSum( int A[][101], int B[][101], int row, int col, int i, int j ){
	if(j == col){
		if(i == row - 1)
			return;
		printSum(A, B, row, col, i + 1, 0);
		return;
	}
	printf("%d%s", A[i][j] + B[i][j], j == col-1?"\n":" ");
	printSum(A, B, row, col, i, j + 1);
}


int main(){
	int r, c, A[101][101], B[101][101], i, j;

	scanf("%d %d", &r, &c);

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			scanf("%d", &A[i][j]);

	for(i = 0; i < r; i++)
                for(j = 0; j < c; j++)
                        scanf("%d", &B[i][j]);

	printSum(A, B, r, c, 0, 0);

	return 0;
}
