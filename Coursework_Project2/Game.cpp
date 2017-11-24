#pragma once
#include "Square.h";
#include "Circle.h";
#include <iostream>;
using namespace std;
/*
	Author : Thomas Hutchinson
	File   : Game.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		This is a test class the the second programming for games project.
		It will create a series of shapes and randomly move them around a set grid
		If two shapes then collide it will report this collision and remove them
		from the grid.
*/

int main()
{
	Square* sq1 = new Square();
	Square* sq2 = new Square(1.0, 2.0, 5.0,5.0);
	Square* sq3 = new Square(*sq1);

	Circle* ci1 = new Circle();
	Circle* ci2 = new Circle(1.0, 2.0, 5.0, 10.0);
	Circle* ci3 = new Circle(*ci1);



}