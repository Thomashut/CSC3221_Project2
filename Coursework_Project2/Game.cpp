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
	vector<Circle*> circleVector = vector<Circle*>(0);
	for (int i = 0; i < 10; i++)
	{
		float x = rand() % 100 + 1;
		float y = rand() % 100 + 1;
		float radius = rand() % 10 + 1;
		Circle* crl = new Circle(x, y, radius);

		circleVector.push_back(crl);
	}

	// Create Squares
	vector<Square*> squareVector = vector<Square*>(0);
	for (int i = 0; i < 10; i++)
	{
		float x = rand() % 100 + 1;
		float y = rand() % 100 + 1;
		float width = rand() % 10 + 1;
		float height = rand() % 10 + 1;
		Square* sqr = new Square(x, y, width, height);

		squareVector.push_back(sqr);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "Square " << i << " : x = " << squareVector[i]->getx() << " y = " <<
			squareVector[i]->gety() << " width = " << squareVector[i]->getWidth() <<
			" height = " << squareVector[i]->getHeight() <<endl;

		cout << "Circle " << i << " : x = " << circleVector[i]->getx() << " y = " <<
			circleVector[i]->gety() << " radius = " << circleVector[i]->getRadius() << endl;
	}

	//cout << circleVector[1];

	cout << "---------------------------------------------------" << endl;

	cout << squareVector.size() << endl;
	cout << circleVector.size() << endl;

	// Check for all collisions durring generation to kill on turn 1
	for (int i = 0; i < squareVector.size(); i++)
	{
		if(squareVector[i] != nullptr)
		for (int j = 0; j < circleVector.size(); j++)
		{
			if(circleVector[j] != nullptr && squareVector[i] != nullptr)
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

		if (squareVector[i] != nullptr && squareVector[i] != nullptr)
		for (int j = 0; j < squareVector.size(); j++)
		{
			if(squareVector[j] != nullptr && i != j )
				if (rectangleRectangleCollision(*squareVector[i], *squareVector[i]))
				{
					cout << "COLLISION - between Circle : " << i << " and Square : " << j << endl;
					Square* ptr1 = squareVector[i];
					Square* ptr2 = squareVector[j];

					squareVector[i] = nullptr;
					squareVector[j] = nullptr;

					//delete ptr1;
					//delete ptr2;
				}
		}
	}

	//for (int i = 0; i < circleVector.size(); i++)
	//{
	//	if(circleVector[i] != nullptr)
	//		for (int j = 0; j < circleVector.size(); j++)
	//		{
	//			if (circleVector[j] != nullptr)
	//				if (circleCircleCollision(*circleVector[i], *circleVector[j]))
	//				{
	//					cout << "COLLISION - between Circle : " << i << " and Circle : " << j << endl;
	//					Circle* ptr1 = circleVector[i];
	//					Circle* ptr2 = circleVector[j];

	//					circleVector[i] = nullptr;
	//					circleVector[j] = nullptr;

	//					delete ptr1;
	//					delete ptr2;
	//				}
	//		}
	//}
	
	//int frame = 0; // Count how many itterations it takes to destroy all of the shapes
	//// Main Loop
	//while (squareVector.size() > 1 || circleVector.size() > 1)
	//{

	//}

	//cout << "It took " << frame << " Frames to kill all of the shapes!";
}