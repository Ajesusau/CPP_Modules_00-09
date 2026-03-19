#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	std::cout << "Array default constructor called" << std::endl;
	this->_elements = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	std::cout << "Array default constructor called" << std::endl;
	this->_elements = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(0) {
	std::cout << "Array copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	std::cout << "Array copy assignment operator called" << std::endl;
	if (this != &other) {
		if (this->_elements)
			delete[] this->_elements;
		this->_size = other._size;
		if (this->_size > 0) {
			this->_elements = new T[this->_size];
			unsigned int i = 0;
			while (i < _size) {
				this->_elements[i] = other._elements[i];
				i++;
			}
		} else {
			this->_elements = NULL;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Array destructor called" << std::endl;
	delete[] _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (_elements[i]);
}

template <typename T>
T const& Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (_elements[i]);
}

template <typename T>
unsigned int Array<T>::size() const {
    return this->_size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds");
}
