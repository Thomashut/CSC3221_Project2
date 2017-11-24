#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
/*
	Author	: Thomas Hutchinson
	File	: Collisions.cpp
	Purpose	: Programming for Games - Coursework 2
	Description :
		A mixin class that takes shapes and runs functions that
		calculate for collisions. I decided to remove the collsions
		from the shapes themselves to provide additional functionality
		and extendability. This was I can easily model specific collisions between
		specific types of shapes and if in the future I add addtional shapes
		I can easily create additional functions here to handle that new behaviour
*/

/*	
	Expects 2 rectangles (squares) will return true if they are touching
	Will return false if they aren't touching or aren't actually squares
*/
static bool rectangleRectangleCollision(const Square& sqr1, const Square& sqr2)
{
	// Calculate the upper bounds of the two given squares
	float sqr1RightCornerX = sqr1.calculateShapeX();
	float sqr1RightCornerY = sqr1.calculateShapeY();

	float sqr2RightCornerX = sqr2.calculateShapeX();
	float sqr2RightCornerY = sqr2.calculateShapeY();

	/*
		If square twos x is within the lower and upper bound of square 1s x then true OR
		if square ones x is within the lower and upper bound of square 2s x then true OR
		if square twos y is within the lower and upper bound of square 1s y then true OR
		if square ones y is within the lower and upper bound of square 2s y then true
	*/
	return( (sqr2.getx() >= sqr1.getx() && sqr2.getx() <= sqr1RightCornerX) ||
				(sqr1.getx() >= sqr2.getx() && sqr1.getx() <= sqr2RightCornerX) ||
				(sqr2.gety() >= sqr1.gety() && sqr2.gety() <= sqr1RightCornerY) ||
				(sqr1.gety() >= sqr2.gety() && sqr1.gety() <= sqr2RightCornerY));

}

static bool circleCircleCollision(const Shape& crl1, const Shape& crl2)
{
	return true;
}

static bool rectangleCircleCollision(const Shape& s1, const Shape& s2)
{
	return true;
}