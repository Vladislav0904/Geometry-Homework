#include "Rectangle.h"

Rectangle::Rectangle(point_t bottomLeft, point_t topRight)
{
	bottomLeft_ = bottomLeft;
	topRight_ = topRight;
}

Rectangle::Rectangle(rectangle_t a)
{
	bottomLeft_ = point_t(a.getPos().getX() - a.getWidth() / 2, a.getPos().getY() - a.getHeight() / 2);
	topRight_ = point_t(a.getPos().getX() + a.getWidth() / 2, a.getPos().getY() + a.getHeight() / 2);
}

std::string Rectangle::getName() {
	return "RECTANGLE";
}

double Rectangle::getArea() {
	rectangle_t a = getFrameRect();
	return a.getWidth() * a.getHeight();
}

rectangle_t Rectangle::getFrameRect() {
	rectangle_t a = rectangle_t(getTopRight().getX() - getBottomLeft().getX(), getTopRight().getY() - getBottomLeft().getY(), point_t((getBottomLeft().getX() + getTopRight().getX()) / 2, (getBottomLeft().getY() + getTopRight().getY()) / 2));
	return a;
}

void Rectangle::move(double k) {
	setBottomLeft(point_t(getBottomLeft().getX() + k, getBottomLeft().getY() + k));
	setTopRight(point_t(getTopRight().getX() + k, getTopRight().getY() + k));
}

void Rectangle::move(double x, double y) {
	rectangle_t a = getFrameRect();
	a.setPos(point_t(a.getPos().getX() + x, a.getPos().getY() + y));
	Rectangle result = Rectangle(a);
	setBottomLeft(result.getBottomLeft());
	setTopRight(result.getTopRight());
}

void Rectangle::scale(double k) {
	rectangle_t a = getFrameRect();
	a.setWidth(a.getWidth() * k);
	a.setHeight(a.getHeight() * k);
	Rectangle result = Rectangle(a);
	setBottomLeft(result.getBottomLeft());
	setTopRight(result.getTopRight());
}


Rectangle& Rectangle::clone() const
{
	Rectangle* rect = new Rectangle(*this);
	return *rect;
}