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
		A helper class that takes shapes and runs functions that
		calculate for collisions. I decided to remove the collsions
		from the shapes themselves to provide additional functionality
		and extendability. This was I can easily model specific collisions between
		specific types of shapes and if in the future I add addtional shapes
		I can easily create additional functions here to handle that new behaviour
*/

/*
	A helper function will will calculate the distance between two sets of coordiantes 
	and then return it. This is used in the above functions in several places to help 
	detect collision
*/
static float calculateDistance(float x1, float x2, float y1, float y2)
{
	return sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0));
}

// Will return the greater of two given floats
static float max(float lhs, float rhs)
{
	if (lhs > rhs)
		return lhs;
	else
		return rhs;
}

// Will return the lesser of two given floats
static float min(float lhs, float rhs)
{
	if (lhs < rhs)
		return lhs;
	else
		return rhs;
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
	Will calculate whether or not a circle and a square have collided by finding the point on
	the rectangle that is closest to the circles center. It will then check to see if that
	point is within the circle. If it is then the two shapes must have collided and if not
	they cannot be touching
*/
static bool rectangleCircleCollision(const Square& sqr, const Circle& crl)
{
	float nearestX = crl.getx() - max(sqr.getx(), min(crl.getx(), sqr.getx() + sqr.getWidth()));
	float nearestY = crl.gety() - max(sqr.gety(), min(crl.gety(), sqr.gety() + sqr.getHeight()));

	return (pow(nearestX, 2.0) + pow(nearestY, 2.0)) < pow(crl.getRadius(),2.0);
}




