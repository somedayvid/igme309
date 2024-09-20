#pragma once
#include <cmath>
template <class T>
class Vector
{
private:
	T x;
	T y;
	T z;
	int dimension;
	float magnitude;
public:
	//constructors destructors
	Vector(T x, T y, T z = NULL);
	~Vector();
	Vector(const Vector& other);

	//arithmetic operators
	Vector& operator+(const Vector& other);
	Vector& operator-(const Vector& other);
	Vector& operator*(const Vector& other);
	//assignment operators
	Vector& operator+=(const Vector& other);
	Vector& operator-=(const Vector& other);
	Vector& operator*=(const Vector& other);
	Vector& operator=(const Vector& other);

	//other vector functions
	void scale(T scaler);
	void normalize();
	float dot(const Vector& other);
	Vector& cross(const Vector& other);
	void addDimension(T z);
	void print();
};

/// <summary>
/// Parameterized constructor for the values of the vector
/// </summary>
/// <typeparam name="T">Template generic class</typeparam>
/// <param name="x">X coordinate</param>
/// <param name="y">Y coordinate</param>
/// <param name="z">Z coordinate</param>
template<class T>
inline Vector<T>::Vector(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	if (z != NULL) {
		dimension = 3;
		this->z = z;
	}
	else {
		dimension = 2;
	}
}

template<class T>
inline Vector<T>::~Vector()
{

}

/// <summary>
/// Copy constructor: copies another vector onto this one
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The vector to be copied over this one</param>
template<class T>
inline Vector<T>::Vector(const Vector& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	dimension = other.dimension;
}

/// <summary>
/// Vector addition operator: adds corresponding coordinates up
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other vector being added to this one</param>
/// <returns>A new vector with added coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator+(const Vector& other)
{
	if (dimension == other.dimension) {
		if (dimension == 2) {
			Vector<T>* newVector = new Vector<T>(x + other.x, y + other.y);
			return *newVector;
		}
		else if (dimension == 3) {
			Vector<T>* newVector = new Vector<T>(x + other.x, y + other.y, z + other.z);
			return *newVector;
		}
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Vector subtraction operator: subtracts other vector's corresponding coordinates from this one
/// </summary>
/// <typeparam name="T">Generic Template Type</typeparam>
/// <param name="other">Other vector whose values will be subtracted from this one's</param>
/// <returns>A new vector with subtracted coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator-(const Vector& other)
{
	if (dimension == other.dimension) {
		if (dimension == 2) {
			Vector<T>* newVector = new Vector<T>(x - other.x, y - other.y);
			return *newVector;
		}
		else if (dimension == 3) {
			Vector<T>* newVector = new Vector<T>(x - other.x, y - other.y, z - other.z);
			return *newVector;
		}
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Vector multiplication operator: multiplies corresponding coordinate values
/// </summary>
/// <typeparam name="T">Generic Template Class</typeparam>
/// <param name="other">The other vector whose values will be multiplied with this one</param>
/// <returns>A new vector with multiplied coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator*(const Vector& other)
{
	if (dimension == other.dimension) {
		if (dimension == 2) {
			Vector<T>* newVector = new Vector<T>(x * other.x, y * other.y);
			return *newVector;
		}
		else if (dimension == 3) {
			Vector<T>* newVector = new Vector<T>(x * other.x, y * other.y, z * other.z);
			return *newVector;
		}
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Vector addition assignment operator: adds and then assigns corresponding coordinate values
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other vector whose values are being added to this one</param>
/// <returns>This vector with its new coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator+=(const Vector& other)
{
	if (dimension == other.dimension) {
		x = this->operator+(other).x;
		y = this->operator+(other).y;
		if (dimension == 3) {
			z = this->operator+(other).z;
		}
		return *this;
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Vector subtraction assignment operator: subtracts other vector's corresponding coordinates from this one and assigns
/// corresponding coordinate values
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other vector whose values are to be subtracted from this one</param>
/// <returns>This vector with its new coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator-=(const Vector& other)
{
	if (dimension == other.dimension) {
		x = this->operator-(other).x;
		y = this->operator-(other).y;
		if (dimension == 3) {
			z = this->operator-(other).z;
		}
		return *this;
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Vector multiplicaation assignment operator: multiplies both vector's coordinates together and assigns them to this one
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other vector whose coordinate values are to be multiplied with this one</param>
/// <returns>This vector with its new coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator*=(const Vector& other)
{
	if (dimension == other.dimension) {
		x = this->operator*(other).x;
		y = this->operator*(other).y;
		if (dimension == 3) {
			z = this->operator*(other).z;
		}
		return *this;
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Assignment operator : copies other vector over this one
/// </summary>
/// <typeparam name="T">Template Generic Type</typeparam>
/// <param name="other">Other vector whose values are to be copied over this one</param>
/// <returns>This vector with its new coordinate values</returns>
template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (dimension == other.dimension) {
		x = other.x;
		y = other.y;
		if (dimension == 3) {
			z = other.z;
		}
		return *this;
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Scales each of the vectors coordinate values by the scalar
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="scaler">The amount to scale/multiply each coordinate value by</param>
template<class T>
inline void Vector<T>::scale(T scaler)
{
	x *= scaler;
	y *= scaler;
	if (dimension == 3) {
		z *= scaler;
	}
}

/// <summary>
/// Normalizes the vector by converting it to a unity vector so it has a length of 1
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
template<class T>
inline void Vector<T>::normalize()
{
	magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z,0));
	x /= magnitude;
	y /= magnitude;
	if (dimension == 3) {
		z /= magnitude;
	}
}

/// <summary>
/// Gets the dot product between two equal dimension vectors
/// </summary>
/// <typeparam name="T">Template Generic Type</typeparam>
/// <param name="other">The other vector</param>
/// <returns>A float representing the dot product</returns>
template<class T>
inline float Vector<T>::dot(const Vector& other)
{
	if (dimension == other.dimension) {
		return x * other.x + y * other.y + z * other.z;
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Calculates the cross product between two equal dimension vectors
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="other">The other vector</param>
/// <returns>A vector representing the line that is perpendicular to both vectors</returns>
template<class T>
inline Vector<T>& Vector<T>::cross(const Vector& other)
{
	if (dimension == other.dimension) {
		Vector<T>* newVector = new Vector<T>(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		return *newVector;
	}
	else {
		throw std::invalid_argument("Vector dimensions need to match!");
	}
}

/// <summary>
/// Turns a 2D vector into a 3D one by adding another dimension
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
/// <param name="z">The length to give the Z axis of the vector</param>
template<class T>
inline void Vector<T>::addDimension(T z)
{
	this->z = z;
	dimension = 3;
}

/// <summary>
/// Prints out all the dimensions of the vector
/// </summary>
/// <typeparam name="T">Template Generic Class</typeparam>
template<class T>
inline void Vector<T>::print()
{
	std::cout << dimension << "D Vector at (" << x << ", " << y;
	if (dimension == 3) {
		std::cout << ", " << z;
	}
	std::cout << ")" << std::endl;
}
