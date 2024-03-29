#pragma once
#include "Square.h";
#include "Circle.h";
#include "Collisions.cpp";
#include <iostream>;
#include <vector>;
#include <random>;
using namespace std;
/*
	Author : Thomas Hutchinson
	File   : Game.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		This is a test class the the second programming for games project.
		It will create a series of shapes and randomly move them around a set grid
		If two shapes then collide it will report this collision and remove them
		from the grid. This will contiue until there is (only) one/no shape(s) remaining.

	Improvements:
		The way I handle collision detection is sub-optimal and over cautious. By constantly
		checking every shape against one another every time a shape is moved I sacrafice 
		performance which in a real time enviroment is not ideal. If I were to improve this main
		function I will adopt a more intelligent collision detection method that only tests
		for detection on a shape's close neighbours rather than every shape on the grid.


	Requirements:
		With this project you should find a sample output snapshot in the base directory,
		You should also find the following files:
			-Shape.h
			-Square.h
			-Circle.h
			-Shape.cpp
			-Square.cpp
			-Circle.cpp
			-Game.cpp (this file)
			-Collisions.cpp
*/

/* Constants used to stop the shapes from flying away */
const static int GRID_WIDTH = 100;
const static int GRID_HEIGHT = 100;


// Will "randomly" move a square in some direction while making sure it doesn't fly away
static void moveSquare(Square* sqr)
{
	int randomX = rand() % 10 + 1;
	int randomY = rand() % 10 + 1;

	if (sqr->getx() + randomX > GRID_WIDTH)
		sqr->setx(sqr->getx() - randomX);
	else if (sqr->getx() - randomX < 0)
		sqr->setx(sqr->getx() + randomX);
	else
	{
		int coin = rand() % 100;
		if (coin > 50)
			sqr->setx(sqr->getx() + randomX);
		else
			sqr->setx(sqr->getx() - randomX);
	}

	if (sqr->gety() + randomY > GRID_HEIGHT)
		sqr->sety(sqr->gety() - randomY);
	else if (sqr->gety() - randomY < 0)
		sqr->sety(sqr->gety() + randomY);
	else
	{
		int coin = rand() % 100;
		if (coin > 50)
			sqr->sety(sqr->gety() + randomY);
		else
			sqr->sety(sqr->gety() - randomY);
	}
}

// Will "randomly" move a square in some direction while making sure it doesn't fly away
static void moveCircle(Circle* crl)
{
	int randomX = rand() % 10 + 1;
	int randomY = rand() % 10 + 1;

	if (crl->getx() + randomX > GRID_WIDTH)
		crl->setx(crl->getx() - randomX);
	else if (crl->getx() - randomX < 0)
		crl->setx(crl->getx() + randomX);
	else
	{
		int coin = rand() % 100;
		if (coin > 50)
			crl->setx(crl->getx() + randomX);
		else
			crl->setx(crl->getx() - randomX);
	}

	if (crl->gety() + randomY > GRID_HEIGHT)
		crl->sety(crl->gety() - randomY);
	else if (crl->gety() - randomY < 0)
		crl->sety(crl->gety() + randomY);
	else
	{
		int coin = rand() % 100;
		if (coin > 50)
			crl->sety(crl->gety() + randomY);
		else
			crl->sety(crl->gety() - randomY);
	}
}

/* Given a vector of circle pointers and an index it will test to make sure that not of the circles have
collided with one another. If a collision has occured it will delete the two collided circles */
static void testForCircleCircleCollisions(vector<Circle*> &vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect.size(); j++)
		{
			if (i != j)
			{
				if (circleCircleCollision(*vect[i], *vect[j]))
				{
					std::cout << "COLLISION - between Circle : " << i << " and Circle : " << j << endl;
					Circle* ptr1 = vect[i];
					Circle* ptr2 = vect[j];

					if (i < j)
					{
						vect.erase(vect.begin() + i);
						vect.erase(vect.begin() + (j - 1));
					}
					else
					{
						vect.erase(vect.begin() + j);
						vect.erase(vect.begin() + (i - 1));
					}

					delete ptr1;
					delete ptr2;
					break; // no need to do more comparisons as shape is now gone
				}
			}
		}
	}
}

