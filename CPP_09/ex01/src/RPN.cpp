#include "RPN.hpp"

RPN::RPN() {
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN& other) {
	std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {
	std::cout << "RPN destructor called" << std::endl;
}

double	RPN::calculate(std::string exprs) {
	std::istringstream	tokenExprs(exprs);
	std::string			token;
	
	while (tokenExprs >> token) {
		if (token.length() == 1) {
			if(isdigit(token[0]))
				_stack.push(token[0] - '0');
			else if (token[0] == '+')
				add(_stack);
			else if (token[0] == '-')
				subtract(_stack);
			else if (token[0] == '*')
				multiply(_stack);
			else if (token[0] == '/')
				division(_stack);
			else
				throw InvalidArgumentException();
		} else if (token.length() == 2) {
			if (token[0] == '-' && isdigit(token[1]))
				_stack.push(-(token[1] - '0'));
			else 
				throw InvalidArgumentException();
		} else {
			throw InvalidArgumentException();
		}
	}
	if (_stack.size() == 1)
		return _stack.top();
	else
		throw InvalidArgumentException();
}

void	RPN::add(std::stack<double>& stack) {
	double	a;
	double	b;
	double	result;

	if (!stack.empty()) {
		b = stack.top();
		stack.pop();
	} else {
		throw InvalidArgumentException();
	}
	if (!stack.empty()) {
		a = stack.top();
		stack.pop();
	}else {
		throw InvalidArgumentException();
	}
	result = a + b;
	stack.push(result);
}

void	RPN::subtract(std::stack<double>& stack) {
	double	a;
	double	b;
	double	result;

	if (!stack.empty()) {
		b = stack.top();
		stack.pop();
	} else {
		throw InvalidArgumentException();
	}
	if (!stack.empty()) {
		a = stack.top();
		stack.pop();
	}else {
		throw InvalidArgumentException();
	}
	result = a - b;
	stack.push(result);
}

void	RPN::multiply(std::stack<double>& stack) {
	double	a;
	double	b;
	double	result;

	if (!stack.empty()) {
		b = stack.top();
		stack.pop();
	} else {
		throw InvalidArgumentException();
	}
	if (!stack.empty()) {
		a = stack.top();
		stack.pop();
	}else {
		throw InvalidArgumentException();
	}
	result = a * b;
	stack.push(result);
}

void	RPN::division(std::stack<double>& stack) {
	double	a;
	double	b;
	double	result;

	if (!stack.empty()) {
		b = stack.top();
		stack.pop();
	} else {
		throw InvalidArgumentException();
	}
	if (!stack.empty()) {
		a = stack.top();
		stack.pop();
	}else {
		throw InvalidArgumentException();
	}
	if (b == 0)
		throw DivisionByZeroException();
	result = a / b;
	stack.push(result);
}

const char* RPN::InvalidArgumentException::what() const throw() {
	return "Invalid Argument.";
}

const char* RPN::DivisionByZeroException::what() const throw() {
	return "Cannot divide by 0.";
}
