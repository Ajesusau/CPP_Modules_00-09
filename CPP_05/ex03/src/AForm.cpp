#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false) ,_signGrade(signGrade), _execGrade(execGrade) {
	std::cout << "AForm default constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

std::string	AForm::getName() const {
	return this->_name;
}

bool		AForm::getSigned() const {
	return this->_signed;
}

int			AForm::getSignGrade() const {
	return this->_signGrade;
}

int			AForm::getExecGrade() const {
	return this->_execGrade;
}

void		AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void		AForm::execute(const Bureaucrat& bureaucrat) const {
	if (!this->getSigned())
		throw AForm::NotSignedException();
	else if (bureaucrat.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();
	else
		this->action();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm grade too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm: " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade() << ".";
	return os;
}
