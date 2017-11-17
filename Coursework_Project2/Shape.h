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
const static float DEFAULT_SIZE = 1;

class Shape 
{

public:
	virtual ~Shape();

	// Getters for the shape class, all shapes will move on the grid in the same way so these methods can stay the same
	float getx() const;
	float gety() const;

	// Returns the size of the shape
	float getSize() const;

	// Given two floats this will move the shape to a specific location on the grid (teleport)
	void move(float x, float y);

	// When called will increase the x or y coordinate by 1
	void incrementx();
	void incrementy();

	// When called with decrease the x or y coordinate by 1
	void decrementx();
	void decrementy();

	// A base function that can be overriden by children classes. When called it will detect if it has collided with something
	virtual bool collision(const Shape* s);

	/*
		The following overloads will increment and decrement the current shapes position respectively.So when a ++ is called
		upon a shape that will increment both the x and the y cords by 1 or -1 respectively. Making the shapes move in a diagonal
		line
	*/
	Shape& operator++(int);
	Shape& operator++();

	Shape& operator--(int);
	Shape& operator--();

	// Default implimentation for the equals operator
	virtual bool operator==(const Shape& s);

	// Default output for a shape to make for easier debugging
	friend std::ostream& operator<<(std::ostream& os, const Shape& s);
	

	//Start of Setter Methods
	void setx(float x);
	void sety(float y);
	void setSize(float size);

private:
	float x;
	float y;

	float size;
};

// Implimentation of the default output function.
std::ostream& operator<<(std::ostream& os, const Shape& s)
{
	os << "Shape's X cord: " << s.x << " Shapes Y cord: " << s.y << " Shapes Size: " << s.size << "\n";
	return os;
}

