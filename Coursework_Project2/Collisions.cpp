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
	Will return false if they aren't touching or aren't actually squares. Calculates this by checking
	to see if they are within each others x and y range.
*/

/*
A helper function will will calculate the distance between two sets of coordiantes and then return
it. This is used in the above functions in several places to help detect collision
*/
static float calculateDistance(float x1, float x2, float y1, float y2)
{
	return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}


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
	Will calculate whether or not two circles have collided by calculating their combined
	radius then checking to see if that combined radius is larger than the distance between the
	two shapes. If it combined radius is greater than the distance hen the two circles must be
	touching
*/
static bool circleCircleCollision(const Circle& crl1, const Circle& crl2)
{
	float distance = calculateDistance(crl2.getx(), crl1.getx(), crl2.gety(), crl1.gety());

	return (crl1.getRadius() + crl2.getRadius()) >= distance;
}

/*
	Will calculate whether or not a circle and a rectangle have collided by calculating the sum of
	their raidus and span. If this total is greater than the distance between their two origin points then
	the shapes must be touching. If the the total is lower than the distance between the two origin points then
	the shapes cannot be touching.
*/
static bool rectangleCircleCollision(const Square& s1, const Circle& s2)
{
	float distance = calculateDistance(s2.getx(), s1.getx(), s2.gety(), s1.gety());
	float rectangleSpan = calculateDistance(s1.calculateShapeX(), s1.getx(), s1.calculateShapeY(), s1.gety());

	return (s2.getRadius() + rectangleSpan) >= distance;
}

