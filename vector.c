#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"


struct VectorType {
	double x;
	double y;
};

//Constructors, getters, setters, and destructor

extern Vector CreateVector(double x_component, double y_component) {
	Vector new_vector = malloc(sizeof(struct VectorType));
	new_vector->x = x_component;
	new_vector->y = y_component;
	return new_vector;
}

extern void SetX(Vector v, double new_x) {
	v->x = new_x;
}

extern void SetY(Vector v, double new_y) {
	v->y = new_y;
}

extern Vector CopyVector(const Vector v) {
	Vector copy = CreateVector(v->x, v->y);
	return copy;
}

extern double GetX(const Vector v) {
	return v->x;
}

extern double GetY(const Vector v) {
	return v->y;
}

extern void DestroyVector(Vector v) {
	free(v);
}

//Functions for adding, subtracting, multiplying, and dividing vectors

extern void AddVector(Vector v1, const Vector v2) {
	SetX(v1, v1->x + v2->x);
	SetY(v1, v1->y + v2->y);
}

extern void SubtractVector(Vector v1, const Vector v2) {
	SetX(v1, v1->x - v2->x);
	SetY(v1, v1->y + v2->y);
}

extern void MultiplyVector(Vector v, double scalar) {
	v->x *= scalar;
	v->y *= scalar;
}

extern void DivideVector(Vector v, double scalar) {
	v->x /= scalar;
	v->y /= scalar;
}

//Functions for getting the magnitude and squared magnitude of a vector

extern double Magnitude(const Vector v) {
	double result = sqrt(v->x * v->x + v->y * v->y);
	return result;
}

extern double SquaredMagnitude(const Vector v) {
	double result = v->x * v->x + v->y * v->y;
	return result;
}


//Various other utility functions
extern double DotProduct(const Vector v1, const Vector v2) {
	double result = Magnitude(v1) * Magnitude(v2) * cos(AngleBetween(v1, v2));
	return result;
}

extern double Distance(const Vector v1, const Vector v2) {
	double result = sqrt(pow(v2->x - v1->x, 2) + pow(v2->y - v1->y, 2));
	return result;
}

extern void Normalize(Vector v) {
	double mag = Magnitude(v);
	v->x /= mag;
	v->y /= mag;
}

extern void Limit(Vector v, double max) {
	if (Magnitude(v) > max) {
		double heading = Heading(v);
		v->x = max * cos(heading);
		v->y = max * sin(heading);
	}
}

extern void SetMagnitude(Vector v, double mag) {
	double heading = Heading(v);
	v->x = mag * cos(heading);
	v->y = mag * sin(heading);
}

extern double Heading(const Vector v) {
	return atan2(v->y, v->x);
}

extern void Rotate(Vector v, double angle) {
	double new_heading = Heading(v) + angle;
	double new_x = Magnitude(v) * cos(new_heading);
	double new_y = Magnitude(v) * sin(new_heading);
	v->x = new_x;
	v->y = new_y;
}

extern void SetHeading(Vector v, double angle) {
	double new_x = Magnitude(v) * cos(angle);
	double new_y = Magnitude(v) * sin(angle);
	v->x = new_x;
	v->y = new_y;
}

extern double AngleBetween(const Vector v1, const Vector v2) {
	double dot_prod = DotProduct(v1, v2);
	double len_v1 = Magnitude(v1);
	double len_v2 = Magnitude(v2);

	double cos_theta = dot_prod / (len_v1 * len_v2);
	double angle = acos(cos_theta);

	return angle;
}

extern Vector LinearInterpolate(Vector v1, Vector v2, double amount) {
	assert(amount >= 0.0 && amount <= 1.0);
	double distance = Distance(v1, v2);
	double heading = atan2(v2->y - v1->y, v2->x - v1->x);
	double scaled_distance = amount * distance;
	double new_x = v1->x + scaled_distance * cos(heading);
	double new_y = v1->y + scaled_distance * sin(heading);
	Vector result = CreateVector(new_x, new_y);

	return result;
}

extern bool Equals(const Vector v1, const Vector v2) {
	return v1->x == v2->x && v1->y == v2->y;
}

extern Vector FromAngle(double angle) {
	Vector result = CreateVector(cos(angle), sin(angle));
	return result;
}

extern Vector Random() {
	double angle_in_degrees = rand() % 360;
	double angle_in_radians = angle_in_degrees * (PI/180);
	Vector result = CreateVector(cos(angle_in_radians), sin(angle_in_radians));
	return result;
}

