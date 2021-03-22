#pragma once
#include "Vector.h"

class MassPoint
{
public:
	Vector position, velocity, old_position, wind, acceleration, force;
	float mass;
	bool is_movable;

	MassPoint();
	MassPoint(Vector _pos, bool _ismovable);
	~MassPoint();
	void Update(float time);
};

