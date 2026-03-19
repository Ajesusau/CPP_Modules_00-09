#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	std::cout << "Test vector large range." << std::endl;
	Span sp2 = Span(100000);
	std::vector<int> vector;
	std::srand(time(NULL));
	int i = 0;
	while (i < 100000) {
		int random_int = rand() % 1000000000;
		vector.push_back(random_int);
		i++;
	}

	try	{
		sp2.addNumbers(vector.begin(), vector.end());
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	} catch (std::exception &e)	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test fails." << std::endl;
	Span sp3 = Span(1);

	try	{
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
	} catch (std::exception &e)	{
		std::cout << e.what() << std::endl;
	}

	try {
		sp.addNumber(6);
		sp.addNumber(3);
	} catch (std::exception &e)	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
