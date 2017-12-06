#pragma once
#include "Square.h";
#include "Circle.h";
#include <iostream>;
#include <vector>;
#include <random>;
#include "Collisions.cpp";
using namespace std;
/*
	Author : Thomas Hutchinson
	File   : Game.cpp
	Purpose: Programming for Games - Coursework 2
	Description:
		This is a test class the the second programming for games project.
		It will create a series of shapes and randomly move them around a set grid
		If two shapes then collide it will report this collision and remove them
		from the grid. This will contiue until there is (only) one/no shape(s) remaining
*/

int main()
{
	// Create circles
	vector<Circle*> circleVector = vector<Circle*>(10);
	//circleVector[0] = new Circle(2.5, 5.1, 3.0);
	//circleVector[1] = new Circle(3.5, 3.1, 0.5);
	//circleVector[2] = new Circle(6.7, 4.6, 1.2);
	//circleVector[3] = new Circle(2.4, 7.3, 3.4);
	//circleVector[4] = new Circle(4.5, 8.7, 5.5);
	//circleVector[5] = new Circle(8.2, 7.7, 6.2);
	//circleVector[6] = new Circle(9.7, 9.5, 2.2);
	//circleVector[7] = new Circle(2.1, 2.3, 1.2);
	//circleVector[8] = new Circle(1.2, 5.7, 0.5);
	//circleVector[9] = new Circle(0.5, 8.8, 3.1);
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
	//squareVector[0] = new Square(2.0, 5.0, 5.0, 2.0);
	//squareVector[1] = new Square(1.2, 2.5, 5.0, 2.0);
	//squareVector[2] = new Square(5.3, 6.5, 5.0, 2.0);
	//squareVector[3] = new Square(6.5, 4.3, 5.0, 2.0);
	//squareVector[4] = new Square(4.4, 7.5, 5.0, 2.0);
	//squareVector[5] = new Square(2.3, 8.8, 5.0, 2.0);
	//squareVector[6] = new Square(1.6, 9.1, 5.0, 2.0);
	//squareVector[7] = new Square(8.5, 2.1, 5.0, 2.0);
	//squareVector[8] = new Square(3.1, 0.2, 5.0, 2.0);
	//squareVector[9] = new Square(9.9, 2.2, 5.0, 2.0);

	for (int i = 0; i < 10; i++)
	{
		float x = rand() % 100 + 1;
		float y = rand() % 100 + 1;
		float width = rand() % 10 + 1;
		float height = rand() % 10 + 1;
		Square* sqr = new Square(x, y, width, height);

		squareVector[i] = sqr;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "Square " << i << " : x = " << squareVector[i]->getx() << " y = " <<
			squareVector[i]->gety() << " width = " << squareVector[i]->getWidth() <<
			" height = " << squareVector[i]->getHeight() << endl;

		cout << "--Circle " << i << " : x = " << circleVector[i]->getx() << " y = " <<
			circleVector[i]->gety() << " radius = " << circleVector[i]->getRadius() << endl;
	}

	//cout << circleVector[1];

	cout << "---------------------------------------------------" << endl;

	// Check for all collisions durring generation to kill on turn 1
	for (int i = 0; i < squareVector.size(); i++)
	{
		if (squareVector[i] != nullptr)
			for (int j = 0; j < circleVector.size(); j++)
			{
				if (circleVector[j] != nullptr && squareVector[i] != nullptr)
					if (rectangleCircleCollision(*squareVector[i], *circleVector[j]))
					{
						cout << "COLLISION - between Square : " << i << " and Circle : " << j << endl;
						Square* ptr1 = squareVector[i];
						Circle* ptr2 = circleVector[j];

						squareVector[i] = nullptr;
						circleVector[j] = nullptr;

						//delete ptr1;
						//delete ptr2;
					}
			}

		if (squareVector[i] != nullptr)
			for (int j = 0; j < squareVector.size(); j++)
			{
				if (squareVector[j] != nullptr && i != j)
					if (rectangleRectangleCollision(*squareVector[i], *squareVector[j]))
					{
						cout << "COLLISION - between Square : " << i << " and Square : " << j << endl;
						Square* ptr1 = squareVector[i];
						Square* ptr2 = squareVector[j];

						squareVector[i] = nullptr;
						squareVector[j] = nullptr;

						//delete ptr1;
						//delete ptr2;
					}
			}
	}

	for (int i = 0; i < circleVector.size(); i++)
	{
		for (int j = 0; j < circleVector.size(); j++)
		{
			if (circleVector[j] != nullptr && circleVector[i] != nullptr && i != j)
			{

				if (circleCircleCollision(*circleVector[i], *circleVector[j]))
				{
					cout << "COLLISION - between Circle : " << i << " and Circle : " << j << endl;
					Circle* ptr1 = circleVector[i];
					Circle* ptr2 = circleVector[j];

					circleVector[i] = nullptr;
					circleVector[j] = nullptr;
					
					//delete ptr1;
					//delete ptr2;

				}
			}
		}
	}

	int frame = 0; // Count how many itterations it takes to destroy all of the shapes
	// Main Loop -- To do
	while (squareVector.size() > 1 || circleVector.size() > 1)
	{
		break;
		frame++;
	}

	cout << "It took " << frame << " Frames to kill all of the shapes!" << endl;
}