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
const int WIDTH = 500;
const int HEIGHT = 500;

// Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

// Control when was the last update() called.
int gTimeLastUpdateMs = 0;

// Control the value of each color channel used to display a square.
GLfloat updateValue = 0.0f;

double x[4]={0,0.3,2.7,3};
double y[4]={0,1,1,0};

void bezier(double * xi, double * yi,const int t){
	double aux=pow((1-t),3)*x[0] + 3*t*pow((1-t),2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
	xi=&aux;
	aux=pow((1-t),3)*y[0] + 3*t*pow((1-t),2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
	yi=&aux;
	std::cout<<"xi: "<<*xi<<" yi: "<<*yi<<std::endl;
}
/* 
 * Fazer a curva
 *
 * fazer a bagaça mudar os pontos conforme clico com o mouse
 *
 *
 */

void display()
{
	glTranslatef(-1.5,0,-10);
//	glRotatef(updateValue,1,0,0);
	glColor3f(1,1,1);
	glBegin(GL_POINTS);
		glVertex2f(x[0],y[0]);
		glVertex2f(x[1],y[1]);
		glVertex2f(x[2],y[2]);
		glVertex2f(x[3],y[3]);
	glEnd();
	double xi=0,yi=0;
//	std::cout<<"entrou aqui\n";
	glBegin(GL_POINTS);
	for(double t=0; t<=1; t+=0.001){
//		bezier(&xi,&yi,t);
		xi=pow((1-t),3)*x[0] + 3*t*pow((1-t),2)*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
		yi=pow((1-t),3)*y[0] + 3*t*pow((1-t),2)*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
//		std::cout<<"t: "<<t<<" x: "<<xi<<" y: "<<yi<<std::endl;
		glVertex2f(xi,yi);
	}
	glEnd();
//	std::cout<<"jamais saiu\n";
}

// This function is called periodically. The param delta contains the time
// difference between the current and the last frame, in seconds.
void update(double delta)
{
	// Update the color of the square based on the time
	updateValue += (GLfloat)delta*2;
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
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
	glClearColor(0, 0, 0, 0);

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
	glutCreateWindow("BEZIERRRRRRRRRRRRRRRRRRRRR");

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
