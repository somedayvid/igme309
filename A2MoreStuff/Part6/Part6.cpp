// Part6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

float main()
{
	Vector<float>* myVect = new Vector<float>(10, 20);
	Vector<float>* myVect2 = new Vector<float>(5, 10);

	myVect->print();
	myVect2->print();
	Vector<float>* whatVector = new Vector<float>(myVect->operator+(*myVect2));
	whatVector->print();

	//Vector<float>* myVect3 = new Vector<float>(20, 50);

	whatVector->operator=(myVect->operator+=(*myVect2));
	whatVector->print();
	myVect->operator+=(*whatVector);
	myVect->print();

	//whatVector->normalize();
	//whatVector->print();
	//whatVector->addDimension(20);
	//whatVector->print();
}