#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		T& operator[](unsigned int i);
		T const& operator[](unsigned int i) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
#include "../src/Array.tpp"

#endif
