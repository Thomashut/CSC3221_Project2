#pragma once
#include "Shape.h";
/*
	Author : Thomas Hutchinson
	File   : Shape.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		This class provides a base level of implimentation for all it's children classes.
		It is an abastract class though as it makes no sense to ever create an object that
		is just a "shape". Both circle and square inherit from this class.
*/

Shape::~Shape()
{
	delete this;
}

float Shape::getx() const
{
	return this->x;
}

float Shape::gety() const
{
	return this->y;
}

float Shape::getSize() const
{
	return this->size;
}

void Shape::move(float x, float y)
{
	this->x = x;
	this->y = y;
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

bool Shape::collision(const Shape* s)
{
	return (this->getx() == s->getx() && this->gety() == s->gety());
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

bool Shape::operator==(const Shape& s)
{
	return (this->getx() == s.getx()) &&
		(this->gety() == s.gety()) &&
		(this->getSize() == s.getSize());
}

void Shape::setx(float x)
{
	this->x = x;
}

void Shape::sety(float y)
{
	this->y = y;
}

void Shape::setSize(float size)
{
	this->size = size;
}

