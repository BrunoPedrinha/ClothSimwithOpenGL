#pragma once
#include "Vector.h" 

Vector::Vector() {
	x = y = z = 0;
}

Vector::Vector(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float Vector::length()
{
	return sqrt(x*x+y*y+z*z);
}

Vector Vector::normalized()
{
	float l = length();
	return Vector(x/l,y/l,z/l);
}

void Vector::operator+= (const Vector &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

Vector Vector::operator/ (const float &a)
{
	return Vector(x/a,y/a,z/a);
}

Vector Vector::operator- (const Vector &v)
{
	return Vector(x-v.x,y-v.y,z-v.z);
}

Vector Vector::operator+ (const Vector &v)
{
	return Vector(x+v.x,y+v.y,z+v.z);
}

Vector Vector::operator* (const float &a)
{
	return Vector(x*a,y*a,z*a);
}

Vector Vector::operator-()
{
	return Vector(-x,-y,-z);
}

Vector Vector::cross(const Vector &v)
{
	return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

float Vector::dot(const Vector &v)
{
	return x*v.x + y*v.y + z*v.z;
}