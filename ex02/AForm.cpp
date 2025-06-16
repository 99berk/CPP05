#include "includes/AForm.hpp"
#include <iostream>
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
    _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Default constructor called" << std::endl;
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw (AForm::GradeTooHighException());
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw (AForm::GradeTooLowException());
    this->_isSigned = 0;
}

AForm::AForm(AForm const &copy):
    _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign),
        _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this->_gradeToExecute < 1 || this->_gradeToSign < 1)
        throw (AForm::GradeTooHighException());
    if (this->_gradeToExecute > 150 || this->_gradeToSign > 150)
        throw (AForm::GradeTooLowException());
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy)
{
    this->_isSigned = copy._isSigned;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw (AForm::GradeTooLowException());
    else
        this->_isSigned = 1;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}
int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

bool AForm::isSigned() const
{
    return this->_isSigned;
}

std::string AForm::getName() const
{
    return this->_name;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "\e[1;31m Grade too high!\e[0m";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "\e[1;31m Grade too low!\e[0m";
}

std::ostream &operator<<(std::ostream &os, AForm& print)
{
    if (print.isSigned())
        return os << "AForm " << print.getName()\
            << " needs min " << print.getGradeToSign() << " grade to be signed and min "\
            << print.getGradeToExecute() << " grade to be executed. It's signed";
    else
        return os << "AForm " << print.getName()\
            << " needs min " << print.getGradeToSign() << " grade to be signed and min "\
            << print.getGradeToExecute() << " grade to be executed. It's not signed";
}