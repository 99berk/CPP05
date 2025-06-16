#include "includes/Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &copy)
{
    *this = copy;
    // this->name = copy.name;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern  &Intern::operator=(Intern const &copy)
{
    if (this == &copy)
        return *this;
    return *this;
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
    std::string forms[] = {"Presidential form", "Robotomy form", "Shrubbery form"};
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