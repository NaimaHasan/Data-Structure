//Given the three points of a triangle, you will have to find another point which is equidistance from all the other points. 

#include <bits/stdc++.h>

struct point
{
	double x, y;
};

double distance(point a, point b)
{
	return sqrt( ((a.x-b.x)*(a.x-b.x)) + ((a.y-b.y)*(a.y-b.y)) );
}

double sum(point a, point vertices[])
{
	double ans = 0;

	for(int i = 0; i < 3; i++)
		ans += distance(a, vertices[i]);

	return ans;
}

int main(){
	point v[3], ans, mid1, mid2;
	int i;

	double minX, minY, maxX, maxY;

	for(i = 0; i < 3; i++)
		scanf("%lf %lf", &v[i].x, &v[i].y);

	minX = v[0].x; minY = v[0].y; maxX = v[0].x; maxY = v[0].y;

	for(i = 0; i < 3; i++)
	{
		if(v[i].x < minX)
			minX = v[i].x;

		if(v[i].y < minY)
			minY = v[i].y;

		if(v[i].x > maxX)
			maxX = v[i].x;

		if(v[i].y > maxY)
			maxY = v[i].y;
	}

	for(i = 0; i < 100; i++){
		mid1.x = (2*minX + maxX) / 3;
		mid2.x = (minX + 2*maxX) / 3;

		mid1.y = (2*minY + maxY) / 3;
		mid2.y = (minY + 2*maxY) / 3;

		// printf("The points are (%0.2lf, %0.2lf) (%0.2lf, %0.2lf)\n\n", mid1.x, mid1.y, mid2.x, mid2.y);

		// printf("values of sums are %lf %lf\n\n", sum(mid1, v), sum(mid2, v));

		if(sum(mid1, v) < sum(mid2, v))
		{
			maxX = mid2.x;
			maxY = mid2.y;
		}
		else if(sum(mid1, v) > sum(mid2, v))
		{
			minX = mid1.x;
			minY = mid2.y;
		}
		else
		{
			minX = mid1.x;
			minY = mid2.y;
			maxX = mid2.x;
			maxY = mid2.y;
		}
	}

	printf("The distaces to each point is %lf %lf %lf\n", distance(mid1, v[0]), distance(mid1, v[1]), distance(mid1, v[2]));

}
