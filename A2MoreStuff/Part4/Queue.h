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
	bool isEmpty();
	bool isFull();
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

template<class T>
inline void Queue<T>::dequeue()
{
	if (size == 0) {
		throw std::invalid_argument("Queue is empty!");
	}
	else {
		heapArray[size - 1] = NULL;
		--size;
	}
}

template<class T>
inline T Queue<T>::peek()
{
	if (size == 0) {
		throw std::invalid_argument("Queue is empty!");
	}
	else {
		return *(heapArray);
	}
}

template<class T>
inline T Queue<T>::rear()
{
	if (size == 0) {
		throw std::invalid_argument("Queue is empty!");
	}
	else {
		return *(heapArray + size - 1);
	}
}

template<class T>
inline bool Queue<T>::isEmpty()
{
	if (size == 0) {
		return true;
	}
	else { return false; }
}

template<class T>
inline bool Queue<T>::isFull()
{
	if (size == capacity) {
		return true;
	}
	else { return false; }
}

template<class T>
inline void Queue<T>::print()
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
