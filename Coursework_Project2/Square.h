#pragma once
#include "Shape.h";
/*
	Author : Thomas Hutchinson
	File   : Square.h
	Purpose: Programming for Games - Coursework 2
	Description:
		Inherits from the shape header. This header provides information about the 
		square varient of a shape. A square is represented by an x and a y point on a 2D plane.
		This point marks the bottom left corner of the square. From there the width and the height
		can be used to callculate the size of the square on the grid.
*/
const static float DEFAULT_WIDTH = 1;
const static float DEFAULT_HEIGHT = 1;
class Square : public Shape
{
	public:
		// Default constructor
		Square();

		// Copy Constructor
		Square(const Square& s);

		// Normal Constructor
		Square(float x, float y, float width, float height);

		// Overriden desconstructor
		virtual ~Square();

		float getWidth() const;

		float getHeight() const;

		void setWidth(float width);
	
		void setHeight(float height);

		// Will return the top right hand corner of the rectangle  
		float calculateShapeX() const;
		float calculateShapeY() const;

		// Overload of the assignment operator
		virtual Square& operator=(const Square& s);

		bool operator==(const Square& s);

		// Function which returns a single char representing the shape type
		virtual char whatAmI() const;

	private:
		float* width = nullptr;
		float* height = nullptr;

};

//std::ostream& operator<< (std::ostream& os, const Square& s)
//{
//	os << " : x = " << s.getx() << " y = " <<
//		s.gety() << " width = " << s.getWidth() << " height = " << s.getHeight() << "\n";
//
//	return os;
//}
