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

	//std::cout << sizeof(myaayy);

	Matrix<float>* myMatrix = new Matrix<float>(new float[9]{6,1,1,4,-2,5,2,8,7}, 3, 9);
	cout << myMatrix->determinant();
	//Matrix<float>* matrix2 = new Matrix<float>(new float[6]{7,8,9,10,11,12}, 3, 6);

	//myMatrix->multiplyByVector(myVect);
	//myMatrix->operator=(myMatrix->operator*(*matrix2));
	//myMatrix->print();
	//myMatrix->transpose();
	//myMatrix->print();
	//myMatrix->transpose();
	//myMatrix->print();

	//Matrix<float>* newMatrix = new Matrix<float>(new float[4] {1,2,3,4}, 2, 4);
	//cout << newMatrix->determinant();


}