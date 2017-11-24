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

		float getRadius() const;

		void setRadius(float radius);

		virtual bool operator==(const Circle& s);

		virtual Circle& operator=(const Circle& s);

		// Function which returns a single char representing the shape type
		virtual char whatAmI() const;

	private:
		float radius;

};
