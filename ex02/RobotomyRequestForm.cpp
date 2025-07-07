#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->target = other.target;
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "Bzzzzzz... Bzzzzzz... Bzzzzzz..." << std::endl;
	std::srand((unsigned)time(NULL));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed for " << this->target << "!" << std::endl;
}
