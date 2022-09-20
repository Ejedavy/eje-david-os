#include <stdio.h>
#include <math.h>

typedef struct Point Point;

struct Point {
	float x;
	float y;
};

float distance(Point A, Point B) {
	float dx = A.x - B.x;
	float dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}

float area(Point A, Point B, Point C) {
	return 0.5 * (A.x * B.y - B.x * A.y + 
	              B.x * C.y - C.x * B.y + 
	              C.x * A.y - A.x * C.y);
}

int main(void) {
	Point A = {2.5, 6};
	Point B = {1, 2.2};
	Point C = {10, 6};
	
	float AB = distance(A, B);

	float ABC = area(A, B, C);
	
	printf("The distance is %f\n", AB);
	printf("The area is %f\n", ABC);
}
