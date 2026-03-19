#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {

	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const{
	return this->_name;
}

int			Bureaucrat::getGrade() const {
	return this->_grade;
}

void		Bureaucrat::incrementGrade() {
	if((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void		Bureaucrat::decrementGrade() {
	if((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void		Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception& exception) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} catch (std::exception& exception) {
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << exception.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() <<", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
