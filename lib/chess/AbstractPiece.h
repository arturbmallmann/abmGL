#ifndef ABSTRACT_PIECE_H
#define ABSTRACT_PIECE_H
#include "Position.h" 
class AbstractPiece{
	public:
		double scale, angle;
		Position position;
		AbstractPiece ();
		AbstractPiece (Position position,double scale,double angle);
		virtual void update();

		virtual void display();
};
#endif
