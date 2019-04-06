#include <GL/glut.h>

class Entidade{
	public:
		double x,y,z;
		double angulo;
		Entidade (){
			this->angulo=0;
		}
		Entidade (int x,int y,int z){
			this->x=x;
			this->y=y;
			this->z=z;
		}
		void update(){
			this->angulo+=0.9;
		}

		void display(){
			glPushMatrix();
			glTranslated(this->x,this->y,this->z);
			glRotatef(this->angulo,0,0,1);
		//	glutWireCube(1);
			glutSolidCube(0.7);
			glPopMatrix();
		}
};
