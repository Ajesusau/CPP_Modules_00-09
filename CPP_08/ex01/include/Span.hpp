#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vect;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void	addNumber(int n);
		long		shortestSpan();
		long		longestSpan();

		template <typename T>
		void addNumbers(T begin, T end) {
			if (this->vect.size() + std::distance(begin, end) > N)
				throw NotEnoughSpaceException();
			this->vect.insert(this->vect.end(), begin, end);
		}

		class FullContainerException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughSpaceException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
