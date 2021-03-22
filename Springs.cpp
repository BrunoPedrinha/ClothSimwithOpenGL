#include "Springs.h"


Springs::Springs()
{
}

Springs::Springs(MassPoint *_p1, MassPoint *_p2){
	p1 = _p1;
	p2 = _p2;
	Vector temp = p2->position - p1->position;
	rest_distance = temp.length();
}

Springs::~Springs()
{
}

void Springs::Update(float time){
	Vector temp_pos = p2->position - p1->position;
	float distance = temp_pos.length();
	Vector offset = temp_pos * (1 - rest_distance / distance);
	if(p1->is_movable)p1->position += offset * 0.5;
	if(p2->is_movable)p2->position += offset * -0.5;
}