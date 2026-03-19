#ifndef RPN_HPP
# define RPN_HPP

#include <exception>
#include <iostream>
#include <sstream>
#include <stack>


class RPN
{
	private:
		std::stack<double> _stack;
		void	add(std::stack<double>& stack);
		void	subtract(std::stack<double>& stack);
		void	multiply(std::stack<double>& stack);
		void	division(std::stack<double>& stack);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		double	calculate(std::string exprs);

		class	InvalidArgumentException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class	DivisionByZeroException : public std::exception {
			public:
				virtual const char* what() const throw();
		};


};

#endif
