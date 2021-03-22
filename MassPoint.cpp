#include "MassPoint.h"
#define GRAVITY Vector (0.0f, -5.8f, 0.0f)
#define DAMPING 0.1


MassPoint::MassPoint()
{
}

MassPoint::MassPoint(Vector _pos, bool _ismovable){
	position = _pos;
	old_position = position;
	is_movable = _ismovable;
	mass = 1;
	velocity = Vector(0.0f, 0.0f, 0.0f);
	acceleration = Vector (0.0f, 0.0f, 0.0);
	force = Vector(20.0f, 20.0f, 20.0f);
	wind = Vector (50.0f, 50.0f, 50.0f);
}


MassPoint::~MassPoint(void)
{
}

void MassPoint::Update(float time){
	if(is_movable){
		acceleration += GRAVITY / mass;
		Vector temp = position;
		position = position + (position - old_position) * (1.0 - DAMPING) + acceleration * time * time;
		old_position = temp;
		acceleration = Vector (0.0f, 0.0f, 0.0f);
	}

}
