#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	std::cout << "--- Test 1: Funcionamiento normal ---" << std::endl;
	try {
		Bureaucrat b1("Hermes", 3);
		std::cout << b1 << std::endl;
		
		b1.incrementGrade();
		std::cout << "Después de incrementar: " << b1 << std::endl;
		
		b1.decrementGrade();
		std::cout << "Después de decrementar: " << b1 << std::endl;
	} catch (std::exception& exception) {
		std::cout << "Error inesperado: " << exception.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grado inicial demasiado alto (0) ---" << std::endl;
	try {
		Bureaucrat b2("Icarus", 0);
		std::cout << b2 << std::endl;
	} catch (std::exception& exception) {
		std::cout << "Capturada: " << exception.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Grado inicial demasiado bajo (151) ---" << std::endl;
	try {
		Bureaucrat b3("Sisyphus", 151);
		std::cout << b3 << std::endl;
	} catch (std::exception& exception) {
		std::cout << "Capturada: " << exception.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Incrementar más allá del grado 1 ---" << std::endl;
	try {
		Bureaucrat b4("Top Manager", 1);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
	} catch (std::exception& exception) {
		std::cout << "Capturada: " << exception.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Decrementar más allá del grado 150 ---" << std::endl;
	try {
		Bureaucrat b5("The Intern", 150);
		std::cout << b5 << std::endl;
		b5.decrementGrade();
	} catch (std::exception& exception) {
		std::cout << "Capturada: " << exception.what() << std::endl;
	}

	return 0;

}
