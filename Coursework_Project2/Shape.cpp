#pragma once
#include "Square.h"
#include "Circle.h"
#include <stdexcept>
/*
	Author : Thomas Hutchinson
	File   : Shape.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		This class provides a base level of implimentation for all it's children classes.
		It is an abastract class though as it makes no sense to ever create an object that
		is just a "shape". Both circle and square inherit from this class.
*/
Shape::Shape()
{
	this->setx(DEFAULT_X);
	this->sety(DEFAULT_Y);
}

Shape::Shape(float x, float y)
{
	this->x = new float(x);
	this->y = new float(y);
}

Shape::Shape(const Shape& s) 
{
	this->setx(s.getx());
	this->sety(s.gety());
}


Shape::~Shape()
{
	if (this->x != nullptr)
	{
		float* ptr1 = this->x;
		delete ptr1;
	}

	if (this->y != nullptr)
	{
		float* ptr2 = this->y;
		delete ptr2;
	}
}

float Shape::getx() const
{
	return *this->x;
}

float Shape::gety() const
{
	return *this->y;
}

void Shape::incrementx()
{
	this->x += 1;
}

void Shape::incrementy()
{
	this->y += 1;
}

void Shape::decrementx()
{
	this->x -= 1;
}

void Shape::decrementy()
{
	this->y -= 1;
}

Shape& Shape::operator++(int)
{
	this->x += 1;
	this->y += 1;

	return *this;
}

Shape& Shape::operator++()
{
	this->x += 1;
	this->y += 1;

	return *this;
}

Shape& Shape::operator--(int)
{
	this->x -= 1;
	this->y -= 1;

	return *this;
}

Shape& Shape::operator--()
{
	this->x -= 1;
	this->y -= 1;

	return *this;
}

Shape& Shape::operator=(const Shape& s)
{
	if (*this == s)
		return *this;

	this->setx(s.getx());
	this->sety(s.gety());

	return *this;
}

bool Shape::operator==(const Shape& s)
{
	return (this->getx() == s.getx()) &&
		(this->gety() == s.gety());
}

void Shape::setx(float x)
{
	if (this->x == nullptr)
	{
		this->x = new float(x);
	}
	else
	{
		float* ptr = this->x;
		this->x = new float(x);
		delete ptr;
	}
}

void Shape::sety(float y)
{
	if (this->y == nullptr)
	{
		this->y = new float(y);
	}
	else
	{
		float* ptr = this->y;
		this->y = new float(y);
		delete ptr;
	}
}


/* WHen called will return a s representing that this object is a generic shape
   if you get this then that means this function hasn't been impliemnted for the shape
   and something isn't working as expected
*/
char Shape::whatAmI() const
{
	return 's';
}

