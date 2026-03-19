#include "Span.hpp"

Span::Span() {
	std::cout << "Span default constructor called" << std::endl;
	this->N = 0;
}

Span::Span(unsigned int N) {
	std::cout << "Span constructor called" << std::endl;
	this->N = N;
}

Span::Span(const Span& other) {
	std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &other) {
		this->N = other.N;
		this->vect = other.vect;
	}
	return *this;
}

Span::~Span() {
	std::cout << "Span destructor called" << std::endl;
}

void	Span::addNumber(int n) {
	if (this->vect.size() >= this->N)
		throw FullContainerException();
	vect.push_back(n);
}

long	Span::shortestSpan() {
	if (this->vect.size() < 2)
		throw NotEnoughNumbersException();
	size_t	i = 1;
	std::vector<int> tmp = this->vect;
	std::sort(tmp.begin(), tmp.end());
	long min_diff = static_cast<long>(tmp[1]) - tmp[0];;
	while (i < tmp.size() - 1) {
		long diff = static_cast<long>(tmp[i + 1]) - tmp[i];
		if (diff < min_diff)
			min_diff = diff;
		i++;
	}
	return min_diff;
}

long	Span::longestSpan() {
	if (this->vect.size() < 2)
		throw NotEnoughNumbersException();
	
	int min = *std::min_element(vect.begin(), vect.end());
	int max = *std::max_element(vect.begin(), vect.end());
	return static_cast<long>(max) - min;
}

const char *Span::FullContainerException::what() const throw()
{
	return ("Container is full");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in container");
}

const char *Span::NotEnoughSpaceException::what() const throw()
{
	return ("Not enough space in container");
}
