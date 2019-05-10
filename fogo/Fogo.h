#ifndef		__FOGO_H__
#define		__FOGO_H__

#include <GL/freeglut.h>
#include <algorithm>

#include <math.h>
#include "Point.h"
// 3D point/vector class
class Fogo {
public:
	Fogo(Point, double,double);
	void update();
	void display();
	void reset();
	
	double size();
	double color();
	//getters
private:
	Point position;
	double stat,initV,speed,scale;
	
};
#endif
