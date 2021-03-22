#pragma once
#include <stdio.h>
#include "Vector.h"
#define NUM_BALLS 5

class GeoObject {
	public : 
		Vector position;
		Vector velocity;
		Vector acceleration;
		float radius;
		float mass;
		bool hit;

		//temp stuff just for fun
		double y_rotation;

	public : 
		GeoObject();
		~GeoObject();
		
		void Update(float time);
		virtual void Render();
		float CalcDistance(GeoObject *ball1);
		bool HitDetection(GeoObject *_ball);
};