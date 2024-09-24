#pragma once
template<class T>
class Queue
{
private:
	int size;
	int capacity;
	T* heapArray;
public:
	Queue();
	~Queue();
	void enqueue(T item);
	void dequeue();
	T peek();
	T rear();
	void print();
};

template<class T>
inline Queue<T>::Queue()
{
	size = 0;
	capacity = 0;
	heapArray = NULL;
}

template<class T>
inline Queue<T>::~Queue()
{
	delete[] heapArray;
	heapArray = nullptr;
}

/// <summary>
/// Adds a the parameter to the queue
/// </summary>
/// <typeparam name="T">Template generic type</typeparam>
/// <param name="item">Item to be added</param>
template<class T>
inline void Queue<T>::enqueue(T item)
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
/// Removes the element that was added to the queue the longest ago
/// </summary>
/// <typeparam name="T">Template generic type</typeparam>
template<class T>
inline void Queue<T>::dequeue()
{
	if (size == 0) {
		std::cout << ("Queue is empty!") << std::endl;
	}
	else {
		heapArray[0] = NULL;
		--size;
		for (int i = 0; i < size; ++i) {
			heapArray[i] = heapArray[i + 1];
		}
		heapArray[size] = NULL;
	}
}

/// <summary>
/// Returns the first element in the queue; the next to be dequeued if called
/// </summary>
/// <typeparam name="T">Template generic type</typeparam>
/// <returns>The first element in the queue</returns>
template<class T>
inline T Queue<T>::peek()
{
	if (size == 0) {
		std::cout << ("Queue is empty!") << std::endl;
	}
	else {
		return *(heapArray);
	}
}

/// <summary>
/// Returns the last element in the queue; the most recently added element
/// </summary>
/// <typeparam name="T">Template type</typeparam>
/// <returns><The last element in the queue/returns>
template<class T>
inline T Queue<T>::rear()
{
	if (size == 0) {
		std::cout << ("Queue is empty!") << std::endl;
	}
	else {
		return *(heapArray + size - 1);
	}
}

/// <summary>
/// Prints out all the elements in the queue starting from the one added the longest ago
/// </summary>
/// <typeparam name="T">Template generic type</typeparam>
template<class T>
inline void Queue<T>::print()
{
	std::cout << "Queue has a capacity of: " << capacity << ": [";


	for (unsigned short i = 0; i < size; ++i) {
		if (i + 1 == size) {
			std::cout << *(heapArray + i);
		}
		else {
			std::cout << *(heapArray + i) << ", ";
		}
	}

	std::cout << "]" << std::endl;
}
