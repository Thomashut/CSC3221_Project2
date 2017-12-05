#pragma once
#include <ostream>;
/*
	Author : Thomas Hutchinson
	File   : Shape.h
	Purpose: Programming for Games - Coursework 2
	Description:
		An abstract base class that provides a base level of implimentation rules for all
		types that fall under a shape
*/
const static float DEFAULT_X = 1;
const static float DEFAULT_Y = 1;

class Shape 
{

public:
	Shape();

	Shape(float x, float y);

	Shape(const Shape& s);

	virtual ~Shape();

	// Getters for the shape class, all shapes will move on the grid in the same way so these methods can stay the same
	float getx() const;
	float gety() const;


	// When called will increase the x or y coordinate by 1
	void incrementx();
	void incrementy();

	// When called with decrease the x or y coordinate by 1
	void decrementx();
	void decrementy();

	/*
		The following overloads will increment and decrement the current shapes position respectively.So when a ++ is called
		upon a shape that will increment both the x and the y cords by 1 or -1 respectively. Making the shapes move in a diagonal
		line
	*/
	Shape& operator++(int);
	Shape& operator++();

	Shape& operator--(int);
	Shape& operator--();

	virtual Shape& operator=(const Shape& s);

	// Default implimentation for the equals operator
	bool operator==(const Shape& s);

	// Function which returns a single char representing the shape type
	virtual char whatAmI() const = 0;


	//Start of Setter Methods
	void setx(float x);
	void sety(float y);

private:
	float* x = nullptr;
	float* y = nullptr;
};

//std::ostream& operator<< (std::ostream& os, const Shape& s)
//{
//	os << " : x = " << s.getx() << " y = " <<
//		s.gety() << "\n";
//
//	return os;
//}

