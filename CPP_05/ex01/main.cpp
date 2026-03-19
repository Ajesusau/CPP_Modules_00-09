#include <iostream>
#include "Bureaucrat.hpp"

int main() {
		Bureaucrat boss("The Boss", 1);
		Bureaucrat intern("Poor Intern", 150);
		Form importantDocument("Tax Report", 50, 25);
		try {
			Form importantDocument2("Tax Report", 151, 25);
		} catch (std::exception& e) {
			std::cout << "Capturada: " << e.what() << std::endl;
		}


		std::cout << importantDocument << std::endl;

		intern.signForm(importantDocument);
		boss.signForm(importantDocument);

		std::cout << importantDocument << std::endl;
	return 0;
}
