#include <bits/stdc++.h>

double sqr(double a){
	return a * a;
}

struct point {
	double x, y, z;

	point(double _x, double _y, double _z){
		x = _x;
		y = _y;
		z - _z;
	}

	point() {}

	double distance(point another){
		return sqrt( sqr(x-another.x) + sqr(y-another.y) + sqr(z-another.z) );
	}

	void cpy(point another){
		x = another.x;
		y = another.y;
		z = another.z;
	}
};

int main(){
	point A, B, P;
	point low, high, mid1, mid2, ans;
	double dist1, dist2;

	scanf("%lf %lf %lf", &A.x, &A.y, &A.z);
	scanf("%lf %lf %lf", &B.x, &B.y, &B.z);
	scanf("%lf %lf %lf", &P.x, &P.y, &P.z);

	low.cpy(A);
	high.cpy(B);

	for(int i = 0; i < 100; i++){
		mid1.x =  low.x + (high.x-low.x)/3;
		mid1.y =  low.y + (high.y-low.y)/3;
		mid1.z =  low.z + (high.z-low.z)/3;

		mid2.x =  high.x - (high.x-low.x)/3;
		mid2.y =  high.y - (high.y-low.y)/3;
		mid2.z =  high.y - (high.z-low.z)/3;

		dist1 = mid1.distance(P);
		dist2 = mid2.distance(P);

		if(dist1<dist2) high.cpy(mid2);
		else low.cpy(mid1);
	}

	printf("%lf\n", dist1);

	return 0;
}