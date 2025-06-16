#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy): AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
     if (this == &copy)
        return *this;
    this->_target = copy._target;
    return *this;
}

const char *PresidentialPardonForm::FormNotSigned::what() const throw()
{
    return "Form is not signed!";
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw(FormNotSigned());
    else if (this->getGradeToExecute() < executor.getGrade())
        throw(GradeTooLowException());
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}