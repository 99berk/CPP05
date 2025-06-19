#include "AForm.hpp"
#include <iostream>

AForm::AForm()
	: name("Default"), isSigned(false), gradeToSign(100), gradeToExecute(50)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	if (other.gradeToSign < 1 || other.gradeToExecute < 1)
		throw GradeTooHighException();
	if (other.gradeToSign > 150 || other.gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "AForm assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm parameterized constructor called" << std::endl;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return os;
}
