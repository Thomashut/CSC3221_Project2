#pragma once
#include "Square.h";
/*
	Author : Thomas Hutchinson
	File   : Square.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		Implimentation of the square header file that inherits from the shape file.
		This class provides the implimentation of the square shape. It provides methods in
		how to calculate it's size and movement. The X and Y point represent the bottom left hand
		point of the square and then from there you can use the height and the width to calcuate the
		rest of the square/rectangle
*/

Square::Square()
{
	this->setx(DEFAULT_X);
	this->sety(DEFAULT_Y);
	this->setHeight(DEFAULT_HEIGHT);
	this->setWidth(DEFAULT_WIDTH);
}

Square::Square(const Square& s)
{
	this->setHeight(s.getHeight());
	this->setWidth(s.getWidth());
}

Square::Square(float x, float y, float width, float height)
{
	this->setx(x);
	this->sety(y);
	this->setWidth(width);
	this->setHeight(height);
}

Square::~Square()
{
	delete this->width;
	delete this->height;
	delete this;
}

Square& Square::operator=(const Square& s)
{
	if (*this == s)
		return *this;

	this->setx(s.getx());
	this->sety(s.gety());
	this->setHeight(s.getHeight());
	this->setWidth(s.getWidth());

	return *this;
}

float Square::getWidth() const
{
	return *this->width;
}

float Square::getHeight() const
{
	return *this->height;
}

void Square::setWidth(float width)
{
	if (this->width == nullptr)
	{
		this->width = new float(width);
	}
	else
	{
		float* ptr = this->width;
		this->width = new float(width);
		delete ptr;
	}
}

void Square::setHeight(float height)
{
	if (this->height == nullptr)
	{
		this->height = new float(height);
	}
	else
	{
		float* ptr = this->height;
		this->height = new float(height);
		delete ptr;
	}
}

float Square::calculateShapeX() const
{
	return this->getx() + this->getWidth();
}

float Square::calculateShapeY() const
{
	return this->gety() + this->getHeight();
}

bool Square::operator==(const Square& s)
{
	return (this->getx() == s.getx() &&
		this->gety() == s.gety() &&
		this->getHeight() == s.getHeight() &&
		this->getWidth() == s.getWidth());
}

// WHen called will return a r representing that this object is a rectangle (square)
char Square::whatAmI() const
{
	return 'r';
}
