#include <iostream>
#include <exception>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
	double result;

	if(argc != 2) {
		std::cerr << "Usage: ./RPN [expression]" << std::endl;
		return 1;
	} else {
		try {
			RPN rpn;
			result = rpn.calculate(argv[1]);
			std::cout << result << std::endl;
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
