#pragma once
struct point_t 
{	
public:
	point_t() {x_ = 0.0; y_ = 0.0;};
	point_t(double x, double y) {x_ = x; y_ = y;};
	~point_t() = default;
	point_t(const point_t& obj) { x_ = obj.x_; y_ = obj.y_; };
	double getX() { return x_; };
	double getY() { return y_; };
	void print() { std::cout << "point_t(" << x_ << ' ' << y_ << ")\n"; }
private:
	double x_{ 0.0 };
	double y_{ 0.0 };
};

struct rectangle_t {
public:
	rectangle_t() { width_ = 0.0; height_ = 0.0; pos = point_t(0.0, 0.0);};
	rectangle_t(double width, double height, point_t centerPos) : width_(width), height_(height), pos(centerPos) {};
	double getWidth() { return width_; }
	double getHeight() { return height_; }
	point_t getPos() { return pos; }
	void setWidth(double width) { width_ = width; }
	void setHeight(double height) { height_ = height; }
	void setPos(point_t point) { pos = point; }
	void print() { std::cout << "rectangle_t(" << width_ << ' ' << height_ << ")\n"; }

	friend std::ostream& operator<< (std::ostream& out, rectangle_t& rectangle);


	

private:
	double width_{ 0.0 };
	double height_{ 0.0 };
	point_t pos = point_t(0.0, 0.0);
};