#pragma once
#include "Circle.h"
/*
	Author : Thomas Hutchinson
	File   : Circle.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		This class provides the concrete implimentation of the Circle header file.
		A circle is an object that inherits from the shape class and this file specificly
		provides that implimentation. The circle can detect it's own size and movement.
*/

Circle::Circle()
{
	this->setx(DEFAULT_X);
	this->sety(DEFAULT_Y);
	this->setRadius(DEFAULT_RADIUS);
}

Circle::Circle(const Circle& s)
{
	this->setx(s.getx());
	this->sety(s.gety());
	this->setRadius(s.getRadius());
}

Circle::Circle(float x, float y, float radius)
{
	this->setx(x);
	this->sety(y);
	this->setRadius(radius);
}

Circle::~Circle()
{
	if (this->radius != nullptr)
	{
		float* ptr = this->radius;
		delete ptr;
	}
}

float Circle::getRadius() const
{
	return *this->radius;
}

void Circle::setRadius(float radius)
{
	if (this->radius == nullptr)
	{
		this->radius = new float(radius);
	}
	else
	{
		float* ptr = this->radius;
		this->radius = new float(radius);
		delete ptr;
	}
}

bool Circle::operator==(const Circle& s)
{
	return (this->getx() == s.getx() &&
		this->gety() == s.gety() &&
		this->getRadius() == s.getRadius());
}

// WHen called will return a c representing that this object is a circle
char Circle::whatAmI() const
{
	return 'c';
}

Circle& Circle::operator=(const Circle& s)
{
	if (*this == s)
		return *this;

	this->setx(s.getx());
	this->sety(s.gety());
	this->setRadius(s.getRadius());

	return *this;
}
