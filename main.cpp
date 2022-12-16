#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 
#include "Rectangle.h"
#include "RectTrapezium.h"
#include "CompositeShape.h"
#include "ShapeContainer.h"

void testFile();

RectTrapezium& readRectTrapezium(std::string& line);
Rectangle& readRectangle(std::string& line);
CompositeShape& readComplex(std::string& line, std::ifstream& inFile);
std::string& splitString(std::string string, int size);


int main() {
    std::cout << "Some tests: \n";
    Rectangle *a = new Rectangle(point_t(0.210, 0.0), point_t(5.0, 5.0));
	RectTrapezium *b = new RectTrapezium(point_t(0.0, 0.0), 10.0, 5.0, 7.0);
	CompositeShape cs(2);
	cs.push(a);
	cs.push(b);
	cs.print();
    std::cout << cs << "\n";
	testFile();

}

std::string& splitString(std::string string, int size)
{
	std::string* separatedString = new std::string[size];
	for (int i = 0; i < size - 1; i++)
	{
		int end = string.find(' ') + 1;
		separatedString[i] = string.substr(0, end);
		string = string.substr(end);
	}
	separatedString[size - 1] = string;
	return *separatedString;
}


Rectangle& readRectangle(std::string& line)
{
	std::string* sepStr = &splitString(line, 5);
	double
		x1 = std::stod(sepStr[1]),
		y1 = std::stod(sepStr[2]),
		x2 = std::stod(sepStr[3]),
		y2 = std::stod(sepStr[4]);
	Rectangle* rect = new Rectangle(point_t(x1, y1), point_t(x2, y2));
	return *rect;
}

RectTrapezium& readRectTrapezium(std::string& line)
{
	std::string* sepStr = &splitString(line, 6);
	double
		x = std::stod(sepStr[1]),
		y = std::stod(sepStr[2]),
		bottomBase = std::stod(sepStr[3]),
		topBase = std::stod(sepStr[4]),
		height = std::stod(sepStr[5]);

	RectTrapezium* trap = new RectTrapezium(point_t(x, y), bottomBase, topBase, height);
	return *trap;
}

CompositeShape& readComplex(std::string& line, std::ifstream& inFile)
{
    std::string* sepStr = &splitString(line, 2);

    int
        size = std::stod(sepStr[1]),
        items = 0;
    CompositeShape* complex = new CompositeShape(size);

    std::getline(inFile, line);
    while (line != "COMPLEXEND")
    {
        int end = line.find(' ');
        std::string name = line.substr(0, end);

        if (name == "RECTRAPEZIUM")
        {
			RectTrapezium* trap = &readRectTrapezium(line);
            complex->push(trap);
            items++;
        }
        else if (name == "RECTANGLE")
        {
            items++;
            complex->push(&readRectangle(line));
        }
        std::getline(inFile, line);
    }
    if (items != size)
        throw std::runtime_error("Wrong figure number in COMPLEX");
    return *complex;
}

void testFile()
{
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile)
    {
        std::cerr << "No file";
        exit(-1);
    }

    std::cout << "Figures:\n";
    ShapeContainer shapes;

    while (!inFile.eof())
    {
        std::string line;
        std::getline(inFile, line);
        int end = line.find(' ');
        std::string name = line.substr(0, end);
        if (name == "RECTRAPEZIUM")
        {
            try
            {
                shapes.push(readRectTrapezium(line));
                std::cout << shapes[shapes.getItems() - 1] << '\n';
            }
            catch (const std::exception&)
            {
                std::cerr << name << " wrong parameters\n";
            }
        }
        else if (name == "RECTANGLE")
        {
            try
            {
                shapes.push(readRectangle(line));
                std::cout << shapes[shapes.getItems() - 1] << '\n';
            }
            catch (const std::exception&)
            {
                std::cerr << name << " wrong parameters\n";
            }
        }
        else if (name == "COMPLEX")
        {
            try
            {
                shapes.push(readComplex(line, inFile));
                std::cout << shapes[shapes.getItems() - 1] << '\n';
            }
            catch (const std::exception&)
            {
                std::cerr << name << " wrong parameters\n";
            }
        }
        else if (name == "MOVE")
        {

            std::string* sepStr = &splitString(line, 3);
            double
                x = std::stod(sepStr[1]),
                y = std::stod(sepStr[2]);

            shapes.move(x, y);
            std::cout << "MOVE " << x << y << '\n';
        }
        else if (name == "SCALE")
        {
            std::string* sepStr = &splitString(line, 4);
            double
                x = std::stod(sepStr[1]),
                y = std::stod(sepStr[2]),
                k = std::stod(sepStr[3]);
            shapes.print();
            for (int i = 0; i < shapes.getItems(); i++)
            {
                //1
                rectangle_t rect = shapes[i].getFrameRect();
                double
                    midX = rect.getPos().getX(),
                    midY = rect.getPos().getY();
                //2
                shapes[i].move(x, y);
                //3
                rect = shapes[i].getFrameRect();
                //4
                double
                    dX = midX - rect.getPos().getX(),
                    dY = midY - rect.getPos().getY();
                //5
                shapes[i].scale(k);
                //6
                double
                    deltaX = dX * k,
                    deltaY = dY * k;
                //7
                shapes[i].move(deltaX, deltaY);
            }
            std::cout << "SCALE " << x << ' ' << y << ' ' << k << ' ' << '\n';
        }
    }

    std::cout << "\nSorted figures:\n";
    shapes.sort();
    shapes.print();
}