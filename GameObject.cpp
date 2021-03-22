#include "GameObject.h"
#include "VMath.h"
#include <Windows.h>
#include <gl\GLU.h>


GameObject::GameObject()
{
	position = Vector (0.0f, 0.0f, -15.0f);
	velocity = Vector (0.0f, 0.0f, 5.0f);
	acceleration = Vector(0.0f, -9.8f, 0.0f);
	alive = false;
}

GameObject::~GameObject()
{
}

void GameObject::Update(float time){

	position.x += 0;
	position.y += 0;
	position.z += (velocity.z * time) + (0.5 * acceleration.z * time * time);

	velocity.x += 0;
	velocity.y += 0;
	velocity.z += acceleration.z * time;
}

void GameObject::Render(){
	glPushMatrix();
	glTranslated(position.x, position.y, position.z);
	glColor3f(1.0f, 0.0f, 0.0f);
//	glutSolidSphere(1, 3, 3);
	glPopMatrix();
}
