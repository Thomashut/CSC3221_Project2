#pragma once
#include "Shape.h";
#include <ostream>;
/*
	Author : Thomas Hutchinson
	File   : Square.h
	Purpose: Programming for Games - Coursework 2
	Description:
		Inherits from the shape header. This header provides information about the 
		square varient of a shape.
*/

class Square : public Shape
{
	public:
		// Default constructor
		Square();

		// Copy Constructor
		Square(const Square& s);

		// Normal Constructor
		Square(float x, float y, float size);

		// Overriden desconstructor
		virtual ~Square();

		// Override of collision function for specificly squares
		virtual bool collision(const Shape& s);

		// Overload of the assignment operator
		virtual Square& operator=(const Square& s);

		virtual bool operator==(const Square& s);

		// Override of output function for square specific properties
		//friend std::ostream& operator<<(std::ostream& os, const Square& s);
	private:

};

//// Implimentation of Square's specific output function
//std::ostream& operator<<(std::ostream& os, const Square& s)
//{
//	os << "Square's X Position: " << s.getx() << " Square's y Position: " << s.gety() <<
//		" Square's Size: " << s.getSize() << "\n";
//	return os;
//}