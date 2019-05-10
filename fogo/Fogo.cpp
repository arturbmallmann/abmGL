#include "Fogo.h"
// 3D point/vector class
//Fogo::Fogo(Point position, double scale = 0.1,double speed=0.1){
Fogo::Fogo(Point position, double scale ,double speed){
	this->position = position;
	this->stat = 0.0;
	this->initV = scale;
	this->scale = scale;
}
void Fogo::update(){
	//usar LERP pra variar cor e tamanho
	// LERP variando de A=10 a B=30
	// 10 + (B-A)
	// 10 + (30-10)
	// 10 + 20 * (variação) 0.0 -> 1.0
			this->stat += this->speed; 
}
double Fogo::size(){
	return initV + stat;
}
void Fogo::display(){
	glPushMatrix();
	glScalef(this->size(),this->size(),this->size());
	glTranslate(this->position.x(),this->position.y(),this->position.z());
	glPopMatrix();
}
void Fogo::reset(){
	stat+=0.0;
}
