#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &other) {}
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int i = 0;
	while (i < 3 && formNames[i] != name)
		i++;

	AForm* form = NULL;
	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Error: Intern cannot create '" << name << "' form (not found)." << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << name << std::endl;
	return form;
}
