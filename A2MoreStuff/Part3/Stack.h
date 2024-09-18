#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
	int size;
	int capacity;
	T* heapArray;
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
	heapArray = NULL;
	size = 0;
	capacity = 0;
}

/// <summary>
/// Copy constructor: for creating a copy of an already exsisting generic stack class
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <param name="other">The generic stack class to be copied</param>
template<typename T>
inline Stack<T>::Stack(const Stack& other) {
	size = other.size;
	capacity = other.capacity;
	heapArray = new T[capacity];

	//adding all the elements in the original array to the new one
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] = other.heapArray[i];
	}
}

/// <summary>
/// Assignment operator: for copying another stack generic class over another one
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <param name="other">Stack obj being copied</param>
/// <returns>itself after being copied</returns>
template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this == &other) {
		return *this;
	}

	if (heapArray != nullptr) {
		delete[] heapArray;
		heapArray = nullptr;
	}

	size = other.size;
	capacity = other.capacity;

	heapArray = new T[capacity];

	//adding all the elements in the original array to the new one
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] = other.heapArray[i];
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
	delete[] heapArray;
	heapArray = nullptr;
}

/// <summary>
/// Pushes an element onto the top of the stack
/// </summary>
/// <typeparam name="T">Generic Type</typeparam>
/// <param name="item">Item to be pushed</param>
template<typename T>
inline void Stack<T>::Push(T item)
{
	T* newArray;
	size++;
	//generates an array if this is the first push to a new stack
	if (heapArray == NULL) {
		capacity = 1;
		newArray = new T[capacity]{ item };
		heapArray = newArray;	//points the pointer towards the newly created array
	}
	else {
		if (size > capacity) {	//increases capacity if the new size is greater than current capacity
			capacity *= 2;
			newArray = new T[capacity];
			for (unsigned short i = 0; i < capacity; ++i) {	//loops through to just make sure the new temporary array is empty
				newArray[i] = NULL;
			}
			for (unsigned short i = 0; i < size; ++i) {		//then loops through to put each element into its matching index in the new array
				newArray[i] = *(heapArray + i);
			}
			newArray[size - 1] = item;						//finally adds the new element to the top of the stack
			delete[] heapArray;								//then deletes the no longer needed array and points to newly created one
			heapArray = newArray;
		}
		else {												//if there is space for the new item and the array is not emtpy then we just
			for (unsigned short i = 0; i < size; ++i) {		//search for the closest none occupied space in the stack and put the item there
				if (heapArray[i] == NULL) {
					heapArray[i] = item;
					break;
				}
			}
		}
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