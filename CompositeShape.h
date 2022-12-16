#pragma once
#include "shape.h"
#include <iostream>
class CompositeShape :
    public Shape
{
public:
    CompositeShape();
    CompositeShape(int length);
    void push(Shape* item);
    void print();
    virtual std::string getName() { return "COMPLEX"; };
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x, double y);
    virtual void move(double k);
    virtual void scale(double k);
    void sort();
    virtual CompositeShape& clone() const;
private:
    int itemsMax = 0;
    int itemsTotal = 0;
    Shape** items;
};

