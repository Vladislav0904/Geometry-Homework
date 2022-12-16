#pragma once
#include <iostream>
#include "shape.h"
#include "base-types.h"

class ShapeContainer
{
private:
	Shape** shapes_;
	int items_;
public:
	ShapeContainer();
	ShapeContainer(const ShapeContainer& compositeShape);
	~ShapeContainer();



	void push(Shape& shape);
	void print();
	void sort();
	void move(double x, double y);
	void scale(double k);
	int getItems();
	Shape& operator[] (int index);
};