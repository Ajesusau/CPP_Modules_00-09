#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main() {
	Intern someRandomIntern;
	Bureaucrat boss("Zaphod", 1);
	AForm* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	
	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	AForm* unknown = someRandomIntern.makeForm("unknown form", "target");
	if (!unknown)
		std::cout << "Prueba de error superada." << std::endl;

	return 0;
}
