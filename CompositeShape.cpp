#include "CompositeShape.h"
#include "Rectangle.h"
#include <algorithm>
#include <iostream>

CompositeShape::CompositeShape() {
	itemsTotal = 0;
	itemsMax = 1;
	items = new Shape * [itemsMax];
}

CompositeShape::CompositeShape(int length) {
	itemsTotal = 0;
	itemsMax = length;
	items = new Shape * [itemsMax];
}

rectangle_t CompositeShape::getFrameRect() {
	Rectangle buf = Rectangle(items[0]->getFrameRect());
	double
		xL = buf.getBottomLeft().getX(),
		xM = buf.getTopRight().getX(),
		yL = buf.getBottomLeft().getY(),
		yM = buf.getTopRight().getY();
	for (int i = 1; i < itemsTotal; i++) {
		buf = items[i]->getFrameRect();
		xL = std::min(xL, buf.getBottomLeft().getX());
		xM = std::max(xM, buf.getTopRight().getX());
		yL = std::min(yL, buf.getBottomLeft().getY());
		yM = std::max(yM, buf.getTopRight().getY());
	}
	double
		midX = (xL + xM) / 2.0,
		midY = (yL + yM) / 2.0,
		width = abs(xM - xL),
		height = abs(yM - yL);
	return rectangle_t(width, height, point_t(midX, midY));
}

double CompositeShape::getArea()
{
	double area = 0.0;
	for (int i = 0; i < itemsTotal; i++)
		area += items[i]->getArea();

	return area;
}

void CompositeShape::push(Shape* item) {
	if (itemsTotal < itemsMax) {
		items[itemsTotal] = item;
		itemsTotal += 1;
	}
	else throw std::runtime_error("Invalid array index");

}

void CompositeShape::print() {
	for (int i = 0; i < itemsTotal; i++) {
		std::cout << *items[i] << "\n";
	}
}

void CompositeShape::move(double k) {
	for (int i = 0; i < itemsTotal; i++) {
		items[i]->move(k);
	}
}

void CompositeShape::move(double x, double y) {
	rectangle_t rect = getFrameRect();
	double
		dX = x - rect.getPos().getX(),
		dY = y - rect.getPos().getY();

	for (int i = 0; i < itemsTotal; i++)
		items[i]->move(dX, dY);
}

void CompositeShape::scale(double k)
{
	for (int i = 0; i < itemsTotal; i++)
		items[i]->scale(k);
}

CompositeShape& CompositeShape::clone() const
{
	CompositeShape* compositeShape = new CompositeShape(*this);
	return *compositeShape;
}