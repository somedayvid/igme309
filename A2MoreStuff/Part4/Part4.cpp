// Part4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int>* intQueue = new Queue<int>();

	intQueue->print();
	intQueue->dequeue();
	intQueue->enqueue(2);
	intQueue->print();
	intQueue->enqueue(3);
	intQueue->enqueue(5);
	intQueue->print();
	cout << "Result of peek: " << intQueue->peek() << endl;
	cout << "Result of rear: " << intQueue->rear() << endl;
	intQueue->dequeue();
	intQueue->print();
	intQueue->enqueue(11);
	intQueue->print();
	intQueue->enqueue(20);
	intQueue->print();
	intQueue->dequeue();
	intQueue->print();

	delete intQueue;
	intQueue = nullptr;

}