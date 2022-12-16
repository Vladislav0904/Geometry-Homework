#pragma once
#include "shape.h"
#include <iostream>


class RectTrapezium: public Shape
{
public:
    RectTrapezium() {};
    RectTrapezium(point_t bottomLeft, double bottomBase, double topBase, double height);
    RectTrapezium(const RectTrapezium& obj) { bottomLeft_ = obj.bottomLeft_; bottomBase_ = obj.bottomBase_; topBase_ = obj.topBase_; height_ = obj.height_;};
    virtual std::string getName();
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x, double y);
    virtual void move(double k);
    virtual void scale(double k);
    virtual RectTrapezium& clone() const;
    point_t getBottomLeft() { return bottomLeft_; }
    double getBottomBase() { return bottomBase_; }
    double getTopBase() { return topBase_; }
    double getHeight() { return height_; }
    void setBottomLeft(point_t bottomLeft) { bottomLeft_ = bottomLeft; }
    void setBottomBase(double bottomBase) { bottomBase_ = bottomBase; }
    void setTopBase(double topBase) { topBase_ = topBase; }
    void setHeight(double height) { height_ = height; }
private:
    point_t bottomLeft_ = point_t(0.0, 0.0);
    double bottomBase_ = 0.0;
    double topBase_ = 0.0;
    double height_ = 0.0;

};

