#include "GeoObject.h"
#include <Windows.h>
#include <gl\GLU.h>
#include "V_Randomizer.h"
#include <math.h>
#include "Particles.h"

//This is my constructor.
GeoObject::GeoObject(){
	//Ignore the commented things - just physics i'm using for a project.

	static V_Randomizer rand = V_Randomizer();
	position = Vector(rand.rand(-5, 5), rand.rand(-5, 5), 0);

	//vectors declared.
	velocity = Vector(0, 0, 0);
	acceleration = Vector(0, -9.8, 0);
	y_rotation = 0.0;
	radius = 1.0f;
}
//This is the destructor.
GeoObject::~GeoObject(){
	/*printf("Lolbye from the destructor\n");*/
}

void GeoObject::Update(float time){
	position.x += (velocity.x * time) + (0.5 * acceleration.x * time * time);
	position.y += (velocity.y * time) + (0.5 * acceleration.y * time * time);
	position.z += 0;

	velocity.x += acceleration.x * time;
	velocity.y += acceleration.y * time;
	velocity.z += 0;

	hit = false;

	mass = 1;

	y_rotation += 1.0;

	//when it hits the wall, position the ball before the wall
	if(position.y < -3){
		velocity.y *= -1; 
		position.y = -3;
	}
	if(position.y > 9){
		velocity.y *= -1; 
		position.y = 9;
	}

	if(position.x < -7){
		velocity.x *= -1; 
		position.x = 9;
	}

	if(position.x > 9){
		velocity.x *= -1; 
		position.x = 9;
	}

}
float GeoObject::CalcDistance(GeoObject *ball1){
	return sqrtf(
		(position.x - ball1->position.x) * (position.x - ball1->position.x) +
		(position.y - ball1->position.y) * (position.y - ball1->position.y)); /*+
		(position.z - ball1.position.z) * (position.z - ball1.position.z));*/
}
void GeoObject::Render(){
	//glPushMatrix();
	////setting the values I got in the constructor.
	//glTranslated(position.x, position.y, 0);
	////glRotated(y_rotation, 1.0, 1.0, 1.0);

	////Setting the values I got in the constructor.
	//glutWireSphere(size.x, size.y, size.z);
	//glPopMatrix();
}

bool GeoObject::HitDetection(GeoObject *_ball){
	if(hit){
		return true;
	}else return true;
}

