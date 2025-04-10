#include "Form.hpp"

Form::Form()
	: _name("Default Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form parametric constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::isSigned() const {
	return this->_signed;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high! Cannot be higher than 1.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low! Grade requirements not met.";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form: " << form.getName()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return os;
}