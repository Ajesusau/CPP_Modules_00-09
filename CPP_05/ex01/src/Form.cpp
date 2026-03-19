#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false) ,_signGrade(signGrade), _execGrade(execGrade) {
	std::cout << "Form default constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

std::string	Form::getName() const {
	return this->_name;
}

bool		Form::getSigned() const {
	return this->_signed;
}

int			Form::getSignGrade() const {
	return this->_signGrade;
}

int			Form::getExecGrade() const {
	return this->_execGrade;
}

void		Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form grade too high";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName() << ", signed: " << (f.getSigned() ? "yes" : "no")
		<< ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade() << ".";
	return os;
}
