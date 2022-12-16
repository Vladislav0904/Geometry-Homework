#include "RectTrapezium.h"

RectTrapezium::RectTrapezium(point_t bottomLeft, double bottomBase, double topBase, double height) {
    bottomLeft_ = bottomLeft;
    bottomBase_ = bottomBase;
    topBase_ = topBase;
    height_ = height;
}


std::string RectTrapezium::getName() {
	return "RECTRAPEZIUM";
}

double RectTrapezium::getArea() {
    return (getBottomBase() + getTopBase()) / 2 * getHeight();
}

rectangle_t RectTrapezium::getFrameRect() {
    return rectangle_t(getBottomBase(), getHeight(), point_t(getBottomLeft().getX() + (getBottomBase() + getTopBase()) / 2, getBottomLeft().getY() + getHeight() / 2));
}

void RectTrapezium::move(double k) {
    setBottomLeft(point_t(getBottomLeft().getX() + k, getBottomLeft().getY() + k));
}

void RectTrapezium::move(double x, double y) {
    setBottomLeft(point_t((x - (getBottomBase() + getTopBase()) / 4), y - getHeight() / 2));
}

void RectTrapezium::scale(double k) {
    setBottomBase(getBottomBase() * k);
    setTopBase(getTopBase() * k);
    setHeight(getHeight() * k);
    point_t a = point_t(getBottomLeft().getX() + (getBottomBase() + getTopBase()) / 2, getBottomLeft().getY() + getHeight() / 2);
    setBottomLeft(point_t(a.getX() - (getBottomBase() + getTopBase()) / 4, a.getY() - getHeight() / 2));
}


RectTrapezium& RectTrapezium::clone() const
{
    RectTrapezium* rect = new RectTrapezium(*this);
    return *rect;
}