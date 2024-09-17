#pragma once
template <typename T>
class Node
{
public:
	T item;
	Node<T>* next;

	Node(T newItem);
	~Node();
	void print();
};

template<typename T>
inline Node<T>::Node(T newItem)
{
	item = newItem;
	next = NULL;
}

template<typename T>
inline Node<T>::~Node()
{
}

template<typename T>
inline void Node<T>::print()
{
	std::cout << item << std::endl;
}
