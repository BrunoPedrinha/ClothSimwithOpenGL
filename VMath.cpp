#include "VMath.h"
using namespace SSF_Lib;
 
void  VMath::LoadV(Vector &a, float _x, float _y, float _z){
	a.x = _x; a.y = _y; a.z = _z;
}

void  VMath::LoadV(Vector* a, float _x, float _y, float _z){
	a->x = _x; a->y = _y; a->z = _z;
}


float VMath::Dot(const Vector &a, const Vector &b){
	return((a.x * b.x + a.y * b.y + a.z * b.z));
}


Vector VMath::Cross(const Vector &a, const Vector &b){
	Vector result;
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}

float VMath::Normalize(Vector &a){
	float magnitude;
	magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
#ifdef DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
	if ( fabs(magnitude) < VERY_SMALL ) {
		std::string errorMsg("Divide by nearly zero! ");
		throw errorMsg;
	}
#endif
	a.x = a.x / magnitude;
	a.y = a.y / magnitude;
	a.z = a.z / magnitude;
	return magnitude;
}

Vector VMath::GetNorm(const Vector &a){
	float magnitude;
	Vector result;
	magnitude = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
#ifdef DEBUG  /// If in debug mode let's worry about divide by zero or nearly zero!!! 
	if ( fabs(magnitude) < VERY_SMALL ) {
		std::string errorMsg("Divide by nearly zero! ");
		throw errorMsg;
	}
#endif
	result.x = a.x / magnitude;
	result.y = a.y / magnitude;
	result.z = a.z / magnitude;
	return result;
}

Vector VMath::Sub(const Vector a, const Vector b){
	Vector result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return result;
}

Vector VMath::Mult(const Vector a, float scalar){
	Vector result;
	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	return result;
}

void PrintV(const Vector &a){
		printf("(%f, %f, %f\n", a.x,a.y,a.z);
}

//Vector VMath::Reflect(Vector v, Plane p){
//	Vector result;
//	float scalar = 2.0f * Dot(v,p);
//	Vector temp = Mult(p, scalar);
//	result = Sub(v,temp);
//	return result;
//}

//Vector VMath::Reflect2(Vector v, Plane p){
//	Vector result;
//	float mag  = Mag(v);
//	Normalize(v);
//	float scalar = 2.0f * Dot(v,p);
//	Vector temp = Mult(p, scalar);
//	result = Sub(v,temp);
//	result  = Mult(result, mag);
//	return result;
//}

float VMath::Mag(const Vector &a){
	return(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}


float VMath::Distance(const Vector &a, const Vector &b){
	Vector r  = Sub(a,b);
	return(Mag(r));
}

//float VMath::Distance(const Vector &v, const Plane &p){
//	return v.x*p.x + v.y*p.y + v.z*p.z - p.d;
//}

//float VMath::Distance(const Sphere &s, const Plane &p){
//	return Distance((Vector)s,p) - s.r;
//}
