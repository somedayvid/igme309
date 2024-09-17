#pragma once
template<class T>
class Template
{
private:
	int size;
public:
	Template();
	~Template();
	void size();
};

template<class T>
inline Template<T>::Template()
{
	size = 0;
}

template<class T>
inline Template<T>::~Template()
{
}

template<class T>
inline void Template<T>::size()
{
	return size;
}
