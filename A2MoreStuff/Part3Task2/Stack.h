#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack
{
private:
	int size;
	Node* head;
public:
	Stack();
	//rule of three
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	//methods
	void Push(T item);
	void Pop();
	T& Top();
	void Print();
	int GetSize();
	bool IsEmpty();
};

/// <summary>
/// Generic class unparameterized constructor
/// </summary>
/// <typeparam name="T">Generic Class</typeparam>
template<typename T>
inline Stack<T>::Stack()
{
	head = NULL;
	size = 0;
}

/// <summary>
/// Custom destructor for the class
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
template<typename T>
inline Stack<T>::~Stack()
{
	
}

/// <summary>
/// Pushes an element onto the top of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <param name="item">Item to be pushed</param>
template<typename T>
inline void Stack<T>::Push(T item)
{
	if (head == NULL) {

	}
}

/// <summary>
/// Removes the top, or latest, element of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
template<typename T>
inline void Stack<T>::Pop()
{
	heapArray[size - 1] = NULL;
	--size;
}

/// <summary>
/// Returns a reference to the top, or last in, element of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <returns>reference to the top element of the stack</returns>
template<typename T>
inline T& Stack<T>::Top()
{
	if (size == 0) {
		throw std::invalid_argument("Stack is empty!");
	}
	else {
		return heapArray[size - 1];
	}
}

/// <summary>
/// Prints out all items in stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
template<typename T>
inline void Stack<T>::Print()
{
	for (unsigned short i = 0; i < size; ++i) {
		if (i + 1 == size) {
			std::cout << *(heapArray + i);
		}
		else {
			std::cout << *(heapArray + i) << ", ";
		}
	}
	std::cout << std::endl;
}

/// <summary>
/// Simply returns internally recorded size; number of elements in stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <returns>int of size of stack</returns>
template<typename T>
inline int Stack<T>::GetSize()
{
	return size;
}

/// <summary>
/// Simply returns a boolean depending on whether the stack is empty or not
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <returns>boolean, true if empty, false otherwise</returns>
template<typename T>
inline bool Stack<T>::IsEmpty()
{
	if (size == 0) {
		return true;
	}
	else { return false; }
}