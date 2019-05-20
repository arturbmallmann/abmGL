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
#include <SimpleForms.h>
//#include <AbstractPiece.h>
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

void display()
{
	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -20.0f);

	glRotatef(30, 1, 0,0);
	glRotatef(gValueR*20, 0.0f, 1.0f, 0.0f);
	glCullFace(GL_BACK);
	// Render a square using the informed color.
	GLfloat r = sin(gValueR);
	GLfloat g = sin(gValueG);
	GLfloat b = sin(gValueB);
	glColor3f(r, g, b);
//	glRectf(-1.0f, 1.0f, 1.0f, -1.0f);
//	glutWireTeapot(2);
	chessTable(0.3,8.0);
	//piramid();
	cube(2.0f,(unsigned int *)0); //O arquivo em que construi o cubo se encontra na pasta ../lib/
}

// This function is called periodically. The param delta contains the time
// difference between the current and the last frame, in seconds.
void update(double delta)
{
	// Update the color of the square based on the time
	gValueR += (GLfloat)delta;
	gValueG += (GLfloat)(delta * 1.3);
	gValueB += (GLfloat)(delta * 1.5);
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
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
	glDepthFunc(GL_LESS);
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Call our display() function
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
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);

	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Trabalho cubo");

	glEnable(GL_CULL_FACE);

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