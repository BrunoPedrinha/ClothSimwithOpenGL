#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <glut.h>
#include <math.h>
#include "GeoObject.h"
#include "GameObject.h"
#include "Ball.h"
#include "Camera.h"
#include "Cloth.h"
#include "Particles.h"
#define NUM_BALLS 5

//#include "V_Randomizer.h"


/// Simple prototypes for the callbacks
void RenderScene(void);
void HandleTimer(int ID);
void FunctionKeys(int key, int x, int y);
void Keyboard(unsigned char key, int x, int y);
void ChangeSize(GLsizei w, GLsizei h);
void CleanUp(void);
void CheckCollision();
GLuint loadTextureRAW( const char * filename, int wrap , int width, int height);


/// Globals - We really should do this better 
GeoObject* ball[NUM_BALLS];
GameObject bullets[500];
Camera c, c2;
//Particles *p = new Particles();
Cloth *cloth = new Cloth();




void main(int argc, char **argv){
	atexit (CleanUp);									/// A C++ callback for exiting the program. 
														/// Used because GLUT doesn't exit very well.
	
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowSize(1200,800);
	glutCreateWindow("This is the window title");
	printf("Using openGL %s\n",(char*)::glGetString(GL_VERSION));
    glEnable(GL_DEPTH_TEST); ///  set up depth-buffering
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	GLfloat light_pos[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);


	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);

	/// Java does the same sort of thing here, 
	/// simply pass the name of a function that should
	/// be called whenever an event occurs. 

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(FunctionKeys);

	for(int i = 0; i <NUM_BALLS; i++){
		ball[i] = new Ball();
	}
	for(int i = 0; i < 500; i++){
		bullets[i] = GameObject();
	}
	
	glutTimerFunc(1000,HandleTimer,1); /// See HandleTimer(...)

	
	/*GLfloat diffcolor[] = { 0.65f, 0.65f, 0.65f, 1.0f };
	GLfloat speccolor[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat ambcolor[] =  { 0.1, 0.1, 0.1, 1.0 };

	glLightfv(GL_LIGHT1,GL_AMBIENT,ambcolor);
	glLightfv(GL_LIGHT2,GL_DIFFUSE,diffcolor);
    glLightfv(GL_LIGHT3,GL_SPECULAR,speccolor);*/



	

	glutMainLoop(); /// This starts the main loop which will 
					/// call the appropreate subroutine 
					/// given the event
}



/// If the window changes size this subroutine will be called 
/// note: This subroutine will be called upon the creation of the window since, logically,
/// the window has changed from nothing to something	

void ChangeSize(GLsizei w, GLsizei h){
	glViewport(0,0,w,h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
	gluPerspective(45.0f,aspectRatio,0.1f,1000.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		
}



/// Whenever the scene needs to be redrawn this function is called

void RenderScene(void){
	
	static float a = 0.0;
	
	GLfloat lightpos[] = { 0.0, 0.0,-10.0, 0.0 };
	glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  /// Clears the screen and the z-buffer
	
	glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
	glPushMatrix();
	
	for(int i = 0; i<NUM_BALLS; i++){
		ball[i]->Render();
	}
	for(int i = 0; i < 500; i++){
		if(bullets[i].alive){
			bullets[i].Render();
		}
	}
//	p->Render();
	cloth->Render();
	///::glutWireSphere();
	glPopMatrix();
	
	
	glFlush(); /// Shove everything through the "pipeline" 
	glutSwapBuffers();
	
}



void HandleTimer(int ID){
	/// This function send a message to the main loop that it's time to call
	/// the DisplayFunc which I called "RenderScene"
	glutPostRedisplay();
	for(int i = 0; i<NUM_BALLS; i++){
		ball[i]->Update(0.033);
		//printf("%f\n",ball[i]->position);
	}
	c.GetInstance();
	c2.GetInstance();
	CheckCollision(); 
	for(int i = 0; i < 500; i++){
		if(bullets[i].alive){
			bullets[i].Update(0.033);
		}
	}
//	p->Update(0.033);
	cloth->Update(0.033);
	/// The first value is the number of millseconds before the next event
	/// The second arg is a pointer to the callback function
	/// The third is the ID number of this timer 	
	glutTimerFunc(33,HandleTimer,1);
}



void FunctionKeys(int key, int x, int y){
	/// this function is called whenever a button off the standard keybord is pressed
	/// for example the function keys or the arrow keys - hint
	/// Look for the following
	if(key == GLUT_KEY_UP)printf("UP arrow\n");
		/// GLUT_KEY_DOWN
		/// GLUT_KEY_RIGHT
		/// GLUT_KEY_LEFT
}



void Keyboard(unsigned char key, int x, int y){
	printf("%c<%d> %d %d\n",key,key,x,y);
	if(key=='q' || key=='Q' || key == 27) exit(0);
	if(key == 'w' || key == 'W') c.ZoomIn(Vector(5.0f, 0.0f, 0.0f));
	if(key == 's' || key == 'S') c.Rotate(Vector (0.0f, 0.0f, -5.0f));
	if(key == 'a' || key == 'A') c.Rotate(Vector (5.0f, 0.0f, 0.0f));
	if(key == 32 || key == 'F'){
		for(int i = 0; i < 500; i++){
			if(!bullets[i].alive){
				bullets[i].alive = true;
				break;
			}
		}
	}
}


void CleanUp(void) {    //This is a non-OOP ~destructor
	printf("About to clean up");
}
void CheckCollision(){
	for(int i=0; i<NUM_BALLS; i++){
		for(int j=i+1; j<NUM_BALLS; j++){
			float dist = ball[i]->CalcDistance(ball[j]);
			
			if(dist < ball[i]->radius + ball[j]->radius){
				printf("%f\n", ball[i]->radius + ball[j]->radius);
				Vector unit_normal = ball[j]->position-ball[i]->position;
				Vector normalize_unit = unit_normal/(sqrtf((unit_normal.x * unit_normal.x) + (unit_normal.y * unit_normal.y)));
				float dot1 = ((ball[i]->velocity.x * normalize_unit.x) + (ball[i]->velocity.y * normalize_unit.y));
				float dot2 = ((ball[j]->velocity.x * normalize_unit.x) + (ball[j]->velocity.y * normalize_unit.y));
				double impact_angle = acos(dot1 / sqrtf((ball[i]->velocity.x * ball[i]->velocity.x) + (ball[i]->velocity.y * ball[i]->velocity.y)) * sqrtf((normalize_unit.x *normalize_unit.x) + (normalize_unit.y + normalize_unit.x))); 
				if(impact_angle < (3.14159 / 2)){
					float epsilon = 0.8f;
					float v1_norm = ((ball[i]->mass * dot1) + (ball[j]->mass * dot2) - (epsilon * (dot1 - dot2) * ball[j]->mass)) / (ball[i]->mass + ball[j]->mass);
					float v2_norm = ((ball[i]->mass * dot1) + (ball[j]->mass * dot2) - (epsilon * (dot2 - dot1) * ball[i]->mass)) / (ball[i]->mass + ball[j]->mass);
					float change_v1_norm = v1_norm - dot1;
					float change_v2_norm = v2_norm - dot2;
					Vector vel1_collision = normalize_unit * (change_v1_norm);
					Vector vel2_collision = normalize_unit * (change_v2_norm);
					ball[i]->velocity = ball[i]->velocity + (vel1_collision);
					ball[j]->velocity = ball[j]->velocity + (vel2_collision);
				}
			}
		}
	}
}

