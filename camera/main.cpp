/**
 * This demo shows how to periodically call an update() function and calculate
 * the time difference between those updates, i.e. delta time.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <math.h>
 // Constants to define the width/height of the window
const int WIDTH = 500;
const int HEIGHT = 500;

// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control when was the last update() called.
int gTimeLastUpdateMs = 0;

// Control the value of each color channel used to display a square.
GLfloat gValueR = 0.0f;
GLfloat gValueG = 0.0f;
GLfloat gValueB = 0.0f;

void renderCoordinateAxis()
{
	//Z
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex3f(0.0,0.0,-100);
		glVertex3f(0.0,0.0,100);
	glEnd();
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-100.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(100.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 100.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -100.0);
	glEnd();
	
}

void piramid(){
	glPushMatrix();
	for(int i=0;i<4;i++){
		glRotatef(90,0,1,0);
		glPushMatrix();
			glColor3d((i%2)*255,(i%3)*255,(i%4)*255);
//			glRotatef(45,1,0,0);
//			glTranslatef(0,);	
			glBegin(GL_TRIANGLES);
				glVertex3f(0,0,0);
				glVertex3f(-1,-1,-1);
				glVertex3f(1,-1,-1);

			glEnd();
		glPopMatrix();
	}
	glPopMatrix();
}

void cubo(){


}

static const double chess_size = 28;
static const double scale = 0.4;
int color=0;
void chess(){
	glPushMatrix();
	glRotatef(90,1.0f,0,0);
	glScalef(scale,scale,scale);
	glTranslatef(-(chess_size/2)-1, -(chess_size/2)-1,0);
	for(int x=0; x<chess_size; x++){
		glTranslatef(0,1,0);
		glPushMatrix();
		for(int z=0; z<chess_size; z++){
				color=(x+z)%2;	
				glColor3f(0,0,color);
				glTranslatef(1,0,0);

				glRectf(0,0,1,1);
		}
		glPopMatrix();
	}
	glLoadIdentity();
	glPopMatrix();
}



double z=-10;
double angle=0;
double tempo = 0;
void display()
{
	// Move the camera away from the origin along the Z axis by 10 pixels.
	

	renderCoordinateAxis();
// Render the X and Y axis to guide ourselves.

	// Render a square using the informed color.
	GLfloat r = sin(gValueR);
	GLfloat g = sin(gValueG);
	GLfloat b = sin(gValueB);
	glColor3f(r, g, b);
	chess();
	glTranslatef(0,1.5,0);
	glutWireTeapot(2);
	glTranslatef(0,1.5,0);
	glRotatef(180,1,0,1);
	piramid();
	glTranslatef(1,1,0);
	piramid();
}

// This function is called periodically. The param delta contains the time
// difference between the current and the last frame, in seconds.
void update(double delta)
{
	// Update the color of the square based on the time
	gValueR += (GLfloat)delta;
	gValueG += (GLfloat)(delta * 1.3);
	gValueB += (GLfloat)(delta * 1.5);
	if (tempo<= 5){
		tempo+=delta;
		std::cout<<"tempo: "<<tempo<<'\n';
		z+=0.02;
	}else if(angle<1080){
		angle+=6;
	}
	std::cout<<"angle:"<<angle<<'\n';	
}

GLenum mode = GL_LESS; 
void keyboard(unsigned char key, int x, int y)
{
	switch(key){
			case 27:
				// ESC key
				exit(0);
			case ' ':
				z=-10;
				tempo=0;
				angle=0;
				break;
			case '1':
				std::cout<<"GL_ALWAYS"<<'\n';
				mode = GL_ALWAYS;
				break;
			case '2':
				std::cout<<"GL_LESS"<<'\n';
				mode = GL_LESS;
				break;
			case '3':
				std::cout<<"GL_NEVER"<<'\n';
				mode = GL_NEVER;
			break;
	}
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}
void internalDisplay()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(mode);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Call our display() function
	glTranslatef(0,-1,z);
	glRotatef(20,1.0f,0.0f,0.0f);
	glRotatef(angle,0.0f,1.0f,0.0f);
	display();

	// Start the rendering on a new frame
	glutSwapBuffers();
}

void internalUpdate(int value)
{
	int timeNowMs = glutGet(GLUT_ELAPSED_TIME);
	double deltaSeconds = (timeNowMs - gTimeLastUpdateMs) / 1000.0;

	// Save the time update() was called
	gTimeLastUpdateMs = timeNowMs;
	//std::cout << "timeNOw = " << timeNowMs << ", deltaSeconds = " << deltaSeconds << std::endl;
	// Invoke our update() function
	update(deltaSeconds);

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);

	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);

	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 100.0);

	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	
	// Register a few callback functions
	glutDisplayFunc(internalDisplay);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, internalUpdate, 0);

	glutMainLoop();
	return 0;
}
