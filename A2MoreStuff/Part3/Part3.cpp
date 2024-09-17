// Part3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	cout << "intStack testing" << endl;
	Stack<int>* intStack = new Stack<int>();

	intStack->Push(3);
	intStack->Push(1);
	intStack->Push(2);
	intStack->Push(7);

	cout << "Print 1: ";
	intStack->Print();

	cout << "Size #1: " << intStack->GetSize() << endl;

	intStack->Pop();
	intStack->Pop();

	cout << "Print 2: ";
	intStack->Print();

	cout << "Size #2: " << intStack->GetSize() << endl;

	intStack->Top() = 10;

	cout << "Print 3: ";
	intStack->Print();

	intStack->Pop();
	intStack->Pop();
	try {
		intStack->Top();
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	if (intStack->IsEmpty()) {
		cout << "Stack Empty" << endl;
	}
	else { cout << "Stack Not empty" << endl; }

	cout << endl;

	cout << "floatStack testing" << endl;

	Stack<float>* floatStack = new Stack<float>();
	floatStack->Push(3.3f);
	floatStack->Push(9.3f);
	floatStack->Push(8.5f);
	floatStack->Push(10.334f);

	cout << "Print 1: ";
	floatStack->Print();

	floatStack->Pop();

	cout << "Print 2: ";
	floatStack->Print();

	floatStack->Push(8.5f);

	floatStack->Top() = 20.3f;

	cout << "Print 3: ";
	floatStack->Print();

	cout << endl;

	cout << "charStack testing" << endl;

	Stack<char>* charStack = new Stack<char>();
	charStack->Push('f');
	charStack->Push('g');
	charStack->Push('h');
	charStack->Push('d');

	cout << "Print 1: ";
	charStack->Print();

	charStack->Pop();
	charStack->Pop();

	cout << "Print 2: ";
	charStack->Print();

	charStack->Top() = 'l';

	cout << "Print 3: ";
	charStack->Print();

	cout << endl;

	cout << "Copy constructor testing" << endl;

	Stack<float>* floatCopy = new Stack<float>(*floatStack);

	cout << "Print 1: ";
	floatCopy->Print();

	floatCopy->Pop();
	floatCopy->Push(3.4f);
	floatCopy->Push(3.4f);

	floatCopy->Top() = 32.1f;

	cout << "Print 2: ";
	floatCopy->Print();
	cout << endl;

	cout << "Copy assignment Operator testing" << endl;

	floatCopy->operator=(*floatStack);

	cout << "Print 1: ";
	floatCopy->Print();

	delete intStack;
	delete floatStack;
	delete charStack;
	delete floatCopy;
	intStack = nullptr;
	floatStack = nullptr;
	charStack = nullptr;
	floatCopy = nullptr;
}