#pragma once
#include "shape.h"
#include <iostream>

class Rectangle : public Shape
{
public:
    Rectangle() {};
    Rectangle(point_t bottomLeft, point_t topRight);
    Rectangle(rectangle_t a);
    Rectangle(const Rectangle& obj) { bottomLeft_ = obj.bottomLeft_; topRight_ = obj.topRight_; };
    virtual std::string getName();
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x, double y);
    virtual void move(double k);
    virtual void scale(double k);
    virtual Rectangle& clone() const;
    point_t getBottomLeft() { return bottomLeft_; }
    point_t getTopRight() { return topRight_; }
    void setBottomLeft(point_t bottomLeft) { bottomLeft_ = bottomLeft; }
    void setTopRight(point_t topRight) { topRight_ = topRight; }
private:
    point_t bottomLeft_ = point_t(0.0, 0.0);
    point_t topRight_ = point_t(0.0, 0.0);
};