/* Given a vector of square pointers it will test to make sure that not of the square have
collided with one another. If a collision has occured it will delete the two collided square */
static void testForSquareSquareCollisions(vector<Square*> &vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect.size(); j++)
		{
			if (i != j)
			{
				if (rectangleRectangleCollision(*vect[i], *vect[j]))
				{
					std::cout << "COLLISION - between Square : " << i << " and Square : " << j << endl;
					Square* ptr1 = vect[i];
					Square* ptr2 = vect[j];

					if (i < j)
					{
						vect.erase(vect.begin() + i);
						vect.erase(vect.begin() + (j - 1));
					}
					else
					{
						vect.erase(vect.begin() + j);
						vect.erase(vect.begin() + (i - 1));
					}

					delete ptr1;
					delete ptr2;
					break; // no need to do more comparisons as shape is now gone
				}
			}
		}
	}
}

/* Given a vector of square pointers and a vector of Circle Pointers it will test to make sure that not 
	of the square have collided with one another. If a collision has occured it will delete the 
	two collided square
	*/
static void testForSquareCircleCollisions(vector<Square*> &vect1, vector<Circle*> &vect2)
{
	for (int i = 0; i < vect1.size(); i++)
	{
		for (int j = 0; j < vect2.size(); j++)
		{
		if (i != j)
		{
			if (rectangleCircleCollision(*vect1[i], *vect2[j]))
			{
				std::cout << "COLLISION - between Square : " << i << " and Circle : " << j << endl;
				Square* ptr1 = vect1[i];
				Circle* ptr2 = vect2[j];

				vect1.erase(vect1.begin() + i);
				vect2.erase(vect2.begin() + j);

				delete ptr1;
				delete ptr2;
				break; // no need to do more comparisons as shape is now gone
			}
		}
		}
	}
}


int main()
{
	// Create circles
	vector<Circle*> circleVector = vector<Circle*>(10);

	for (int i = 0; i < 10; i++)
	{
		float x = rand() % 100 + 1;
		float y = rand() % 100 + 1;
		float radius = rand() % 10 + 1;
		Circle* crl = new Circle(x, y, radius);

		circleVector[i] = crl;
	}

	// Create Squares
	vector<Square*> squareVector = vector<Square*>(10);

	for (int i = 0; i < 10; i++)
	{
		float x = rand() % 100 + 1;
		float y = rand() % 100 + 1;
		float width = rand() % 10 + 1;
		float height = rand() % 10 + 1;
		Square* sqr = new Square(x, y, width, height);

		squareVector[i] = sqr;
	}

	std::cout << "---------- Shapes Generated ----------" << endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Square " << i << " : x = " << squareVector[i]->getx() << " y = " <<
			squareVector[i]->gety() << " width = " << squareVector[i]->getWidth() <<
			" height = " << squareVector[i]->getHeight() << endl;

		std::cout << "--Circle " << i << " : x = " << circleVector[i]->getx() << " y = " <<
			circleVector[i]->gety() << " radius = " << circleVector[i]->getRadius() << endl;
	}


	std::cout << "---------- Initial Collisions ----------" << endl;

	// Check for all collisions durring generation to kill on turn 1
	testForCircleCircleCollisions(circleVector);
	testForSquareSquareCollisions(squareVector);
	testForSquareCircleCollisions(squareVector, circleVector);

	std:cout << "---------- Shape Count ------------------" << endl;

	std::cout << "About to Begin, Squares Left: " << squareVector.size() << " Cicles Left: " 
		<< circleVector.size() << endl;

	int frame = 0; // Count how many itterations it takes to destroy all of the shapes 

	std::cout << "---------- Start of Loop ----------" << endl;

	// Main Loop -- Keep looping until there's only one shape (or less) left
	while (squareVector.size() + circleVector.size() > 1)
	{
		// Move all of the squares and test for collisions
		for (int i = 0; i < squareVector.size(); i++)
		{
			if (squareVector[i] != nullptr)
			{
				moveSquare(squareVector[i]);
				testForSquareSquareCollisions(squareVector);
				testForSquareCircleCollisions(squareVector, circleVector);
			}
		}

		//Move all of the circles and test for collisions 
		for (int i = 0; i < circleVector.size(); i++)
		{
			if (circleVector[i] != nullptr)
			{
				moveCircle(circleVector[i]);
				testForCircleCircleCollisions(circleVector);
				testForSquareCircleCollisions(squareVector, circleVector);
			}
		}
		frame++; // increment the number of complete loops it take to destroy all of the shapes
	}

	std::cout << "---------- End of Loop -------------" << endl;

	std::cout << "It took " << frame << " Frames to kill all of the shapes!" << endl;
}

