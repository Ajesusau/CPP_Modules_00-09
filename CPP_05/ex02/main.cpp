#include <iostream>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(std::time(0));
	Bureaucrat boss("The Boss", 1);
	Bureaucrat middle("Mid-Level", 70);
	Bureaucrat intern("The Intern", 150);

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Poor Guy");

	std::cout << "\n--- TEST 1: Shrubbery (El Interno) ---" << std::endl;
	try {
		intern.signForm(shrub);
		intern.executeForm(shrub);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Robotomy (Éxito y Fallo) ---" << std::endl;
	boss.signForm(robot);
	middle.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);

	std::cout << "\n--- TEST 3: Presidential Pardon ---" << std::endl;
	boss.signForm(pardon);
	boss.executeForm(pardon);

	std::cout << "\n--- TEST 4: Ejecutar sin firma ---" << std::endl;
	ShrubberyCreationForm freshForm("forest");
	boss.executeForm(freshForm);

	return 0;
}
