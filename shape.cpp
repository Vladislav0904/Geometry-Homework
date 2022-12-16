#include "shape.h"
#include "Rectangle.h"
#include "base-types.h"
#include <iostream>
#include <iomanip>

std::ostream& operator << (std::ostream& os, Shape& p)
{
	os << std::fixed << std::setprecision(1);
	try {
		Rectangle a = Rectangle(p.getFrameRect());
		os << p.getName() << " " << p.getArea() << " " << a.getBottomLeft().getX() << " " << a.getBottomLeft().getY() << " " << a.getTopRight().getX() << " " << a.getTopRight().getY();
		return os;
	}
	catch (std::exception const& e) {};
}

bool operator<(Shape& s1, Shape& s2)
{
	return (s1.getArea() < s2.getArea());
}

void shapeSort(Shape*& shape, int items)
{
	for (int i = 0; i < items; i++)
	{
		for (int j = 0; j < items - 1; j++)
		{
			if (**(&shape + j + 1) < **(&shape + j))
			{
				Shape* buffer = *(&shape + j);
				*(&shape + j) = *(&shape + j + 1);
				*(&shape + j + 1) = buffer;
			}
		}
	}
}