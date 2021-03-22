#pragma once 
#include <math.h>
#include <stdio.h>

/// This is a library of vector math routines. I wrote this to help demonstrate some basic 
/// priciples of C++
#include "Vector.h"
//#include "Plane.h"
//#include "Sphere.h"

namespace  SSF_Lib {

	class VMath {

	public:
	
		/// Load values into this vector
		static void LoadV(Vector &a, float x, float y, float z);
		static void LoadV(Vector* a, float x, float y, float z);

		/// Calculate the dot product between Vectors a & b 
		static  float Dot(const Vector &a, const Vector &b);

		/// 
		static Vector Cross(const Vector &a, const Vector &b);

		/// Calculate the magnitude of the vector
		static  float Mag(const Vector &a);

		/// Get a normal vector to this const vector	
		static Vector GetNorm(const Vector &a);

		/// Normalize this vector
		static float Normalize(Vector &a);

		/// Subtract vector's a & b
		static Vector Sub(const Vector a, const Vector b);

		/// Multiply vector a by a const value 
		static Vector Mult(const Vector a, const float scalar);

		/// Utility print 
		static void PrintV(const Vector &a);

		/// Reflect a normalized direction vector off a plane 
		//static Vector Reflect(const Vector v, const Plane p);

		/// Reflect a velocity vector off a plane maintaining the original velocity 
		//static Vector Reflect2(const Vector v, const Plane p);


		/// Get the distance between two vectors 
		static float Distance(const Vector &a, const Vector &b);

		/// Get the distance between a point (vector) and a plane 
		// float Distance(const Vector &v, const Plane &p);

		/// Get the distance between a sphere and a plane
		//static float Distance(const Sphere &s, const Plane &p);


	};

}