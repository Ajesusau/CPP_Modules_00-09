#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNumberValue = 0;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumberValue = value << _fractionalBits;
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumberValue = round(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointNumberValue = other._fixedPointNumberValue;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumberValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointNumberValue = raw;
}

float Fixed::toFloat() const
{
	return (float)_fixedPointNumberValue / (1 << _fractionalBits);
}

int Fixed::toInt() const 
{
	return _fixedPointNumberValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
    out << c.toFloat();
    return out;
}

bool	Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	long temp = (long)this->getRawBits() * (long)other.getRawBits();
	result.setRawBits(temp >> _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	long temp = ((long)this->getRawBits() << _fractionalBits) / (long)other.getRawBits();
	result.setRawBits(temp);
	return result;
}

Fixed	&Fixed::operator++(void)
{
	this->_fixedPointNumberValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fixedPointNumberValue++;
	return temp;
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedPointNumberValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fixedPointNumberValue--;
	return temp;
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if(a < b)
		return a;
	else
		return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if(a < b)
		return a;
	else
		return b;
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if(a > b)
		return a;
	else
		return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if(a > b)
		return a;
	else
		return b;
}
