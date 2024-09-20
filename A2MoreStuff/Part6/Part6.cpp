// Part6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <array>

using namespace std;

float main()
{
	//Vector<float>* myVect = new Vector<float>(10, 20);
	//Vector<float>* myVect2 = new Vector<float>(5, 10);

	//myVect->print();
	//myVect2->print();
	//Vector<float>* whatVector = new Vector<float>(myVect->operator+(*myVect2));
	//whatVector->print();

	////Vector<float>* myVect3 = new Vector<float>(20, 50);

	//whatVector->operator=(myVect->operator+=(*myVect2));
	//whatVector->print();
	//myVect->operator+=(*whatVector);
	//myVect->print();

	////whatVector->normalize();
	////whatVector->print();
	////whatVector->addDimension(20);
	////whatVector->print();

	float myaayy[] = { 1,2,3,
					 4,5,6};

	float array2[] = { 7,8,9,10,11,12};

	//std::cout << sizeof(myaayy);

	Matrix<float>* myMatrix = new Matrix<float>(myaayy, 2,6);
	Matrix<float>* matrix2 = new Matrix<float>(array2, 3, 6);
	
	myMatrix->operator*(*matrix2);

}