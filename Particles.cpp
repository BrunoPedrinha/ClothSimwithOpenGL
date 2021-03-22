#include "Particles.h"
#include "V_Randomizer.h"
#include <Windows.h>
#include <gl\GLU.h>

V_Randomizer r;

Particles::Particles(){

	/*position = new Vector[NUM_PARTICLES];
	velocity = new Vector[NUM_PARTICLES];
	acceleration = new Vector[NUM_PARTICLES];*/

	for(int i = 0; i<NUM_PARTICLES; i++){

		position[i].x = position[i].y = 10.0f; position[i].z = 0.0;

		velocity[i].x = r.box_muller(0.0, 1.0);
		velocity[i].y = r.box_muller(0.0, 1.0);
		velocity[i].z = r.box_muller(0.0, 1.0);

		acceleration[i].x = acceleration[i].y = acceleration[i].z = 0.0;
	}
}


Particles::~Particles(){
	/*delete[] position;
	delete[] velocity;
	delete[] acceleration;*/
}

void Particles::Update(double time){
	for(int i = 0; i<NUM_PARTICLES; i++){

		position[i].x += (velocity[i].x * time) + (0.5 * acceleration[i].x * time * time);
		position[i].y += (velocity[i].y * time) + (0.5 * acceleration[i].y * time * time);
		position[i].z += (velocity[i].z * time) + (0.5 * acceleration[i].z * time * time);

		

		velocity[i].x += acceleration[i].x * 10;
		velocity[i].y += acceleration[i].y * 10;
		velocity[i].z += acceleration[i].z * 10;
	}
}
void Particles::Render(){
	
	glBegin(GL_POINTS);
		for(int i = 0; i<NUM_PARTICLES; i++){
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3d(position[i].x,position[i].y,position[i].z);
		}
	glEnd();
	
}
