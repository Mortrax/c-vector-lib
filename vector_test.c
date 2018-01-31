#include "vector.h"
#include <stdio.h>



int main(int argc, char* argv[]) {
	
	Vector v = CreateVector(10.0, 20.0);

	printf("Magnitude of v: %f\n", Magnitude(v)); 
	
	Rotate(v, (PI/2.0));

	printf("Magnitude of v: %f\n", Magnitude(v)); 

	printf("v->x: %f, v->y: %f\n", GetX(v), GetY(v));

	Vector v2 = CreateVector(10.0, 20.0);

	Normalize(v2);

	printf("v2->x: %f, v2->y: %f\n", GetX(v2), GetY(v2));

	Vector v3 = CreateVector(10.0, 20.0);

	Limit(v3, 5.0);

	printf("v3->x: %f, v3->y: %f\n", GetX(v3), GetY(v3));

	Vector v4 = CreateVector(10.0, 20.0);

	SetMagnitude(v4, 10);

	printf("v4->x: %f, v4->y: %f\n", GetX(v4), GetY(v4));
	printf("Magnitude of v4: %f\n", Magnitude(v4));

        Vector v5 = CreateVector(5.0, 10.0);
        Vector v6 = CreateVector(5.0, 10.0);
        Rotate(v6, (PI/2.0));

        printf("Angle between v5 and v5 rotated: %f\n", AngleBetween(v5, v6));

	DestroyVector(v);
	DestroyVector(v2);
	DestroyVector(v3);
	DestroyVector(v4);
        DestroyVector(v5);
        DestroyVector(v6);

	return 0;
}
