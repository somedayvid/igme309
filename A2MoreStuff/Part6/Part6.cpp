// Part6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <array>

using namespace std;

float main()
{
	cout << "Int Vector testing" << endl;
	Vector<float>* floatVector = new Vector<float>(1, 2, 3);
	Vector<float>* otherFloatVector = new Vector<float>(3, 2, 1);

	cout << "Vector Testing: " << endl;
	cout << "floatVector: " << endl;
	floatVector->print();

	cout << endl << "otherFloatVector: " << endl;
	otherFloatVector->print();

	cout << endl << "Adding otherFloatVector to floatVector: " << endl;
	floatVector->operator+=(*otherFloatVector);

	floatVector->print();

	cout << endl << "Subtracting otherFloatVector from floatVector: " << endl;
	floatVector->operator-=(*otherFloatVector); 

	floatVector->print();

	cout << endl << "Scaling floatVector by 3" << endl;
	floatVector->scale(3);

	floatVector->print();

	cout << endl << "Subtracting otherFloatVector from floatVector" << endl;
	floatVector->operator-=(*otherFloatVector);

	floatVector->print();

	cout << endl << "Getting the dot product between floatVector and otherFloatVector: " << endl;
	cout << floatVector->dot(*otherFloatVector);

	cout << endl<<endl << "Setting floatVector equal to the cross product between floatVector and otherFloatVector: " << endl;
	floatVector->operator=(floatVector->cross(*otherFloatVector));

	floatVector->print();

	cout << endl << "Normalizing floatVector: " << endl;
	floatVector->normalize();

	floatVector->print();

	cout <<endl<< "Matrix testing: " << endl;
	Matrix<float>* floatMatrix = new Matrix<float>(new float[9] {1,2,3,4,5,6,7,8,9}, 3, 9);
	Matrix<float>* otherFloatMatrix = new Matrix<float>(new float[9] {7,2,3,9,8,10,14, 13, 4}, 3, 9);
	cout <<endl<< "floatMatrix: " << endl;
	floatMatrix->print();
	cout <<endl << endl<< "otherFloatMatrix: " << endl;
	otherFloatMatrix->print();

	cout <<endl<<endl<< "Adding floatMatrix and otherFloatMatrix together: " << endl;
	floatMatrix->operator=(floatMatrix->operator+(*otherFloatMatrix));

	floatMatrix->print();

	cout <<endl<<endl<< "Subtracting otherFloatMatrix from floatMatrix: " << endl;
	floatMatrix->operator=(floatMatrix->operator-(*otherFloatMatrix));

	floatMatrix->print();
	otherFloatMatrix->print();

	cout <<endl<<endl<< "Multiplying floatMatrix and otherFloatMatrix: " << endl;
	floatMatrix->operator=(floatMatrix->operator*(*otherFloatMatrix));

	floatMatrix->print();

	cout <<endl<<endl<< "Multiplying floatMatrix by otherFloatVector: " << endl;
	Matrix<float>* matrixTimesVector = new Matrix<float>(floatMatrix->multiplyByVector(*otherFloatVector));

	matrixTimesVector->print();

	cout << endl << endl << "Scaling floatMatrix by 3: " << endl;
	floatMatrix->scale(3);

	floatMatrix->print();

	cout <<endl<<endl<< "Determinant of otherFloatMatrix:  " << endl;
	cout << otherFloatMatrix->determinant() << endl;

	otherFloatMatrix->print();

	cout <<endl<<endl<< "Transpose otherFloatMatrix: " << endl;
	otherFloatMatrix->transpose();

	otherFloatMatrix->print();

	cout <<endl<<endl<< "Inverse otherFloatMatrix: " << endl;
	otherFloatMatrix->inverse();

	otherFloatMatrix->print();
}