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
	Matrix& multiplyByVector(Vector<T>& other);

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
	T* newHeapArray = new T[size];

	//adding all the elements in the original array to the new one
	for (unsigned short i = 0; i < size; ++i) {
		newHeapArray[i] = other.heapArray[i];
	}

	delete[] heapArray;
	heapArray = newHeapArray;
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
		throw std::invalid_argument("Row and column size needs to match!");
	}
}

/// <summary>
/// Subtraction operator which just subtracts each corresponding element in the matrix with the one in the other matrix
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other matrix to subtract from this one</param>
/// <returns>A new matrix with subtracted values</returns>
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
		throw std::invalid_argument("Row and column size needs to match!");
	}
}

/// <summary>
/// Multiplication operator which performs matrix multiplication
/// </summary>
/// <typeparam name="T">Template Generic Type</typeparam>
/// <param name="other">The other matrix to be multiplied with</param>
/// <returns>A new matrix with the new size and dimensions and dot product values</returns>
template<class T>
inline Matrix<T>& Matrix<T>::operator*(const Matrix& other)
{
	if (columns == other.rows) {
		T* newArray = new T[rows * other.columns]{ NULL };
		for (int i = 0; i < rows * other.columns; ++i) {
			T tempDotProduct = 0;
			for (int j = 0; j < columns; ++j) {
				int x = 0; 
				int y = 0;

				x = j;
				if (i > other.columns - 1) { 
					x += i / other.columns * columns;
				}

				y = j * other.columns + i % other.columns;
								
				tempDotProduct += heapArray[x] * other.heapArray[y];
			}
			for (int k = 0; k < rows * other.columns; ++k) {
				if (newArray[k] == NULL) {
					newArray[k] = tempDotProduct;
					break;
				}
			} 
		}
		Matrix<T>* newMatrix = new Matrix<T>(newArray, rows, rows * other.columns);
		return *newMatrix;
	}
	else {
		throw std::invalid_argument("This matrix's columns need to match the other's rows!");
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
/// Scales each value in the matrix by the scalar
/// </summary>
/// <typeparam name="T">Template Generic Type</typeparam>
/// <param name="scalar">The number amount to scale by</param>
template<class T>
inline void Matrix<T>::scale(T scalar)
{
	for (unsigned short i = 0; i < size; ++i) {
		heapArray[i] *= scalar;
	}
}

/// <summary>
/// Transposes a matrix, swapping the rows and columns
/// </summary>
/// <typeparam name="T">Generic Template Type</typeparam>
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

/// <summary>
/// Operator linking thing so the determinant function can be called with default parameters from the matrix it is being called from
/// </summary>
/// <typeparam name="T">Generic Template Type</typeparam>
/// <returns>The determinant once the other function runs through</returns>
template<class T>
inline T Matrix<T>::determinant()
{
	return determinant(heapArray, rows, columns);
}

/// <summary>
/// Recursive function to calculate the determinant of a matrix
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

/// <summary>
/// Inverses this matrix
/// </summary>
/// <typeparam name="T">Template Generic Type</typeparam>
template<class T>
inline void Matrix<T>::inverse()
{
	if (determinant() != 0) {
		transpose();	
		T* newArray;

		if (rows == 2 && columns == rows) {
			newArray = new T[size]{ heapArray[3], -heapArray[1], -heapArray[2], heapArray[0] };
			for (int i = 0; i < size; ++i) {
				newArray[i] /= determinant(heapArray, 2, 2);
			}
		}
		else {
			newArray = new T[rows * columns];
			for (int m = 0; m < rows * columns; ++m) {
				newArray[m] = std::numeric_limits<T>::min();
			}

			int tempArraySize = (columns - 1) * (rows - 1);

			for (int i = 0; i < rows * columns; ++i) {

				T* tempArray = new T[tempArraySize];
				for (int m = 0; m < tempArraySize; ++m) {
					tempArray[m] = std::numeric_limits<T>::min();
				}

				for (int j = 0; j < rows * columns; ++j) {
					if ((j / columns) != (i / columns) && (j % columns != i % columns)) {
						for (int l = 0; l < tempArraySize; ++l) {
							if (tempArray[l] == std::numeric_limits<T>::min()) {
								tempArray[l] = heapArray[j];
								break;
							}
						}
					}
				}

				for (int l = 0; l < rows * columns; ++l) {
					if (newArray[l] == std::numeric_limits<T>::min()) {
						newArray[l] = determinant(tempArray, rows - 1, columns - 1);
						break;
					}
				}

				delete[] tempArray;
				tempArray = nullptr;
			}

			double mynewDeterminant = determinant();
			for (int i = 0; i < rows * columns; ++i) {
				if (i % 2 != 0) {
					newArray[i] *= -1;
				}
				newArray[i] /= mynewDeterminant;
			}
		}

		delete[] heapArray;
		heapArray = newArray;
		newArray = nullptr;
	}
}

/// <summary>
/// Multiplies a matrix by a 2 or 3d vector
/// </summary>
/// <typeparam name="T">Generic Template Type</typeparam>
/// <param name="other">The vector to multiply the matrix with</param>
/// <returns>A matrix with one column size and rows equal to this</returns>
template<class T>
inline Matrix<T>& Matrix<T>::multiplyByVector(Vector<T>& other)
{
	if (columns == other.getSize()) {
		T* newArray = new T[rows]{ NULL };
		T* tempVectorArray = new T[other.getSize()] { NULL };
			
		tempVectorArray[0] = other.getX();
		tempVectorArray[1] = other.getY();
		if (other.getSize() == 3) {
			tempVectorArray[2] = other.getZ();
		}

		for (int i = 0; i < rows; ++i) {
			T tempDotProduct = 0;
			for (int j = 0; j < columns; ++j) {
				int x = 0;
				int y = 0;

				x = j;
				if (i > 0) {
					x += columns * i;
				}

				y = j;
				tempDotProduct += heapArray[x] * tempVectorArray[y];
			}
			for (int k = 0; k < rows; ++k) {
				if (newArray[k] == NULL) {
					newArray[k] = tempDotProduct;
					break;
				}
			}
		}
		Matrix<T>* newMatrix = new Matrix<T>(newArray, rows, other.getSize());
		return *newMatrix;
	}
	else {
		throw std::invalid_argument("Matrix's column size needs to match vector's number of elements!");
	}
}

/// <summary>1
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
