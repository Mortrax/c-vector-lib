#ifndef VECTOR_H_
#define VECTOR_H_
#include <stdbool.h>

#define PI 3.1415926535897

//An abstract datatype to represent the type of a two dimensional
//Euclidean Vector with x & y components, a magnitude, and a 
// direction

typedef struct VectorType *Vector;

//Constructors, getters, setters, and destructor

extern Vector CreateVector(double x_component, double y_component);
extern void SetX(Vector v, double new_x);
extern void SetY(Vector v, double new_y);
extern Vector CopyVector(const Vector v);
extern double GetX(const Vector v);
extern double GetY(const Vector v);
extern void DestroyVector(Vector v);

//Functions for adding, subtracting, multiplying, and dividing vectors

extern void AddVector(Vector v1, const Vector v2);
extern void SubtractVector(Vector v1, const Vector v2);
extern void MultiplyVector(Vector v, double scalar);
extern void DivideVector(Vector v, double scalar);

//Functions for getting the magnitude and squared magnitude of a vector

extern double Magnitude(const Vector v);
extern double SquaredMagnitude(const Vector v);

//Various other utility functions

extern double DotProduct(const Vector v1, const Vector v2);
extern double Distance(const Vector v1, const Vector v2); //Euclidean distance
extern void Normalize(Vector v); //Normalize a vector to length 1
extern void Limit(Vector v, double max); //Limit vector's magnitude to size of max
extern void SetMagnitude(Vector v, double mag); //Set vector's magnitude
extern double Heading(const Vector v); //Calculate angle of rotation for the vector
extern void Rotate(Vector v, double angle); //Rotate the Vector by an angle value
extern void SetHeading(Vector v, double angle); //Set the heading of the Vector
extern double AngleBetween(const Vector v1, const Vector v2); //Calculate angle between to vecs
extern Vector LinearInterpolate(Vector v1, Vector v2, double amount); //Linear interpolation
extern bool Equals(const Vector v1, const Vector v2); //Check two vectors for equality
extern Vector FromAngle(double angle); //Create a new 2d unit vector from an angle
extern Vector Random(); //Create a new 2d unit vector from a random angle


#endif




