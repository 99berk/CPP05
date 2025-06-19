#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	if (this != &other)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

static AForm *makePresident(const std::string target)
{
    return new PresidentialPardonForm(target);
}

static AForm *makeShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm   *Intern::makeForm(std::string formName, std::string target)
{
    AForm *(*allForms[])(std::string target) = {&makePresident, &makeRobotomy, &makeShrubbery};
    std::string forms[] = {"presidential form", "robotomy form", "shrubbery form"};
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern create the " << formName << " now" << std::endl;
            return allForms[i](target);
        }
    }
    std::cout << "Intern can't create " << formName << std::endl;
    return NULL;
}