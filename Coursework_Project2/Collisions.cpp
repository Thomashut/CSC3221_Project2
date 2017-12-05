#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <math.h>
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

// Just storing pi here to save doing extra calculations or importing it from somewhere else, helps save performance
const static float pi = 3.14159265359;

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
	return( ((sqr2.getx() >= sqr1.getx() && sqr2.getx() <= sqr1RightCornerX) &&
			(sqr2.gety() >= sqr1.gety() && sqr2.gety() <= sqr1RightCornerY) )
											
											||
			
			((sqr1.getx() >= sqr2.getx() && sqr1.getx() <= sqr2RightCornerX) &&
			(sqr1.gety() >= sqr2.gety() && sqr1.gety() <= sqr2RightCornerY)) );

}

/*
	Calculate whether a collision between two circles has occured by seeing if their radi have
	overlapped with one another. The first section calulates the distance beteween them and then the second
	section calculates their combined radi and if the distance between them is less than their combined
	radi then they must be touching. If the distance between the two circles is greater than the combined
	radi then they are too far away from one another and they cannot be touching.
*/
static bool circleCircleCollision(const Circle& crl1, const Circle& crl2)
{
	float combinedCircumfrance = crl1.getRadius() + crl2.getRadius();
	float distance = abs(crl1.getx - crl2.getx()) + abs(crl1.gety() - crl2.gety());

	return distance <= combinedCircumfrance;
}

/*
	Calculates whether a collison between a circle and rectangle has occured by seeing if their distance
	between their coordinates is less than or equal to their combined peremeter/radius. If the distance between
	them is greater than their combined radius/paremeter then they cannot be touching and this function
	will return false. However, if the distance between them is less than the combined peremter/radius the
	two shapes must overlap in some way
*/
static bool rectangleCircleCollision(const Square& s1, const Circle& s2)
{
	float combinedRadius = pow((s1.getWidth() + s1.getHeight()) + s2.getRadius(),2.0);
	float distance = pow(s1.getx() - s2.getx(),2.0) + pow(s1.gety() - s1.gety(),2.0);

	return distance <= combinedRadius;
}