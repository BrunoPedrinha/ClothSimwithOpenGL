#include "math.h"
#pragma once

class Vector {

public:
	float x, y, z;

	Vector();
	Vector(float, float, float);
	void operator+= (const Vector &v);
	Vector operator/ (const float &a);
	Vector operator- (const Vector &v);
	Vector operator+ (const Vector &v);
	Vector operator* (const float &a);
	Vector operator-();
	Vector cross(const Vector &v);
	float dot(const Vector &v);
	float length();
	Vector normalized();
};