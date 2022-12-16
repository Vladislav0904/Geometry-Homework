#include <iostream>
#include "base-types.h"


std::ostream& operator<< (std::ostream& out, rectangle_t& rectangle)
{
	double
		xL = rectangle.pos.getX() - rectangle.width_ / 2,
		xM = rectangle.pos.getX() + rectangle.width_ / 2,
		yL = rectangle.pos.getY() - rectangle.height_ / 2,
		yM = rectangle.pos.getY() + rectangle.height_ / 2;
	out << '(' << xL << ' ' << yL << ") (" << xM << ' ' << yM << ')';
	return out;
}