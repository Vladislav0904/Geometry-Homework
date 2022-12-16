#include "ShapeContainer.h"

ShapeContainer::ShapeContainer()
{
	shapes_ = new Shape * [0];
	items_ = 0;
}

ShapeContainer::ShapeContainer(const ShapeContainer& compositeShape)
{

	items_ = compositeShape.items_;
	shapes_ = new Shape * [items_];

	for (int i = 0; i < items_; i++)
		shapes_[i] = &compositeShape.shapes_[i]->clone();
}

ShapeContainer::~ShapeContainer()
{
	for (int i = 0; i < items_; i++)
		delete shapes_[i];
	delete[] shapes_;
}

void ShapeContainer::push(Shape& shape)
{
	Shape** shapes = new Shape * [items_];

	for (int i = 0; i < items_; i++)
		shapes[i] = shapes_[i];

	shapes_ = new Shape * [items_ + 1];

	for (int i = 0; i < items_; i++)
		shapes_[i] = shapes[i];

	shapes_[items_] = &shape;
	items_++;

	for (int i = 0; i < items_ - 1; i++)
		delete shapes[i];
	delete[] shapes;
}

void ShapeContainer::print()
{
	for (int i = 0; i < items_; i++)
		std::cout << *shapes_[i] << '\n';
}

void ShapeContainer::sort()
{
	shapeSort(*shapes_, items_);
}

void ShapeContainer::move(double x, double y)
{
	for (int i = 0; i < items_; i++)
		shapes_[i]->move(x, y);
}

void ShapeContainer::scale(double k)
{
	for (int i = 0; i < items_; i++)
		shapes_[i]->scale(k);
}

Shape& ShapeContainer::operator[] (int index)
{
	return *shapes_[index];
}

int ShapeContainer::getItems()
{
	return items_;
}