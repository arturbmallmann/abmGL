#include "AbstractPiece.h" 
#include "Position.h" 
AbstractPiece::AbstractPiece(){
	this->angle=0;
	this->position = Position(0,0,0);
};
AbstractPiece::AbstractPiece(Position position,double scale,double angle){
	this->position = position;
	this->scale = scale;
	this->angle = angle;
};
