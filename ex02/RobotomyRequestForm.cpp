#include "includes/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy): AForm("RobotomyRequestForm", 72, 45), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
     if (this == &copy)
        return *this;
    this->_target = copy._target;
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "Brbrrrrrrrrbrrrrr..." << std::endl;
    std::srand((unsigned)time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}

const char *RobotomyRequestForm::FormNotSigned::what() const throw()
{
    return "Form not signed!";
}