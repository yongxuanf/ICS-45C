#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Circle : public Shape
{
public:
	Circle(int cX, int cY, double r, string name): Shape(cX,cY,name), radius(r)
	{}
	virtual double area()
	{
		return (radius * radius) * PI;
	}
	virtual void draw()
	{
		for (int i = 0; i <= 2*radius;++i)
		{
			for (int j= 0; j <= 2*radius; ++j)
			{
				double distance = sqrt((i-radius) * (i-radius) + (j-radius)*(j-radius));
				if (distance > radius - 0.5 && distance < radius +0.5)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << "\n";
		}
	}
private:
	const double PI = 3.14159;
	double radius;
};

#endif