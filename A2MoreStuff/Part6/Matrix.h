#pragma once
#include <array>
#include <cmath>
template <class T>
class Matrix
{
private:
	T* heapArray;
	int rows;
	int columns;
	int size;
public:
	Matrix(T array[], int numRows, int numElements);
	~Matrix();

	Matrix(const Matrix& other);

	//arithmetic operators
	Matrix& operator+(const Matrix& other);
	Matrix& operator-(const Matrix& other);
	Matrix& operator*(const Matrix& other);
	//Assignment operators	 
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	void scale(T scalar);

	void print();
};

template<class T>
inline Matrix<T>::Matrix(T myElements[], int numRows, int numElements)
{
	heapArray = myElements;
	rows = numRows;

	columns = numElements/ rows;	

	size = numElements;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	delete[] heapArray;
	heapArray = nullptr;
}

template<class T>
inline Matrix<T>::Matrix(const Matrix& other)
{
	rows = other.rows;
	columns = other.columns;
	size = other.size;
	heapArray = new T[size];

	//adding all the elements in the original array to the new one
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] = other.heapArray[i];
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
/// <returns></returns>
template<class T>
inline Matrix<T>& Matrix<T>::operator+(const Matrix& other)
{
	if (columns == other.columns && rows == other.rows) {
		T* newArray = new T[size];
		for (unsigned short i = 0; i < size; ++i) {
			newArray[i] = heapArray[i] + other.heapArray[i];
		}
		Matrix<T>* newMatrix = new Matrix<T>(newArray, rows, size);

		return *newMatrix;
	}
	else {
		std::cout << "Row and column sizes need to match!" << std::endl;
	}
}

template<class T>
inline Matrix<T>& Matrix<T>::operator-(const Matrix& other)
{
	if (columns == other.columns && rows == other.rows) {
		T* newArray = new T[size];
		for (unsigned short i = 0; i < size; ++i) {
			newArray[i] = heapArray[i] - other.heapArray[i];
		}
		Matrix<T>* newMatrix = new Matrix<T>(newArray, rows, size);

		return *newMatrix;
	}
	else {
		std::cout << "Row and column sizes need to match!" << std::endl;
	}
}

template<class T>
inline Matrix<T>& Matrix<T>::operator*(const Matrix& other)
{
	if (columns == other.rows) {
		T* newArray = new T[rows * other.columns];
		for (int i = 0; i < rows * other.columns; ++i) {
			T tempDotProduct = 0;
			for (int j = 0; j < columns; ++j) {
				int x = 0;
				int y = 0;

				x = j;
				if (i > other.columns - 1) {
					x += columns;
				}

				y = j * other.columns;
				
				if(i % 2 != 0) {
					y += 1;
				}
				tempDotProduct += heapArray[x] * other.heapArray[y];
			}
			std::cout << tempDotProduct << " ";
		}
		Matrix<T>* newMatrix = new Matrix<T>(newArray, rows, size);
		return *newMatrix;
	}
}

template<class T>
inline Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
{
	// TODO: insert return statement here
}

template<class T>
inline Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
{
	// TODO: insert return statement here
}

template<class T>
inline Matrix<T>& Matrix<T>::operator*=(const Matrix& other)
{
	// TODO: insert return statement here
}

template<class T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	// TODO: insert return statement here
}

template<class T>
inline void Matrix<T>::scale(T scalar)
{
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] *= scalar;
	}
}

template<class T>
inline void Matrix<T>::print()
{
	std::cout << "rows: " << rows << ", Columns: " << columns << std::endl;
	for (int i = 0; i < rows * columns; ++i) {
		if (i % rows == 0) { std::cout << std::endl; }
		std::cout << *(heapArray + i) << " ";
	}
}
