#pragma once
#include <iostream>
#include "base-types.h"

class Shape {
public:
	virtual double getArea() = 0;
	virtual rectangle_t getFrameRect() = 0;
	virtual void move(double x, double y) = 0;
	virtual void move(double k) = 0;
	virtual void scale(double k) = 0;
	virtual std::string getName() = 0 ;
	virtual Shape& clone() const = 0;
	friend std::ostream& operator << (std::ostream& os, Shape& p);
	friend bool operator<(Shape& s1, Shape& s2);
	friend void shapeSort(Shape*& shape, int items);
};