#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {

	std::cout << "--- Test with std::vector ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try {
			std::vector<int>::iterator it = easyfind(vec, 20);
			std::cout << "Found: " << *it << std::endl;
		
			std::cout << "Searching for non-existent value (42)..." << std::endl;
			easyfind(vec, 42);
	} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "--- Test with std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try {
			std::list<int>::iterator it = easyfind(lst, 3);
			std::cout << "Found: " << *it << std::endl;
		
			std::cout << "Searching for non-existent value (-1)..." << std::endl;
			easyfind(lst, -1);
	} catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
