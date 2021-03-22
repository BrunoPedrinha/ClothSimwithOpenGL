#pragma once
#include "MassPoint.h"
#include "Vector.h"

class Springs
{
public:
	MassPoint *p1, *p2;
	float rest_distance;


	Springs();
	Springs(MassPoint *_p1, MassPoint *_p2);
	~Springs();
	void Update(float time);
};

