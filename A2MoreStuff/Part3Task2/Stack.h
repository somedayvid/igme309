#pragma once
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack
{
private:
	int size;
	Node<T>* head;
	Node<T>* tail;
public:
	Stack();
	//rule of three
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	//methods
	void Push(T item);
	void Pop();
	Node<T>* Top();
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
/// Copy constructor
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
template<typename T>
inline Stack<T>::Stack(const Stack& other)
{
	if (size > 0) {
		Node<T>* current;
		for (int i = 0; i < size; ++i) {
			current = head->next;
			delete head;
			head = current;
		}
	}

	size = other.size;

	Node<T>* otherCurrent = other.head;
	Node<T>* thisCurrent;

	Node<T>* newHead = new Node<T>(*otherCurrent);
	thisCurrent = newHead;
	head = newHead;
	tail = newHead;

	for (int i = 0; i < size - 1; ++i) {
		otherCurrent = otherCurrent->next;
		Node<T>* newNode = new Node<T>(*otherCurrent);
		thisCurrent->next = newNode;
		tail = thisCurrent->next;
		thisCurrent = tail;
	}
}

/// <summary>
/// Assignment operator
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other stack</param>
/// <returns>This with new nodes</returns>
template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this == &other) {
		return *this;
	}

	size = other.size;

	Node<T>* current;
	for (int i = 0; i < size; ++i) {
		current = head->next;
		delete head;
		head = current;
	}

	Node<T>* otherCurrent = other.head;
	Node<T>* thisCurrent;

	Node<T>* newHead = new Node<T>(*otherCurrent);
	thisCurrent = newHead;
	head = newHead;
	tail = newHead;

	for (int i = 0; i < size - 1; ++i) {
		otherCurrent = otherCurrent->next;
		Node<T>* newNode = new Node<T>(*otherCurrent);
		thisCurrent->next = newNode;
		tail = newNode;
		thisCurrent = tail;
	}

	return *this;
}

/// <summary>
/// Custom destructor for the class
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
template<typename T>
inline Stack<T>::~Stack()
{
	Node<T>* current;
	for (int i = 0; i < size; ++i) {
		current = head->next;
		delete head;
		head = current;
	}
	head = nullptr;
	tail = nullptr;
}

/// <summary>
/// Pushes an element onto the top of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <param name="item">Item to be pushed</param>
template<typename T>
inline void Stack<T>::Push(T item)
{
	Node<T>* newNode = new Node<T>(item);
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

/// <summary>
/// Removes the top, or latest, element of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
template<typename T>
inline void Stack<T>::Pop()
{
	Node<T>* current = head;
	for (int i = 0; i < size - 2; ++i) {
		current = current->next;
	}
	
	delete current->next;
	current->next = nullptr;
	tail = current;
	size--;
}

/// <summary>
/// Returns a reference to the top, or last in, element of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <returns>reference to the top element of the stack</returns>
template<typename T>
inline Node<T>* Stack<T>::Top()
{
	if (size == 0) {
		throw std::invalid_argument("Stack is empty!");
	}
	else {
		return tail;
	}
}

/// <summary>
/// Prints out all items in stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
template<typename T>
inline void Stack<T>::Print()
{
	Node<T>* current = head;
	while (current->next != NULL) {
		std::cout << current->item << ", ";
		current = current->next;
	}
	std::cout << current->item << std::endl;
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