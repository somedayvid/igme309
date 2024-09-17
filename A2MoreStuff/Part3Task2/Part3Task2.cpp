// Part3Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int>* intStack = new Stack<int>();
	intStack->Push(2);
	intStack->Push(4);
	intStack->Pop();
	intStack->Print();
}