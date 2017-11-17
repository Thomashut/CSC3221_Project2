#pragma once
#include "Shape.h";
/*
	Author : Thomas Hutchinson
	File   : Circle.h
	Purpose: Programming for Games - Coursework 2
	Description:
		This header file inherits from the shape header. This header itself provides additional
		implimentation guidelines about what a circle class requires. The class itself will
		represent a circle shape.
*/

const static float DEFAULT_RADIUS = 1;
class Circle : public Shape
{
	public:
		// Default constructor
		Circle();

		// Copy constructor
		Circle(const Circle& s);

		// Normal Constructor
		Circle(float x, float y, float size, float radius);

		virtual ~Circle();

		virtual bool collision(const Shape& s);

		float getRadius() const;

		void setRadius(float radius);

		virtual bool operator==(const Circle& s);

		virtual Circle& operator=(const Circle& s);

		//friend std::ostream& operator<<(std::ostream& os, const Circle& c);
	private:
		float radius;

};

//std::ostream& operator<<(std::ostream& os, const Circle& c)
//{
//	os << "Circle's X Position: " << c.getx() << " Circle's y Position: " << c.gety() <<
//		" Circle's Size: " << c.getSize() << " Circles's Radius: " << c.getRadius() << "\n";
//	return os;
//}