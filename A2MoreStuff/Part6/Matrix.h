#pragma once
#include <array>
#include <cmath>
#include "Vector.h"

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

	//Assignment operator
	Matrix& operator=(const Matrix& other);

	void scale(T scalar);
	void transpose();
	T determinant();
	T determinant(T incomingArray[], const int incomingRows, const int incomingColumns, int multiplier = 1);
	void inverse();
//	void multiplyByVector(const Vector& other);

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

/// <summary>
/// Copy constructor to create a copy of another matrix
/// </summary>
/// <typeparam name="T">Generic Template Class</typeparam>
/// <param name="other">Other matrix to be copied from</param>
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
/// Addition operator to add two matrices together
/// </summary>
/// <typeparam name="T">Generic Template Class</typeparam>
/// <param name="other">Other matrix to add to this one</param>
/// <returns>Deref to new matrix with combined stats</returns>
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

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
/// <returns></returns>
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

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="other"></param>
/// <returns></returns>
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
		}
		Matrix<T>* newMatrix = new Matrix<T>(newArray, rows, size);
		return *newMatrix;
	}
}

/// <summary>
/// Sets this matrix's values equal to the other
/// </summary>
/// <typeparam name="T">Generic Template Class</typeparam>
/// <param name="other">The other matrix to be copied over this one</param>
/// <returns>This matrix but with its new values</returns>
template<class T>
inline Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	if (this == &other) {
		return *this;
	}

	if (heapArray != nullptr) {
		delete[] heapArray;
		heapArray = nullptr;
	}

	size = other.size;
	rows = other.rows;
	columns = other.columns;

	heapArray = new T[size];

	//adding all the elements in the original array to the new one
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] = other.heapArray[i];
	}
	return *this;
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="scalar"></param>
template<class T>
inline void Matrix<T>::scale(T scalar)
{
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] *= scalar;
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
inline void Matrix<T>::transpose()
{
	T* newArray = new T[size];

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			int x = i * columns + j;
			int y = j * rows + i;
			newArray[x] = heapArray[y];
		}
	}

	for (int i = 0; i < rows * columns; i++) {
		heapArray[i] = newArray[i];
	}

	rows += columns;
	columns -= rows;
	rows += columns;
	columns *= -1;

	delete[] newArray;
	newArray = nullptr;
}

template<class T>
inline T Matrix<T>::determinant()
{
	return determinant(heapArray, rows, columns);
}

/// <summary>
/// Calculates and returns the determinant of this matrix
/// </summary>
/// <typeparam name="T">Generic Template Type</typeparam>
/// <param name="incomingArray">The array of matrix numbers</param>
/// <param name="incomingRows">The number of rows in the matrix</param>
/// <param name="incomingColumns">The number of columns in the matrix</param>
/// <returns>A double representing the determinant</returns>
template<class T>
inline T Matrix<T>::determinant(T incomingArray[], const int incomingRows, const int incomingColumns, int multiplier)
{
	double determinantTotal = 0;
	T* newArray = incomingArray;
	int newRows = incomingRows;
	int newColumns = incomingColumns;
	int newSize = newRows * newColumns;

	if (newRows == newColumns) {
		if(newRows == 2)
		{
			return newArray[0] * newArray[3] - newArray[1] * newArray[2];
		}
		else {
			for (int i = 0; i < newColumns; ++i) {
				int tempArraySize = (newColumns - 1) * (newRows - 1);
				T* tempArray = new T[tempArraySize]{ NULL };
				for (int k = newColumns; k < newSize; ++k) {
					if ((k - i) % newColumns != 0) {
						for (int l = 0; l < tempArraySize; ++l) {
							if (tempArray[l] == NULL) {
								tempArray[l] = newArray[k];
								break;
							}
						}
					}
				}

				if (i % 2 != 0) {
					determinantTotal -= (newArray[i] * determinant(tempArray, newRows - 1, newColumns - 1, newArray[i]));
				}
				else {
					determinantTotal += (newArray[i] * determinant(tempArray, newRows - 1, newColumns - 1, newArray[i]));
				}

				delete[] tempArray;
				tempArray = nullptr;
			}
			return determinantTotal;
		}
	}
	else {
		throw std::invalid_argument("Must be a matrix of equal row and column size");
	}
}

template<class T>
inline void Matrix<T>::inverse()
{
	T* tempArray = new T[size]{ heapArray[3], -heapArray[1], -heapArray[2], heapArray[0] };
	for (int i = 0; i < size; ++i) {
		tempArray[i] /= determinant(heapArray, 2, 2);
	}
	delete[] heapArray;
	heapArray = tempArray;
	tempArray = nullptr;
}

//template<class T>
//inline void Matrix<T>::multiplyByVector(const Vector<T>& other)
//{
//	std::cout << other->getSize();
//}

/// <summary>
/// Prints out all the contents in matrix form with rows and columns
/// </summary>
/// <typeparam name="T">Template Generic Type</typeparam>
template<class T>
inline void Matrix<T>::print()
{
	std::cout << "rows: " << rows << ", Columns: " << columns << std::endl;
	for (int i = 0; i < rows * columns; ++i) {
		if (i % columns == 0) {
			std::cout << std::endl;
		}
		std::cout << *(heapArray + i) << " ";
	}
}
