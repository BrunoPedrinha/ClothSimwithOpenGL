#pragma once
#include "Vector.h"
#define NUM_PARTICLES 500000

class Particles{
private:
	Vector position[NUM_PARTICLES];
	Vector velocity[NUM_PARTICLES];
	Vector acceleration[NUM_PARTICLES];

public:
	Particles();
	~Particles();

	void Update(double time);
	void Render();
};

