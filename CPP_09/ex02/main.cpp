#include <iostream>
#include <exception>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {

	if(argc < 2) {
		std::cerr << "Usage: ./PmergeMe [int] [int] ..." << std::endl;
		return 1;
	} else if(argc > 3001) {
		std::cerr << "Error: Do not use more than 3000 numbers." << std::endl;
		return 1;
	} else {
		try {
			PmergeMe pmergeme;
			pmergeme.sortNumbers(argv);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
