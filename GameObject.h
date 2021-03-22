#pragma once
#include "Vector.h"
class GameObject
{
public:
	Vector position, velocity, acceleration;
	bool alive;

	GameObject();
	~GameObject();
	void Update(float time);
	void Render();
};

