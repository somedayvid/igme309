#pragma once
template <typename T>
class Node
{
public:
	T item;
	Node<T>* next;

	Node(const Node& other);
	Node<T>& operator=(const Node& other);

	Node(T newItem);
	~Node();
	void print();
};

template<typename T>
inline Node<T>::Node(const Node& other)
{
	item = other.item;
}

template<typename T>
inline Node<T>& Node<T>::operator=(const Node& other)
{
	if (this == &other) {
		return *this;
	}

	item = other.item;
	return *this;
}

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
