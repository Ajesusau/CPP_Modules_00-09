#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) {
	std::cout << "MutantStack copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other) {
	std::cout << "MutantStack copy assignment operator called" << std::endl;
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}
