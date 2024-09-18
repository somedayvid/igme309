// Part4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int>* intQueue = new Queue<int>();

	intQueue->enqueue(2);
	intQueue->print();
	intQueue->enqueue(3);
	intQueue->enqueue(5);
	intQueue->print();
	cout << intQueue->peek() << endl;
	cout << intQueue->rear() << endl;
	intQueue->dequeue();
	intQueue->print();
}