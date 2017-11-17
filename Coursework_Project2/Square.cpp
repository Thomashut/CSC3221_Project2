#pragma once
#include "Square.h";
/*
	Author : Thomas Hutchinson
	File   : Square.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		Implimentation of the square header file that inherits from the shape file.
		This class provides the implimentation of the square shape. It provides methods in
		how to calculate it's size and movement as well with how to calculate it's collisions
		with other shapes
*/

Square::Square()
{
	this->setx(DEFAULT_X);
	this->sety(DEFAULT_Y);
	this->setSize(DEFAULT_SIZE);
}

Square::Square(const Square& s)
{
	this->setx(s.getx());
	this->sety(s.gety());
	this->setSize(s.getSize());
}

Square::Square(float x, float y, float size)
{
	this->setx(x);
	this->sety(y);
	this->setSize(size);
}

Square::~Square()
{
	delete this;
}

Square& Square::operator=(const Square& s)
{
	if (*this == s)
		return *this;

	this->setx(s.getx());
	this->sety(s.gety());
	this->setSize(s.getSize());

	return *this;
}

bool Square::operator==(const Square& s)
{
	return (this->getx() == s.getx() &&
		this->gety() == s.gety() &&
		this->getSize() == s.getSize());
}



// TO-DO
bool Square::collision(const Shape& s)
{
	return true;
}
